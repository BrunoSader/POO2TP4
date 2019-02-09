/*************************************************************************
                           graphGen  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <graphGen> (fichier graphGen.cpp) ------
#if ! defined ( GRAPHGEN_H )
#define GRAPHGEN_H

//--------------------------------------------------- Interfaces utilis�es
#include <iostream>
#include <unordered_map>
#include <map>
#include "reader.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <graphGen>
//
//
//------------------------------------------------------------------------

class graphGen
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste de param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'op�rateurs
    graphGen & operator = ( const graphGen & ungraphGen );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    graphGen ( const graphGen & ungraphGen );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    graphGen (const reader & readFile);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~graphGen ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s

private:
//------------------------------------------------------- Attributs priv�s
unordered_map<string,int> graphMap;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <graphGen>

#endif // GRAPHGEN_H
