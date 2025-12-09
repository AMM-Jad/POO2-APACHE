/*************************************************************************
                           Graphe  -  Encapsule la structure d'un graphe orienté
                             -------------------
    début                : 03/12
    copyright            : (C) 2025 par Ammydriss Jad, Essaki Mohammed, EL HABI Aymane
*************************************************************************/

//---------- Réalisation de la classe <Graphe> (fichier Graphe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Graphe.h"
#include "Noeud.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Graphe::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool Graphe::AjouterLien( string labelPre, string labelNoeud , bool details)
{

	if( tableLiens.count(labelNoeud) != 0 ) // ajout de l'accès au noeud déjà présent
	{
		tableLiens[labelNoeud].AjouterLien(labelPre, details);
	}
	else // Ajout du noeud avec un accès vers lui  
	{
		Noeud nouveauDoc = Noeud( labelNoeud );
		nouveauDoc.AjouterLien( labelPre, details );
		tableLiens.emplace( labelNoeud, nouveauDoc );
		nombreNoeuds++;
	}
	// si le labelPre n'est pas dans la table on l'ajoute aussi en tant que Noeud sans accès vers lui
	if( tableLiens.count(labelPre) == 0 ) //Ajout du noeud avec un accès vers lui
	{
		tableLiens.emplace( labelPre, Noeud(labelPre));
		nombreNoeuds++;
	}
	return true;
}

const vector < Noeud > Graphe::GetPlusConnectes( int n ) const
// Algorithme:
// Extrait les documents de la structure pour les trier selon leur nombre d'accès puis par nom
// Utilisation d'une fonction lambda pour le tri personnalisé
// Puis extraction d'un sous vecteur de taille voulu
{
	unsigned int nbRetour = 0;
	if( n < 0 || (unsigned int)n > nombreNoeuds )
	{
		nbRetour = nombreNoeuds;
	}
	else
	{
		nbRetour = (unsigned int) n;
	}
	
	vector < Noeud > tousDocs = vector < Noeud > ( nombreNoeuds);
	unsigned int i = 0;
	for (map < string , Noeud > ::const_iterator it = tableLiens.begin(); it != tableLiens.end() ; ++ it )
	{
		tousDocs[i] = it->second;
		i++;
	}
	vector < Noeud > selection = vector < Noeud> (nbRetour);
	partial_sort_copy(tousDocs.begin(), tousDocs.end(), selection.begin() , selection.end(), // utilisation d'une fonction lambda
		[](const Noeud & docA, const Noeud & docB)
		{
			return docA > docB;
		});
	return selection;
	
}

const map < string, Noeud > & Graphe::GetStructure() 
{
	return tableLiens;
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
/*Graphe::Graphe ( const Graphe & unGraphe )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Graphe>" << endl;
#endif
} //----- Fin de Graphe (constructeur de copie)
*/

Graphe::Graphe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Graphe>" << endl;
#endif
    nombreNoeuds = 0;
	tableLiens=map < string, Noeud >();
} //----- Fin de Graphe


Graphe::~Graphe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Graphe>" << endl;
#endif
} //----- Fin de ~Graphe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
