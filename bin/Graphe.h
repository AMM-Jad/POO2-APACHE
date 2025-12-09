/*************************************************************************
                           Graphe  -  Encapsule la structure d'un graphe orienté
                             -------------------
    début                : 01/19
    copyright            : (C) 2019 par Gadacha A, Tondereau A
*************************************************************************/

//---------- Interface de la classe <Graphe> (fichier Graphe.h) ----------------
#if ! defined ( GRAPHE_H )
#define GRAPHE_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
using namespace std;
#include "Noeud.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Graphe>
//
//
//------------------------------------------------------------------------

class Graphe
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    bool AjouterLien( string labelPre, string labelNoeud, bool detail = true);
    // Mode d'emploi : 
    // Ajoute un lien entre les deux Noeuds mentionnés dans la structure si detail est à True,
    // ne fait qu'incrémenter le nombre d'accès à la cible sinon
    // Contrat : 
    // Si un des noms a déjà été ajouté précédemment dans la structure alors il correspond au même Noeud

    const vector < Noeud > GetPlusConnectes( int n ) const;
    // Mode d'emploi : 
    // Renvoie les n Noeuds les plus consultés dans un tableau
    // si n >= nombreNoeuds alors tous les éléments sont renvoyés
    // si n est negatif alors tous les éléments sont renvoyés
    // Contrat : 

    const map < string , Noeud > & GetStructure();
    // Mode d'emploi : 
    // Renvoie la structure de données contenant tous les liens entre Noeuds
    // Contrat :


//------------------------------------------------- Surcharge d'opérateurs
    /*Graphe & operator = ( const Graphe & unGraphe );
    // Mode d'emploi :
    //
    // Contrat :
    //*/


//-------------------------------------------- Constructeurs - destructeur
    /*Graphe ( const Graphe & unGraphe );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    // */

    Graphe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Graphe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

map < string, Noeud > tableLiens;
unsigned int nombreNoeuds;
};
//-------------------------------- Autres définitions dépendantes de <Graphe>

#endif // GRAPHE_H