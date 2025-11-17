#include<iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        cout << "saturday\n";
        break;
    case 2:
        cout << "sunday\n";
        break;
    case 3:
        cout << "monday\n";
        break;
    case 4:
        cout << "tuesday\n";
        break;
    case 5:
        cout << "wednesday\n";
        break;
    case 6:
        cout << "thurestday\n";
        break;
    case 7:
        cout << "friday\n";
        break;
    default:
        cout << "worng\n";
    }

    

    return 0;
}