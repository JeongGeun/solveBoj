#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<vector<int>>stk;
    vector<int>ans;
    for (int i = 0; i < board.size(); i++)
    {
        vector<int>v;
        for (int j = board.size()-1; j >=0; j--)
        {
            if(board[j][i])
            v.push_back(board[j][i]);
        }
        stk.push_back(v);
    }
    
    for (int i = 0; i < moves.size(); i++)
    {
        int k = moves[i] - 1;
        if (!stk[k].empty())
        {
            int a = stk[k].back();
            stk[k].pop_back();
            if (!ans.empty())
            {
                if (ans.back() == a) { 
                    ans.pop_back(); 
                    answer++;
                }
                else
                {
                    ans.push_back(a);
                }
            }
            else ans.push_back(a);
        }
    }

    return 2*answer;
}
int main()
{
    vector<vector<int>> bo = { {0, 0, 0, 0, 0
}, { 0, 0, 1, 0, 3
}, { 0, 2, 5, 0, 1
}, { 4, 2, 4, 4, 2
}, { 3, 5, 1, 3, 1
} };
    vector<int>m = {1, 5, 3, 5, 1, 2, 1, 4};
    solution(bo, m);
}