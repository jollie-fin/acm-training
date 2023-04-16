#include <set>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector < vector < int > > adjacence;

int N;
unsigned int c1,c2;

int crash()
{
    return *((int *) 0);
}
void acquisition()
{
    cin >> N;
    if (N > 100000)
            crash();  
    adjacence.resize(N);     
    for (int i = 0; i < N; i++)
    {
        int c;
        int nc;
        cin >> c >> nc;
        adjacence[c].resize(nc);
        for (int j = 0; j < nc; j++)
            cin >> adjacence[c][j];
        if (nc > 100)
            crash();
    }
    cin >> c1 >> c2;
}

int calcule()
{
    set <unsigned int> s;
    if (c1 == c2)
        return 0;

    s.insert(c1);


    for (int inter = 0; inter < N; inter++)
    {
        set <unsigned int> s2;
       for (set<unsigned int>::iterator i = s.begin(); i != s.end(); ++i)
        {
            for (unsigned j = 0; j < adjacence[*i].size(); j++)
            {
                s2.insert(adjacence[*i][j]);
            }
        }
        if (s2.find(c2) != s2.end())
        {
            return inter;
        }
        s = s2;
    }
    crash();
    return 0;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        acquisition();
        cout << c1 << " " << c2 << " " << calcule() << endl;
        if (i < n-1)
            cout << endl;
    }
    return 0;
}
            
