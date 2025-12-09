/*************************************************************************
                           LectureLog  -  Extrait les informations 
                           de lignes de logs apache
                             -------------------
    début                : 01/19
    copyright            : (C) 2019 par Gadacha A, Tondereau A
*************************************************************************/

//---------- Réalisation de la classe <LectureLog> (fichier LectureLog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include<vector>
#include <iostream>
#include<fstream>
using namespace std;


//------------------------------------------------------ Include personnel
#include "LectureLog.h"

//------------------------------------------------------------- Constantes
const string REFERER_LOCAL = "http://intranet-if.insa-lyon.fr";

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool LectureLog::Ouvrir( string nomFichier ){
    fichier.open( nomFichier , ios::in );
    if (fichier){
        return true;
    }
    return false;
}

bool LectureLog::LireSuivant(){

    string ligne;
    getline(fichier,ligne);

    if(ligne.size() == 0)
    {
        return false;
    }

    derniereActivite.ipClient = trouveEtPasse(ligne," ");

    derniereActivite.nomUtilisateur = trouveEtPasse(ligne," ");

    derniereActivite.nomUtilisateurAuth = trouveEtPasse(ligne," ");

    derniereActivite.date.jour = stoi(trouveEtPasse(ligne,"/").substr(1));
    string mois = trouveEtPasse(ligne,"/");
    int indiceMois;
    for(indiceMois = 0 ; indiceMois<12 && nomMois[indiceMois]!= mois ; indiceMois++){}// boucle vide : s'arretera quand la correspondance avec le mois aura été trouvée
    derniereActivite.date.mois = indiceMois+1;


    derniereActivite.date.annee = stoi(trouveEtPasse(ligne,":"));
    

    derniereActivite.date.heure = stoi(trouveEtPasse(ligne,":"));

    derniereActivite.date.minute = stoi(trouveEtPasse(ligne,":"));

    derniereActivite.date.seconde = stoi(trouveEtPasse(ligne," "));
    
    //on mémorise le décalage lié à l'heure.

    string decalage = trouveEtPasse(ligne,"]");
    derniereActivite.date.decalagePositif = (decalage[0] == '+');
    derniereActivite.date.heureCreneau = stoi(decalage.substr(1,2));
    derniereActivite.date.minuteCreneau = stoi(decalage.substr(3,2));
    
    trouveEtPasse(ligne,"\"");
    
    derniereActivite.typeAction = trouveEtPasse(ligne," ");
    derniereActivite.titreDoc = trouveEtPasse(ligne," ");
    trouveEtPasse(ligne,"\" ");
    derniereActivite.typeDoc = derniereActivite.titreDoc.substr(derniereActivite.titreDoc.find_last_of(".")+1);
    
    derniereActivite.status = stoi(trouveEtPasse(ligne," "));
    bool estNombre = true;
    string quantite = trouveEtPasse(ligne," \"");
    for(unsigned int i = 0 ; i< quantite.size() && estNombre ; i++)
    {
        estNombre = isdigit(quantite[i]);
    }
    if(estNombre)
    {
        derniereActivite.quantiteTr = stoi(quantite);
    }
    else
    {
        derniereActivite.quantiteTr = -1;        
    }

    string ref = trouveEtPasse(ligne, "\"");
    if(ref.substr(0,REFERER_LOCAL.size()) == REFERER_LOCAL)//enlever la racine si elle est locale
    {
        ref = ref.substr(REFERER_LOCAL.size(),ref.size()-REFERER_LOCAL.size());
    }
    derniereActivite.referer = ref;
    trouveEtPasse(ligne,"\"");
    derniereActivite.clientNav = trouveEtPasse(ligne,"\"");
    return true;
}
Activite_t LectureLog::GetActivite(){
    return derniereActivite;
}

/*------------------------------------------------- Surcharge d'opérateurs
//LectureLog & LectureLog::operator = ( const LectureLog & unLectureLog )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//LectureLog::LectureLog ( const LectureLog & unLectureLog )
// Algorithme :
//
{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <LectureLog>" << endl;
//#endif
} //----- Fin de LectureLog (constructeur de copie)*/


LectureLog::LectureLog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LectureLog>" << endl;
#endif
} //----- Fin de LectureLog


LectureLog::~LectureLog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LectureLog>" << endl;
#endif
} //----- Fin de ~LectureLog


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

string LectureLog::trouveEtPasse(string & ligne, string separ)
{
    int place = ligne.find(separ);
    string debut = ligne.substr(0,place);
    ligne = ligne.substr(place+separ.size());
    return debut;
}