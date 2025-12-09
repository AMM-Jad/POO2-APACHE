/*************************************************************************
                           Affichage  -  Manipule les sorties du logiciel
                             -------------------
    début                : 03/12
    copyright            : (C) 2025 par Ammydriss Jad, Essaki Mohammed, EL HABI Aymane
*************************************************************************/

//---------- Réalisation de la classe <Affichage> (fichier Affichage.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Affichage.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Affichage::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

statutFlux Affichage::OuvrirFichier( string chemin, surEcriture comportement )
{
	ifstream fExiste ( chemin , ios::in );
	if( fExiste && comportement == surEcriture::ANNULER )
	{
		fExiste.close();
		return statutFlux::ERREUR_ECRITURE;
	}
	if( fExiste )
	{
		fExiste.close();
	}
	//test d'ouverture 
	fEcriture.open( chemin , ios::out | ios::trunc );
	if( !fEcriture )
	{
		return statutFlux::ERREUR_OUVERTURE;
	}
	nomFichier = chemin;
	return statutFlux::VALIDE;
}

bool Affichage::EcrireGraphe( const map < string , Noeud > & tableLiens )
// Algorithme : 
// Commence par écrire tous les noeuds du graphe, puis prend des itérateurs constants pour parcourir toute la structure de donnée
// Doit récuperer le numéro des deux noeuds de la liaison à chaque écriture
{
	if(!fEcriture)
	{
		return false;
	}
	fEcriture << "digraph " << " {" << endl;
	for( map <string , Noeud >::const_iterator it = tableLiens.cbegin() ; it !=  tableLiens.cend() ; it++ )
	{
		fEcriture << "node" << it->second.GetNumNoeud() << " [label = \"" << it->first << "\"];" << endl;
	}
	for( map <string , Noeud >::const_iterator it = tableLiens.cbegin() ; it !=  tableLiens.cend() ; it++ )
	{
		for ( map < string, int >::const_iterator itNoeud = it->second.GetStructure().cbegin() ; itNoeud != it->second.GetStructure().cend() ; itNoeud++)
		{
			fEcriture << "node" << tableLiens.at(itNoeud->first).GetNumNoeud() << " -> node" << it->second.GetNumNoeud();
			fEcriture << " [label=\"" << itNoeud->second << "\"];" << endl;
		}
	}
	fEcriture << "}"<< endl;
	return true;
}	

bool Affichage::EcrireSousGraphe( const vector < Noeud > & sousGraphe )
// Algorithme : 
// Commence par écrire tous les noeuds du graphe, puis prend des itérateurs constants pour parcourir toute la structure de donnée
// Doit récuperer le numéro des deux noeuds de la liaison à chaque écriture
// Doit vérifier que les deux noeuds sont bien liés avant de chercher la valeur de l'arc entre les deux.
{
	if(!fEcriture)
	{
		return false;
	}
	fEcriture << "digraph " << " {" << endl;
	for( vector < Noeud > ::const_iterator it = sousGraphe.cbegin() ; it !=  sousGraphe.cend() ; it++ )
	{
		fEcriture << "node" << it->GetNumNoeud() << " [label = \"" << it->GetLabel() << "\"];" << endl;
	}
	for( vector < Noeud > ::const_iterator itCible = sousGraphe.cbegin() ; itCible !=  sousGraphe.cend() ; itCible++ )
	{
		for( vector < Noeud > ::const_iterator itSource = sousGraphe.cbegin() ; itSource!=  sousGraphe.cend() ; itSource++ )
		{
			if(itCible->GetAccesDepuisSource( itSource->GetLabel() ) != -1) //si il y a bien une connection entre les deux noeuds 
			{
				fEcriture << "node" << itSource->GetNumNoeud() << " -> node" << itCible->GetNumNoeud() << " [label=\"" << itCible->GetAccesDepuisSource( itSource->GetLabel() ) << "\"];" << endl;
			}
		}
	}
	fEcriture << "}"<< endl;
	return true;
}
void Affichage::FermerFichier()
{
	if(fEcriture)
	{
		fEcriture.close();
	}
}

void Affichage::AfficherListe( const vector < Noeud > & listeNoeuds )
{
	for ( unsigned int i = 0 ; i < listeNoeuds.size() ; i ++ )
	{
		cout << listeNoeuds[i].GetLabel() << " (" << listeNoeuds[i].GetNombreLiens() << " hits)" << endl; 
	}
}

//------------------------------------------------- Surcharge d'opérateurs
/*Affichage & Affichage::operator = ( const Affichage & unAffichage )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
/*Affichage::Affichage ( const Affichage & unAffichage )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Affichage>" << endl;
#endif
} //----- Fin de Affichage (constructeur de copie)
*/

Affichage::Affichage ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Affichage>" << endl;
#endif
} //----- Fin de Affichage


Affichage::~Affichage ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Affichage>" << endl;
#endif
} //----- Fin de ~Affichage


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées