#include <iostream>
using namespace std;
class Shape
{
public:
    virtual float area() = 0; // Pure virtual function
};
class Circle : public Shape
{
private:
    float radius;
public:
    Circle(float r)
    {
        radius = r;
    }
    float area()
    {
        return 3.14 * radius * radius;
    }
};
class Rectangle : public Shape
{
private:
    float length, breadth;
public:
    Rectangle(float l, float b)
    {
        length = l;
        breadth = b;
    }
    float area()
    {
        return length * breadth;
    }
};
class Triangle : public Shape
{
private:
    float base, height;
public:
    Triangle(float b, float h)
    {
        base = b;
        height = h;
    }
    float area()
    {
        return 0.5 * base * height;
    }
};
int main()
{
    float rad, len, bre, bas, hei;
    cout << "Enter radius of the circle: ";
    cin >> rad;
    cout << "Enter length of the rectangle: ";
    cin >> len;
    cout << "Enter breadth of the rectangle: ";
    cin >> bre;
    cout << "Enter base of the triangle: ";
    cin >> bas;
    cout << "Enter height of the triangle: ";
    cin >> hei;
    Circle c(rad);
    Rectangle r(len, bre);
    Triangle t(bas, hei);
    Shape *ptr;
    ptr = &c;
    cout << "Area of Circle: " << ptr->area() << endl;
    ptr = &r;
    cout << "Area of Rectangle: " << ptr->area() << endl;
    ptr = &t;
    cout << "Area of Triangle: " << ptr->area() << endl;
    return 0;
}
