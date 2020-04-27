#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

int arr[21][21];
int n;
int ret=987654321;
int psum;

bool check(int x ,int y,int d1,int d2)
{
	if (x + d1 >= n || x + d2 >= n || x + d1 + d2 >= n) return false;
	if (y - d1 < 0 || y + d2 >= n || y - d1 + d2 < 0 || y - d1 + d2 >= n) return false;
	return true;
}

bool daegak(int x1, int y1, int x2, int y2, int x3, int y3)
{
	int bigx = max(x1, x2);
	int bigy = max(y1, y2);
	int minx = min(x1, x2);
	int miny = min(y1, y2);
	if (x3 >= minx && x3 <= bigx && y3 >= miny && y3 <= bigy && abs(x1 - x3) == abs(y1 - y3) && abs(x2-x3)==abs(y2-y3)) return true;
	return false;
}

int cal(int x, int y, int d1, int d2)
{
	vector<int>v(5, 0);
	int ssum = psum;
	for (int i = 0; i < x + d1; i++)
	{
		if (i < x) 
		{
			for (int j = 0; j <= y; j++)
				v[0] += arr[i][j];
		}
		else
		{
			for (int j = 0; j <= y; j++)
			{
				if (daegak(x,y,x+d1,y-d1,i,j)) break;
				v[0] += arr[i][j];
			}
		}
	}

	for (int i = 0; i <=x + d2; i++)
	{
		if (i < x) 
		{
			for (int j = y + 1; j < n; j++)
				v[1] += arr[i][j];
		
		}
		else {
			for (int j = n - 1; j >y; j--)
			{
				if (daegak(x, y, x + d2, y +d2, i, j)) break;
				v[1] += arr[i][j];
			}
		}
	}

	for (int i = x + d1; i < n; i++)
	{
		if (i > x + d1 + d2) {
			for (int j = 0; j < y - d1 + d2; j++)
				v[2] += arr[i][j];
		}
		else {
			for (int j = 0; j < y - d1 + d2; j++)
			{
				if (daegak(x+d1, y-d1, x + d1+d2, y - d1+d2, i, j))break;
				v[2] += arr[i][j];
			}
		}
	}

	for (int i = x + d2+1; i < n; i++)
	{
		if (i > x + d1 + d2) 
		{
			for (int j = y - d1 + d2; j < n; j++)
				v[3] += arr[i][j];
		}
		else {
			for (int j = n - 1; j > y - d1 + d2; j--)
			{
				if (daegak(x + d2, y +d2, x + d1 + d2, y - d1 + d2, i, j)) break;
				v[3] += arr[i][j];
			}
		}
	}
	for (int i = 0; i < 4; i++) ssum -= v[i];
	v[4] = ssum;
	sort(v.begin(), v.end());
	return v[4] - v[0];

}

void draw()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int d1 = 1; d1 < n; d1++)
			{
				for (int d2 = 1; d2 < n; d2++)
				{
					if (check(i,j,d1,d2))
					{
						ret = min(ret,cal(i,j,d1,d2));
					}
				}
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			psum += arr[i][j];
		}
	}
	draw();
	cout << ret << "\n";
}