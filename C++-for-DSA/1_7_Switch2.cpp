#include<iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;
    switch (x%2)
    {
    case 0:
        cout << "Even\n";
        break;
    case 1:
        cout << "Odd\n";
        break;

    }

    char c;
    cin >> c;
    switch (c)
    {
    case 'a':
        cout << "Vowel\n";
        break;
    case 'e':
        cout << "Odd\n";
        break;
    case 'i':
        cout << "Vowel\n";
        break;
    case 'o':
        cout << "Vowel\n";
        break;
    case 'u':
        cout << "Vowel\n";
        break;
    default:
        cout << "Consonon\n";


    }
    return 0;
}