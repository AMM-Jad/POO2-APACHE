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
// Rôle de la classe <Analog>
//
//
//------------------------------------------------------------------------

//----------------------------------------------------------------- PUBLIC

//public:
//----------------------------------------------------- Méthodes publiques
    int main( int argc, char** argv );
    // Mode d'emploi : 
    // Appelé à l'éxécution du programme
    // Contrat : 
    //

//------------------------------------------------- Surcharge d'opérateurs


//------------------------------------------------------------------ PRIVE

//protected:
//----------------------------------------------------- Méthodes protégées

    int getHeure ( string heure );
    
    bool testOptions( Activite_t aTester,vector < bool (*)(Activite_t & ,ParamsTest) > & filtres, vector < ParamsTest > & refs);

    bool selectHoraire ( Activite_t & aTester , ParamsTest params);

    bool selectExtension( Activite_t & aTester , ParamsTest params);

    bool demanderSurEcriture();

    bool stringEstChiffre( string );
//----------------------------------------------------- Attributs protégés

//-------------------------------- Autres définitions dépendantes de <Analog>

#endif // Analog_H

