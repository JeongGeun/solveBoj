#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int n;
vector<int> adj[501];
int arr[501][501] = { 0, };
int indegree[501] = { 0, };

int main()
{
	int t;
	cin >> t;
	for(int k=0;k<t;k++)
	{
		cin >> n;
		
		for (int i = 0; i < 501; i++) adj[i].clear();
		memset(arr, 0, sizeof(arr));
		vector<int>v;
		memset(indegree,0,sizeof(indegree));
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			for (int j = 0; j < v.size(); j++)
			{
				//indegree[v[j]]++;
				arr[a][v[j]] = 1;
			}
			v.push_back(a);
		}
		
		int m;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			if (arr[a][b])
			{
				arr[a][b] = 0;
				arr[b][a] = 1;
			}
			else
			{
				arr[a][b] = 1;
				arr[b][a] = 0;
			}
			//indegree[a]--;
		}
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < v.size(); j++)
			{
				if (arr[v[i]][v[j]])
				{
					adj[v[i]].push_back(v[j]);
					indegree[v[j]]++;
				}
			}
		}
		queue<int>q;
		for (int i = 1; i <= n; i++)
		{
			if (indegree[i] == 0)
			{
				q.push(i);
			}
		}
		vector<int>res;
		bool flag = true;
		for (int i = 1; i <= n; i++)
		{
			if (q.size() > 1)
			{
				cout << "?\n";
				flag = false;
				break;
			}
			if (q.empty())
			{
				cout << "IMPOSSIBLE\n";
				flag = false;
				break;
			}
			int cur = q.front();
			res.push_back(cur);
			q.pop();
			for (int h : adj[cur])
			{
				if (--indegree[h] == 0)
				{
					q.push(h);
				}
			}
		}
		if (flag)
		{
			for (int i = res.size() - 1; i >= 0; i--)
			{
				cout << res[i] <<" ";
			}
			cout << endl;
		}
		
	}


}