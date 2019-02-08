/*************************************************************************
                           reader  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <reader> (fichier ${file_name}) ------
#if ! defined ( reader_H )
#define reader_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <fstream>
#include <string>
#include<forward_list>  
using namespace std;
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
typedef struct 
{
string jour;
string mois;
string annee;
string heure;
string minute;
string seconde;
string decalageGMT;
}uneDate;

typedef struct 
{
string ip;
string userLogName;
string authenticatedUser;
uneDate date;
string requete;
string lien;
string protocole;
string status;
string transQT;
string lienReferer;
string navClient; 
}logApache;
//------------------------------------------------------------------------ 
// Rôle de la classe <reader>
//
//
//------------------------------------------------------------------------ 

class reader 
{
//----------------------------------------------------------------- PUBLIC

public:
    friend ostream & operator << (ostream & out, const reader & r);
    friend class top10;
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    


//------------------------------------------------- Surcharge d'opérateurs
    reader & operator = ( const reader & unreader );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    reader ( const reader & unreader );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    reader (string fileName);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~reader ( );
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
forward_list<logApache> log; 
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <reader>

#endif // reader_H
