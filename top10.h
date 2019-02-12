/*************************************************************************
                           top10  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <top10> (fichier top10.h) --------
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
// La classe top10 permet de generer sur la sortie standard un classement des
// 10 liens les plus visites. Elle contient une multimap, top, qui tri
// les liens par nombre de hits.
//------------------------------------------------------------------------

class top10
{
//----------------------------------------------------------------- PUBLIC

public:

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs
  friend ostream & operator << (ostream & out, const top10 & t);

//-------------------------------------------- Constructeurs - destructeur
	top10 (const reader & r);
	// Mode d'emploi :
	// Creation de la multimap top et tri des elements qu'elle contient
	// Contrat : /

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
