#include<bits/stdc++.h>
using namespace std;

struct Student
{
    int id;
    string name;
    char section;
    int marks;
};

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        Student best;
        bool first = true;

        for (int i = 0; i < 3; ++i)
        {
            Student s;
            cin >> s.id >> s.name >> s.section >> s.marks;

            if (first || s.marks > best.marks || (s.marks == best.marks && s.id < best.id))
            {
                best = s;
                first = false;
            }
        }

        cout << best.id << " " << best.name << " " << best.section << " " << best.marks << endl;
    }

    return 0;
}
