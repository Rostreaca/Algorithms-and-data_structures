//https://school.programmers.co.kr/learn/courses/30/lessons/42747# problem
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int H_Index = 0;
    sort(citations.rbegin(), citations.rend());
    int h, cnt = 0;
    for (int h = citations[0]; h >= 0; h--)
    {
        for (int j = 0; j < citations.size(); j++)
        {
            if (citations[j] >= h)
            {
                cnt++;
            }
        }
        if (cnt >= h)
        {
            H_Index = h;
            return H_Index;
        }
        cnt = 0;
    }
    return H_Index;
}

void main() //verify
{
    vector<int> n = { 3, 0, 6, 1, 5 };

    cout << solution(n);
}