#include <string>
#include <vector>
#include <map>
#include<iostream>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;

//각 보석들이 들어있는 인덱스 큐
deque<int> check[100001];
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int>m;
    vector<int>arr;
    int cnt = 1;
    //map으로 string으로 들어온 값들에 1번부터 번호 부여해서 int형으로 바꿔줌
    for (int i = 0; i < gems.size(); i++)
    {
        if (m.count(gems[i]))
        {
            arr.push_back(m[gems[i]]);
        }
        else
        {
            m[gems[i]] = cnt;
            arr.push_back(m[gems[i]]);
            cnt++;
        }
    }
    
    //check 큐에 각 보석별로 인덱스 넣기
    for (int i = 0; i < arr.size(); i++)
        check[arr[i]].push_back(i + 1);
    //현재 체크 큐에는 보석별로 값이 가작 작은 인덱스 순으로 들어가 있음
    int mcnt = m.size();
    //마지막 인덱스 기억하기 위해
    int lx = -1;
    //슬라이딩 윈도우 시작
    priority_queue<pair<int,int>,vector<pair<int, int>>,greater<pair<int, int>>>q;
    for (int i = 1; i <= mcnt; i++)
    {
        q.push({ check[i][0] ,i});
        //제일 큰 인덱스 기억하기
        lx = max(check[i][0], lx);
    }

    int ans = 1e9;
    //v1에 거리크기,가장 작은 인덱스, 가장 큰 인덱스 순으로 들어감
    vector<pair<int,pair<int, int>>>v1;

    while (1)
    {
        int tp = q.top().first;
        //만약 더 작은 구간이 존재한다면
        if (ans >= lx - tp)
        {
            ans = lx-tp;
            v1.push_back({ ans,{tp,lx} });
        }
        //제일 작은 인덱스의 값을 가진 보석번호
        int x = q.top().second;
        q.pop();
        if (!check[x].empty())
        {
            //제일 작은 값을 빼고 그 다음 인덱스를 넣어줌
            check[x].pop_front();
            //만약 해당하는 보석에 더 인덱스가 없다면 조건을 만족 할 수 없으므로 break;
            if (check[x].empty()) break;
            //아니라면 q에 넣고 현재 들어 있는 q에 있는 제일 큰값보다 크다면 lx값 바꿔줌
            q.push({ check[x][0] ,x });
            lx = max(lx, check[x][0]);
        }
 
    }
    //해당 되는 구간들을 가장 짧은 거리, 가장 작은 인덱스 순으로 sort
    sort(v1.begin(), v1.end());
    answer.push_back(v1[0].second.first);
    answer.push_back(v1[0].second.second);
 
    return answer;
}

int main()
{
    string s[8] = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
    vector<string> v;
    v.push_back("DIA");
    v.push_back("RUBY");
    v.push_back("RUBY");
    v.push_back("DIA");
    v.push_back("DIA");
    v.push_back("EMERALD");
    v.push_back("SAPPHIRE");
    v.push_back("DIA");
    solution(v);

}