#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
        string output;
        for (char ch : s)
        {
            if (ch != ' ')
                output += ch;
        }
        sort(output.begin(), output.end());
        cout << output << endl;
    }
    return 0;
}