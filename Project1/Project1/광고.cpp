#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> maketable(string s)
{
	vector<int> table(s.size());
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
	int n;
	string s;
	cin >> n;
	cin >> s;
	vector<int> table = maketable(s);

	if (table[n - 1] == 0)
	{
		cout <<n << endl;
	}
	else
	{
		cout << n - table[n - 1] << endl;
	}
}