#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
#include<string>
using namespace std;
typedef pair<int, pair<int, int>> PI;
int arr[101][101];
int visit[101][101];
int dx[] = {0,1,0,-1}; 
int dy[] = {-1,0,1,0};
int n, m;

int bfs()
{
	int ans = 0;
	priority_queue<PI,vector<PI>,greater<PI>>q;
	q.push({ 0,{0,0} });
	visit[0][0]++;
	while (!q.empty())
	{
		int cnt = q.top().first;
		int x = q.top().second.first;
		int y = q.top().second.second;
		q.pop();
		if (visit[m - 1][n - 1])
		{
			return cnt;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (!visit[nx][ny])
			{
				visit[nx][ny]++;
				if (arr[nx][ny])
				{
					q.push({ cnt + 1,{nx,ny} });
				}
				else
				{
					q.push({ cnt,{nx,ny} });
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			arr[i][j] = s[j] - '0';
	}
	cout << bfs() << endl;
}