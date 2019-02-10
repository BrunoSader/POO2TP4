/*************************************************************************
                           graphGen  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <graphGen> (fichier graphGen.cpp) ------
#if ! defined ( GRAPHGEN_H )
#define GRAPHGEN_H

//--------------------------------------------------- Interfaces utilis�es
#include <iostream>
#include <unordered_map>
#include "reader.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <graphGen>
//
//
//------------------------------------------------------------------------
#include <iostream>
#include <unordered_map>

template<typename T1, typename T2>
struct Links
{
	T1 lien;
	T2 referer;

	// constructor
	Links(T1 lien, T2 referer)
	{
		this->lien = lien;
		this->referer = referer;
	}

	// operator== is required to compare keys in case of hash collision
	bool operator==(const Links &link) const
	{
		return lien == link.lien && referer == link.referer;
	}
};

// specialized hash function for unordered_map keys
struct hash_fn
{
	template <class T1, class T2>
	std::size_t operator() (const Links<T1, T2> &link) const
	{
		std::size_t h1 = std::hash<T1>()(link.lien);
		std::size_t h2 = std::hash<T2>()(link.referer);

		return (h1 + h2);
	}
};

class graphGen
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste de param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'op�rateurs
    graphGen & operator = ( const graphGen & ungraphGen );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    graphGen ( const graphGen & ungraphGen );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    graphGen (const reader & readFile);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~graphGen ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s
unordered_map<Links<string,string>, int, hash_fn> graphMap;
private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <graphGen>

#endif // GRAPHGEN_H
