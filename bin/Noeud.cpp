/*************************************************************************
                           Noeud  -  Encapsule les attributs et les actions sur un noeud de graphe orienté ou non
                             -------------------
    début                : 01/19
    copyright            : (C) 2019 par Gadacha A, Tondereau A
*************************************************************************/

//---------- Réalisation de la classe <Noeud> (fichier Noeud.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Noeud.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Noeud::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Noeud::AjouterLien( string source , bool details)
{
    if(details)
    {
        if( liens.count(source) != 0 )
        {
            liens[source]++;
        }
        else
        {
            liens.emplace( source , 1 );
        }
    }

	nombreLiens++;
}

unsigned int Noeud::GetNombreLiens() const
{
	return nombreLiens;
}

const map < string, int > & Noeud::GetStructure() const
{
    return liens;
}

const string Noeud::GetLabel() const
{
    return label;
}

unsigned int Noeud::GetNumNoeud() const
{
    return numNoeud;
}


int Noeud::GetAccesDepuisSource( string source ) const
{
    if( liens.count( source ) != 0 )
    {
        return liens.at(source);
    }
    return -1;
}

//------------------------------------------------- Surcharge d'opérateurs
/*Noeud & Noeud::operator = ( const Noeud & unNoeud )
// Algorithme :
//
{
} //----- Fin de operator =*/
//*/

bool Noeud::operator > ( const Noeud & aComparer ) const 
{
    if( aComparer.GetNombreLiens() != nombreLiens )
    {
        return nombreLiens> aComparer.GetNombreLiens();
    }
    else
    {
        return label > aComparer.GetLabel();
    }
}

//-------------------------------------------- Constructeurs - destructeur
/*Noeud::Noeud ( const Noeud & unNoeud )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Noeud>" << endl;
#endif
} //----- Fin de Noeud (constructeur de copie)
*/

Noeud::Noeud ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur par defaut de <Noeud>" << endl;
#endif
    nombreLiens = 0;
    numNoeud = nombreNoeuds;
    nombreNoeuds++;
    label = "DEFAULT";
    liens = map < string, int>();
} //----- Fin de Noeud

Noeud::Noeud ( string labelNoeud )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Noeud>" << endl;
#endif
    nombreLiens = 0;
    numNoeud = Noeud::nombreNoeuds;
    Noeud::nombreNoeuds++;
    label = labelNoeud;
} //----- Fin de Noeud


Noeud::~Noeud ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Noeud>" << endl;
#endif
} //----- Fin de ~Noeud


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

unsigned int Noeud::nombreNoeuds = 0;