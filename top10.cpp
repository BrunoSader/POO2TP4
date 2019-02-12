/*************************************************************************
					  top10  -  description
				 -------------------
	début        : 10/12/2018
	copyright    : (C) 2018 par Bruno SADER, David HAMIDOVIC
	e-mail       : bruno.sader@insa-lyon.fr david.hamidovic@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <top10> (fichier top.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "top10.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies
ostream & operator << (ostream & out, const top10 & t)
// Algorithme :
// On affiche grace a un iterator, qui parcours une multimap toutes
// les donnees contenues dans le top10 (entre en parametre)
{
    int j =0;
    cout<<"top 10 of the most visited links: "<<endl;
    for(multimap<int, string >::const_reverse_iterator it = t.top.crbegin(); it != t.top.crend() && j<10; ++it)
        {
            cout<<"\turl = "<<it->second<<" | number of hits = "<<it->first<<endl;
            j++;
        }
    return out;
}
//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

top10::top10 (const reader & r)
// Algorithme :
// Creation d'une unordered_map, map, afin de stocker les liens distincts du reader
// et d'incrementer leur nombre de hits. Si un lien existe deja dans map, on incremente
// le nombre de hits sinon on insert le lien. Afin de distinguer les deux cas
// on utilise une variable ret qui est la valeur de retour de la fonction insert
// de map. Finalement les elements constituant map sont inseres dans top avec le nombre
// de hits comme cle et le lien comme valeur afin de les trier.
{
#ifdef MAP
	cout << "Appel au constructeur de <top10>" << endl;
#endif
	unordered_map<string,int> map;
	pair<unordered_map<string,int>::iterator,bool> ret;
	for(forward_list<logApache>::const_iterator it = r.log.cbegin(); it != r.log.cend(); ++it)
	{
		ret = map.insert(make_pair(it->lien,1));
		if(ret.second==false)
		{
			ret.first->second+=1;
		}
	}
	for(unordered_map<string, int >::const_iterator it = map.cbegin(); it != map.cend(); ++it)
	{
		top.insert(make_pair(it->second,it->first));
	}
} //----- Fin de top10


top10::~top10 ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <top10>" << endl;
#endif
} //----- Fin de ~top10


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
