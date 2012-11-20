#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

int flot[100][100];
int capa[100][100];
int passe[100];
int chemin[100];
int lg_chemin;


int n,source,destination;

bool acquisition()
{
    int c;
    cin >> n;
    if (n==0) return false;
    cin >> source >> destination >> c;
    source--; destination--;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            flot[i][j] = 0;
            capa[i][j] = 0;
        }

    for (int i = 0; i < c; i++)
    {   
        int x,y,ca;
        cin >> x >> y >> ca;
        x--; y--;
        capa[x][y] += ca;
        capa[y][x] += ca;
    }
            
    return true;
}

bool calcule_chemin()
{
    for (int i = 0; i < n; i++)
    {
        passe[i] = -1;
        chemin[i] = 0;
    }

    int position_courante;
    queue <int> largeur;
    largeur.push(source);
    passe[source] = 0;
    while ((position_courante = largeur.front()) != destination)
    {
/*        cout << "pc " << position_courante;
        for (int i = 0; i < n; i++)
            cout << " " << passe[i];
        cout << endl;*/
        largeur.pop();
        for (int i = 0; i < n; i++)
        {
            if (i!=position_courante && passe[i]==-1 && flot[position_courante][i] < capa[position_courante][i])
            {
                passe[i] = position_courante;
                largeur.push(i);
            }
        }
        if (largeur.empty())
            return false;
    }
    
    lg_chemin = 0;
    position_courante = destination;
    chemin[lg_chemin++] = destination;
    while (position_courante != source)
    {
        position_courante = passe[position_courante];
        chemin[lg_chemin++] = position_courante;
    }
    return true;
}

int capa_residuelle()
{
    int min = 1001;
    for (int i = 0; i < lg_chemin-1; i++)
    {
        int ca = capa[chemin[i+1]][chemin[i]] - flot[chemin[i+1]][chemin[i]];
        if (ca < min)
            min = ca;
    }
    return min;
}

void incremente_flot(int fincr)
{
    for (int i = 0; i < lg_chemin-1; i++)
    {
        flot[chemin[i+1]][chemin[i]] += fincr;
        flot[chemin[i]][chemin[i+1]] -= fincr;
    }
}


int calcule_capa()
{
    int f=0;
    while(calcule_chemin())
    {
        int fincr = capa_residuelle();
        f+=fincr;
        incremente_flot(fincr);
//        affiche_flot();
    }
    return f;
}

int main()
{
    int i = 1;
    while(acquisition())
    {
        cout << "Network " << i++ << "\nThe bandwidth is " << calcule_capa() << ".\n" << endl;
    }
}   
