#include<iostream>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;

typedef pair<int, int> P;

struct sh
{
	int x;
	int y;
	int dir;
	int cnt;
};

vector<P>arr[4][4];
int ret;
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,-1,-1,-1,0,1,1,1};

void dfs(vector<P>map[4][4], int scnt, int sdir,int sx,int sy)
{
	vector<P>temp[4][4];
	//cout << scnt << endl;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			temp[i][j] = map[i][j];
	int visit[17] = { 0, };
	if (!temp[sx][sy].empty())
	{
		temp[sx][sy].pop_back();
	}
	for (int t = 1; t <= 16; t++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (!temp[i][j].empty()&&!visit[t])
				{
					if (temp[i][j][0].first == t)
					{
						int dir = temp[i][j][0].second;
						for (int d = dir; d < dir + 8; d++)
						{
							int k = d % 8;
							int nx = i + dx[k];
							int ny = j + dy[k];
							if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
							if (nx == sx && ny == sy) continue;
							if (!temp[nx][ny].empty()) {
								int tcnt = temp[nx][ny][0].first;
								int tdir = temp[nx][ny][0].second;
								temp[i][j].pop_back();
								temp[i][j].push_back({ tcnt,tdir });
								temp[nx][ny].pop_back();
								temp[nx][ny].push_back({ t,k });
							}
							else
							{
								temp[i][j].pop_back();
								temp[nx][ny].push_back({ t,k });
							}
							break;
						}
						visit[t] = 1;
					}
				}
			}
		}
	}

	for (int t = 1; t < 4; t++)
	{
		int nsx = sx + t*dx[sdir];
		int nsy = sy + t * dy[sdir];
		if (nsx < 0 || nsx >= 4 || nsy < 0 || nsy >= 4) continue;
		if (temp[nsx][nsy].empty()) continue;
		//cout << temp[nsx][nsy][0].first << endl;
		dfs(temp, scnt + temp[nsx][nsy][0].first, temp[nsx][nsy][0].second, nsx, nsy);
	}
	ret = max(scnt, ret);
}

int main()
{
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int a, b;
			cin >> a >> b;
			arr[i][j].push_back({a,--b});
			//shark[a].push_back({ i,j,b });
		}
	}
	int sharkNum = 0;
	int sharkDir = 0;
	sharkNum = arr[0][0][0].first;
	sharkDir = arr[0][0][0].second;
	arr[0][0].pop_back();
	ret = sharkNum;
	
	dfs(arr, sharkNum, sharkDir,0,0);
	cout << ret << endl;
}