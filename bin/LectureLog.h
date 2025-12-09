/*************************************************************************
                           LectureLog  -  Extrait les informations 
                           de lignes de logs apache
                             -------------------
    début                : 01/19
    copyright            : (C) 2019 par Gadacha A, Tondereau A
*************************************************************************/

//---------- Interface de la classe <LectureLog> (fichier LectureLog.h) ----------------
#if ! defined ( LECTURELOG_H )
#define LECTURELOG_H

//--------------------------------------------------- Interfaces utilisées
#include<string.h>
#include<fstream>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

typedef struct{
    unsigned int seconde;
    unsigned int minute;
    unsigned int heure;
    unsigned int jour;
    unsigned int mois;
    unsigned int annee;

    bool decalagePositif;
    unsigned int heureCreneau;
    unsigned int minuteCreneau;
} Date;

typedef struct{
    string ipClient;
    string nomUtilisateurAuth;
    string nomUtilisateur;
    string typeAction;
    string titreDoc;
    string typeDoc;
    string referer;
    string clientNav;
    Date date;
    int status, quantiteTr;
} Activite_t;

//------------------------------------------------------------------------
// Rôle de la classe <LectureLog>
//
//
//------------------------------------------------------------------------

class LectureLog 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Ouvrir ( string nomFichier );
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //Ouvre un fichier.log sur un flux
    // Contrat :
    //
    bool LireSuivant();
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //Lis la prochaine activite et la range dans l'attribut derniereActivite
    // Contrat :
    //
    Activite_t GetActivite();
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //Permet d'acceder a la deriere activite 
    // Contrat :
    
    //------------------------------------------------- Surcharge d'opérateurs
    LectureLog & operator = ( const LectureLog & unLectureLog );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    LectureLog ( const LectureLog & unLectureLog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    LectureLog ( );
    // Mode d'emploi :
    //Constructeur de LectureLog qui initialise derniereActivite
    // Contrat :
    //
    

    virtual ~LectureLog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    string trouveEtPasse(string & ligne, string separ);
    // Algorithme : 
    // Renvoie la sous chaine jusqu'à la séquence separ, non comprise
    // transforme la chaine ligne en la sous chaine après la séquence separ, non comprise
    
//----------------------------------------------------- Attributs protégés

    Activite_t derniereActivite;
    
    ifstream fichier;
    
    const string nomMois[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    
};

//-------------------------------- Autres définitions dépendantes de <LectureLog>

#endif // LECTURELOG_H

