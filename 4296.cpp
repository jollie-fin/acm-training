#include <set>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct arete
{
    int a;
    int b;
    int v;

    arete(int pa,int pb,int pv)
    {
        a = pa; b = pb; v = pv;
    };

    bool operator<(const arete& ar) const
    {
        return v > ar.v;
    };
};

struct demi_arete
{
    int a;
    int v;
    demi_arete(int pa,int pv)
    {
        a = pa;
        v = pv;
    };
};

struct couple
{
    int a,b;
   couple (int pa, int pb)
    {
        a=pa;b=pb;
    };
};

unsigned int N;
unsigned int R;
unsigned int Q;

vector <couple> objectif;

priority_queue <arete> liste_arete;
vector <vector <arete> > liste_adjacence;
set <int> connection;
vector <vector <demi_arete> > arbre_couvrant;
vector <bool> passe;

inline bool est_valide(const arete &ar)
{
    return (connection.find(ar.a) == connection.end() && connection.find(ar.b) != connection.end())
         ||(connection.find(ar.a) != connection.end() && connection.find(ar.b) == connection.end());
}
int debug = 0;
void ajoute_element()
{
    arete ar(0,0,0);
    do
    {
        debug++;
        ar = liste_arete.top();
        liste_arete.pop();
    }    
    while (!est_valide(ar));

    if (connection.find(ar.a) == connection.end())
    {
        connection.insert(ar.a);
        for (unsigned i = 0; i < liste_adjacence[ar.a].size(); i++)
        {
            arete ar2 = liste_adjacence[ar.a][i];
            if (est_valide(ar2))
                liste_arete.push(ar2);
        }
    }
    else
    {
        connection.insert(ar.b);
        for (unsigned i = 0; i < liste_adjacence[ar.b].size(); i++)
        {
            arete ar2 = liste_adjacence[ar.b][i];
            if (est_valide(ar2))
                liste_arete.push(ar2);
        }
    }

    arbre_couvrant[ar.a].push_back(demi_arete(ar.b,ar.v));
    arbre_couvrant[ar.b].push_back(demi_arete(ar.a,ar.v));
}

void construit_span()
{
    connection.clear();
    arbre_couvrant.clear();
    arbre_couvrant.resize(N);
    liste_arete = priority_queue<arete> ();
    for (unsigned i = 0; i < liste_adjacence[0].size(); i++)
    {
        liste_arete.push(liste_adjacence[0][i]);
    }
    connection.insert(0);
    while (connection.size() != N)
    {
        ajoute_element();
    }
}

void entree()
{
    liste_adjacence.clear();
     cin >> N >> R;
    liste_adjacence.resize(N);
    for (unsigned int i =0; i < R; i++)
    {
        int a,b,v;
        cin >> a >> b >> v;
        a--;
        b--;
        liste_adjacence[a].push_back(arete(a,b,v));
        liste_adjacence[b].push_back(arete(a,b,v));
    }
    cin >> Q;
    objectif.clear();
    for (unsigned int i = 0; i < Q; i++)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        objectif.push_back(couple(a,b));
    }
}
#define infini -1
int min_rec(int pos, int obj)
{
    if (passe[pos])
        return infini;
    if (pos == obj)
        return 0;

    passe[pos] = true;
    int max = infini;
    for (unsigned int i = 0; i < arbre_couvrant[pos].size(); i++)
    {
        demi_arete &c = arbre_couvrant[pos][i];
        int tmp = min_rec(c.a,obj);

        if (tmp != infini)
        {
            if (c.v > tmp)
            {
                tmp = c.v;
            }

            if (tmp > max) 
            {
                max = tmp;
            }
        }
    }
    return max;    
}

void affiche_min(const couple &c)
{
    passe.clear();
    passe.resize(N,false);
    cout << min_rec(c.a,c.b) << endl;
}

void calcule()
{
    entree();
    construit_span();
    for (unsigned int i = 0; i < Q; i++)
    {
        affiche_min(objectif[i]);
    }
}

int main(int argc, char **argv)
{
    int nb;
    cin >> nb;
    for (int i = 0; i < nb; i++)
    {
        cout << "Case" << " " << i+1 << endl;
        calcule();
        cout << endl;
    }
    return 0;
}

