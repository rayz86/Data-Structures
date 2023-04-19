/*=======================================
Lab ID:5.6
Program title: operator overloading using friend function
Author: Rayyan Shaikh
Roll no.: 21co43
Language: cpp
Class: Comp b
Due Date:
=========================================
Description: operator overloading using friend function
Input:
Output:
Algorithm: -
Pre-requisite: Basics of C++
Known bugs: -
=======================================*/
#include <iostream>
using namespace std;
class Number
{
    private:
        int num;
    public:
        Number(int num = 0)
        {
            this->num = num;
        }
        friend void operator << (ostream &out, Number &obj);
        friend void operator >> (istream &in, Number &obj);
    };
void operator << (ostream &out, Number &obj)
{
    out << obj.num;
}
void operator >> (istream &in, Number &obj)
{
    in >> obj.num;
}
int main()
{
    Number n1(2);
    cout << "Enter a value : ";
    cin >> n1;
    cout << "Displaying Object : ";
    cout << n1;
    return 0;
}

