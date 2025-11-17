#include <bits/stdc++.h>

using namespace std;

vector<int> sort_it(int n)
{
    vector<int> a(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());

    return a;
}

int main()
{
    int n;
    cin >> n;
    vector<int> sorted_array = sort_it(n);
    for (int output : sorted_array)
    {
        cout << output << " ";
    }
    
    return 0;
}