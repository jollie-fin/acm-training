#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct couple
{
    double x,y;
    couple(int px = 0, int py = 0)
    {
        x = px;
        y = py;
    };

    bool operator<(const couple &c) const
    {
        return x < c.x;
    };
};

int n;
couple pos[1000];

long d2;
    long d;

bool estcouvert(double x, double x1, double y1)
{
    long r = (double) (x-x1)*(x-x1)+y1*y1 + 0.5;
//    cout << "r " << r << "," << x << "," << x1 << "," << y1 << endl;
    return long(r+0.5)<=d2;
}

bool couvre(double x, int deb, int fin)
{
    for (int i = deb; i < fin; i++)
    {
        if (!estcouvert(x,pos[i].x, pos[i].y))
            return false;
    }
    return true;
}

double position(int i)
{
    double r = pos[i].x - sqrt(d2-pos[i].y*pos[i].y);
//    cout << "position x:" << pos[i].x << " d2:" << d2 << " y2:" << pos[i].y*pos[i].y << " p:" << r << endl;
    return r;

}

int maximise_couverture()
{

    for (int i = 0; i < n; i++)
    {
        if (pos[i].y > d)
            return -1;
    }

    int resultat = 0;

    int deb = 0;
    int fin = n;

    while(true)
    {
        resultat++;
        double x;
        while(!couvre(x=position(deb),deb,fin))
        {
//            cout << "deb" << deb << endl;
            deb++;
            if (deb > fin)
                return -1;
        }
        while(couvre(x,deb,fin))
        {
            if (deb==0)
                return resultat;
            deb--;
        }
        deb++;

//        cout << "deb,fin " << deb << "," << fin << endl;
        fin = deb;
        deb = 0;
    }
}

bool acquisition()
{

    cin >> n >> d;
    if (n==0 && d==0)
        return false;
    d2 = d*d;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        pos[i] = couple(double(x),double(y));
    }
    sort(pos,pos+n);
    return true;
}

int main()
{
    int i = 1;
    while (acquisition())
    {
        cout << "Case " << i++ << ": " << maximise_couverture() << endl;
    }
    return 0;
}
