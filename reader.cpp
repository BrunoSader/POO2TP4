/*************************************************************************
                           reader  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <reader> (fichier reader.cpp ) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "reader.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies
ostream & operator << (ostream & out, const reader & r)
{
    for(forward_list<logApache>::const_iterator it = r.log.cbegin(); it != r.log.cend(); ++it)
    {
    out<<"ip = "<<it->ip<<endl;
    out<<"userLogName = "<<it->userLogName<<endl;
    out<<"authenticatedUser = "<<it->authenticatedUser<<endl;
    out<<"date.jour = "<<it->date.jour<<endl;
    out<<"date.mois = "<<it->date.mois<<endl;
    out<<"date.annee = "<<it->date.annee<<endl;
    out<<"date.heure = "<<it->date.heure<<endl;
    out<<"date.minute = "<<it->date.minute<<endl;
    out<<"date.seconde = "<<it->date.seconde<<endl;
    out<<"date.decalageGMT = "<<it->date.decalageGMT<<endl;
    out<<"requete = "<<it->requete<<endl;
    out<<"lien = "<<it->lien<<endl;
    out<<"protocole = "<<it->protocole<<endl;
    out<<"status = "<<it->status<<endl;
    out<<"transQT = "<<it->transQT<<endl;
    out<<"lienReferer = "<<it->lienReferer<<endl;
    out<<"navClient = "<<it->navClient<<endl;
    }
    
    return out;
}
//----------------------------------------------------- Méthodes publiques
// type reader::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*reader & reader::operator = ( const reader & unreader )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
reader::reader ( const reader & unreader )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <reader>" << endl;
#endif
} //----- Fin de reader (constructeur de copie)


reader::reader (string fileName)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <reader>" << endl;
#endif
	ifstream myfile;
	myfile.open(fileName.c_str());
	string buffer;
	if(myfile.is_open())
	{
		int i = 0;
		
		do
		{
            logApache logBuffer;
			
			getline(myfile,logBuffer.ip,' ');
			getline(myfile,logBuffer.userLogName,' ');
			getline(myfile,logBuffer.authenticatedUser,' ');
			getline(myfile,buffer,'[');
			getline(myfile,logBuffer.date.jour,'/');
			getline(myfile,logBuffer.date.mois,'/');
			getline(myfile,logBuffer.date.annee,':');
			getline(myfile,logBuffer.date.heure,':');
			getline(myfile,logBuffer.date.minute,':');
			getline(myfile,logBuffer.date.seconde,' ');
			getline(myfile,logBuffer.date.decalageGMT,']');
			getline(myfile,buffer,'"');
			getline(myfile,logBuffer.requete,' ');
			getline(myfile,logBuffer.lien,' ');
			getline(myfile,logBuffer.protocole,'"');
            getline(myfile,buffer,' ');
			getline(myfile,logBuffer.status,' ');
			getline(myfile,logBuffer.transQT,' ');
			getline(myfile,buffer,'"');
			getline(myfile,logBuffer.lienReferer,'"');
			getline(myfile,buffer,'"');
			getline(myfile,logBuffer.navClient,'"');
            if(myfile.eof())
            {
                break;
            }
            log.push_front(logBuffer);
			++i;
		}while(getline(myfile,buffer));
	}
} //----- Fin de reader


reader::~reader ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <reader>" << endl;
#endif
} //----- Fin de ~reader


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
