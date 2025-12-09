/*************************************************************************
                           Affichage  -  Manipule les sorties du logiciel
                             -------------------
    début                : 03/12
    copyright            : (C) 2025 par Ammydriss Jad, Essaki Mohammed, EL HABI Aymane
*************************************************************************/

//---------- Interface de la classe <Affichage> (fichier Affichage.h) ----------------
#if ! defined ( AFFICHAGE_H )
#define AFFICHAGE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <fstream>
#include <vector>
using namespace std;
#include "Noeud.h"


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
enum statutFlux{ VALIDE , ERREUR_OUVERTURE , ERREUR_ECRITURE };
enum surEcriture{ ANNULER , FORCER };
//------------------------------------------------------------------------
// Rôle de la classe <Affichage>
// Gère l'affichage et l'écriture des résultats dans des fichiers
// (format GraphViz .dot) ou sur la sortie standard
//------------------------------------------------------------------------

class Affichage
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    statutFlux OuvrirFichier( string chemin, surEcriture comportement = ANNULER );
    // Mode d'emploi : 
    // Ouvre un flux d'écriture vers le fichier spécifié par 'chemin'
    // Si un fichier existe déjà et que 'comportement' vaut ANNULER, retourne ERREUR_ECRITURE
    // Si le fichier ne peut pas être ouvert en écriture, retourne ERREUR_OUVERTURE
    // Sinon, ouvre le flux et retourne VALIDE
    // Contrat : Le chemin doit être valide

    bool EcrireGraphe( const map < string , Noeud > & tableLiens );
    // Mode d'emploi :
    // Écrit le graphe complet au format GraphViz (DOT) dans le fichier ouvert
    // 'tableLiens' contient l'ensemble des nœuds et leurs connexions
    // Retourne true si l'écriture réussit, false sinon
    // Contrat : Un fichier doit avoir été ouvert avec succès au préalable 

    bool EcrireSousGraphe( const vector < Noeud > & sousGraphe);
    // Mode d'emploi : 
    // Écrit un sous-graphe au format GraphViz contenant uniquement les nœuds spécifiés
    // et les liens existants entre eux dans le fichier ouvert précédemment
    // Retourne true si l'écriture réussit, false sinon
    // Contrat : Un fichier doit avoir été ouvert avec succès au préalable 


    void FermerFichier();
    // Mode d'emploi : 
    // Ferme le flux d'écriture s'il est ouvert
    // Contrat : Aucun (la méthode vérifie si le flux est ouvert)

    void AfficherListe( const vector < Noeud > & listeNoeuds );
    // Mode d'emploi : 
    // Affiche sur la sortie standard le label et le nombre d'accès de chaque nœud
    // Les nœuds sont affichés dans l'ordre du vecteur fourni
    // Format : "label (nombre hits)"
    // Contrat : Aucun 
//------------------------------------------------- Surcharge d'opérateurs
    /*Affichage & operator = ( const Affichage & unAffichage );
    // Mode d'emploi :
    //
    // Contrat :
    //*/


//-------------------------------------------- Constructeurs - destructeur
    Affichage ( const Affichage & unAffichage );
    // Mode d'emploi (constructeur de copie) :
    // Crée une copie de l'objet Affichage passé en paramètre
    // Contrat : Aucun

    Affichage ( );
    // Mode d'emploi :
    // Constructeur par défaut, initialise un objet Affichage
    // Contrat : Aucun

    virtual ~Affichage ( );
    // Mode d'emploi :
    // Destructeur, libère les ressources et ferme les flux ouverts
    // Contrat : Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    ofstream fEcriture;
    string nomFichier;
};

//-------------------------------- Autres définitions dépendantes de <Affichage>

#endif // Affichage_H

