#include <iostream>
#include <queue>
#include <algorithm>

struct Produit
{
	int d;
	int p;
	inline bool operator< (const Produit &p) const { return d > p.d;}
};

std::vector <Produit> pdt;




int main()
{
	int n;
	while (std::cin >> n)
	{	
		if (n==0)
		{
			std::cout << 0 << std::endl;
			continue;
		}
	
		pdt.resize(n);
		for (int i=0; i<n; i++)
		{
			std::cin >> pdt[i].p >> pdt[i].d;
		}

		std::sort(pdt.begin(), pdt.end());
		int profit = 0;
		int k=0;
		int t = 0;
	
		std::priority_queue<int> PQ;
		do
		{
			if (PQ.empty())
				t=pdt[k].d;
			while (pdt[k].d == t)
			{
				PQ.push(pdt[k].p);
				k++;
			}

			t--;
			profit += PQ.top();
			PQ.pop();
		}while (t != 0);
		std::cout << profit << std::endl;
	}
}

