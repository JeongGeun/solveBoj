#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;

typedef pair<int, int> P;
vector<P> adj[5001];
int visit[5001];

int bfs(int k,int v)
{
	queue<int>q;
	memset(visit,0,sizeof(visit));
	q.push(v);
	visit[v]++;
	int ans = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto i : adj[cur])
		{
			if (i.second >= k && !visit[i.first])
			{
				ans++;
				q.push(i.first);
				visit[i.first]++;
			}
		}

	}
	return ans;

}


int main()
{
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({a,c});
	}
	for (int i = 0; i < q; i++)
	{
		int k, v;
		cin >> k >> v;
		cout << bfs(k, v) << endl;
		
	}


}