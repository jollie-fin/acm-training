#include <cmath>
#include <iostream>

using namespace std;

double round(double x){
	if (modf(x,0)>=.5)
		return x>=0?ceil(x):floor(x);
	else
		return x<0?ceil(x):floor(x);
}


int main()
{
    int c;
    long double pi = 3.14159265358979323846264338327950288419716939937510;
    cin >> c;
    for (int i=0; i < c; i++)
    {
        int x;
        cin >> x;
        long double xx = x;
        long double r = 1.;
        long double j,jj;
        for (j = 1.; j <= 4.; j++)
            for (jj = 1; jj <= xx; jj++)
                r *= pow(4.*(pow(cos(pi*j/5.),2.)+pow(cos(pi*jj/(xx+1.)),2.)),.25);
        int resultat = round(r);
        cout << i+1 << " " << resultat <<endl;
    }
}


