/*************************************************************************
                           Noeud  -  Encapsule les attributs et les actions sur un noeud de graphe orienté ou non
                             -------------------
    début                : 03/12
    copyright            : (C) 2025 par Ammydriss Jad, Essaki Mohammed, EL HABI Aymane
*************************************************************************/

//---------- Interface de la classe <Noeud> (fichier Noeud.h) ----------------
#if ! defined ( NOEUD_H )
#define NOEUD_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Noeud>
// Représente un nœud dans un graphe orienté
// Encapsule le label, les liens entrants et le compteur d'accès
//------------------------------------------------------------------------

class Noeud
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AjouterLien( string sourceReferer, bool avecDetails);
    // Mode d'emploi : 
    // Enregistre un accès au nœud depuis la source 'sourceReferer'
    // Si 'avecDetails' est true, stocke le lien dans la structure avec son poids
    // Sinon, incrémente uniquement le compteur total d'accès
    // Contrat : Si 'sourceReferer' a déjà été passé, il correspond au même nœud source 

    unsigned int GetNombreLiens() const;
    // Mode d'emploi : 
    // Retourne le nombre total d'accès au nœud (poids total de tous les liens entrants)
    // Contrat : Aucun

    unsigned int GetNumNoeud() const;
    // Mode d'emploi :
    // Retourne le numéro unique d'identification du nœud
    // Ce numéro est attribué automatiquement à la création
    // Contrat : Aucun

    const map < string, int > & GetStructure() const;
    // Mode d'emploi :
    // Retourne la map contenant tous les liens entrants vers ce nœud
    // Clé = label du nœud source, Valeur = poids du lien (nombre d'accès)
    // Contrat : Aucun

    const string GetLabel() const;
    // Mode d'emploi : 
    // Retourne le label (nom) du nœud
    // Contrat : Aucun

    int GetAccesDepuisSource( string labelSource ) const;
    // Mode d'emploi : 
    // Retourne le poids du lien entre 'labelSource' et ce nœud
    // Retourne -1 si aucun lien n'existe depuis cette source
    // Contrat : Aucun

//------------------------------------------------- Surcharge d'opérateurs
    /*Noeud & operator = ( const Noeud & unNoeud );
    // Mode d'emploi :
    //
    // Contrat :
    //*/
    bool operator > ( const Noeud & noeudAComparer ) const ;
    // Mode d'emploi : 
    // Compare deux nœuds : d'abord par nombre d'accès, puis par label (ordre lexicographique)
    // Retourne true si le nœud courant est supérieur à 'noeudAComparer'
    // Contrat : Aucun 


//------------ groupe "com.google.code.gson", version 2.8.52.artfact "htpclient" du groupe "org.apache.htpcomponents", version 4.5.7Pour exploiter cete API, la classe AstroTest est fournie sur Moodle: elle montre commentdemander le calcul du profl astrologique-------------------------------- Constructeurs - destructeur
    /*Noeud ( const Noeud & unNoeud );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //*/
    Noeud ( );
    // Mode d'emploi : 
    // Constructeur par défaut, crée un nœud avec le label "DEFAULT"
    // Contrat : Aucun
    Noeud ( string labelNoeud);
    // Mode d'emploi :
    // Constructeur, crée un nœud avec le label spécifié
    // Contrat : Aucun

    virtual ~Noeud ( );
    // Mode d'emploi :
    // Destructeur, libère les ressources du nœud
    // Contrat : Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
string label;
map < string, int> liens;
unsigned int nombreLiens;
unsigned int numNoeud;
static unsigned int nombreNoeuds;
};

//-------------------------------- Autres définitions dépendantes de <Noeud>

#endif // NOEUD_H

