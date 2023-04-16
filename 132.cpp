#include <complex>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct affixe
{
    affixe(long a, long b)
    {
        x = a; y = b;
    }
    double x;
    double y;
};

vector <affixe> polygone;
affixe cdg(0,0);

string nom_polygone;

bool acquisition()
{
    polygone.clear();
    cin >> nom_polygone;
    if (nom_polygone == "#")
        return false;
    long re,im;
    cin >> re >> im;
    cdg = affixe (re,im);

    cin >> re >> im;
    while (re!=0 && im!=0)
    {
        polygone.push_back(affixe (re,im));
        cin >> re >> im;
    }
    return true;
}

int determinant(const affixe &a, const affixe &b, const affixe &c, const affixe &d)
{
    long det = (a.x-b.x) * (c.y-d.y) - (a.y-b.y) * (c.x-d.x);
    if (det > 0) return 1;
    else if (det < 0) return -1;
    else return 0;
}

int scalaire(const affixe &a, const affixe &b, const affixe &c, const affixe &d)
{
    long scal = (a.x-b.x) * (c.x-d.x) + (a.y-b.y) * (c.y-d.y);
    if (scal > 0) return 1;
    else if (scal < 0) return -1;
    else return 0;
}

bool a_l_exterieur(int i, int j)
{
    int signe = 0.;

    for (int ii = 0; ii < (signed) polygone.size(); ii++)
    {
        if (ii != i && ii != j)
        {
            int signetmp = determinant(polygone[ii],polygone[i],polygone[j],polygone[i]);
            if (i == 11 && j == 14)
            {
                //cout << " " << i << "(" << polygone[i].x << " " << polygone[i].y << ")" << "," << j  << "(" << polygone[j].x << " " << polygone[j].y << ")" << "," << ii  << "(" << polygone[ii].x << " " << polygone[ii].y << ")" << "->" << signetmp << endl;
            }

           // cout << i << "," << j << "," << ii << "->" << signe << "," << signetmp
            if (signe == 0)
                signe = signetmp;
            else if (signe*signetmp < 0.)
                return false;
        }
    }
    return true;                        
}

bool equilibre(int i, int j)
{
    //cout << "scal " << scalaire(polygone[i],cdg,polygone[i],polygone[j]) << " " << scalaire(polygone[j],cdg,polygone[j],polygone[i]) << endl;
    return scalaire(polygone[i],cdg,polygone[i],polygone[j])>0 && scalaire(polygone[j],cdg,polygone[j],polygone[i])>0;
}

int representant(int i, int j)
{
    int r = 0;
    for (int k = 0; k < polygone.size(); k++)
        if (determinant(polygone[k],polygone[i],polygone[j],polygone[i]) == 0)
            r = k;
    return r;
}

int main()
{
    while (acquisition())
    {
        int min = polygone.size();
        for (int j = polygone.size() - 1; j>=0; j--)
            for (int i = j - 1; i>=0; i--)
            {
                bool equi = equilibre(i,j);
               // cout << i+1 << "," << j+1 << " " << equi << " " << a_l_exterieur(i,j) << endl;
                if (equi && a_l_exterieur(i,j))
                {
                   // cout << "bingo " << i+1 << "," << j+1 << endl;
                    int r = representant(i,j);
                   // cout << i+1 << "," << j+1 << "<-" << r+1 << endl;
                    if (r+1 < min)
                        min = r+1;
                }
            }
        cout << nom_polygone << " " << min << endl;
    }
}
