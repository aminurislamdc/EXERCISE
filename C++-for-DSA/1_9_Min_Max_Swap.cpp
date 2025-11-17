#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int x,y;
    cin >> x >> y;
    cout << max(x,y) << endl;
    cout << min(x,y) << endl;
    cout << max({10,20,30,40,50,60,70,80,90,100}) << endl;
    cout << min({10,20,30,40,50,60,70,80,90,100}) << endl;

    swap(x,y);
    cout << x << " " << y << endl;
    return 0;
}