#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<string.h>
using namespace std;

typedef pair<int, int> P;
int n, m;
int arr[101][101];
//int map[101][101];
int check[101][101];
int visit[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void bfs()
{
	deque<P>q;
	q.push_back({ 0,0 });
	visit[0][0] = 1;
	while (!q.empty())
	{
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int xx = nx + dx[i];
			int yy = ny + dy[i];
			if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			if (!visit[xx][yy] && !arr[xx][yy])
			{
				visit[xx][yy] = 1;
				q.push_back({ xx,yy });
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visit[i][j])
			{
				check[i][j] = 1;
			}
		}
	}
	memset(visit, 0, sizeof(visit));
}

void find()
{
	vector<P>erchs;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j])
			{
				int cnt = 0;
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (check[nx][ny] == 1)
					{
						cnt++;
					}
				}
				if (cnt >= 2)
				{
					erchs.push_back({ i,j });
				}
			}
		}
	}
	for (int i = 0; i < erchs.size(); i++)
	{
		arr[erchs[i].first][erchs[i].second] = 0;
		check[erchs[i].first][erchs[i].second] = 1;
	}
}

bool bchk()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j]) return true;
		}
	}
	return false;
}

int main()
{

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j])
			{
				check[i][j] = 2;

			}
		}
	}
	int time = 0;
	while (1)
	{
		if (!bchk()) break;
		bfs();
		find();
		time++;
	}
	cout << time << "\n";

}