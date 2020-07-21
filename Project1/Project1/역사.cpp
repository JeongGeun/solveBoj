#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k;
int dist[401][401];

int main()
{
	cin >> n >> k;
	for (int i = 0; i < 401; i++)
	{
		for (int j = 0; j < 401; j++)
		{
			if(i!=j)
			dist[i][j] = 1e9;
		}
	}

	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
	}
	
	for (int a = 1; a <= n; a++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j<= n; j++)
				dist[i][j] = min(dist[i][j],dist[i][a]+dist[a][j]);
	
	
	
	int num = 0;
	cin >> num;
	
	for (int i = 0; i < num; i++)
	{
		int a, b;
		cin >> a >> b;
		if (dist[a][b] != 1e9)
		{
			cout << "-1\n";
		}
		else if (dist[b][a] != 1e9)
		{
			cout << "1\n";
		}
		else cout << "0\n";
	}

}