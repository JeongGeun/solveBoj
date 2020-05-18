#include <string>
#include <vector>
#include<iostream>
#include<utility>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<pair<int, int>> v[10];
    v[1].push_back({0,0});
    v[2].push_back({ 0,1 });
    v[3].push_back({ 0,2 });
    v[4].push_back({ 1,0 });
    v[5].push_back({ 1,1 });
    v[6].push_back({ 1,2 });
    v[7].push_back({ 2,0 });
    v[8].push_back({ 2,1 });
    v[9].push_back({ 2,2 });
    v[0].push_back({ 3,1 });
    int lx = 3;
    int rx = 3;
    int ly = 0;
    int ry = 2;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer += 'L';
            lx = v[numbers[i]][0].first;
            ly = v[numbers[i]][0].second;
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer += 'R';
            rx = v[numbers[i]][0].first;
            ry = v[numbers[i]][0].second;
        }
        else {
            int xx = v[numbers[i]][0].first;
            int yy = v[numbers[i]][0].second;
            if (abs(xx - lx) + abs(yy - ly) > abs(xx - rx) + abs(yy - ry))
            {
                answer += 'R';
                rx = v[numbers[i]][0].first;
                ry = v[numbers[i]][0].second;
            }
            else if (abs(xx - lx) + abs(yy - ly) < abs(xx - rx) + abs(yy - ry))
            {
                answer += 'L';
                lx = v[numbers[i]][0].first;
                ly = v[numbers[i]][0].second;
            }
            else
            {
                if (hand[0] == 'l')
                {
                    answer += 'L';
                    lx = v[numbers[i]][0].first;
                    ly = v[numbers[i]][0].second;
                }
                else {
                    answer += 'R';
                    rx = v[numbers[i]][0].first;
                    ry = v[numbers[i]][0].second;
                }
            }
        }
    }
    return answer;
}

