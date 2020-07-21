#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int visit[500];

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 1e9;
    deque<int>q;
    for (auto i : weak)
    {
        q.push_back(i);
    }
    
    for (int a = 0; a < q.size(); a++)
    {
        int top = q[0];
        q.pop_front();
        q.push_back(top+n);
        do {
            int didx = 0;
            memset(visit, 0, sizeof(visit));

            for (int i = 0; i < q.size(); i++)
            {
                int qk = q[i];
                qk %= n;
                if (!visit[qk])
                {
                    int rage = q[i] + dist[didx];
                    for (int j = i; j < q.size(); j++)
                    {
                        int k = q[j];
                        if (k <= rage)
                        {
                            k %= n;
                           visit[k] = 1;
                        }
                        else break;
                    }
                    didx++;
                }
            }
            if (didx > 0&&didx<=dist.size()) answer = min(didx, answer);
        } while (next_permutation(dist.begin(), dist.end()));
    }

    if (answer == 1e9) answer = -1;
    return answer;
}

int main()
{
    vector<int>weak = { 1,5,6,10 };
    vector<int>dist = { 1,2,3,4 };
    solution(12, weak, dist);
}