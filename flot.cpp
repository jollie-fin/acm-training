#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector <int> adjacence[201];
vector <int> capa[201];
vector <int> flot[201];
int x[100];
int y[100];
int capalin[100];
int nbpinguins[100];
double distance2;











int passe[201];
int chemin[201];
int lg_chemin;
int nbpinguinstotal;

int n,source,destination;

bool distance(double x1, double y1, double x2, double y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<=distance2;
}

void acquisition()
{
    nbpinguinstotal = 0;
    cin >> n >> distance2;

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> nbpinguins[i] >> capalin[i];
    }

    for (int i = 0; i < 201; i++)
    {
        adjacence[i].clear();
        capa[i].clear();
        flot[i].clear();
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i!=j)    
            if (distance(x[i],y[i],x[j],y[j]))
            {
                adjacence[i].push_back(100+j);
                adjacence[j].push_back(100+i);
                capa[i].push_back(400);
                capa[j].push_back(400);
                flot[i].push_back(0);
                flot[j].push_back(0);
            }
        }
        adjacence[100+i].push_back(i);
        capa[100+i].push_back(capalin[i]);
        flot[100+i].push_back(0);
        adjacence[200].push_back(100+i);
        capa[200].push_back(nbpinguins[i]);
        flot[200].push_back(0);
        nbpinguinstotal+=nbpinguins[i];
    }            
    return true;
}

bool calcule_chemin()
{
    for (int i = 0; i < 201; i++)
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
        largeur.pop();
        for (int ii = 0; ii < adjacence[position_courante].size(); ii++)
        {
            int i = adjacence[position_courante][ii];
            if (i!=position_courante && passe[i]==-1 && flot[position_courante][ii] < capa[position_courante][ii])
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
    int min = 10000001;
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
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if ((passe[i] != -1) && (passe[j] == -1) && capa[i][j] != 0)
                cout << i+1 << " " << j+1 << endl;
        }

    return f;
}

bool est_ce_possible(int dest)
{
    source = 200;
    destination = dest;
    return calcule_capa == nbpinguinstotal;
}

int main()
{
    int nn;
    for (i = 0; i < nn; i++)
    {
        acquisition();
        bool premier = true;
        for (int j = 0; j < n; j++)
        {
            if (est_ce_possible(j))
            {
                if (!premier)
                {
                    cout << " ";
                }
                cout << j;
            }
            if (!premier)
                cout << -1;
            cout << endl;
        }
    }
}   
