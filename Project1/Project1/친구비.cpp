#include<iostream>
#include<string.h>
#include<algorithm>
#include<set>
using namespace std;

int arr[10001];
int parent[10001];
int visit[10001];

int find(int x)
{
	if (parent[x] == -1) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
	visit[x] = 1;
	visit[y] = 1;
	x = find(x);
	y = find(y);
	if (x != y)
	{
		if (arr[x] < arr[y])
			parent[y] = x;
		else
		{
			parent[x] = y;
		}
	}
}	



int main()
{
	int n, m, k;
	memset(parent, -1, sizeof(parent));

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++)
	{
		int v, w;
		cin >> v >> w;
		merge(v, w);
	}
	set<int>s;
	long long int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		if (parent[i] == -1) ans += arr[i];
	}
	if(ans<=k)
	cout << ans << "\n";
	else
	cout <<"Oh no\n";
}