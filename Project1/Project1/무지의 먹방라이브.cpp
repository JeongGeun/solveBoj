#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int tlen = food_times.size();
    deque<pair<int, int>>v;

    for (int i = 0; i < food_times.size(); i++)
    {
        v.push_back({ food_times[i],i + 1 });
    }

    int m = k / tlen;
    int res = k % tlen;
    long long tk = k;

    sort(v.begin(), v.end());
    int cnt = 0;
    
    while(!v.empty())
    {
        int a=v[0].first - cnt;

        if (tk < (long long)a * tlen)
        {
            tk %= tlen;
            break;
        }
        if (a<= 0)
        {
            v.pop_front();
            tlen--;
        }
        else
        {
            tk -= (long long)tlen * a;
            tlen--;
            cnt = v[0].first;
            v.pop_front();
        }
    }
    if (v.size() == 0) return - 1;

    vector<int> pq;
    for (int i = 0; i<(int)v.size(); i++)
    {
        pq.push_back(v[i].second);
    }
    
    sort(pq.begin(), pq.end());
    answer = pq[tk];
    cout << answer << endl;
    return answer;
}

int main()
{
    vector<int> f = {1,4,9,17};
    solution(f, 9);
}