/*************************************************************************
                           top10  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <top10> (fichier ${file_name}) ------
#if ! defined ( top10_H )
#define top10_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <unordered_map>
#include <map>
#include "reader.h"
using namespace std;
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <top10>
//
//
//------------------------------------------------------------------------ 

class top10 
{
//----------------------------------------------------------------- PUBLIC

public:
    friend ostream & operator << (ostream & out, const top10 & t);
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    top10 & operator = ( const top10 & untop10 );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    top10 ( const top10 & untop10 );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
	
	top10 (const reader & r, int heure = 24, string extension = "null");
	// Mode d'emploi :
	//
	// Contrat :
	//

    virtual ~top10 ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
multimap<int,string> top;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <top10>

#endif // top10_H
