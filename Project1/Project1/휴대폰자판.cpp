#include<iostream>
#include<string.h>
#include<set>
using namespace std;
int ret;

struct Trie
{
	Trie* next[26];
	bool finish;
	set<int> nc;
	int cnt;

	Trie()
	{
		memset(next, 0, sizeof(next));
		finish = false;
		cnt = 0;
	}
	~Trie()
	{
		for (int i = 0; i < 26; i++)
			if (next[i]) delete next[i];
	}

	void insert(char* key)
	{
		if (*key == '\0')
		{
			finish = true;
		}
		else {
			int cur = *key - 'a';
			if (next[cur] == NULL)
			{
				next[cur] = new Trie();
			}
			cnt++;
			nc.insert(cur);
			next[cur]->insert(key + 1);

		}

	}
	void find(Trie* Root,Trie* Node)
	{
		if (Node!=NULL)
		{
			if (nc.size() > 1)
			{
				ret += cnt;
			}

			if (nc.size() == 1 && finish == true)
			{
				ret += cnt;
			}
		}
		for (auto i = nc.begin(); i != nc.end(); i++)
		{
			next[*i]->find(Root,next[*i]);
		}
	}
};


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int num = 0;
	cout << fixed;
	cout.precision(2);
	while (cin >> num)
	{
		Trie* root = new Trie();
		ret = 0;
		for (int i = 0; i < num; i++)
		{
			char key[82];
			cin >> key;
			root->insert(key);
		}

		root->find(root,NULL);
		double ans = (num+ret) / (double)num;
		cout << ans << endl;
		delete root;


	}
}