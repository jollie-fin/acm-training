#include <iostream>
#include <map>

using namespace std;

int F;
int N;
int B;

struct config
{
    short position[1000];
    char dir[1000];
   
    bool operator< (const config &c) const
    {
        for (int i = 0; i < N; i++)
        {
            if (position[i] < c.position[i])
                return true;
            else if (position[i] > c.position[i])
                return false;
            else if (dir[i] < c.dir[i])
                return true;
            else if (dir[i] > c.dir[i])
                return false;
        }
        return true;
    };
 
    bool operator= (const config &c) const
    {
        for (int i = 0; i < N; i++)
        {
            if (position[i] != c.position[i])
                return false;
            if (dir[i] != c.dir[i])
                return false;
        }
        return true;
    };
};

config init;

map <config, int> hist;

bool acquisition()
{
    cin >> N >> F >> B;
    etat.clear();
    for (int i = 0; i < N; i++)
    {
        cin >> config.position[i] >> config.dir[i];
    }
int main()
{
    cout << sizeof(config) << endl;
}
