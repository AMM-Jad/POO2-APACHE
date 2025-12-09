/*************************************************************************
                           Analog  -  Lecture et statistiques sur des fichiers de logs apache
                             -------------------
    début                : 01/19
    copyright            : (C) 2019 par Gadacha A, Tondereau A
*************************************************************************/

//---------- Réalisation du module <Analog> (fichier Analog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Analog.h"
#include "LectureLog.h"
#include "Graphe.h"
#include "Noeud.h"
#include "Affichage.h"

//------------------------------------------------------------- Constantes
const int NOMBRE_DOCS_DEFAUT = 10;
//----------------------------------------------------------------- PUBLIC

//---------------------------	-------------------------- Méthodes publiques
// type Analog::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
int main( int argc, char ** argv)
{
	
	bool argsValides = true; 
	vector < bool (*)(Activite_t & ,ParamsTest) > filtres;
	vector < ParamsTest > params_fonctions;

	bool nomLogPresent = false;
	string nomLog;
	
	bool faireGraphe = false;
	string nomGraphe;

	bool nombreChoisi = false;
	int nbSelect = NOMBRE_DOCS_DEFAUT;

	bool forceDemande = false;
	// parcourt le tableau des arguments
	for ( int i = 1 ; i < argc && argsValides ; i++ )
	{
		string argCourant = argv[ i ] ;
		if( strlen( argv[i] ) < 1 ) 
		{
			argsValides = false;
		}
		if( argCourant == "-g" )
		{
			if( i == argc -1 )
			{
				argsValides = false;
				cerr << "Paramètre non valide pour l'option -g : aucun paramètre" << endl;
			}
			else
			{
				nomGraphe = argv [ i+1 ];
				faireGraphe = true;
				i++;
			}
		}
		else if( argCourant == "-t" )
		{
			if( i == argc -1 )
			{
				argsValides = false;
				cerr << "Paramètre non valide pour l'option -t : aucun paramètre" << endl;
			}
			else
			{
				int heureDebut = getHeure(argv[ i + 1 ] );
				if( heureDebut == -1)
				{
					argsValides = false;
					cerr << "Paramètre non valide pour l'option -t " << endl;
				}
				else
				{
					//creer un pointeur de fonction vers la selection Horaire, la ref, les ajouter dans les vector
					ParamsTest paramHeure = {};
					paramHeure.intParam = heureDebut ;
					params_fonctions.push_back(paramHeure);
					filtres.push_back(&selectHoraire);
					i++;
				}
			}
		}
		else if( argCourant == "-e")
		{
			params_fonctions.push_back({});
			filtres.push_back(&selectExtension);
		}

		else if( argCourant == "-n" )
		{
			if( i == argc -1 )
			{
				argsValides = false;
				cerr << "Paramètre non valide pour l'option -n : aucun paramètre" << endl;
			}
			else
			{
				bool digit = true;
				for( unsigned int j = 0 ; j < strlen(argv[i+1]) && digit; j++)
				{
					if( !isdigit( argv[ i+1 ][ j ] ) )
					{
						digit = false;
						break;
					}
				}
				if(!digit)
				{
					argsValides = false;
					cerr << " Paramètre non valide pour l'option -n : pas un nombre positif"; 
				}
				else	//cas valide
				{
					nbSelect = stoi(argv[i+1]);
					nombreChoisi = true;
					i++;
				}
				
			}
		}
		else if( argCourant == "-f")
		{
			forceDemande = true;
		}
		else if ( argCourant == "-a")
		{
			nbSelect = -1;
		}		
		else if (argCourant.size()>4 && argCourant.substr(argCourant.size() - 4) == ".log")
		{
			nomLogPresent = true;
			nomLog = argCourant;
		}
		else
		{
			cerr << "Paramètre "<< argv[i] <<" non reconnu " << endl;
			argsValides = false; 
		}
	}

	if(!nomLogPresent && argsValides)
	{
		cerr << "Aucun log spécifié" << endl;
		argsValides = false;
	}
	if(!argsValides)
	{
		cerr << "Abandon."<< endl;
		return 1;
	}


	LectureLog lecteur;
	if(!lecteur.Ouvrir(nomLog))
	{
		cerr << "Impossible d'ouvrir le log spécifié" << endl;
		return 1;
	}
	//construction du graphe des connexions dans les classes prévues pour
	Graphe connections;
	bool init = true;
	bool vide = true;
	while( lecteur.LireSuivant() )
	{
		Activite_t activite = lecteur.GetActivite();
		if( testOptions( activite, filtres, params_fonctions ) )
		{
			vide = false;
			connections.AjouterLien( activite.referer, activite.titreDoc , faireGraphe ) ;
		}
		init = false;
	}
	if(init || vide )
	{
		cerr << "Le log spécifié est vide" << endl;
		return 1;
	}
	if( faireGraphe ) //construction du Graphe puis écriture dans le fichier spécifié
	{
		Affichage dessinGraphe;
		statutFlux resOuverture = dessinGraphe.OuvrirFichier( nomGraphe );
		
		if( resOuverture == ERREUR_ECRITURE )
		{
			if( forceDemande || demanderSurEcriture() ) //demander la confirmation avant de forcer l'écrasement d'un fichier existant, ou -f
			{
				resOuverture = dessinGraphe.OuvrirFichier( nomGraphe, FORCER );
			}
			else
			{
				cout << "Abandon." << endl;
				return 0;
			}
		}
		if( resOuverture == ERREUR_OUVERTURE )
		{
			cerr << "Impossible d'écrire dans le fichier spécifié" << endl;
			return 1;
		}
		else if( resOuverture == VALIDE )
		{
			if(!nombreChoisi)
			{
				dessinGraphe.EcrireGraphe ( connections.GetStructure() );
			}
			else // nombre de noeuds à inclure précisé
			{
				dessinGraphe.EcrireSousGraphe( connections.GetPlusConnectes ( nbSelect ) );
			}
			
			dessinGraphe.FermerFichier();
		}
	}
	else
	{
		Affichage sortieListe;
		sortieListe.AfficherListe( connections.GetPlusConnectes ( nbSelect ) );
	}
	return 0;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

int getHeure(string strHeure)
{
  for( unsigned int i = 0 ; i < strHeure.size() ; i++)
    {
  	if( !isdigit( strHeure[i] ) )
    {
      return -1;
    }
  }

  int heure = stoi ( strHeure ) ;
  if( heure < 0 or heure > 23 ) 
  {
    return -1;
  }
  return heure;
}

bool testOptions( Activite_t aTester,vector < bool (*)(Activite_t & ,ParamsTest) > & filtres, vector < ParamsTest > & refs)
{
	for (unsigned int i = 0 ; i < filtres.size() ; i++ )
	{
		if(!filtres[i](aTester, refs[ i ] ) )
		{
			return false;
		}
	}
	return true;
}
bool selectHoraire ( Activite_t & aTester , ParamsTest params)
{
	return aTester.date.heure == params.intParam;
}

bool selectExtension( Activite_t & aTester , ParamsTest params)
{
	static unsigned int nombreExtensions = 8;
	static string extensions_rejetees[] = {"js","css","png","jpg","jpeg","gif","tiff","ico"};
	for(unsigned int i = 0 ; i < nombreExtensions ; i++ )
	{
		if(aTester.typeDoc == extensions_rejetees[i])
		{
			return false;
		}
	}
	return true;
}

bool demanderSurEcriture()
{
  cout << "Fichier déjà existant, voulez vous l'écraser? [O/n]" << endl;
  string reponse = " ";
  cin >> reponse;
  if(reponse=="o" || reponse =="O")
  {
  	return true;
  }
  return false;
}

bool stringEstChiffre( string chaine )
{
	for( unsigned int i = 0 ; i < chaine.size() ; i++)
  {
		if( !isdigit( chaine[i] ) )
		{
			return false;
		}
  }
	return true;
}