#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

struct horse
{
	int x;
	int y;
	int dir;

};

int n, k;
deque<int> arr[14][14];
int map[14][14];
vector<horse> ho;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0}; 

bool white(int x,int y,int nx,int ny,int id)
{
	vector<int>v;
	bool flag = false;
	for (int i = 0; i < arr[x][y].size(); i++)
	{
		if (id == arr[x][y][i])
		{
			flag = true;
		}
		if (flag)
		{
			v.push_back(arr[x][y][i]);
		}
	}

	for (int i = 0; i < (int)v.size(); i++)
	{
		if (!arr[x][y].empty())
		arr[x][y].pop_back();
	}

	for (int i = 0; i < v.size(); i++)
	{
		arr[nx][ny].push_back(v[i]);
		ho[(v[i] - 1)].x = nx;
		ho[(v[i] - 1)].y = ny;
	}
	if (arr[nx][ny].size() >= 4) return true;

	return false;
}

bool red(int x, int y, int nx, int ny, int id)
{
	vector<int>v;
	bool flag = false;
	int cnt = 0;
	for (int i = arr[x][y].size() - 1; i >= 0; i--)
	{
		if (!flag)
		{
			v.push_back(arr[x][y][i]);
		
		}
		
		if (id == arr[x][y][i])
		{
			flag = true;
		}
	}
	for (int i = 0; i < (int)v.size(); i++)
	{
		if(!arr[x][y].empty())
		arr[x][y].pop_back();
	}
	

	for (int i = 0; i < v.size(); i++)
	{
		arr[nx][ny].push_back(v[i]);
		ho[(v[i] - 1)].x = nx;
		ho[(v[i] - 1)].y = ny;
	}
	if (arr[nx][ny].size() >= 4) return true;
	
	return false;
}
bool play()
{
	for (int idx = 0; idx < ho.size(); idx++)
	{
		int x = ho[idx].x;
		int y = ho[idx].y;
		int dir = ho[idx].dir;

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx <= 0 || nx > n || ny <= 0 || ny > n)
		{
			int rdir = 0;
			if (dir == 0) rdir = 1;
			else if (dir == 1) rdir = 0;
			else if (dir == 2) rdir = 3;
			else if (dir == 3) rdir = 2;

			int rx = x + dx[rdir];
			int ry = y + dy[rdir];
			ho[idx].dir = rdir;
			if (rx <= 0 || rx > n || ry <= 0 || ry > n) continue;
			if (map[rx][ry] != 2)
			{
				if (map[rx][ry] == 0)
				{
					if(white(x, y, rx, ry, idx + 1)) return true;
				}
				else
				{
					if(red(x, y, rx, ry, idx + 1)) return true;
				}
			}
			//ho[idx].dir = rdir;
			continue;
		}
		if (map[nx][ny] == 0)
		{
			if(white(x,y,nx,ny,idx+1)) return true;
		}
		else if (map[nx][ny] == 1)
		{
			if(red(x, y, nx, ny, idx + 1)) return true;
		}
		else
		{
			int rdir = 0;
			if (dir == 0) rdir = 1;
			else if (dir == 1) rdir = 0;
			else if (dir == 2) rdir = 3;
			else if (dir == 3) rdir = 2;

			int rx = x + dx[rdir];
			int ry = y + dy[rdir];
			ho[idx].dir = rdir;
			if (rx <= 0 || rx > n || ry <= 0 || ry > n) continue;

			if (map[rx][ry] != 2)
			{
				if (map[rx][ry] == 0)
				{
					if(white(x, y, rx, ry, idx + 1)) return true;
				}
				else
				{
					if(red(x, y, rx, ry, idx + 1)) return true;
				}
			}
			
		}

	}
	return false;
}


int main()
{
	cin >> n >> k;
	for (int i =1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	}
	for (int i = 0; i < k; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		ho.push_back({x,y,--z});
		arr[x][y].push_back(i+1);
	}
	int time = 1;
	while (1)
	{
		if (time > 1000) { 
			time = -1;
			break; 
		}
		if (play())
		{
			break;
		}
		time++;
	}
	cout << time << endl;
}



