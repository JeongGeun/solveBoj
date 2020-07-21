#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int>table;
vector<int>result;
string T, P;

void makeTable(string pattern)
{
	table.resize((int)pattern.size(),0);
	int j = 0;
	for (int i = 1; i < pattern.size(); i++)
	{
		while (j > 0 && pattern[i] != pattern[j])
		{
			j = table[j - 1];
		}

		if (pattern[i] == pattern[j])
		{
			table[i] = ++j;
		}
	}

}

void KMP()
{
	int j = 0;
	for (int i = 0; i < T.size(); i++)
	{
		while (j > 0 && T[i] != P[j])
		{
			j = table[j - 1];
		}

		if (T[i] == P[j])
		{
			if (j == P.size() - 1)
			{
				result.push_back(i-P.size()+2);
				j = table[j];
			}
			else j++;
		}
	}


}

int main()
{
	getline(cin,T);
	getline(cin, P);
	makeTable(P);
	KMP();
	cout << result.size() << endl;
	for (int i : result)
		cout << i <<" ";
}
