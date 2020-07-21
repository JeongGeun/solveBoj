#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;

int main()
{
	int n, m;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	set<string>s;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		s.insert(input);
	}
	for (int i = 0; i < m; i++)
	{
		string temp;
		cin >> temp;
		if (s.count(temp) > 0) ans++;
	}
	cout << ans << "\n";


}