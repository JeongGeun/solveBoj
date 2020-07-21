#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<set>
#include<string.h>
#include<map>
using namespace std;

bool kflag;
int ans;
vector<string>len2[10001];
vector<pair<int,string>>query[10001];
int qu[100001];
struct Trie {
    Trie* next[26];
    int cnt;
    set<int>cnext;
    bool finish;

    Trie()
    {
        memset(next, 0, sizeof(next));
        cnt = 0;
        finish = false;
    }
    ~Trie()
    {
        for (int i = 0; i < 26; i++)
            if (next[i]) delete next[i];
    }
    void insert(char* key)
    {
        if (*key == '\0')
            finish = true;
        else {
                int cur = *key - 'a';
                cnt++;
                cnext.insert(cur);
                if (next[cur] == NULL)
                    next[cur] = new Trie();
                next[cur]->insert(key + 1);
         }
    }
    void find(char* key)
    {
        //if (finish)
        //{
          //  if(*(key)=='\0') ans++;
           // return;
       // }
        //if (*key == '\0') return;
        if (*key == '?')
        {
            ans = cnt;
            return;
        }
        else
        {
            int cur = *key - 'a';
            if (next[cur])
                next[cur]->find(key + 1);
        }
    
    
    }


};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer(queries.size(),0);
    set<int>len;
    for (int i = 0; i < words.size(); i++)
    {
        len2[words[i].size()].push_back(words[i]);
        len.insert(words[i].size());
    }

    for (int i = 0; i < queries.size(); i++)
    {
        query[queries[i].size()].push_back({ i,queries[i] });
    }

    for (auto i = len.begin(); i != len.end(); i++)
    {
        Trie* root = new Trie();
        for (int j = 0; j < len2[*i].size(); j++)
        {
            root->insert(&len2[*i][j][0]);
            reverse(len2[*i][j].begin(), len2[*i][j].end());
        }
        int llen = *i;
        for (int j = 0; j < query[*i].size(); j++)
        {
            if (query[*i][j].second[llen-1] == '?')
            {
                ans = 0;
                root->find(&query[*i][j].second[0]);
                answer[query[*i][j].first] = ans;
            }
            reverse(query[*i][j].second.begin(), query[*i][j].second.end());
        }
        delete root;
    }
  
    for (auto i = len.begin(); i != len.end(); i++)
    {
        Trie* root = new Trie();
        for (int j = 0; j < len2[*i].size(); j++)
        {
            root->insert(&len2[*i][j][0]);
        }
        int llen = *i;
        for (int j = 0; j < query[*i].size(); j++)
        {
            if (query[*i][j].second[llen - 1] == '?')
            {
                ans = 0;
                root->find(&query[*i][j].second[0]);
                answer[query[*i][j].first] = ans;
            }
        }
        delete root;
    }
    for (int i = 0; i < answer.size(); i++) cout << answer[i] << endl;
    return answer;
}

int main()
{
    vector<string>words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
    vector<string>queries = { "fro??","????o", "fr???", "fro???", "pro?"};
    solution(words, queries);
}   
