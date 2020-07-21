#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<utility>
#include<queue>
using namespace std;

struct sh {
	int x;
	int y;
	int num;
	int dir;
	int pdir;
	bool flag=false;
};

int arr[21][21];
pair<int,int> visit[21][21];
int n, m, k;
int dx[] = {-1,1,0,0};
int dy[] = { 0,0,-1,1 };
vector<vector<vector<int>>>fdir;
vector<sh>shark;

void play()
{
	vector<int>map[21][21];

	for (int i = 0; i < shark.size(); i++)
	{
		if (!shark[i].flag)
		{
			visit[shark[i].x][shark[i].y] = { shark[i].num,k };
		}
	}
	for (int i = 0; i < shark.size(); i++)
	{
		if (!shark[i].flag)
		{
			int x = shark[i].x;
			int y = shark[i].y;
			int dir = shark[i].dir;
			int num = shark[i].num;
			int pdir = shark[i].pdir;
			bool flag = false;
			for (int d = 0; d < 4; d++)
			{
				int nx = x + dx[fdir[num-1][dir][d]];
				int ny = y + dy[fdir[num - 1][dir][d]];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (!visit[nx][ny].first)
				{
					flag = true;
					map[nx][ny].push_back(num);
					shark[i].x = nx;
					shark[i].y = ny;
					shark[i].dir = fdir[num - 1][dir][d];
					break;
				}
			}

			if (!flag)
			{
				for (int d = 0; d < 4; d++)
				{
					int nx = x + dx[fdir[num - 1][dir][d]];
					int ny = y + dy[fdir[num - 1][dir][d]];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (visit[nx][ny].first==num)
					{
						map[nx][ny].push_back(num);
						shark[i].x = nx;
						shark[i].y = ny;
						shark[i].dir = fdir[num - 1][dir][d];
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j].size() >= 2)
			{
				sort(map[i][j].begin(), map[i][j].end());
				for (int a = 1; a < map[i][j].size(); a++)
				{
					shark[map[i][j][a] - 1].flag = true;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j].second)
				visit[i][j].second--;
			
			if (visit[i][j].second == 0) visit[i][j].first = 0;
		}
	}

}

bool check()
{
	int cnt = 0;
	for (int i = 0; i < shark.size(); i++)
	{
		if (!shark[i].flag) cnt++;
	}
	if (cnt == 1) return true;
	return false;
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		sh s;
		int dir;
		cin >> dir;
		s.dir = --dir;
		s.pdir = -1;
		s.num = i + 1;
		shark.push_back(s);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j])
			{
				shark[arr[i][j] - 1].x = i;
				shark[arr[i][j] - 1].y = j;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		vector<vector<int>>vv;
		for (int a = 0; a < 4; a++)
		{
			vector<int>v;
			for (int j = 0; j < 4; j++)
			{
				int a;
				cin >> a;
				v.push_back(--a);
			}
			vv.push_back(v);
		}
		fdir.push_back(vv);
	}
	int time = 0;
	while (1)
	{
		time++;

		if (time > 1000)
		{
			time = -1;
			break;
		}
		play();
		if (check())
		{
			break;
		}

	}
	cout << time << endl;

}