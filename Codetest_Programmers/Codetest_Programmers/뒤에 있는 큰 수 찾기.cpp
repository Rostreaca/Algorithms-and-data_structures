//https://school.programmers.co.kr/learn/courses/30/lessons/154539 problem
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack <pair<int, int>> s;
    s.push(make_pair(numbers[0], 0));

    for (int i = 1; i < numbers.size(); i++)
    {
        while (!s.empty() && s.top().first < numbers[i])
        {
            int idx = s.top().second;
            answer[idx] = numbers[i];
            s.pop();
        }
        s.push(make_pair(numbers[i], i));
    }

    return answer;
}

void main() //verify
{
    vector<int> n = { 1,3,5,5 };

    for (int i : solution(n))
    {
        cout << i;
    }
}