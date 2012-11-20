#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
using namespace std;

double x[500000];
double y[500000];
int n;

double xmin;
double xmax;

double distance(double pos)
{
    double ret = 0;

    for (int i = 0; i < n; i++)
    {
        double d=(x[i]-pos)*(x[i]-pos)+y[i]*y[i];
        if (d>ret)
            ret = d;
    }
    return ret;
}

double trichotomie()
{
    double pos=xmin;
    double pos2=xmax;
    while (xmax-xmin>1e-6 || abs(sqrt(distance(xmax))-sqrt(distance(xmin))) > 1e-6)
    {
        pos2 = (xmax*2.+xmin)/3.;
        pos = (xmax+2.*xmin)/3.;
        
        double d = distance(pos);
        double d2 = distance(pos2);


        if (d>d2) xmin = pos;
        else if (d<=d2) xmax = pos2;
//        else return pos;
    }
    return pos;
}

bool entree()
{
    cin >> n;
    if (n==0) return false;
    cin >> x[0] >> y[0];
    xmin = x[0];
    xmax = x[0];

    for (int i = 1; i < n; i++)
    {
        cin >> x[i] >> y[i];
        if (x[i]<xmin)
            xmin=x[i];
        if (x[i]>xmax)
            xmax=x[i];
    }
    return true;
}

int main()
{
    while (entree())
    {
        double pos = trichotomie();
        printf("%.10f %.10f\n",pos,sqrt(distance(pos)));
    }
    return 0;
}
