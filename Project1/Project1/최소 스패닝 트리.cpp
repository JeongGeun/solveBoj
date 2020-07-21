#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> PI;
int parent[10001];

int find(int x)
{
	if (parent[x] == -1) return x;
	return find(parent[x]);
}

bool merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)return false;
	parent[x] = y;
	return true;
}

int main()
{
	int v, e;
	cin >> v >> e;
	memset(parent, -1, sizeof(parent));
	priority_queue<PI, vector<PI>, greater<PI>>pq;
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ c,{a,b} });
	}

	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < e; i++)
	{
		int cost = pq.top().first;
		int v1 = pq.top().second.first;
		int v2 = pq.top().second.second;
		pq.pop();
		if (merge(v1, v2))
		{
			ans += cost;
			cnt++;
			if (cnt == v - 1) break;
		}
	}
	cout << ans << "\n";
}