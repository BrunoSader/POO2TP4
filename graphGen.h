/*************************************************************************
					  graphGen  -  description
				 -------------------
	début        : 10/12/2018
	copyright    : (C) 2018 par Bruno SADER, David HAMIDOVIC
	e-mail       : bruno.sader@insa-lyon.fr david.hamidovic@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <graphGen> (fichier graphGen.cpp) ------
#if ! defined ( GRAPHGEN_H )
#define GRAPHGEN_H

//--------------------------------------------------- Interfaces utilis�es
#include <iostream>
#include <unordered_map>
#include "reader.h"
#include <iostream>
#include <unordered_map>
using namespace std;

//------------------------------------------------------------------------
// R�le de la classe <graphGen>
// La classe graphGen permet de creer un fichier .dot afin de le generer
// sous graphe grace a GraphViz. Elle contient deux unordered map, graphMap
// qui gere le nombre de hits fait entre un lien et son referer grace a une
// cle Links (une structure qui contient chaqu'un des liens) et nodeMap
// qui gere la creation des nodes (la numerotation et leurs relations).
//------------------------------------------------------------------------

template<typename T1, typename T2>
struct Links
// R�le de la structure <Links>
// Structure Links afin de creer une fonction de hashage qui travaille sur
// une cle compose de 2 strings.
{
	T1 lien;
	T2 referer;

	Links(T1 lien, T2 referer)
	{
		this->lien = lien;
		this->referer = referer;
	}

	// operator== est requis pour comparer des cles en cas de collision
	bool operator==(const Links &link) const
	{
		return lien == link.lien && referer == link.referer;
	}
};

struct hash_fn
// Algorithme :
// Fonction de hashage utilise pour la graphMap qui considere la structure
// Links comme cle. Appel a la fonction de hashage de base (afin d'avoir
// le moins de collision) pour le lien et le referer et somme les deux
{
	template <class T1, class T2>
	size_t operator() (const Links<T1, T2> &link) const
	{
		size_t h1 = hash<T1>()(link.lien);
		size_t h2 = hash<T2>()(link.referer);
		return (h1 + h2);
	}
};

class graphGen
{
//----------------------------------------------------------------- PUBLIC

public:

//----------------------------------------------------- M�thodes publiques


//------------------------------------------------- Surcharge d'op�rateurs

	friend ostream & operator << (ostream & out, const graphGen & g);
	// Mode d'emploi :
	// Prend en parametre un flux de sortie et un graphGen
	// afin de sortir sur le flux les composants du graphGen.
	// Contrat : /

//-------------------------------------------- Constructeurs - destructeur

  graphGen (const reader & readFile, string nomFichier);
	// Mode d'emploi :
	// Creation de la graphMap et de la nodeMap afin de creer le fichier .dot
	// Contrat : /

  virtual ~graphGen ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s
	unordered_map<Links<string,string>, int, hash_fn> graphMap;
	unordered_map<string,int> nodeMap;
private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <graphGen>

#endif // GRAPHGEN_H
