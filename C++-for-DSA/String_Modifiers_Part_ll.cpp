#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s = "Hi";
    string s2 = "hello ";
    s = s2;
    //s.assign("gello");
    //s.erase(3,1);
    s.replace(6,0,"Jaren");
    s.insert(6,"Aminur ");
    cout << s << endl;
    return 0;
}