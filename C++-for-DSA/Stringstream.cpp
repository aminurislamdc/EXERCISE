#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    cout << s << endl;
    stringstream ss(s);
    string world;
    while (ss >> world)
    {
        cout << world << endl;
    }

    
    return 0;
}