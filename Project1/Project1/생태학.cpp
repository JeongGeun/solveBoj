#include<iostream>
#include<map>
#include<string>
#include <iomanip>
using namespace std;

int main()
{
	string s;
	double sum = 0;
	map<string, int> m;

	while (getline(cin, s))
	{
		if (m.count(s) == 0)
		{
			m[s] = 1;
		}
		else
		{
			m[s]++;
		}
		sum++;
	}
	cout << fixed;
	cout.precision(4);
	for (auto i = m.begin(); i != m.end(); i++)
	{
		double se = i->second / sum * 100;
		cout << i->first<<" ";
		cout << i->second/sum*100 << "\n";
	}

}