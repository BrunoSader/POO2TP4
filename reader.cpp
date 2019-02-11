/*************************************************************************
                           reader  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <reader> (fichier reader.cpp ) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "reader.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies
ostream & operator << (ostream & out, const reader & r)
{
    for(forward_list<logApache>::const_iterator it = r.log.cbegin(); it != r.log.cend(); ++it)
    {
    out<<"ip = "<<it->ip<<endl;
    out<<"userLogName = "<<it->userLogName<<endl;
    out<<"authenticatedUser = "<<it->authenticatedUser<<endl;
    out<<"date.jour = "<<it->date.jour<<endl;
    out<<"date.mois = "<<it->date.mois<<endl;
    out<<"date.annee = "<<it->date.annee<<endl;
    out<<"date.heure = "<<it->date.heure<<endl;
    out<<"date.minute = "<<it->date.minute<<endl;
    out<<"date.seconde = "<<it->date.seconde<<endl;
    out<<"date.decalageGMT = "<<it->date.decalageGMT<<endl;
    out<<"requete = "<<it->requete<<endl;
    out<<"lien = "<<it->lien<<endl;
    out<<"protocole = "<<it->protocole<<endl;
    out<<"status = "<<it->status<<endl;
    out<<"transQT = "<<it->transQT<<endl;
    out<<"lienReferer = "<<it->lienReferer<<endl;
    out<<"navClient = "<<it->navClient<<endl;
    }
    return out;
}
//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


reader::reader (string fileName)
// Algorithme :
// Lit le contenu du fichier .log et le decortique afin qu'il soit
// plus facile a l'utilisation.
// Renvoi une erreur si le fichier souhaite ne peut pas etre lu (ouvert)
{
#ifdef MAP
    cout << "Appel au constructeur de <reader>" << endl;
#endif
	ifstream myfile;
	myfile.open(fileName.c_str());
	string buffer;
	if(myfile.is_open())
	{
		int i = 0;
		errorFlag = false;
		do
		{
            logApache logBuffer;
			
			getline(myfile,logBuffer.ip,' ');
            if(myfile.eof())
            {
                break;
            }   
			getline(myfile,logBuffer.userLogName,' ');
			getline(myfile,logBuffer.authenticatedUser,' ');
			getline(myfile,buffer,'[');
			getline(myfile,logBuffer.date.jour,'/');
			getline(myfile,logBuffer.date.mois,'/');
			getline(myfile,logBuffer.date.annee,':');
			getline(myfile,logBuffer.date.heure,':');
			getline(myfile,logBuffer.date.minute,':');
			getline(myfile,logBuffer.date.seconde,' ');
			getline(myfile,logBuffer.date.decalageGMT,']');
			getline(myfile,buffer,'"');
			getline(myfile,logBuffer.requete,' ');
			getline(myfile,logBuffer.lien,' ');
            
			getline(myfile,logBuffer.protocole,'"');
			getline(myfile,buffer,' ');
			getline(myfile,logBuffer.status,' ');
			getline(myfile,logBuffer.transQT,' ');
			getline(myfile,buffer,'"');
			getline(myfile,logBuffer.lienReferer,'"');
           
			getline(myfile,buffer,'"');
			getline(myfile,logBuffer.navClient,'"');
            		log.push_front(logBuffer);
			++i;
		}while(getline(myfile,buffer));
	}
} //----- Fin de reader

reader::reader (string fileName,bool traitement)
// Algorithme :
// Lit le contenu du fichier .log, le traite afin de le rendre plus lisible
// (en supprimant les informations sur les cookies)
// et le decortique afin qu'il soit plus facile a l'utilisation.
// Renvoi une erreur si le fichier souhaite ne peut pas etre lu (ouvert)
{
#ifdef MAP
    cout << "Appel au constructeur de <reader>" << endl;
#endif
	ifstream myfile;
	myfile.open(fileName.c_str());
	string buffer;
	size_t found;
	if(myfile.is_open())
	{
		int i = 0;
		errorFlag = false;
		do
		{
		    	logApache logBuffer;
			getline(myfile,logBuffer.ip,' ');
			if(myfile.eof())
			{
				break;
			}   
			getline(myfile,logBuffer.userLogName,' ');
			getline(myfile,logBuffer.authenticatedUser,' ');
			getline(myfile,buffer,'[');
			getline(myfile,logBuffer.date.jour,'/');
			getline(myfile,logBuffer.date.mois,'/');
			getline(myfile,logBuffer.date.annee,':');
			getline(myfile,logBuffer.date.heure,':');
			getline(myfile,logBuffer.date.minute,':');
			getline(myfile,logBuffer.date.seconde,' ');
			getline(myfile,logBuffer.date.decalageGMT,']');
			getline(myfile,buffer,'"');
			getline(myfile,logBuffer.requete,' ');
			getline(myfile,logBuffer.lien,' ');
			found = logBuffer.lien.find(";jsessionid=");

			if(found!=std::string::npos)
			{
			logBuffer.lien=logBuffer.lien.substr(0,found);
			}
			getline(myfile,logBuffer.protocole,'"');
			getline(myfile,buffer,' ');
			getline(myfile,logBuffer.status,' ');
			getline(myfile,logBuffer.transQT,' ');
			getline(myfile,buffer,'"');
			getline(myfile,logBuffer.lienReferer,'"');		

			
			if(logBuffer.lienReferer.at(0)!= '/')
			{
				buffer=logBuffer.lienReferer;
				found = buffer.find("//");
				if(found!=std::string::npos)
				{
					buffer=buffer.substr(found+2);
				    
				}
				found = buffer.find("/");
				
				if(found!=std::string::npos)
				{
					logBuffer.lienReferer=buffer.substr(found);   
				}
			}

			getline(myfile,buffer,'"');
			getline(myfile,logBuffer.navClient,'"');
	    		log.push_front(logBuffer);
			
			++i;
			errorFlag = false;
		}while(getline(myfile,buffer));
	}
	
} //----- Fin de reader

reader::reader(string fileName, int heure, bool extension,bool traitement)
{
// Algorithme :
// Lit le contenu du fichier .log, le traite afin de le rendre plus lisible
// (en supprimant les informations sur les cookies),supprime les liens qui
// n'ont pas ete visites entre [heure,heure+1] et les fichiers photos, css ou js,
// et le decortique afin qu'il soit plus facile a l'utilisation.
// Renvoi une erreur si le fichier souhaite ne peut pas etre lu (ouvert)
#ifdef MAP
    cout << "Appel au constructeur de <reader>" << endl;
#endif
	ifstream myfile;
	myfile.open(fileName.c_str());
	regex image(".*\\.(jpg|jpeg|ics|bmp|gif|png|svg|ico|css|js)$");
	string buffer;
	bool ajouter=true;
	size_t found;
	if(myfile.is_open())
	{
		int i = 0;
		errorFlag = false;
		do
		{
		    	logApache logBuffer;
			getline(myfile,logBuffer.ip,' ');
			if(myfile.eof())
			{
				break;
			}   
			getline(myfile,logBuffer.userLogName,' ');
			getline(myfile,logBuffer.authenticatedUser,' ');
			getline(myfile,buffer,'[');
			getline(myfile,logBuffer.date.jour,'/');
			getline(myfile,logBuffer.date.mois,'/');
			getline(myfile,logBuffer.date.annee,':');
			getline(myfile,logBuffer.date.heure,':');
			if(stoi(logBuffer.date.heure)!=heure)
			{
				ajouter=false;
			}
			
			getline(myfile,logBuffer.date.minute,':');
			getline(myfile,logBuffer.date.seconde,' ');
			getline(myfile,logBuffer.date.decalageGMT,']');
			getline(myfile,buffer,'"');
			getline(myfile,logBuffer.requete,' ');
			getline(myfile,logBuffer.lien,' ');

			found = logBuffer.lien.find(";jsessionid=");

			if(found!=std::string::npos)
			{
			logBuffer.lien=logBuffer.lien.substr(0,found);
			}
			if(regex_match(logBuffer.lien,image))
			{
				ajouter=false;
			}
			
			getline(myfile,logBuffer.protocole,'"');
			getline(myfile,buffer,' ');
			getline(myfile,logBuffer.status,' ');
			getline(myfile,logBuffer.transQT,' ');
			getline(myfile,buffer,'"');
			getline(myfile,logBuffer.lienReferer,'"');		

			if(logBuffer.lienReferer.at(0)!= '/')
			{
				buffer=logBuffer.lienReferer;
				found = buffer.find("//");
				if(found!=std::string::npos)
				{
					buffer=buffer.substr(found+2);
				    
				}
				found = buffer.find("/");
				
				if(found!=std::string::npos)
				{
					logBuffer.lienReferer=buffer.substr(found);   
				}
			}

			getline(myfile,buffer,'"');
			getline(myfile,logBuffer.navClient,'"');
			if(ajouter)
			{
	    		log.push_front(logBuffer);
			}
			++i;
			ajouter=true;
		}while(getline(myfile,buffer));
	}
}

reader::reader(string fileName, int heure,bool traitement)
{
// Algorithme :
// Lit le contenu du fichier .log, le traite afin de le rendre plus lisible
// (en supprimant les informations sur les cookies),supprime les liens qui
// n'ont pas ete visites entre [heure,heure+1]
// et le decortique afin qu'il soit plus facile a l'utilisation.
// Renvoi une erreur si le fichier souhaite ne peut pas etre lu (ouvert)
#ifdef MAP
    cout << "Appel au constructeur de <reader>" << endl;
#endif
	ifstream myfile;
	myfile.open(fileName.c_str());
	string buffer;
	bool ajouter=true;
	size_t found;
	if(myfile.is_open())
	{
		int i = 0;
		errorFlag = false;
		do
		{
		    	logApache logBuffer;
			getline(myfile,logBuffer.ip,' ');
			if(myfile.eof())
			{
				break;
			}   
			getline(myfile,logBuffer.userLogName,' ');
			getline(myfile,logBuffer.authenticatedUser,' ');
			getline(myfile,buffer,'[');
			getline(myfile,logBuffer.date.jour,'/');
			getline(myfile,logBuffer.date.mois,'/');
			getline(myfile,logBuffer.date.annee,':');
			getline(myfile,logBuffer.date.heure,':');
			if(stoi(logBuffer.date.heure)!=heure)
			{
				ajouter=false;
			}
			getline(myfile,logBuffer.date.minute,':');
			getline(myfile,logBuffer.date.seconde,' ');
			getline(myfile,logBuffer.date.decalageGMT,']');
			getline(myfile,buffer,'"');
			getline(myfile,logBuffer.requete,' ');
			getline(myfile,logBuffer.lien,' ');
			found = logBuffer.lien.find(";jsessionid=");
			if(found!=std::string::npos)
			{
			logBuffer.lien=logBuffer.lien.substr(0,found);
			}
			getline(myfile,logBuffer.protocole,'"');
			getline(myfile,buffer,' ');
			getline(myfile,logBuffer.status,' ');
			getline(myfile,logBuffer.transQT,' ');
			getline(myfile,buffer,'"');
			getline(myfile,logBuffer.lienReferer,'"');		

			
			if(logBuffer.lienReferer.at(0)!= '/')
			{
				buffer=logBuffer.lienReferer;
				found = buffer.find("//");
				if(found!=std::string::npos)
				{
					buffer=buffer.substr(found+2);
				    
				}
				found = buffer.find("/");
				
				if(found!=std::string::npos)
				{
					logBuffer.lienReferer=buffer.substr(found);   
				}
			}

			getline(myfile,buffer,'"');
			getline(myfile,logBuffer.navClient,'"');
			if(ajouter)
			{
	    		log.push_front(logBuffer);
			}
			++i;
			ajouter=true;
		}while(getline(myfile,buffer));
	}
}

reader::reader(string fileName,bool extension,bool traitement)
{
// Algorithme :
// Lit le contenu du fichier .log, le traite afin de le rendre plus lisible
// (en supprimant les informations sur les cookies),supprime les fichiers photos, css ou js,
// et le decortique afin qu'il soit plus facile a l'utilisation.
// Renvoi une erreur si le fichier souhaite ne peut pas etre lu (ouvert)
#ifdef MAP
    cout << "Appel au constructeur de <reader>" << endl;
#endif
	ifstream myfile;
	myfile.open(fileName.c_str());
	regex image(".*\\.(jpg|jpeg|ics|bmp|gif|png|svg|ico|css|js)$");
	string buffer;
	bool ajouter=true;
	size_t found;
	if(myfile.is_open())
	{
		int i = 0;
		errorFlag = false;
		do
		{
		    	logApache logBuffer;
			getline(myfile,logBuffer.ip,' ');
			if(myfile.eof())
			{
				break;
			}   
			getline(myfile,logBuffer.userLogName,' ');
			getline(myfile,logBuffer.authenticatedUser,' ');
			getline(myfile,buffer,'[');
			getline(myfile,logBuffer.date.jour,'/');
			getline(myfile,logBuffer.date.mois,'/');
			getline(myfile,logBuffer.date.annee,':');
			getline(myfile,logBuffer.date.heure,':');
			getline(myfile,logBuffer.date.minute,':');
			getline(myfile,logBuffer.date.seconde,' ');
			getline(myfile,logBuffer.date.decalageGMT,']');
			getline(myfile,buffer,'"');
			getline(myfile,logBuffer.requete,' ');
			getline(myfile,logBuffer.lien,' ');
			if(regex_match(logBuffer.lien,image))
			{
				ajouter=false;
			}
			found = logBuffer.lien.find(";jsessionid=");
			if(found!=std::string::npos)
			{
			logBuffer.lien=logBuffer.lien.substr(0,found);
			}
			getline(myfile,logBuffer.protocole,'"');
			getline(myfile,buffer,' ');
			getline(myfile,logBuffer.status,' ');
			getline(myfile,logBuffer.transQT,' ');
			getline(myfile,buffer,'"');
			getline(myfile,logBuffer.lienReferer,'"');	
			
			if(logBuffer.lienReferer.at(0)!= '/')
			{
				buffer=logBuffer.lienReferer;
				found = buffer.find("//");
				if(found!=std::string::npos)
				{
					buffer=buffer.substr(found+2);
				    
				}
				found = buffer.find("/");
				
				if(found!=std::string::npos)
				{
					logBuffer.lienReferer=buffer.substr(found);   
				}
			}

			getline(myfile,buffer,'"');
			getline(myfile,logBuffer.navClient,'"');
			if(ajouter==true)
			{
	    		log.push_front(logBuffer);
			}
			++i;
			ajouter=true;
		}while(getline(myfile,buffer));
	}
}
reader::~reader ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <reader>" << endl;
#endif
} //----- Fin de ~reader


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
