#include <vector>
#include <iostream>
#include <queue>
#include<string>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    queue<int> q;

    q.push(arr[0]);

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != q.front())
        {
            answer.push_back(q.front());
            q.pop();
            q.push(arr[i]);
        }
    }

    answer.push_back(arr[arr.size() - 1]);
    return answer;
}

void main() //verify
{
    vector<int> n = {  1,1,3,3,0,1,1  };


    for (int i : solution(n))
    {
        cout << i;
    }
}