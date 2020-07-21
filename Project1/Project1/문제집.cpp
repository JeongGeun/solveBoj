#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;

vector<int>graph[32001];
int indegree[32001];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}
	priority_queue<int,vector<int>,greater<int>>q;
	vector<int>ans;
	for (int i = 1; i <= n; i++)
	{
		if (!indegree[i])
		{
			q.push(i);
		}
	}

	for (int i = 0; i < n; i++)
	{
		int node = q.top();
		ans.push_back(node);
		q.pop();
		for (auto i : graph[node])
		{
			if (--indegree[i] == 0)
			{
				q.push(i);
			}
		}
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";

}