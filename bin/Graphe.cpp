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

bool Graphe::AjouterLien( string labelSource, string labelCible, bool avecDetails)
// Algorithme :
// 1. Si le nœud cible existe déjà, lui ajoute le lien depuis la source
// 2. Sinon, crée le nœud cible et lui ajoute le lien
// 3. Si le nœud source n'existe pas, le crée aussi (sans lien entrant)
{

	if( tableLiens.count(labelCible) != 0 ) // ajout de l'accès au noeud déjà présent
	{
		tableLiens[labelCible].AjouterLien(labelSource, avecDetails);
	}
	else // Ajout du noeud avec un accès vers lui  
	{
		Noeud nouveauDoc = Noeud( labelCible );
		nouveauDoc.AjouterLien( labelSource, avecDetails );
		tableLiens.emplace( labelCible, nouveauDoc );
		nombreNoeuds++;
	}
	// si le labelSource n'est pas dans la table on l'ajoute aussi en tant que Noeud sans accès vers lui
	if( tableLiens.count(labelSource) == 0 ) //Ajout du noeud avec un accès vers lui
	{
		tableLiens.emplace( labelSource, Noeud(labelSource));
		nombreNoeuds++;
	}
	return true;
}

const vector < Noeud > Graphe::GetPlusConnectes( int nombreNoeuds ) const
// Algorithme:
// 1. Détermine le nombre de nœuds à retourner (limite au total disponible)
// 2. Extrait tous les nœuds de la map dans un vecteur
// 3. Utilise partial_sort_copy avec une fonction lambda pour trier par popularité
// 4. Retourne le vecteur trié des n meilleurs nœuds
{
	unsigned int nbARetourner = 0;
	if( nombreNoeuds < 0 || (unsigned int)nombreNoeuds > this->nombreNoeuds )
	{
		nbARetourner = this->nombreNoeuds;
	}
	else
	{
		nbARetourner = (unsigned int) nombreNoeuds;
	}
	
	vector < Noeud > tousLesNoeuds = vector < Noeud > ( this->nombreNoeuds);
	unsigned int i = 0;
	for (map < string , Noeud > ::const_iterator it = tableLiens.begin(); it != tableLiens.end() ; ++ it )
	{
		tousLesNoeuds[i] = it->second;
		i++;
	}
	vector < Noeud > selectionTriee = vector < Noeud> (nbARetourner);
	partial_sort_copy(tousLesNoeuds.begin(), tousLesNoeuds.end(), selectionTriee.begin() , selectionTriee.end(), // utilisation d'une fonction lambda
		[](const Noeud & noeudA, const Noeud & noeudB)
		{
			return noeudA > noeudB;
		});
	return selectionTriee;
	
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
