/*************************************************************************
					  reader  -  description
				 -------------------
	début        : 10/12/2018
	copyright    : (C) 2018 par Bruno SADER, David HAMIDOVIC
	e-mail       : bruno.sader@insa-lyon.fr david.hamidovic@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <reader> (fichier ${file_name}) ------
#if ! defined ( reader_H )
#define reader_H
//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <fstream>
#include <string>
#include <forward_list>
#include <regex>
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
// La classe reader est une classe qui a pour objectif de decortiquer un
// fichier .log afin qu'il soit plus utilisable dans un code c++.
// Elle a plusieurs constructeurs dont un de base qui ne traite aucune
// information afin qu'il puisse etre reutilisé dans d'autres cas de figure.
// Elle contient une liste chaine qui stock le contenu du fichier.
//------------------------------------------------------------------------

class reader
{
//----------------------------------------------------------------- PUBLIC

public:
	bool errorFlag = true;
	friend class top10;
	friend class graphGen;
//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs
	friend ostream & operator << (ostream & out, const reader & r);

//-------------------------------------------- Constructeurs - destructeur
  reader (string fileName);
  // Mode d'emploi :
  // Lecture du fichier .log et ecriture dans la list<string> log.
  // Contrat : /

	reader (string fileName,bool traitement);
	// Mode d'emploi :
  // Lecture du fichier .log , traitement du fichier
	// et ecriture dans la list<string> log.
  // Contrat : /

	reader(string nameFile, int heure, bool extension,bool traitement);
	// Mode d'emploi :
  // Lecture du fichier .log , traitement du fichier
  // et ecriture des informations contenues entre
	// [heure,heure + 1] et n'etant pas des photos, des codes css
	// ou des codes js, dans la list<string> log.
  // Contrat : /

	reader(string fileName, int heure,bool traitement);
	// Mode d'emploi :
  // Lecture du fichier .log , traitement du fichier
  // et ecriture des informations contenues entre
	// [heure,heure + 1] dans la list<string> log.
  // Contrat : /

	reader(string fileName,bool extension,bool traitement);
	// Mode d'emploi :
	// Lecture du fichier .log , traitement du fichier
	// et ecriture des informations n'etant pas des photos, des codes css
	// ou des codes js, dans la list<string> log.
	// Contrat : /

  virtual ~reader ( );
  // Mode d'emploi :
  //
  // Contrat :

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
