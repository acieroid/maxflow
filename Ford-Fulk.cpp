#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

const int N=6; // Nombre de noeds
const int M=8; // Nombre de liens
const int inf=100; // considerer comme plus grand que toutes les capacites
int L[N][4];

void afficher(int *tabLien, int l, int h)
{
    for(int i=0;i<l;++i)
    {
        cout << tabLien[h*i+0] << " " << tabLien[h*i+1] << "   " << tabLien[h*i+2]  << " " << tabLien[h*i+3]  << endl;
    }
}

void setL(int n, int i, int alphaj, int in, int dir)
{
   L[n][0]=i;
   L[n][1]=alphaj;
   L[n][2]=in;
   L[n][3]=dir;
}

bool Lisempty()
{
   for(int i=0;i<N;++i)
   {
	if(L[i][2]==1)
	{ return false;}
   }
   return true;
}

// selection de i dans L et le retirer
int Lnext()
{
   for(int i=0;i<N;++i)
   {
	if(L[i][2]==1)
	{
	   L[i][2]=0;
	   return i;
	}
   }
}

// selection du min
int min (int a, int b)
{
   if(a<b)
   { return a;}
   else
   { return b;}
}

// Main fonction

int main(int argc, char*argv[])
{
   int s=0;
   int t=N-1;
   int Ni, Nj, Ncurr, Nprec;
   int r, alphaT;

   int tabLien[M][4]={
	0,1,3,0,
	0,3,8,0,
	1,2,4,0,
	1,4,2,0,
	3,2,6,0,
	3,4,3,0,
	2,5,4,0,
	4,5,9,0};

   while(1)
   {
        // initialisation de L
        for(int i=0;i<N;++i)
        {
            setL(i,0,0,0,0);
        }
        // recherche du chemin augmentant
        // Marqué s par [0,inf]
        setL(0,0,inf,1,1);

        // boucle tant que l non vide et t non marqué
        while(L[t][3]==0 && !Lisempty())
        {
            // selection de i dans L et le retirer
            Ni=Lnext();

            // marquer les j
            for(int i=0;i<M;++i)
            {
                r=tabLien[i][2]-tabLien[i][3];
                Nj=tabLien[i][1];

                if(tabLien[i][0]==Ni && r>0 && L[Nj][3]==0)
                {
                    setL(Nj,Ni,min(L[Ni][1],r),1,1);
                }

                Nj=tabLien[i][0];

                if(tabLien[i][1]==Ni && tabLien[i][3]>0 && L[Nj][3]==0)
                {
                    setL(Nj,Ni,tabLien[i][3],1,2);
                }
            }

            cout << "place fin boucle chemin"<< endl;
            afficher(&(tabLien[0][0]), M, 4);
            cout << endl;
            afficher(&(L[0][0]), N, 4);
            // getchar();

        }

        // phase d'augmentation
        if(L[t][3]==1)
        {
            Ncurr=t;
            alphaT=L[t][1];

            while(Ncurr!=0)
            {
                Nprec=L[Ncurr][0];
                if(L[Ncurr][3]==1)
                {
                    for(int i=0;i<M;++i)
                    {
                        if(tabLien[i][0]==Nprec && tabLien[i][1]==Ncurr)
                        {
                            tabLien[i][3]=tabLien[i][3]+alphaT;
                            break;
                        }
                    }
                }
                else if(L[Ncurr][3]==2)
                {
                    for(int i=0;i<M;++i)
                    {
                        if(tabLien[i][0]==Ncurr && tabLien[i][1]==Nprec)
                        {
                            tabLien[i][3]=tabLien[i][3]-alphaT;
                            break;
                        }
                    }
                }
                Ncurr=Nprec;
                cout << "place fin boucle augmentation"<< endl;
                afficher(&(tabLien[0][0]), M, 4);
                //getchar();
            }
        }
        else
        { break;}

        cout << "place fin boucle"<< endl;
        afficher(&(tabLien[0][0]), M, 4);
        //getchar();

    }

    // Affichage de la matrice finale
    cout << "place fin de la fin "<< endl;
    afficher(&(tabLien[0][0]), M, 4);
    getchar();


   return 0;
}
