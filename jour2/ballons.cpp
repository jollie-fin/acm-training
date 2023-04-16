#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

struct point
{
    int x,y,z;
    bool operator<(const point &p) const
    {
        return x<p.x || (x == p.x && (y < p.y || (y == p.y && z < p.z)));
    }
    double distance(const point &p) const
    {
        return sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y)+(p.z-z)*(p.z-z));
    }
}

point c1;
vector <point> c;
int n;

void reordonne(int &a, int &b)
{
    if (a > b)
        swap (a,b);
}

bool initialise()
{
    int x0,y0,z0,x1,y1,z1;
    c.erase();
    cin >> n;
    if (n==0)
        return false;
    cin >> x0 >> y0 >> z0;
    cin >> x1 >> y1 >> z1;
    
    reordonne(x0,x1);
    reordonne(y0,y1);
    reordonne(z0,z1);
    x1-=x0;
    y1-=y0;
    z1-=z0;
    for (i = 0; i < n; i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        x-=x0;
        y-=y0;
        z-=z0;
        if (x < x1 && x > 0 && y < y1 && y > 0 && z < z1 && z > 0)
        {
            point p;
            p.x = x;
            p.y = y;
            p.z = z;
            c.push_back(p);
        }
    }
    c1.x = x;
    c1.y = y;
    c1.z = z;
    sort(c.begin(), c.end());
    return true;
}

double rayon[6];

void diametre(int b)
{
    double retour = numeric_limits<double>::max();

    retour = min(retour, double(c[b].x));
    retour = min(retour, double(c[b].y));
    retour = min(retour, double(c[b].z));
    retour = min(retour, double(c1.x-c[b].x));
    retour = min(retour, double(c1.y-c[b].y));
    retour = min(retour, double(c1.z-c[b].z));

    for (int i=0; i < b; i++)
    {
        double d = c[b].distance(c[i]);
        if (d <= rayon[i])
        {
            rayon[b] = 0.;
            return;
        }
        retour = min(retour, d-rayon[i]);
    }
    rayon[b] = retour;
}

double calcule_volume()
{
    double retour;
    for (int i=0; i<c.size(); i++)
    {
        retour += rayon[i]*rayon[i]*rayon[i];
    }
    retour *= 4*M_PI/3;
    return retour;
}

bool calcule_max(int indice)
{
    double volume = 0.;
    if (!initialise())
        return false;
    do
    {
        for (int i=0; i<c.size(); i++)
        {
            diametre();
        }
        volume = max(volume, calcule_volume());
    }
    while (next_permutation(c.begin(), c.end());
    cout << "Box " << indice << ": " << long(volume) << endl;
    return true;
}

int main()
{
    int i=1;
    while (calcule_max(i++));
    return 1;
}
int volume(std::vector <
