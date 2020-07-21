#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int arr[11][11];
int bcnt, gcnt;

void gcal(int t, int x, int y)
{
	bool flag = false;
	int cnt = 0;
	if (t == 1)
	{
		int nx = 0, ny = 0;
		for (int i = 4; i <= 9; i++)
		{
			if (!arr[i][y])
			{
				nx = i;
				ny = y;
			}
			else break;
		}
		arr[nx][ny] = 1;
	}
	else if (t == 2)
	{
		int nx = 0, ny = 0, nx2 = 0, ny2 = 0;
		for (int i = 4; i <= 9; i++)
		{
			if (!arr[i][y] && !arr[i][y + 1])
			{
				nx = i;
				ny = y;
				nx2 = i;
				ny2 = y + 1;
			}
			else break;
		}
		arr[nx][ny] = 1;
		arr[nx2][ny2] = 1;
	}
	else {
		int nx = 0, ny = 0, nx2 = 0, ny2 = 0;
		for (int i = 4; i <= 8; i++)
		{
			if (!arr[i][y] && !arr[i + 1][y])
			{
				nx = i;
				ny = y;
				nx2 = i + 1;
				ny2 = y;
			}
			else break;
		}
		arr[nx][ny] = 1;
		arr[nx2][ny2] = 1;
	}

	while (1)
	{
		int finish = 0;
		for (int k = 9; k > 5; k--)
		{
			int fl = 0;
			for (int j = 0; j < 4; j++)
			{
				if (!arr[k][j])
				{
					fl++;
					break;
				}
			}
			if (!fl)
			{
				finish++;
				for (int j = 0; j < 4; j++)
				{
					arr[k][j] = 0;
				}
				gcnt++;
			}
		}
		if (finish == 0)break;
		for (int j = 0; j < 4; j++)
		{
			for (int i = 8; i >= 4; i--)
			{
				int idx = i;
				if (arr[idx][j])
				{
					while (1)
					{
						if (idx == 9) break;
						if (arr[idx + 1][j])
						{
							break;
						}
						else
						{
							arr[idx + 1][j] = arr[idx][j];
							arr[idx][j] = 0;
							idx++;
						}
					}
				}

			}
		}
	}
	for (int i = 4; i <= 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j])
			{
				flag = true;
				cnt++;
				break;
			}
		}
	}
	if (flag)
	{
		for (int a = 0; a < cnt; a++)
		{
			for (int j = 0; j < 4; j++)
			{
				arr[9 - a][j] = 0;
			}
		}
		for (int j = 0; j < 4; j++)
		{
			for (int i = 8; i >= 4; i--)
			{
				if (arr[i][j])
				{
					arr[i + cnt][j] = arr[i][j];
					arr[i][j] = 0;
				}
			}
		}
	}
}

void bcal(int t, int x, int y)
{
	bool flag = false;
	int cnt = 0;
	if (t == 1)
	{
		int nx = 0, ny = 0;
		for (int i = 4; i <= 9; i++)
		{
			if (!arr[x][i])
			{
				nx = x;
				ny = i;
			}
			else break;
		}
		arr[nx][ny] = 1;
	}
	else if (t == 2)
	{
		int nx = 0, ny = 0, nx2 = 0, ny2 = 0;
		for (int i = 4; i <= 8; i++)
		{
			if (!arr[x][i] && !arr[x][i + 1])
			{
				nx = x;
				ny = i;
				nx2 = x;
				ny2 = i + 1;
			}
			else break;
		}
		arr[nx][ny] = 1;
		arr[nx2][ny2] = 1;

	}
	else
	{
		int nx = 0, ny = 0, nx2 = 0, ny2 = 0;
		for (int i = 4; i <= 9; i++)
		{
			if (!arr[x][i] && !arr[x + 1][i])
			{
				nx = x;
				ny = i;
				nx2 = x + 1;
				ny2 = i;
			}
			else break;
		}
		arr[nx][ny] = 1;
		arr[nx2][ny2] = 1;
	}
	while (1)
	{
		int finish = 0;
		for (int k = 9; k > 5; k--)
		{
			int fl = 0;
			for (int j = 0; j < 4; j++)
			{
				if (!arr[j][k])
				{
					fl++;
					break;
				}
			}
			if (!fl)
			{
				finish++;
				for (int j = 0; j < 4; j++)
				{
					arr[j][k] = 0;
				}
				bcnt++;
			}
		}
		if (finish == 0)break;
		for (int j = 0; j < 4; j++)
		{
			for (int i = 8; i >= 4; i--)
			{
				int idx = i;
				if (arr[j][idx])
				{
					while (1)
					{
						if (idx == 9) break;
						if (arr[j][idx + 1])
						{
							break;
						}
						else
						{
							arr[j][idx + 1] = arr[j][idx];
							arr[j][idx] = 0;
							idx++;
						}
					}
				}

			}
		}
	}

	for (int i = 4; i <= 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[j][i])
			{
				flag = true;
				cnt++;
				break;
			}
		}
	}

	if (flag)
	{
		for (int a = 0; a < cnt; a++)
		{
			for (int j = 0; j < 4; j++)
			{
				arr[j][9 - a] = 0;
			}
		}

		for (int j = 0; j < 4; j++)
		{
			for (int i = 8; i >= 4; i--)
			{
				if (arr[j][i])
				{
					arr[j][i + cnt] = arr[j][i];
					arr[j][i] = 0;
				}
			}
		}
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t, x, y;
		cin >> t >> x >> y;
		gcal(t, x, y);
		bcal(t, x, y);
	}
	cout << bcnt + gcnt << endl;
	int cnt = 0;
	for (int i = 6; i <= 9; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (arr[i][j]) cnt++;
		}
	}

	for (int i = 6; i <= 9; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (arr[j][i]) cnt++;
		}
	}
	cout << cnt << endl;
}