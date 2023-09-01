#include <string>
#include <vector>
#include<cmath>
#include<iostream>
using namespace std;

bool visited[8];
int result = 0;

int dfs(int cnt, int k, vector<vector<int>> dungeons)
{
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (!visited[i] && k >= dungeons[i][0])
        {
            visited[i] = true;
            dfs(cnt + 1, k - dungeons[i][1], dungeons);
            visited[i] = false;
        }
    }
    result = max(cnt, result);
    return result;
}

int solution(int k, vector<vector<int>> dungeons) {
    return dfs(0, k, dungeons);
}

int main()
{
    vector<vector<int>> dungeons = {
        {80,20},
        {50,40},
        {30,10}
    };
    cout<<solution(80, dungeons);

}