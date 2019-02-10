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
ostream & operator << (ostream & out, const graphGen & g)
{
    for(unordered_map<Links<string,string>, int, hash_fn> ::const_iterator it = g.graphMap.cbegin(); it != g.graphMap.cend(); ++it)
    {
        cout<<"lien = "<<it->first.lien<<"  referer = "<<it->first.referer<<" nb hits = "<<it->second<<endl;
    }
   return out;
}

ofstream & operator << (ofstream & fichier, unordered_map<Links<string,string>, int, hash_fn> ::const_iterator it)
{
    return fichier;   
}
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


graphGen::graphGen (const reader & r, string nomFichier)
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de <graphGen>" << endl;
#endif
    int i=0;
    
	for(forward_list<logApache>::const_iterator it = r.log.begin(); it != r.log.end(); ++it)
	{
		pair<unordered_map<Links<string,string>, int, hash_fn> ::iterator,bool> ret;
		ret = graphMap.insert(make_pair(Links<string,string>(it->lien,it->lienReferer),1));
		if(ret.second==false)
		{
			ret.first->second+=1;
		}
		
		pair<unordered_map<string,int>::iterator,bool> ret2;
        ret2 = nodeMap.insert(make_pair(it->lien,i));
        if(ret2.second==true)
        {
            i++;
        }
        ret2 = nodeMap.insert(make_pair(it->lienReferer,i));
        if(ret2.second==true)
        {
            i++;
        }
	}
	
	
	ofstream fichierDot;
	fichierDot.open(nomFichier);
    fichierDot<<"digraph {"<<endl;
    
    for(unordered_map<string, int >::const_iterator it = nodeMap.cbegin(); it != nodeMap.cend(); ++it)
    {
        fichierDot<<"node"<<it->second<<" [label=\""<<it->first<<"\"];"<<endl;
    }

    for(unordered_map<Links<string,string>, int, hash_fn> ::const_iterator it = graphMap.cbegin(); it != graphMap.cend(); ++it)
    {
        fichierDot<<"node"<<nodeMap.at(it->first.referer)<<" -> node"<<nodeMap.at(it->first.lien)<<" [label=\""<<it->second<<"\"];"<<endl;
    }
    fichierDot<<"}";
    fichierDot.close();
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
