#include<iostream>

using namespace std;

char chess[51][51];
int N, M;

char W_start[8][8] = {'W','B','W','B','W','B','W','B',
                'B','W','B','W','B','W','B','W',
                'W','B','W','B','W','B','W','B',
                'B','W','B','W','B','W','B','W',
                'W','B','W','B','W','B','W','B',
                'B','W','B','W','B','W','B','W',
                'W','B','W','B','W','B','W','B',
                'B','W','B','W','B','W','B','W'};
char B_start[8][8] = { 'B','W','B','W','B','W','B','W',
                'W','B','W','B','W','B','W','B',
                'B','W','B','W','B','W','B','W',
                'W','B','W','B','W','B','W','B',
                'B','W','B','W','B','W','B','W',
                'W','B','W','B','W','B','W','B',
                'B','W','B','W','B','W','B','W',
                'W','B','W','B','W','B','W','B' };

int W_count(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (chess[x+i][y+j] != W_start[i][j])
            {
                cnt++;
            }
        }
    }

    return cnt;
}
int B_count(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (chess[x+i][y+j] != B_start[i][j])
            {
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> chess[i][j];
        }
    }

    int answer = 65;

    for (int i = 0; i < N - 7; i++)
    {
        for (int j = 0; j < M - 7; j++)
        {
            if (W_count(i, j) < B_count(i, j))
            {
                answer = W_count(i, j) <answer ? W_count(i, j) : answer;
            }
            else
            {
                answer = B_count(i, j) < answer ? B_count(i, j) : answer;
            }
        }
    }

    cout << answer;

}