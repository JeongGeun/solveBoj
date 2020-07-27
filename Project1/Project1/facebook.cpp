#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

int T, N;
char arr[2][51];
vector<int> adj[51];
char res[51][51];
int visit[51][51];

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		memset(arr, 0, sizeof(arr));
		memset(res, 0, sizeof(res));
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < 51; i++)
			adj[i].clear();
		//fill(adj, adj + N * N + 1, 1e9);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[0][i] == 'Y' && abs(i - j) == 1 && arr[1][j] == 'Y')
				{
					adj[j].push_back(i);
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (i != j)
				{
					res[i][j] = 'N';
				}
				else
				{
					res[i][j] = 'Y';
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			queue<int>q;
			q.push(i);
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				for (auto h : adj[cur])
				{
					if (visit[i][h] == 0)
					{
						res[i][h] = 'Y';
						q.push(h);
						visit[i][h] = 1;
					}
				}
			}
		}
	

		cout << "Case #" << t + 1<<":\n";
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				cout << res[i][j];
			cout << "\n";
		}
		
	}

}