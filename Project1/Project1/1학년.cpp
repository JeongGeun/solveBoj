#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int>v;
long long int dp[101][21];
long long int cnt;


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	dp[0][v[0]] = 1;
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (dp[i - 1][j] == 0) continue;
			if (j + v[i] <= 20) dp[i][j + v[i]] += dp[i - 1][j];
			if (j - v[i] >= 0) dp[i][j - v[i]] += dp[i - 1][j];
		}
	}
	cout << dp[n-2][v[n-1]];
}