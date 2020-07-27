#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dp[10002];
int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> temp;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		temp.push_back(a);
	}
	fill(dp, dp + k + 1, 1e9);
	dp[0] = 0;
	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (j - temp[i] >= 0)
			{
				dp[j] = min(dp[j], dp[j - temp[i]] + 1);
			}
		}
	}
	if (dp[k] != 1e9)
		cout << dp[k] << endl;
	else
		cout << "-1\n";
}