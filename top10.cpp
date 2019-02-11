/*************************************************************************
                           top10  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
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
// type top10::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*top10 & top10::operator = ( const top10 & untop10 )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
top10::top10 ( const top10 & untop10 )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <top10>" << endl;
#endif
} //----- Fin de top10 (constructeur de copie)

top10::top10 (const reader & r, int heure, string extension)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <top10>" << endl;
#endif

	unordered_map<string,int> map;

	if (heure<24 && extension == "null")
	{
		for(forward_list<logApache>::const_iterator it = r.log.cbegin(); it != r.log.cend(); ++it)
		{
			pair<unordered_map<string,int>::iterator,bool> ret;
			ret = map.insert(make_pair(it->lien,1));
			if(stoi(it->date.heure)==heure)
			{
				if(ret.second==false)
				{
					ret.first->second+=1;
				}
			}
		}
		for(unordered_map<string, int >::const_iterator it = map.cbegin(); it != map.cend(); ++it)
		{
			top.insert(make_pair(it->second,it->first));
		}
	}else if(heure==24 && extension=="e")
	{
		for(forward_list<logApache>::const_iterator it = r.log.cbegin(); it != r.log.cend(); ++it)
		{
			pair<unordered_map<string,int>::iterator,bool> ret;
			ret = map.insert(make_pair(it->lien,1));
			if(it->lien.find("html") != string::npos)
			{
				if(ret.second==false)
				{
					ret.first->second+=1;
				}
			}
		}
		for(unordered_map<string, int >::const_iterator it = map.cbegin(); it != map.cend(); ++it)
		{
			top.insert(make_pair(it->second,it->first));
		}
	}else if (heure<24 && extension == "e")
	{
		for(forward_list<logApache>::const_iterator it = r.log.cbegin(); it != r.log.cend(); ++it)
		{
			pair<unordered_map<string,int>::iterator,bool> ret;
			ret = map.insert(make_pair(it->lien,1));
			if(it->lien.find("html") != string::npos && stoi(it->date.heure)==heure)
			{
				if(ret.second==false)
				{
					ret.first->second+=1;
				}
			}
		}
		for(unordered_map<string, int >::const_iterator it = map.cbegin(); it != map.cend(); ++it)
		{
			top.insert(make_pair(it->second,it->first));
		}
	}else
	{
		for(forward_list<logApache>::const_iterator it = r.log.cbegin(); it != r.log.cend(); ++it)
		{
			pair<unordered_map<string,int>::iterator,bool> ret;
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
