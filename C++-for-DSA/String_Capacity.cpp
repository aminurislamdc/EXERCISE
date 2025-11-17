#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s = "hello  world fhhfhfghfhfhh";
    //s.clear();
    //s.resize(7);
    s.resize(30,'J');

    cout << s << endl;
    if (s.empty()==true)
    {
        cout << "Empty" << endl;
    }
    else
    {
        cout << "not Empty" << endl;
    }
    
    
    //cout << s.size() << endl;
    //cout << s.max_size() << endl;
    cout << s.capacity() << endl;
    
    
    
}