#pragma once
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

class Point
{
protected:
    double x;
    double y;
public:
    //перевантаження операції введення
    friend istream& operator>> (istream&, Point&);
    //перевантаження операції виведення
    friend ostream& operator<< (ostream&, Point&);
    //конструктор ініціалізації за замовчуванням
    Point();
    //конструктор ініціалізації
    Point(double x, double y);
    //конструктор копіювання
    Point(const Point& other);
    //перевантаження операції присвоєння об'єктів
    Point& operator =(const Point& other);
    //перевантаження операції додавання координат
    Point operator +(const Point& other);
    //перевантаження операції віднімання координат
    Point operator -(const Point& other);
    //перевантаження операції множення на коефіцієнт
    Point& operator * (int k);
    //перевантаження операції ділення на коефіцієнт
    Point& operator / (int k);
    //Get-ери
    double Get_X();
    double Get_Y();
    //Set-ери
    void Set_X(double x);
    void Set_Y(double y);
    //віртуальний метод переміщення 
    virtual void Move();
    //Деструктор
    ~Point();
};

//конструктор ініціалізації за замовчуванням
Point::Point()
{
    this->x = 0;
    this->y = 0;
}

//конструктор ініціалізації
Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

//конструктор копіювання
Point::Point(const Point& other)
{
    this->x = other.x;
    this->y = other.y;
}

//перевантаження операції присвоєння об'єктів
Point& Point::operator =(const Point& other)
{
    this->x = other.x;
    this->y = other.y;
    return *this;
}

//перевантаження операції додавання координат
Point Point::operator +(const Point& other)
{
    Point temp;
    temp.x = this->x + other.x;
    temp.y = this->y + other.y;
    return temp;
}

//перевантаження операції віднімання координат
Point Point::operator -(const Point& other)
{
    Point temp;
    temp.x = this->x - other.x;
    temp.y = this->y - other.y;
    return temp;
}

//перевантаження операції множення на коефіцієнт
Point& Point::operator * (int k)
{

    this->x = x * k;
    this->y = y * k;
    return *this;
}

//перевантаження операції ділення на коефіцієнт
Point& Point::operator / (int k)
{

    this->x = x / k;
    this->y = y / k;
    return *this;
}

//метод отримання значення поля класу
double Point::Get_X()
{
    return this->x;
}

//метод отримання значення поля класу
double Point::Get_Y()
{
    return this->y;
}

//метод встановлення значення поля класу
void Point::Set_X(double x)
{
    this->x = x;
}

//метод встановлення значення поля класу
void Point::Set_Y(double y)
{
    this->y = y;
}

//віртуальний метод переміщення 
void Point::Move()
{
    double deltaX, deltaY;
    cout << "Викликано метод перемiщення ТОЧКИ на площинi" << endl;
    cout << "Додатнє значення х перемiстить вправо, вiд'ємне-влiво" << endl;
    cout << "Додатнє значення y перемiстить вгору, вiд'ємне-вниз" << endl;
    cout << "Введiть, на скiльки позицiй потрiбно перемiстити координату центра круга х: ";
    cin >> deltaX;
    cout << "Введiть, на скiльки позицiй потрiбно перемiстити координату центра круга у: ";
    cin >> deltaY;
    this->x += deltaX;
    this->y += deltaY;
}

//деструктор
Point::~Point()
{

}

//перевантаження операції введення
istream& operator>>(istream& is, Point& P)
{
    double x, y;
    cout << "Введiть координати точки у форматi: (x,y) ->";

    char c;
    cin >> c;
    assert(c == '(');
    cin >> x;
    P.Set_X(x);
    cin >> c;
    assert(c == ',');
    cin >> y;
    P.Set_Y(y);
    cin >> c;
    assert(c == ')');

    return is;
}

//перевантаження операції виведення
ostream& operator<<(ostream& os, Point& P)
{
    os << '(' << P.x << ',' << P.y << ')' << endl;
    return os;
}
