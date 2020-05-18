#include <string>
#include <vector>
#include <queue>
#include<iostream>
using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int m;
bool check(vector<vector<int>> temp, vector<vector<int>> lock)
{
    bool flag = true;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (lock[i][j] == 0)
            {
                if (temp[i][j] != 1)
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                if (temp[i][j] == 1)
                {
                    flag = false;
                    break;
                }
            }
        }
        if (!flag) break;
    }
    if (flag) return true;
    return false;
}

vector<vector<int>>move(vector<vector<int>> temp,int a,int b,int c,int d)
{
    vector<int>v;

    if (a < c)
    {
        c -= a;
        a =0;
    }
    else
    {
        a -= c;
        c =0;
    }

    if (b < d)
    {
        d -= b;
        b = 0;
    }
    else
    {
        b -= d;
        d = 0;
    }
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);

    for (int k = 0; k < 4; k++)
    {
        vector<vector<int>> tmp(30, vector<int>(30, 0));
        if (v[k])
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    int x = i + dx[k] * v[k];
                    int y = j + dy[k] * v[k];
                    if (x < 0 || x >= m || y < 0 || y >= m) continue;
                    tmp[x][y] = temp[i][j];
                }
            }
        }
        else tmp = temp;
        temp = tmp;
    }

    return temp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    m = lock.size();
    if (m == key.size())
    {
        int ff = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (lock[i][j])ff++;
                if (ff) break;
            }
            if (ff)break;
        }
        if (!ff) return true;
    }
    vector<vector<int>>map = key;
    for (int t = 0; t < 4; t++)
    {
        vector<vector<int>>temp = map;
        int ssize = temp.size();
        for (int i = 0; i < ssize; i++)
        {
            for (int j = 0; j < ssize; j++)
               temp[j][ssize-i-1]=map[i][j];
        }
        map = temp;
        vector<vector<int>> temp2(30, vector<int>(30, 0));
        for (int i = 0; i < ssize; i++)
        {   
            for (int j = 0; j < ssize; j++)
            {
                temp2[i][j] = temp[i][j];
            }
        }
        vector<vector<int>> temp3(30, vector<int>(30, 0));
        temp3 = temp2;
        bool f = false;
        for (int a = 0; a < m; a++)
        {
            for (int b = 0; b < m; b++)
            {
                for (int c = 0; c < m; c++)
                {
                    for (int d = 0; d <m; d++)
                    {
                        temp2 = move(temp2, a, b, c, d);
                        if (check(temp2, lock) == true) return true;
                        temp2 = temp3;                      
                    }
                }
            }
        }

    }
    return answer;
}

int main()
{
    vector<vector<int>>v;
    vector<vector<int>>v2;
    vector<int>p;
    p.push_back(1);
    p.push_back(1);
    p.push_back(1);
    v.push_back(p);
    p.clear();
    p.push_back(1);
    p.push_back(1);
    p.push_back(1);
    v.push_back(p);
    p.clear();
    p.push_back(1);
    p.push_back(1);
    p.push_back(1);
    v.push_back(p);
    p.clear();
    p.push_back(1);
    p.push_back(1);
    p.push_back(1);
    p.push_back(1);
    v2.push_back(p);
    p.clear();
    p.push_back(1);
    p.push_back(0);
    p.push_back(0);
    p.push_back(0);
    v2.push_back(p);
    p.clear();
    p.push_back(1);
    p.push_back(0);
    p.push_back(0);
    p.push_back(0);
    v2.push_back(p);
    p.push_back(1);
    p.push_back(0);
    p.push_back(0);
    p.push_back(0);
    v2.push_back(p);
    cout<<solution(v,v2)<<endl;
}