#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(string s) {
    int answer = s.size();

    for (int i=1;i<=s.size()/2;i++)
    {
        int ret = s.size();
        vector<string> v;
        string temp;
        for (int j = 0; j < s.size(); j++)
        {
            temp += s[j];
            if (temp.size() == i)
            {
                v.push_back(temp);
                temp.clear();
            }
        }
        
        int vsize = v.size();
        for (int idx = 0; idx < vsize; idx++)
        {
            bool flag = false;
            int cnt = 0;
            for (int jdx = idx+1; jdx < vsize; jdx++)
            {
                if (v.at(idx).compare(v.at(jdx)) == 0)
                {
                    flag = true;
                    cnt++;
                }
                else
                {
                    idx = jdx-1;
                    break;
                }

                if (jdx == vsize - 1) idx = jdx;
            }
            if (cnt > 0)
            {
                if (cnt < 9)
                {
                    ret =ret- i * cnt + 1;
                }
                else if (cnt < 99)
                {
                    ret = ret - i * cnt + 2;
                }
                else {
                    ret = ret - i * cnt + 3;
                }
            }
        }
        answer = min(answer, ret);
       
    }
    //cout << answer << endl;
    return answer;
}

int main()
{
    string s;

        cin >> s;
        solution(s);


}