#include<iostream>
using namespace std;

int arr[10002];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int start = 0;
	int end = 0;
	int sum = 0;
	int cnt = 0;
	while (end <= n)
	{
		if (sum < m)
		{
			sum += arr[end++];
		}
		else if(sum>m)
		{
			sum -= arr[start++];
		}
		else
		{
			cnt++;
			sum += arr[end++];
		}
	}
	
	cout << cnt << "\n";




}