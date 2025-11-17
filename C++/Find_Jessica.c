#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string S;
    getline(cin, S);

    istringstream iss(S);
    string word;
    bool jannat = false;

    while (iss >> word)
    {
        if (word == "Jessica")
        {
            jannat = true;
            break;
        }
    }

    if (jannat)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
