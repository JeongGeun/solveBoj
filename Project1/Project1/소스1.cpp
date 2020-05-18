#include <string>
#include <vector>
#include <map>
#include<iostream>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;

//�� �������� ����ִ� �ε��� ť
deque<int> check[100001];
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int>m;
    vector<int>arr;
    int cnt = 1;
    //map���� string���� ���� ���鿡 1������ ��ȣ �ο��ؼ� int������ �ٲ���
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
    
    //check ť�� �� �������� �ε��� �ֱ�
    for (int i = 0; i < arr.size(); i++)
        check[arr[i]].push_back(i + 1);
    //���� üũ ť���� �������� ���� ���� ���� �ε��� ������ �� ����
    int mcnt = m.size();
    //������ �ε��� ����ϱ� ����
    int lx = -1;
    //�����̵� ������ ����
    priority_queue<pair<int,int>,vector<pair<int, int>>,greater<pair<int, int>>>q;
    for (int i = 1; i <= mcnt; i++)
    {
        q.push({ check[i][0] ,i});
        //���� ū �ε��� ����ϱ�
        lx = max(check[i][0], lx);
    }

    int ans = 1e9;
    //v1�� �Ÿ�ũ��,���� ���� �ε���, ���� ū �ε��� ������ ��
    vector<pair<int,pair<int, int>>>v1;

    while (1)
    {
        int tp = q.top().first;
        //���� �� ���� ������ �����Ѵٸ�
        if (ans >= lx - tp)
        {
            ans = lx-tp;
            v1.push_back({ ans,{tp,lx} });
        }
        //���� ���� �ε����� ���� ���� ������ȣ
        int x = q.top().second;
        q.pop();
        if (!check[x].empty())
        {
            //���� ���� ���� ���� �� ���� �ε����� �־���
            check[x].pop_front();
            //���� �ش��ϴ� ������ �� �ε����� ���ٸ� ������ ���� �� �� �����Ƿ� break;
            if (check[x].empty()) break;
            //�ƴ϶�� q�� �ְ� ���� ��� �ִ� q�� �ִ� ���� ū������ ũ�ٸ� lx�� �ٲ���
            q.push({ check[x][0] ,x });
            lx = max(lx, check[x][0]);
        }
 
    }
    //�ش� �Ǵ� �������� ���� ª�� �Ÿ�, ���� ���� �ε��� ������ sort
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