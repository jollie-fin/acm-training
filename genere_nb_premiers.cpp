#include <iostream>

int main()
{
    int nb_premiers = 0;
    std::cout << "int premier [] = {2";
    for (int i = 3; i < 10000; i+=2)
    {
        bool premier = true;
        for (int j = 3; j*j <= i; j+=2)
        {
            if (i%j==0)
                premier = false;
        }
        if (premier)
        {
            std::cout << ",";
            if (++nb_premiers%10==0)
                std::cout << "\n";
            std::cout << i;
            
        }
    }
    std::cout << "};" << std::endl;
    return 0;
}
