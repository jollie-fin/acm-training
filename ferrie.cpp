#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

struct route
{
    bool estceroute;
    double distance;
    long temps;
    vector <long> horaire;
    long sortie(double vitesse_max, long instant)
    {
        if (estceroute)
        {
            return instant+ceil(distance/vitesse_max);
        }
        else
        {
            for (unsigned i = 0; i < horaire.size(); i++)
            {
                if (horaire[i]>=(instant%3600))
                {
                    return (instant/3600)*3600+horaire[i] + temps;
                }
            }
            return horaire[0] + (instant/3600)*3600+3600 + temps;
        }
    }

    route(double pdistance = 0.)
    {
        estceroute = true;
        distance = pdistance;
    }

    route(long ptemps, vector<long> phoraire)
    {
        estceroute = false;
        temps = ptemps;
        horaire = phoraire;
    }
};

vector <route> voie;

bool entree()
{
    int n;
    cin >> n;
    if (n==0) return false;
    voie.resize(n);
    string s1,s2,s3;
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2 >> s3;
        if (s3 == "road")
        {
            double distance;
            cin >> distance;
            voie[i] = route(distance);
        }
        else
        {
            long temps;
            int f;
            cin >> temps >> f;
            vector <long> horaire(f);
            for (int j = 0; j < f; j++)
            {
                cin >> horaire[j];
                horaire[j] *= 60;
            }
            voie[i] = route(temps*60, horaire);
        }
    }
    return true;
}

long garrivee;
double gvitesse;

long instant_arrivee(double vitesse)
{
    long depart = 0;
    for (unsigned i = 0; i < voie.size(); i++)
    {
        depart = voie[i].sortie(vitesse,depart);
    }
    return depart;
}

void calcul()
{
    garrivee = instant_arrivee(80./3600.);
    double vmin = 0.;
    double vmax = 80./3600.;
    
    while (vmax - vmin > 0.001/3600.)
    {
        long i = instant_arrivee((vmax+vmin)/2.);
        if (i > garrivee)
            vmin = (vmax+vmin)/2.;
        else
            vmax = (vmax+vmin)/2.;
    }
    gvitesse = vmin;
}

    
int main()
{
    int i = 0;
    while (entree())
    {
        calcul();
        long arrivee = garrivee;
        printf ("Test Case %d: %02ld:%02ld:%02ld %.2f\n\n", ++i, arrivee / 3600, (arrivee / 60) % 60, (arrivee % 60), gvitesse*3600.);

    }
}
       
