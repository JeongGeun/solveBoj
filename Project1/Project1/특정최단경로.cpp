#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> P;
vector<P> adj[801];
int v1, v2;
int n, e;
int dist[801];
int visit[801];

int go(int start, int end)
{
	fill(dist, dist + n + 1, 1e9);
	memset(visit, 0, sizeof(visit));

	priority_queue<P,vector<P>,greater<P>> q;
	q.push({0,start});
	dist[start] = 0;
	
	while (!q.empty())
	{
		int cur = q.top().second;
		q.pop();
		if (visit[cur]) continue;
		visit[cur] = 1;
		
		for (auto i : adj[cur])
		{
			if (dist[i.first] > dist[cur] + i.second)
			{
				dist[i.first] = dist[cur] + i.second;
				q.push({dist[i.first],i.first});
			}
		}

	}
	if (dist[end]==1e9) return -1;
	
	return dist[end];


}


int main()
{
	
	cin >> n >> e;
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });

	}

	cin >> v1 >> v2;

	int dist1 = 0;
	int dist2 = 0;

	int ab = go(1,v1);
	int bc = go(v1, v2);
	int cd = go(v2, n);
	if (ab != -1 && bc != -1 && cd != -1)
	{
		dist1 = ab + bc + cd;
	}
	else dist1 = -1;

	ab = go(1, v2);
	bc = go(v2, v1);
	cd = go(v1, n);
	if (ab != -1 && bc != -1 && cd != -1)
	{
		dist2 = ab + bc + cd;
	}
	else dist2 = -1;

	if (dist1 == -1 || dist2 == -1) cout << "-1\n";
	else cout << min(dist1, dist2)<<"\n";

}