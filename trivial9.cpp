#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    double pi = 3.141592653589793238462643383279;
    int no = 1;
    for (;;)
    {
        int radius;
        cin >> radius;
        if (radius == 0)  break;
        if (no != 1)
            cout << endl;
        cout << "Test Rig " << no++ << endl; 
        for (;;)
        {
            int lg,angle;
            cin >> lg >> angle;
            if (lg == 0 && angle == 0)  break;
            cout << int(double(lg)/(2.*double(radius)*sin(double(angle*pi/180.)))) << endl;
        }
    }
}


