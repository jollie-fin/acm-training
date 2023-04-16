#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

struct arete
{
    int x,y;
    double p;
    arete(int px = 0, int py = 0, double pp = 0.)
    {
        x = px;
        y = py;
        p = pp;
    };

    bool operator<(const arete &c) const
    {
        return p < c.p;
    };
};

double d;

vector < set < int > > graphe;
vector < bool > est_deja_passe;
priority_queue < arete > poids;
map <string, int> correspondance;

unsigned est_connexe_rec(int lieu)
{
    if (est_deja_passe[lieu]) return 0;
    est_deja_passe[lieu] = true;
    int retour = 1;
    for (set<int>::iterator i = graphe[lieu].begin(); i != graphe[lieu].end(); ++i)
    {
        retour += est_connexe_rec(*i);
    }
    return retour;
}

bool est_connexe()
{
    for (unsigned i = 0; i < est_deja_passe.size(); i++)
    {
        est_deja_passe[i] = false;
    }
    unsigned co = est_connexe_rec(0);
   /* int test = 0;
    for (int i = 0; i < graphe.size(); i++)
        test += graphe[i].size();*/
//    cout << "co " << co << " siz " << graphe.size() << " test " << test << endl;
    
    return co == graphe.size();
}

void retire(const arete &ar)
{
    graphe[ar.x].erase(ar.y);
    graphe[ar.y].erase(ar.x);
}

void remet(const arete &ar)
{
    graphe[ar.x].insert(ar.y);
    graphe[ar.y].insert(ar.x);
}

double distance_minimale()
{
    double retour = 0.;
    if (!est_connexe())
        return -1.;

    while (!poids.empty())
    {
        arete ar = poids.top();
        poids.pop();
        retire (ar);
        if (!est_connexe())
        {
            remet (ar);
            retour += ar.p;
        }
    }
    return retour;
}

bool acquisition()
{
    int ville,nbarete;
    if ((cin >> d >> ville) == 0)
        return false;

    graphe.clear();
    est_deja_passe.clear();
    correspondance.clear();
    poids = priority_queue<arete>();

    graphe.resize(ville);
    est_deja_passe.resize(ville);

    for (int i = 0; i < ville; i++)
    {
        string s;
        cin >> s;
        correspondance[s] = i;
    }
    cin >> nbarete;
//    cout << "nbar " << nbarete << endl;
    for (int i = 0; i < nbarete; i++)
    {
        string s1,s2;
        double p;
        cin >> s1 >> s2 >> p;
//        cout << s1 << s2 << endl;
        int i1= correspondance[s1];
        int i2 = correspondance[s2];
//        cout << "i1 " << i1 << " i2 " << i2 << endl;
        poids.push(arete(i1,i2, p));
        graphe[i1].insert(i2);
        graphe[i2].insert(i1);
    }
    return true;
}

int main()
{
    while(acquisition())
    {
        double distance = distance_minimale();
        
        if (distance < 0 || distance > d)
            printf ("Not enough cable\n");
        else
            printf("Need %.1f miles of cable\n",distance);
    }
}
