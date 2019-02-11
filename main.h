/*************************************************************************
					  Main  -  description
				 -------------------
	début        : 10/12/2018
	copyright    : (C) 2018 par Bruno SADER, David HAMIDOVIC
	e-mail       : bruno.sader@insa-lyon.fr david.hamidovic@insa-lyon.fr
*************************************************************************/

//---------- Interface du module <Test> (fichier Main.h) ----------------
#if ! defined ( main_H )
#define main_H

//---------------------------------------------------------- 
// Rôle du module <main>
// Lecture de la ligne de commande afin de voir
// quelles options ont ete choisies par l'utilisateur
// et d'en prendre compte lors de l'execution du programme.
// Gere aussi les erreurs duent a la mauvaise semantique
// des options lors de l'appel a l'execution.
//----------------------------------------------------------

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include "reader.h"
#include "top10.h"
#include "graphGen.h"
#include <getopt.h>

class Main
{
	int main();

};
#endif // Main_H
