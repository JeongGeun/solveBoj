#include <string>
#include <vector>
#include <queue>
#include<iostream>
using namespace std;

struct loc {
    int lx;
    int ly;
    int rx;
    int ry;
    int dir1;
    int dir2;
};

int visit[101][101][4];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

vector<pair<int, int>> cd[4][4];

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    cd[0][1].push_back({-1,1});
    cd[1][0].push_back({ -1,1 });
    
    cd[1][2].push_back({ 1,1 });
    cd[2][1].push_back({ 1,1 });
    
    cd[2][3].push_back({1,-1});
    cd[3][2].push_back({ 1,-1 });
    
    cd[3][0].push_back({ -1,-1 });
    cd[0][3].push_back({ -1,-1 });

    deque<loc>q;
    q.push_back({0,0,0,1,1,3});
    visit[0][0][1]++;
    visit[0][1][3]++;
    while (!q.empty())
    {
        int qsize = q.size();
        bool flag = false;
        for (int i = 0; i < 4; i++)
        {
            if (visit[n - 1][n - 1][i]) flag = true;
        }
        if (flag) break;

        for (int t = 0; t < qsize; t++)
        {
            int lx = q.front().lx;
            int ly = q.front().ly;
            int rx = q.front().rx;
            int ry = q.front().ry;
            int dir1 = q.front().dir1;
            int dir2 = q.front().dir2;
            q.pop_front();
            for (int i = 0; i < 4; i++)
            {
                int nlx = lx + dx[i];
                int nly = ly + dy[i];
                int nrx = rx + dx[i];
                int nry = ry + dy[i];
                if (nlx < 0 || nlx >= n || nly < 0 || nly >= n)continue;
                if (nrx < 0 || nrx >= n || nry < 0 || nry >= n)continue;
                if (!visit[nlx][nly][dir1] && !visit[nrx][nry][dir2] && !board[nlx][nly] && !board[nrx][nry])
                {
                    visit[nlx][nly][dir1]++;
                    visit[nrx][nry][dir2]++;
                    q.push_back({ nlx,nly,nrx,nry,dir1,dir2 });
                }
            }
            int arr[2] = { 1,3 };
            for (int i = 0; i < 2; i++)
            {

                int ndir = dir1 + arr[i];
                int cdir = ndir + 2;
                ndir %= 4;
                cdir %= 4;
                int nlx = lx + dx[ndir];
                int nly = ly + dy[ndir];
                int nx = lx + cd[dir1][ndir][0].first;
                int ny = ly + cd[dir1][ndir][0].second;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (nlx < 0 || nlx >= n || nly < 0 || nly >= n)continue;
                if (!board[nx][ny]&&!board[nlx][nly])
                {
                    if (!visit[lx][ly][ndir] && !visit[nlx][nly][cdir])
                    {
                        visit[lx][ly][ndir]++;
                        visit[nlx][nly][cdir]++;
                        q.push_back({ lx,ly,nlx,nly,ndir,cdir });
                    }
                }
            }
            for (int i = 0; i < 2; i++)
            {

                int ndir = dir2 + arr[i];
                int cdir = ndir + 2;
                ndir %= 4;
                cdir %= 4;
                int nlx = rx + dx[ndir];
                int nly = ry + dy[ndir];
                int nx = rx + cd[dir2][ndir][0].first;
                int ny = ry + cd[dir2][ndir][0].second;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (nlx < 0 || nlx >= n || nly < 0 || nly >= n)continue;
                if (!board[nx][ny]&&!board[nlx][nly])
                {
                    if (!visit[rx][ry][ndir] && !visit[nlx][nly][cdir])
                    {
                        visit[rx][ry][ndir]++;
                        visit[nlx][nly][cdir]++;
                        q.push_back({ rx,ry,nlx,nly,ndir,cdir });
                    }
                }
            }
        }
        answer++;
    }
    return answer;
}

int main()
{
    vector<vector<int>>board = {{0, 0, 0, 1, 1}, { 0, 0, 0, 1, 0}, { 0, 1, 0, 1, 1}, { 1, 1, 0, 0, 1 }, { 0, 0, 0, 0, 0 }};
    solution(board);
}