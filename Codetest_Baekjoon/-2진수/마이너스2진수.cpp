#include <iostream>
#include <algorithm>

using namespace std;

string toBinary(int n)
{
    string dec;
    while (n != 0)
    {
        if (n % -2 == 0)
        {
            dec += "0";
            n = (n / -2);
        }
        else
        {
            dec += "1";
            n = (n - 1) / -2;
        }
    }
    reverse(dec.begin(), dec.end());
    return dec;
}
int main()
{
    int n;
    cin >> n;

    if (n == 0)
    {
        cout << "0";
    }
    string answer = toBinary(n);

    cout << answer;
}