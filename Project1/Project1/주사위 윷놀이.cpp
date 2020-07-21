#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int arr[30][30];
int chk[30][30];
vector<int> num;
vector<int> v;
int ans;

int play()
{
	memset(chk, -1, sizeof(chk));
	int cnt = 0;
	vector<pair<int, int>> q;
	q.push_back({0,0});
	q.push_back({ 0,0 });
	q.push_back({ 0,0 });
	q.push_back({ 0,0 });

	for (int i = 0; i < 10; i++)
	{
		int x = q[v[i]].first + num[i];
		int y = q[v[i]].second + num[i];
		if (arr[q[v[i]].first][q[v[i]].second] == 0)
		{
			cnt = 0;
			break;
		}
		
		if (q[v[i]].first == 5 || q[v[i]].first == 10 || q[v[i]].first == 15)
		{
			if (arr[q[v[i]].first][y] != 0 && chk[q[v[i]].first][y] != -1)
			{
				cnt = 0;
				break;
			}
			if (arr[q[v[i]].first][y] == 25)
			{
				if (chk[5][4] != -1 || chk[15][4] != -1 || chk[10][3] != -1)
				{
					cnt = 0;
					break;
				}

			}
			else if (arr[q[v[i]].first][y] == 30)
			{
				if (chk[5][5] != -1 || chk[15][5] != -1 || chk[10][4] != -1)
				{
					cnt = 0;
					break;
				}
			}
			else if (arr[q[v[i]].first][y] == 35)
			{
				if (chk[5][6] != -1 || chk[15][6] != -1 || chk[10][5] != -1)
				{
					cnt = 0;
					break;
				}
			}
			else if (arr[q[v[i]].first][y] == 40)
			{
				if (chk[5][7] != -1 || chk[15][7] != -1 || chk[10][6] != -1||chk[20][0]!=-1)
				{
					cnt = 0;
					break;
				}
			}
			chk[q[v[i]].first][q[v[i]].second] = -1;
			chk[q[v[i]].first][y] = v[i];
			q[v[i]].second = y;
			cnt += arr[q[v[i]].first][y];
		}
		else
		{
			if (arr[x][0] !=0 && chk[x][0] != -1)
			{
				cnt = 0;
				break;
			}
			if (arr[x][0] == 40)
			{
				if (chk[5][7] != -1 || chk[15][7] != -1 || chk[10][6] != -1 || chk[20][0] != -1)
				{
					cnt = 0;
					break;
				}
			}
			chk[x][0] = v[i];
			chk[q[v[i]].first][0] = -1;
			q[v[i]].first = x;
			cnt+= arr[x][0];
		}
	
	}

	return cnt;
}


void dfs()
{
	if (v.size() == 10)
	{
		ans=max(ans,play());
		return;
	}
	else if (v.size() < 10)
	{
		v.push_back(0);
		dfs();
		v.pop_back();
		v.push_back(1);
		dfs();
		v.pop_back();
		v.push_back(2);
		dfs();
		v.pop_back();
		v.push_back(3);
		dfs();
		v.pop_back();
	}



}


int main()
{
	memset(arr, 0, sizeof(arr));
	arr[0][0] = -1;
	for (int i = 0; i < 10; i++)
	{
		int a;
		cin >> a;
		num.push_back(a);
	}
	for (int i = 1; i <= 20; i++)
		arr[i][0] = i * 2;
	arr[5][1] = 13;
	arr[5][2] = 16;
	arr[5][3] = 19;
	arr[5][4] = 25;
	arr[5][5] = 30;
	arr[5][6] = 35;
	arr[5][7] = 40;

	arr[10][1] = 22;
	arr[10][2] = 24;
	arr[10][3] = 25;
	arr[10][4] = 30;
	arr[10][5] = 35;
	arr[10][6] = 40;
	
	arr[15][1] = 28;
	arr[15][2] = 27;
	arr[15][3] = 26;
	arr[15][4] = 25;
	arr[15][5] = 30;
	arr[15][6] = 35;
	arr[15][7] = 40;

	dfs();
	cout << ans << endl;
}