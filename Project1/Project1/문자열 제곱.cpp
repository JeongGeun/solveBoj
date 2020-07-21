#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> makeTable(string s)
{
	vector<int> table(s.size(),0);
	int j = 0;
	for (int i = 1; i < s.size(); i++)
	{
		while (j > 0 && s[i] != s[j])
		{
			j = table[j - 1];
		}

		if (s[i] == s[j])
		{
			table[i] = ++j;
		}
	}
	return table;
}

int main()
{
	while (1)
	{
		string s;
		cin >> s;
		if (s[0] == '.')
		{
			break;
		}
		vector<int>table = makeTable(s);
		int ssize = s.size();
		if (ssize % (ssize - table[ssize - 1]) == 0)
			cout << ssize / (ssize - table[ssize - 1]) << "\n";
		else
			cout << "1\n";
	}

}