/*************************************************************************
					  graphGen  -  description
				 -------------------
	début        : 10/12/2018
	copyright    : (C) 2018 par Bruno SADER, David HAMIDOVIC
	e-mail       : bruno.sader@insa-lyon.fr david.hamidovic@insa-lyon.fr
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
// Algorithme :
// On affiche grace a un iterator, qui parcours la graphMap, le lien,
// le lien de referer et le nb de hits
{
    for(unordered_map<Links<string,string>, int, hash_fn> ::const_iterator it = g.graphMap.cbegin(); it != g.graphMap.cend(); ++it)
    {
        cout<<"lien = "<<it->first.lien<<"  referer = "<<it->first.referer<<" nb hits = "<<it->second<<endl;
    }
   return out;
}

//----------------------------------------------------- M�thodes publiques

//-------------------------------------------- Constructeurs - destructeur

graphGen::graphGen (const reader & r, string nomFichier)
// Algorithme :
// Parcours du reader et verification :
// - De la possibilte ou pas d'inserer dans la graphMap
// la pair cle [lien,lienReferer] si elle n'y est pas deja
// sinon incrementation du nombre d'occurence (le nombre de hits).
// - De la possibilte ou pas d'inserer et numeroter le lien et lienReferer
// en tant que nodes (independants) dans la nodeMap s'ils n'y sont pas deja sinon les nodes sont numerotes
// Creation du fichier .dot grace au nomFichier et l'ecriture grace aux maps.
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
