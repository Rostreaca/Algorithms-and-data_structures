#include<vector>
#include<queue>

using namespace std;

int n, m;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
bool visited[100][100];
queue<pair<int, int>> q;

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();

    visited[0][0] = true;
    q.push(make_pair(0, 0));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (!visited[nx][ny] && maps[nx][ny] > 0)
                {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                    maps[nx][ny] = maps[x][y] + 1;
                }
            }
        }
    }

    if (maps[n - 1][m - 1] == 1)
    {
        answer = -1;
    }
    else
    {
        answer = maps[n - 1][m - 1];
    }
    return answer;
}
