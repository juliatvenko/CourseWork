#pragma once
#include <iostream>
#include <assert.h>
#include "Point.h"
using namespace std;

// похідний клас коло
class Circle : public Point
{
protected:
    // радіус кола 
    double R; 
public:
    // перевантаження операції введення
    friend istream& operator>> (istream&, Circle&);
    // перевантаження операції виведення
    friend ostream& operator<< (ostream&, Circle&); 
    // конструктор ініціалізації 
    Circle(double x, double y, double R); 
    // перевантажений конструктор ініціалізації 
    Circle(Point& c, double R); 
    // конструктор ініціалізації за замовчуванням
    Circle(); 
    // конструктор копіювання 
    Circle(const Circle& circle);
    // деструктор
    ~Circle(); 
    // метод отримання значення поля класу
    double Get_R();
    // метод встановлення значення поля класу
    void Set_R(double R); 
    // віртуальний метод переміщення
    virtual void Move(); 
};

Circle::Circle(double x, double y, double R) : Point(x, y) // виклик конструктора базового класу
{
    this->R = R;
}

Circle::Circle(Point& c, double R) : Point(c) // виклик конструктора копіювання базового класу
{
    this->R = R;
}

Circle::Circle() : Point() // виклик конструктора ініціалізації за замовчуванням базового класу
{
    this->R = 0;
}

Circle::Circle(const Circle& circle) : Point(circle.x, circle.y) // виклик конструктора базового класу
{
    this->R = circle.R;
}

Circle::~Circle()
{

}

double Circle::Get_R()
{
    return this->R;
}

void Circle::Set_R(double R)
{
    this->R = R;
}

void Circle::Move() // віртуальний метод переміщення 
{
    double deltaX, deltaY;
    cout << "Викликано метод переміщення КОЛА на площині" << endl;
    cout << "Додатнє значення х перемiстить вправо, вiд'ємне-влiво" << endl;
    cout << "Додатнє значення y перемiстить вгору, вiд'ємне-вниз" << endl;
    cout << "Введiть, на скiльки позицiй потрiбно перемiстити координату центра круга х: ";
    cin >> deltaX;
    cout << "Введiть, на скiльки позицiй потрiбно перемiстити координату центра круга у: ";
    cin >> deltaY;
    this->x += deltaX;
    this->y += deltaY;
}

//перевантаження операції введення
istream& operator>>(istream& is, Circle& C)
{
    double x, y;
    cout << "Введiть координати центру кола у форматi: (x,y) ->";
    char c;
    cin >> c;
    assert(c == '(');
    cin >> x;
    C.Set_X(x);
    cin >> c;
    assert(c == ',');
    cin >> y;
    C.Set_Y(y);
    cin >> c;
    assert(c == ')');
    cout << "Введiть радiус кола R=";
    cin >> C.R;
    return is;
}

//перевантаження операції виведення
ostream& operator<<(ostream& os, Circle& C)
{
    os << "Центр кола знаходиться в точцi: " << '(' << C.x << ',' << C.y << ')' << endl;
    os << "Радiус кола R: " << C.R << endl;
    return os;
}