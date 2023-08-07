#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for (int i = 0; i < arr1.size(); i++)
    {
        vector<int> arr;
        for (int j = 0; j < arr1[i].size(); j++)
        {
            arr.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(arr);
    }

    return answer;
}

int main()
{

    vector<vector<int>> arr1 = { {1 , 2},{ 2, 3 } }; 
    vector<vector<int>> arr2 = { {3 , 4},{ 5, 6 } };
    vector<vector<int>> answer = solution(arr1,arr2);


    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr1[i].size(); j++)
        {
            cout <<"["<< answer[i][j] << "]";
        }
    }
}