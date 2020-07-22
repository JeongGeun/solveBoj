#include<iostream>
using namespace std;

int arr[6] = {5000000,3000000 , 2000000 ,500000,300000,100000 };
int arr2[5] = { 5120000,2560000,1280000,640000,320000 };

int main()
{
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		int a, b;
		int res = 0;
		cin >> a >> b;
		for (int j = 0; j < 6; j++)
		{
			int s = j;
			int e = j + 1;
			int ds = j * (e) / 2;
			int es = e * (e + 1) / 2;
			if (a > ds && es >= a)
			{
				res += arr[s];
				break;
			}
		}
		if (b == 0) res += 0;
		else if (b == 1) res += arr2[0];
		else if (b <= 3) res += arr2[1];
		else if (b <= 7) res += arr2[2];
		else if (b <= 15) res += arr2[3];
		else if (b <= 31) res += arr2[4];
		cout << res << endl;
	}

}