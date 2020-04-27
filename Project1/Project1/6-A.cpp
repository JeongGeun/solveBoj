#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<string.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	for (int t = 0; t < n; t++)
	{
		string v;
		string a;
		string b;
		cin >> a >> b;
		int idx = 0;
		
		if (a.length() <= b.length())
		{
			if (stoi(a) < stoi(b))
			{
				cout << "0\n";
				continue;
			}
		}

		for (int i = 0; i < b.size(); i++)
		{
			v+=a[idx++];
		}

		while (1)
		{

			string s;
			s = v;
	
			int remain = stoi(s)-stoi(b);
			if (idx == a.length())
			{
				if (remain% stoi(b) == 0)
				{
					cout << "1\n";
				}
				else
				{
					cout << "0\n";
				}
				break;
			}
			if (remain >= 0)
			{
				int cnt = v.size();
				v.clear();
				for (int i = 0; i < cnt; i++)
				{
					int d = remain % 10;
					remain /= 10;
					v+=(d + '0');
				}
				reverse(v.begin(), v.end());
			}
			else
			{
				v+=a[idx++];
			}

		}
	}
}