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

// Rôle du module <main>
// Représente seulement la classe permettant d'appeler l'interface 
// créée dans la classe Interface afin d'afficher un visuel pour l'utilisateur 

//--------------------------------------------------- Interfaces utilisées  
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "reader.h"
#include "top10.h"
#include <getopt.h>

class Main
{
	int main();

};
#endif // Main_H


