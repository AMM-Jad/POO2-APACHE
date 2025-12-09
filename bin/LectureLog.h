/*************************************************************************
                           LectureLog  -  Extrait les informations 
                           de lignes de logs apache
                             -------------------
    début                : 03/12
    copyright            : (C) 2025 par Ammydriss Jad, Essaki Mohammed, EL HABI Aymane
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
// Lecture et analyse des fichiers de logs Apache
// Extrait les informations de chaque ligne et les structure dans Activité_t
//------------------------------------------------------------------------

class LectureLog 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Ouvrir ( string nomFichier );
    // Mode d'emploi :
    // Ouvre le fichier de log spécifié en lecture
    // Retourne true si l'ouverture réussit, false sinon
    // Contrat : Le nom de fichier doit être valide
    bool LireSuivant();
    // Mode d'emploi :
    // Lit la prochaine ligne du fichier de log et parse ses informations
    // Les données extraites sont stockées dans l'attribut 'derniereActivite'
    // Retourne true si une ligne a été lue avec succès, false si fin de fichier
    // Contrat : Le fichier doit être ouvert avec succès au préalable
    Activite_t GetActivite();
    // Mode d'emploi :
    // Retourne la dernière activité lue depuis le fichier de log
    // Contrat : LireSuivant() doit avoir été appelé au moins une fois
    
    //------------------------------------------------- Surcharge d'opérateurs
    LectureLog & operator = ( const LectureLog & autreLectureLog );
    // Mode d'emploi :
    // Opérateur d'affectation, copie les données d'un objet LectureLog vers un autre
    // Contrat : Aucun


//-------------------------------------------- Constructeurs - destructeur
    LectureLog ( const LectureLog & autreLectureLog );
    // Mode d'emploi (constructeur de copie) :
    // Crée une copie de l'objet LectureLog passé en paramètre
    // Contrat : Aucun

    LectureLog ( );
    // Mode d'emploi :
    // Constructeur par défaut, initialise un objet LectureLog
    // Contrat : Aucun
    

    virtual ~LectureLog ( );
    // Mode d'emploi :
    // Destructeur, libère les ressources et ferme le fichier s'il est ouvert
    // Contrat : Aucun

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

