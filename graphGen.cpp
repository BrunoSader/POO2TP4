/*************************************************************************
                           graphGen  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <graphGen> (fichier graphGen.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "graphGen.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type graphGen::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

//-------------------------------------------- Constructeurs - destructeur
graphGen::graphGen ( const graphGen & ungraphGen )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <graphGen>" << endl;
#endif
} //----- Fin de graphGen (constructeur de copie)


graphGen::graphGen (const reader & r)
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de <graphGen>" << endl;
#endif
	for(forward_list<logApache>::const_iterator it = r.log.begin(); it != r.log.end(); ++it)
	{
		pair<unordered_map<Links<string,string>, int, hash_fn> ::iterator,bool> ret;
		ret = graphMap.insert(make_pair(Links<string,string>(it->lien,it->lienReferer),1));
		if(ret.second==false)
		{
			ret.first->second+=1;
		}
	}
} //----- Fin de graphGen


graphGen::~graphGen ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <graphGen>" << endl;
#endif
} //----- Fin de ~graphGen


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
