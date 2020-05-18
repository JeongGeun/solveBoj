#include <string>
#include <vector>
#include<queue>
using namespace std;

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    vector<int>graph[200001];
    vector<int>adj[200001];
    int indegree[200001];
    
    for (int i = 0; i < path.size(); i++)
    {
        graph[path[i][0]].push_back(path[i][1]);
        graph[path[i][1]].push_back(path[i][0]);
    }
    for (int i = 0; i < order.size(); i++)
    {
        adj[order[i][0]].push_back(order[i][1]);
        indegree[order[i][1]]++;
    }
    deque<int>q;
    vector<int>ans;
    q.push_back(0);
    for (int i = 0; i < n; i++)
    {
        if (q.empty())
        {
            return false;
        }
        int cur = q.front();
        q.pop_front();
        for (auto h : graph[cur])
        {
            if (indegree[h] == 0)
            {
                q.push_back(h);
                for (auto a : adj[h])
                {
                    indegree[a]--;
                }
            }
        }
    }
    return answer;
}