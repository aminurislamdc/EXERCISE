#include<bits/stdc++.h>
using namespace std;
int*  p;
void jannat()
{
    int* x = new int;
    *x = 10;
    p = x;
    cout << "jannat => " << *p << endl;
    return;
}
int main()
{

    
    jannat();
    cout << "main => " << *p << endl;
    return 0;

}