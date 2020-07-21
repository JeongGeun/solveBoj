#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> PI;
int arr[126][126];
int visit[126][126];
int dx[] = {1,0,-1,0};
int dy[] = { 0,1,0,-1 };

int bfs(int n)
{
	priority_queue<PI, vector<PI>, greater<PI>> q;
	q.push({ arr[0][0],{0,0} });
	visit[0][0] = 1;
	int res = 0;
	while (!q.empty())
	{
		int x = q.top().second.first;
		int y = q.top().second.second;
		int cnt = q.top().first;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (!visit[nx][ny])
			{
				if (nx == n - 1 && ny == n - 1)
				{
					res = cnt + arr[nx][ny];
					visit[nx][ny] = 1;
					break;
				}
				visit[nx][ny] = 1;
				q.push({ cnt + arr[nx][ny],{nx,ny} });
			}
		}
		if (visit[n-1][n-1]) break;
	}
	return res;
}

int main()
{
	int num;
	int cnt = 1;
	
	while (1)
	{
		cin >> num;
		if (num == 0) break;
		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));

		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				cin >> arr[i][j];
			}
		}
		cout <<"Problem "<<cnt++<<": " <<bfs(num) << endl;
	}

}