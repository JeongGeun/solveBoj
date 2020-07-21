#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

typedef pair<int, int> P;
long long int dist[502];
vector<P>adj[502];

int main()
{
	int n, m;
	cin >> n >> m;
	fill(dist, dist + n + 1, 1e9);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b,c});
	}
	dist[1] = 0;
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (auto k : adj[j])
			{
				if (dist[j]!=1e9&&dist[k.first] > dist[j] + k.second)
				{
					dist[k.first] = dist[j] + k.second;
					if (i == n - 1) flag = true;
				}
			}
		}
	}

	if (flag) cout << "-1\n";
	else {
		for (int i = 2; i <= n ; i++)
		{
			if (dist[i] == 1e9) dist[i] = -1;
			cout << dist[i] << "\n";
		}
		
	}


}