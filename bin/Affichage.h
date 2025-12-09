/*************************************************************************
                           Affichage  -  Manipule les sorties du logiciel
                             -------------------
    début                : 01/19
    copyright            : (C) 2019 par Gadacha A, Tondereau A
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
//
//
//------------------------------------------------------------------------

class Affichage
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    statutFlux OuvrirFichier( string chemin, surEcriture = ANNULER );
    // Mode d'emploi : 
    // Ouvre le flux d'ecriture vers le chemin spécifié
    // Si un fichier existe deja et que surEcriture est placé sur ANNULER la methode renvoie ERREUR_ECRITURE
    // Si un fichier ne peut pas être ouvert en écriture la méthode renvoie ERREUR_ECRITURE
    // Sinon le flux est ouvert est le retour est VALIDE
    // Contrat :

    bool EcrireGraphe( const map < string , Noeud > & tableLiens );
    // Mode d'emploi :
    // Prend en paramètre la map contenant tous les liens entre Noeuds, et la retranscrit au format GrapheViz
    // Contrat : 
    // 

    bool EcrireSousGraphe( const vector < Noeud > & sousGraphe);
    // Mode d'emploi : 
    // Dessine uniquement les liens entre les noeuds contenues dans le sous graphe dans le fichier .dot spécifié à l'ouverture
    // Contrat : 
    // 


    void FermerFichier();
    // Mode d'emploi : 
    // Ferme le flux ouvert
    // Contrat : 
    // Le flux est bien ouvert

    void AfficherListe( const vector < Noeud > & listeNoeuds );
    // Mode d'emploi : 
    // Affiche le nom et le nombre de liens des Noeuds dans le conteneur, dans l'ordre
    // Contrat : 
//------------------------------------------------- Surcharge d'opérateurs
    /*Affichage & operator = ( const Affichage & unAffichage );
    // Mode d'emploi :
    //
    // Contrat :
    //*/


//-------------------------------------------- Constructeurs - destructeur
    Affichage ( const Affichage & unAffichage );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Affichage ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Affichage ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    ofstream fEcriture;
    string nomFichier;
};

//-------------------------------- Autres définitions dépendantes de <Affichage>

#endif // Affichage_H

