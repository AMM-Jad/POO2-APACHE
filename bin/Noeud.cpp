/*************************************************************************
                           Noeud  -  Encapsule les attributs et les actions sur un noeud de graphe orienté ou non
                             -------------------
    début                : 03/12
    copyright            : (C) 2025 par Ammydriss Jad, Essaki Mohammed, EL HABI Aymane
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

void Noeud::AjouterLien( string sourceReferer, bool avecDetails)
// Algorithme :
// Incrémente le compteur total d'accès
// Si avecDetails est true, ajoute ou incrémente le lien dans la map 'liens'
{
    if(avecDetails)
    {
        if( liens.count(sourceReferer) != 0 )
        {
            liens[sourceReferer]++;
        }
        else
        {
            liens.emplace( sourceReferer, 1 );
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


int Noeud::GetAccesDepuisSource( string labelSource ) const
// Algorithme :
// Vérifie si la source existe dans la map des liens
// Retourne le poids du lien si trouvé, -1 sinon
{
    if( liens.count( labelSource ) != 0 )
    {
        return liens.at(labelSource);
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

bool Noeud::operator > ( const Noeud & noeudAComparer ) const
// Algorithme :
// Compare d'abord par nombre d'accès (ordre décroissant)
// En cas d'égalité, compare par label (ordre lexicographique)
{
    if( noeudAComparer.GetNombreLiens() != nombreLiens )
    {
        return nombreLiens> noeudAComparer.GetNombreLiens();
    }
    else
    {
        return label > noeudAComparer.GetLabel();
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