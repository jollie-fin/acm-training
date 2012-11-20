#include <set>
#include <iostream>

using namespace std;

int main()
{
    int c;
    static int sin[300];
    cin >> c;
    for (int i=0; i < c; i++)
    {
        int G;
        cin >> G;
        for (int j = 0; j < G; j++)
            cin >> sin[j];
        for (int k = G; k < 1000000; k++)
        {
            set <int> ens;
            int kk;
            for (kk = 0; kk < G; kk++)
            {
                if (ens.find(sin[kk]%k)==ens.end())
                {
                    ens.insert(sin[kk]%k);
                }
                else
                {
                    break;
                }
            }
            if (kk == G)
            {
                cout << k << endl;
                break;
            }
        }
    }
}
