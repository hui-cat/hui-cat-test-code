#include <bits/stdc++.h>
using namespace std;
struct Student
{
    int index;
    int Chinese;
    int total;
};

bool compare(Student stu1, Student stu2)
{
    if (stu1.total != stu2.total) return stu1.total > stu2.total;
    if (stu1.Chinese != stu2.Chinese) return stu1.Chinese > stu2.Chinese;
    return stu1.index < stu2.index;
}

int main()
{
    int n;
    cin >> n;
    vector<Student> students(n);
    for (int i = 0; i < n; i++)
    {
        students[i].index = i+1;
        int a,b,c;
        cin >> a >> b >> c;
        students[i].Chinese = a;
        students[i].total = a+b+c;
    }
    sort(students.begin(), students.end(), compare);
    for (int i = 0; i < 5; i++)
    {
        cout << students[i].index << " " << students[i].total << endl;
    }
    return 0;
}