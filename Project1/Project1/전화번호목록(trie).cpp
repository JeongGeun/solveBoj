#include<iostream>
#include<string.h>
using namespace std;

struct Trie {
	Trie* next[10];
	bool finish;
	Trie() {
		memset(next, 0, sizeof(next));
		finish = false;
	}
	~Trie() {
		for (int i = 0; i < 10; i++)
		{
			if (next[i]) delete next[i];
		}
	}
	void insert(const char* key)
	{
		if (*key == '\0')
			finish = true;
		else {
			int cur = *key - '0';
			if (next[cur] == NULL)
				next[cur] = new Trie();
			next[cur]->insert(key + 1);
		}
	}
	bool find(const char* key)
	{
		if (*key == '\0') return false;
		if (finish) return true;
		int cur = *key - '0';
		return next[cur]->find(key + 1);
	}
};


int main()
{
	int tc = 0;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		int n;
		cin >> n;
		char phone[10001][11];
		Trie* root = new Trie;
		bool chk = true;
		for (int i = 0; i < n; i++)
		{
			cin >> phone[i];
		}
		for (int i = 0; i < n; i++)
		{
			root->insert(phone[i]);
		}
		for (int i = 0; i < n; i++)
		{
			if (root->find(phone[i])) { 
				chk = false; 
				break;
			}
		}
		if (!chk) cout << "NO\n";
		else cout << "YES\n";
		
		delete root;
	}
}