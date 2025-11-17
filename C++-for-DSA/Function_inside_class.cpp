#include<bits/stdc++.h>
using namespace std;
class student
{
    public:
    string name;
    int roll;
    student(string name,int roll)
    {
        this->name = name;
        this->roll = roll;
    }
    void hello()
{
    cout << aminur.name << endl;
}
}

int main()
{
    student aminur("aminur Islam",21);
    aminur.hello();
    return 0;
}