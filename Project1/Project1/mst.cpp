#include<iostream>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> PI;

int parent[1001];

int find(int num)
{
	if (parent[num] == -1) return num;
	return parent[num] = find(parent[num]);

}

bool merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)return false;
	parent[y] = x;
	return true;
}

int main()
{
	int n, m;
	cin >> n >> m;
	memset(parent, -1, sizeof(parent));
	priority_queue<PI, vector<PI>, greater<PI>>pq;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ c,{a,b} });
	}
	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int cost = pq.top().first;
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		pq.pop();
		if (merge(u, v))
		{
			cnt++;
			ans += cost;
			if (cnt == n - 1) break;
		}
	}
	cout << ans << endl;

}