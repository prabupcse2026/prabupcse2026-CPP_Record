#include <iostream>
using namespace std;
class Student
{
private:
    int rollNo;
    string name;
public:
    // Constructor
    Student(int r, string n)
    {
        rollNo = r;
        name = n;
        cout << "Student object created" << endl;
    }
    // Member function
    void display()
    {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }
    // Destructor
    ~Student()
    {
        cout << "Student object destroyed" << endl;
    }
};
int main()
{
    int roll;
    string name;
    cout << "Enter roll number: ";
    cin >> roll;
    cout << "Enter name: ";
    cin >> ws;
    getline(cin, name);
    Student s1(roll, name);
    s1.display();
    return 0;
}
