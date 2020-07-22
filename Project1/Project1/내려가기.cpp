#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int arr[100001][3];
int mindp[3];
int tdp[3];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	for (int j = 0; j < 3; j++)
	{
		tdp[j] = 1e9;
	}
	
	int min1 = 1e9;
	int max1 = 0;
	mindp[0] = arr[0][0];
	mindp[1] = arr[0][1];
	mindp[2] = arr[0][2];

	for (int i = 0;i < n-1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 0)
			{
				tdp[j] = min(tdp[j], mindp[j]+arr[i+1][j]);
				tdp[j+1] = min(tdp[j+1], mindp[j] + arr[i + 1][j+1]);

			}
			else if (j == 1)
			{
				tdp[j-1] = min(tdp[j-1], mindp[j] + arr[i + 1][j-1]);
				tdp[j] = min(tdp[j], mindp[j] + arr[i + 1][j]);
				tdp[j + 1] = min(tdp[j + 1], mindp[j] + arr[i + 1][j + 1]);

			}
			else
			{
				tdp[j - 1] = min(tdp[j - 1], mindp[j] + arr[i + 1][j - 1]);
				tdp[j] = min(tdp[j], mindp[j] + arr[i + 1][j]);
			}
			
		}
		for (int j = 0; j < 3; j++)
		{
			mindp[j] = tdp[j];
			tdp[j] = 1e9;
		}
	}
	for (int i = 0; i < 3; i++) min1 = min(mindp[i], min1);
	memset(mindp, 0, sizeof(mindp));
	memset(tdp, 0, sizeof(tdp));
	mindp[0] = arr[0][0];
	mindp[1] = arr[0][1];
	mindp[2] = arr[0][2];


	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 0)
			{
				tdp[j] = max(tdp[j], mindp[j] + arr[i + 1][j]);
				tdp[j + 1] = max(tdp[j + 1], mindp[j] + arr[i + 1][j + 1]);

			}
			else if (j == 1)
			{
				tdp[j - 1] = max(tdp[j - 1], mindp[j] + arr[i + 1][j - 1]);
				tdp[j] = max(tdp[j], mindp[j] + arr[i + 1][j]);
				tdp[j + 1] = max(tdp[j + 1], mindp[j] + arr[i + 1][j + 1]);

			}
			else
			{
				tdp[j - 1] = max(tdp[j - 1], mindp[j] + arr[i + 1][j - 1]);
				tdp[j] = max(tdp[j], mindp[j] + arr[i + 1][j]);
			}
		}
		for (int j = 0; j < 3; j++)
		{
			mindp[j] = tdp[j];
			tdp[j] = 0;
		}
	}
	
	
	for (int i = 0; i < 3; i++) max1 = max(mindp[i], max1);
	cout << max1 <<" " <<min1;
	
}