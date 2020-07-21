#include<iostream>
#include<algorithm>
using namespace std;

long long int arr[10001];
int main()
{

	int n, k;
	cin >> n >> k;
	long long int maxNumber = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		maxNumber = max(arr[i],maxNumber);
	}

	long long int start = 1;
	long long int end = maxNumber;
	long long int ret = 0;
	while (start <= end)
	{
		long long int mid = (start + end) / 2;
		long long int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			cnt += (arr[i]/mid);
			if (cnt >= k)
			{
				start = mid + 1;
				ret = max(ret, mid);
				break;
			}
		}

		if (cnt < k)
		{
			end = mid - 1;
		}
	}
	cout << ret << "\n";



}