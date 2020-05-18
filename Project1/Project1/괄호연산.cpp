#include <string>
#include <vector>
using namespace std;

string solution(string p) {
    string u, v;
    int lcnt = 0;
    int rcnt = 0;
    vector<char>v1;
    vector<char>v2;
    if (p.size() == 0) return p;
    
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == '(') 
        {
            lcnt++; 
            v1.push_back('(');
        }
        if (p[i] == ')') { 
            rcnt++; 
            if (!v1.empty()) v1.pop_back();
            else {
                v2.push_back(')');
            }
         
        }
        u += p[i];
        if (lcnt == rcnt)
        {
            break;
        }
    }

    for (int i = lcnt + rcnt; i < p.size(); i++)
        v += p[i];
    if (v1.empty() && v2.empty())
    {
        return u + solution(v);
    }
    else
    {
        string temp;
        for (int i = 1; i < u.size() - 1; i++)
        {
            if (u[i] == '(') temp += ')';
            else temp += '(';
        }
        return "(" + solution(v) + ")" + temp;
    }
   
}

int main()
{
    cout << solution("(()())()") << endl;
    cout << solution(")(") << endl;
    cout << solution("()))((()") << endl;
}