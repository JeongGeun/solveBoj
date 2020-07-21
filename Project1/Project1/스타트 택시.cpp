#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct person {
	int x;
	int y;
	int destx;
	int desty;
	int flag;

};

int arr[22][22];
int n, m, k;
int tx, ty;
int ret;
vector<person> pv;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool find(int num,int cnt)
{
	int visit[22][22] = { 0, };
	memset(visit, -1, sizeof(visit));

	deque<pair<int, int>>q;
	q.push_back({ pv[num].x,pv[num].y });
	visit[q[0].first][q[0].second] = 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		if (visit[pv[num].destx][pv[num].desty] != -1) break;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || nx>n || ny<1 || ny>n) continue;
			if (visit[nx][ny] == -1)
			{
				if (arr[nx][ny] == 0)
				{
					visit[nx][ny] = visit[x][y] + 1;
					q.push_back({ nx,ny });
				}
			}
		}
	}
	if (visit[pv[num].destx][pv[num].desty] == -1) return false;
	if (k - cnt - visit[pv[num].destx][pv[num].desty] < 0) return false;
	k = k - cnt + visit[pv[num].destx][pv[num].desty];
	return true;
}


bool bfs()
{
	int visit[22][22] = { 0, };
	int map[22][22] = { 0, };
	int cnt = 0;
	deque<pair<int, int>>q;
	vector<pair<int, int>> start;
	q.push_back({ tx,ty });
	memset(visit, -1, sizeof(visit));
	memcpy(map, arr, sizeof(arr));

	for (int i = 0; i < m; i++)
	{
		if (pv[i].flag == 0)
		{
			map[pv[i].x][pv[i].y] = i + 2;
		}
	}
	visit[tx][ty] = 0;
	bool flag = false;
	if (map[tx][ty] != 0 && map[tx][ty] != 1)
		start.push_back({tx,ty});
	while (!q.empty())
	{
		int qsize = q.size();
		if (!start.empty()) break;
		for (int t = 0; t < qsize; t++)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop_front();
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx<1 || nx>n || ny<1 || ny>n) continue;
				if (visit[nx][ny] == -1)
				{
					if (map[nx][ny] == 0)
					{
						visit[nx][ny] = visit[x][y] + 1;
						q.push_back({ nx,ny });
					}
					else if (map[nx][ny] != 1)
					{
						visit[nx][ny] = visit[x][y] + 1;
						q.push_back({ nx,ny });
						start.push_back({ nx,ny });
						cnt = visit[nx][ny];
					}
				}
			}

		}
	}
	if (!start.empty())
	{
		sort(start.begin(), start.end());
		int num = 0;

		for (int i = 0; i < m; i++)
		{
			if (pv[i].x == start[0].first && pv[i].y == start[0].second)
			{
				num = i;
				pv[i].flag = 1;
				tx = pv[i].destx;
				ty = pv[i].desty;
				break;
			}
		}
		if (find(num, cnt)) return true;
	}
	return false;
}


int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}
	cin >> tx >> ty;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		pv.push_back({a,b,c,d,0});
	}
	int cnt = 0;
	while (1)
	{
		if (cnt == m) break;
		if (bfs())
			cnt++;
		else { 
			k = -1;
			break;
		}
	}
	cout << k << endl;
}