#include "main.h"

int main(int argc, char **argv)
{	
    int opt;
    int option=0;
	
    extern char * optarg;
    bool erreur=false;
    bool faireGraph=false;
    int heure = 0;
    stringstream ss;
    string nomFichierGraph;
	regex dot(".*\\.dot$");
    while ((opt = getopt(argc,argv,"g:et:")) != EOF)
        switch(opt)
        { 
            case 'g':
                ss<<optarg;
                ss>>nomFichierGraph;
                ss.clear();
		if(!regex_match(nomFichierGraph,dot))
		{
		erreur=true;
		cerr<<"option g : argument is missing or not finishing by .dot"<<endl;
		}else{
                faireGraph=true;
		}
                break;
            case 't':
                ss<<optarg;
                ss>>heure;
                if(ss.eof()==0)
                {
                    cerr<<"option t : hour argument is not valid"<<endl;
                    erreur=true;
                    break;
                }else if(heure<0 || heure>23)
                {
                    cerr<<"option t : the hour should be a number between 0 and 23"<<endl;
                    erreur=true;
                    break;
                }else
                {
                    option+=1;
			ss.clear();
                    break;
                }
            case 'e':
                option+=10;
                break;
            case '?':
                erreur=true;
                break;
            default:
                cout<<"d"<<endl;
        }
    cout<<"option = "<<option<<endl;
    string nom(argv[argc-1]);

    if(!erreur)
    {
		reader *r_pt;
		if(option == 1)
		{
			r_pt = new reader(nom,heure,true);
			if (r_pt->errorFlag)
			{
				cerr << "The file could not be opened" << endl;
			}else{
			top10 t = top10(*r_pt);
			cout << t;
			}
		}else if(option == 10)
		{	
			r_pt = new reader(nom,true,true);
			if (r_pt->errorFlag)
			{
				cerr << "The file could not be opened" << endl;
			}else{
			top10 t = top10(*r_pt);
			cout << t;
			}
		}else if(option == 11)
		{	
			r_pt = new reader(nom,heure,true,true);
			if (r_pt->errorFlag)
			{
				cerr << "The file could not be opened" << endl;
			}else{
			top10 t = top10(*r_pt);
			cout << t;
			}
		}else
		{
			r_pt = new reader(nom,true);
			if (r_pt->errorFlag)
			{
				cerr << "The file could not be opened" << endl;
			}else{
			top10 t = top10(*r_pt);
			cout << t;
			}
		}
		if(faireGraph && !(r_pt->errorFlag))
		{
		graphGen g =graphGen(*r_pt,nomFichierGraph);
		}
	delete r_pt;
    }

    return 0;
}
