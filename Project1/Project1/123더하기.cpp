#include<iostream>
using namespace std;

long long int arr[1000001];

int main()
{
	int t;
	cin >> t;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i < 1000001; i++)
	{
		arr[i] = (arr[i - 3] + arr[i - 2] + arr[i - 1])%1000000009;
	}
	
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		cout << arr[n] << endl;
	}


}