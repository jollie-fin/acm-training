#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct couple
{
    int pos;
    int cout;
    couple (int p=0, int c=0)
    {
        cout = c;
        pos = p;
    };

    bool operator<(const couple &c) const
    {
        return cout>c.cout;
    };
};

couple adjacence[26][26];
int taille[26];

int s1,s2,pds;

bool acquisition()
{
    for (int i = 0; i < 26; i++)
    {
        taille[i] = -2;
    }

    pds = 0;
    string s;
    if ((cin >> s) == 0) return false;

    while (s != "deadend")
    {
        int d1 = s[0]-'a';
        int d2 = s[s.length()-1]-'a';
        
        if (taille[d1] == -2)
        {
            taille[d1] = 0;
        }
        if (taille[d2] == -2)
        {
            taille[d2] = 0;
        }
        pds+=s.length();
        adjacence[d1][taille[d1]++] = couple(d2,s.length());
        adjacence[d2][taille[d2]++] = couple(d1,s.length());
        cin >> s;
    }

    s1 = -1; s2 = -1;
    for (int i = 0; i < 26; i++)
    {
        if (taille[i]%2 == 1)
        {
            if (s1 == -1)
                s1 = i;
            else
                s2 = i;
        }
    }
    return true;
}    

int calcule()
{
    if (s1 == -1)
        return pds;
    priority_queue<couple> pq;
    pq.push(couple(s1,pds));
    couple co = couple(s1,pds);
    while (co.pos != s2)
    {
        co = pq.top();
        pq.pop();
        
        for (int i = 0; i < taille[co.pos]; i++)
        {
            pq.push(couple(adjacence[co.pos][i].pos,adjacence[co.pos][i].cout+co.cout));
        }
    }
    return co.cout;
}

int main()
{
    while (acquisition())
    {
        cout << calcule() << endl;
    }
    return 0;
}
    



        
