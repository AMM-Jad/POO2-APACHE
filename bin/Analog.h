/*************************************************************************
                           Analog  -  Lecture et statistiques sur des fichiers de logs apache
                             -------------------
    début                : 03/12
    copyright            : (C) 2025 par Ammydriss Jad, Essaki Mohammed, EL HABI Aymane
*************************************************************************/

//---------- Interface du module <Analog> (fichier Analog.h) ----------------
#if ! defined ( ANALOG_H )
#define ANALOG_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>

#include "LectureLog.h"

//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
typedef struct params_t
{
    string strParam;
    unsigned int intParam;
} ParamsTest;
//------------------------------------------------------------------------
// Rôle du module <Analog>
// Point d'entrée du programme : analyse des logs Apache
// Gestion des options en ligne de commande et génération de statistiques
//------------------------------------------------------------------------

//----------------------------------------------------------------- PUBLIC

//public:
//----------------------------------------------------- Méthodes publiques
    int main( int argc, char** argv );
    // Mode d'emploi : 
    // Point d'entrée du programme, gère les arguments de ligne de commande
    // Analyse le fichier de log spécifié et produit les statistiques demandées
    // Retourne 0 en cas de succès, 1 en cas d'erreur
    // Contrat : argc et argv doivent être valides

//------------------------------------------------- Surcharge d'opérateurs


//------------------------------------------------------------------ PRIVE

//protected:
//----------------------------------------------------- Méthodes protégées

    int getHeure ( string chaineHeure );
    // Mode d'emploi :
    // Convertit une chaîne de caractères en heure valide (0-23)
    // Retourne l'heure si valide, -1 sinon
    // Contrat : Aucun
    
    bool testOptions( Activite_t activiteATester, vector < bool (*)(Activite_t &, ParamsTest) > & filtres, vector < ParamsTest > & parametresFiltres);
    // Mode d'emploi :
    // Applique tous les filtres specifies a une activite
    // Retourne true si l'activite passe tous les filtres, false sinon
    // Contrat : Les vecteurs 'filtres' et 'parametresFiltres' doivent avoir la même taille

    bool selectHoraire ( Activite_t & activiteATester, ParamsTest parametres);
    // Mode d'emploi :
    // Filtre les activites selon l'heure specifiee dans 'parametres.intParam'
    // Retourne true si l'heure de l'activite correspond, false sinon
    // Contrat : 'parametres.intParam' doit contenir une heure valide (0-23)

    bool selectExtension( Activite_t & activiteATester, ParamsTest parametres);
    // Mode d'emploi :
    // Exclut les fichiers avec certaines extensions (images, CSS, JS)
    // Retourne false si l'extension doit être exclue, true sinon
    // Contrat : Aucun

    bool demanderSurEcriture();
    // Mode d'emploi :
    // Demande à l'utilisateur s'il souhaite écraser un fichier existant
    // Retourne true si l'utilisateur répond 'o' ou 'O', false sinon
    // Contrat : Aucun

    bool stringEstChiffre( string chaine );
    // Mode d'emploi :
    // Vérifie si une chaîne ne contient que des chiffres
    // Retourne true si tous les caractères sont des chiffres, false sinon
    // Contrat : Aucun
//----------------------------------------------------- Attributs protégés

//-------------------------------- Autres définitions dépendantes de <Analog>

#endif // Analog_H

