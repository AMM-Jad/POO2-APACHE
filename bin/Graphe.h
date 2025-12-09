/*************************************************************************
                           Graphe  -  Encapsule la structure d'un graphe orienté
                             -------------------
    début                : 03/12
    copyright            : (C) 2025 par Ammydriss Jad, Essaki Mohammed, EL HABI Aymane
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
// Encapsule un graphe orienté représentant les liens entre pages web
// Gère l'ajout de liens et le tri des nœuds par popularité
//------------------------------------------------------------------------

class Graphe
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    bool AjouterLien( string labelSource, string labelCible, bool avecDetails = true);
    // Mode d'emploi : 
    // Ajoute un lien orienté entre deux nœuds (source -> cible)
    // Si 'avecDetails' est true, stocke les détails du lien dans la structure
    // Crée automatiquement les nœuds s'ils n'existent pas déjà
    // Retourne toujours true
    // Contrat : Si un label a déjà été utilisé, il désigne le même nœud

    const vector < Noeud > GetPlusConnectes( int nombreNoeuds ) const;
    // Mode d'emploi : 
    // Retourne les 'nombreNoeuds' nœuds les plus consultés, triés par ordre décroissant
    // Si 'nombreNoeuds' est négatif ou supérieur au total, retourne tous les nœuds
    // Le tri s'effectue d'abord par nombre d'accès, puis par label en cas d'égalité
    // Contrat : Aucun 

    const map < string , Noeud > & GetStructure();
    // Mode d'emploi : 
    // Retourne la map contenant tous les nœuds du graphe
    // Clé = label du nœud, Valeur = objet Noeud
    // Contrat : Aucun


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
    // Constructeur par défaut, initialise un graphe vide
    // Contrat : Aucun

    virtual ~Graphe ( );
    // Mode d'emploi :
    // Destructeur, libère les ressources du graphe
    // Contrat : Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

map < string, Noeud > tableLiens;
unsigned int nombreNoeuds;
};
//-------------------------------- Autres définitions dépendantes de <Graphe>

#endif // GRAPHE_H