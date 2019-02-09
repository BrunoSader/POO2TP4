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


//------------------------------------------------- Surcharge d'op�rateurs
graphGen & graphGen::operator = ( const graphGen & ungraphGen )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
graphGen::graphGen ( const graphGen & ungraphGen )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <graphGen>" << endl;
#endif
} //----- Fin de graphGen (constructeur de copie)


graphGen::graphGen (const reader & readFile)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <graphGen>" << endl;
#endif

for(forward_list<logApache>::const_iterator it = r.log.begin(); it != r.log.end(); ++it)
{
	pair<unordered_map<string[2],int>::iterator,bool> ret;
	ret = map.insert(make_pair(it->lien,1));
	if(stoi(it->date.heure)>=heure && stoi(it->date.heure)<(heure+1) )
	{
		if(ret.second==false)
		{
			ret.first->second+=1;
		}
	}
}
for(unordered_map<string, int >::const_iterator it = map.begin(); it != map.end(); ++it)
{
	top.insert(make_pair(it->second,it->first));
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
