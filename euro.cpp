#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

map <int,int>possibilite;

int x1,x2,x3,x4,x5,x6;

void initialise()
{
    cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6;
    possibilite.clear();
    possibilite[0] = 0;
}

void calcule()
{
    int nb_bons = 0;
    int max = 0;
    do
    {
        nb_bons = 0;
        map <int, int> tmp;
        for (map<int,int>::iterator i = possibilite.begin(); i != possibilite.end(); ++i)
        {
            tmp[i->first+x1] = i->second + 1;
            tmp[i->first+x2] = i->second + 1;
            tmp[i->first+x3] = i->second + 1;
            tmp[i->first+x4] = i->second + 1;
            tmp[i->first+x5] = i->second + 1;
            tmp[i->first+x6] = i->second + 1;
            tmp[i->first-x1] = i->second + 1;
            tmp[i->first-x2] = i->second + 1;
            tmp[i->first-x3] = i->second + 1;
            tmp[i->first-x4] = i->second + 1;
            tmp[i->first-x5] = i->second + 1;
            tmp[i->first-x6] = i->second + 1;
        }
        for (map<int,int>::iterator i = possibilite.begin(); i != possibilite.end(); ++i)
        {
            tmp[i->first] = i->second;
        }
        possibilite = tmp;
        for (map<int,int>::iterator i = possibilite.begin(); i != possibilite.end(); ++i)
        {
            int val = i->first;
            if (val > 0 && val <= 100)
            {
                nb_bons++;
            }
        }
    }while (nb_bons != 100);

    long moyenne = 0;
    for (int i = 1; i <= 100; i++)
    {
        int p = possibilite[i];
//        printf ("%d<-%d\n", i,p);
        moyenne += p;
        if (max < p)
            max = p;
    }
    printf("%.2f %d\n", double(moyenne)/100., max);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        initialise();
        calcule();
    }
}
