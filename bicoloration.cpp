#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

vector < vector <int> > adjacence;
int gcouleur[26];
bool gtouche[26];

void reinitialise(int n)
{
    int i;
    for (i = 0; i<n; i++)
    {
        gcouleur[i] = -1;
        gtouche[i] = false;
    }
}

void initialise(int n)
{
    int i;
    int j;
    adjacence.resize(n);

    string s;

    for (i = 0; i<n; i++)
    {
        getline (cin, s);
        adjacence[i].resize(s.length() - 2);
        for (j = 0; j < (signed) s.length() - 2; j++)
            adjacence[i][j] = s[j+2] - 'A';
    }
}

bool unicolorie(int n)
{
    int i;
    int retour = 0;
    for (i = 0; i < n; i++)
        retour += adjacence[i].size();
    return retour==0;
}

bool recbicolorie(int n, int couleur, int sommet)
{
    if (gcouleur[sommet] == couleur)
        return true;
    else if (gcouleur[sommet] < 0)
    {
        gcouleur[sommet] = couleur;
        for (int i=0; i < (signed) adjacence[sommet].size(); i++)
        {    
            if (recbicolorie(n, !couleur, adjacence[sommet][i]) == false)
                return false;
        }
        return true;
    }
    return false;
}
            
bool bicolorie(int n)
{
    reinitialise(n);
    for (int i = 0; i < n; i++)
    {
        if (gcouleur[i] < 0)
            if(recbicolorie(n,0,i) == false)
                return false;
    }
    return true;
}

bool rectricolorie(int n, int couleur, int sommet)
{
    gtouche[sommet] = true;
    if (gcouleur[sommet] == couleur)
        return true;
    else if (gcouleur[sommet] < 0)
    {
        gcouleur[sommet] = couleur;
        for (int i=0; i < (signed) adjacence[sommet].size(); i++)
        {
            if (rectricolorie(n, (couleur+1)%3, adjacence[sommet][i]) == false)
                if (rectricolorie(n, (couleur+2)%3, adjacence[sommet][i]) == false)
                {
                    gcouleur[sommet] = -1;                
                    return false;
                }
        }
        gcouleur[sommet] = -1;
        return true;
    }
    return false;
}

bool tricolorie(int n)
{
    reinitialise(n);
    for (int i = 0; i < n; i++)
    {
        if (!gtouche[i])
            if(rectricolorie(n,0,i) == false)
                return false;
    }
    return true;
}

int main()
{
    int n;
    string s;
    getline(cin,s);
    n = atoi(s.c_str());
    while (n != 0)
    {
        initialise(n);
        if (unicolorie(n))
        {
            cout << "1 channel needed." << endl;
        }
        else if (bicolorie(n))
        {
            cout << "2 channels needed." << endl;
        }
        else if (tricolorie(n))
        {
            cout << "3 channels needed." << endl;
        }
        else
            cout << "4 channels needed." << endl;
        getline(cin,s);
        n = atoi(s.c_str());
    }
    
     
    return EXIT_SUCCESS;
}
