#pragma once
#include <iostream>
#include <assert.h>
#include <string>
#include "Point.h"
#include "Circle.h"
using namespace std;

// похідний клас сектор
class Sector : public Circle
{
private:
    // кут дуги сегмента в радіанах 
    double alpha;
public:
    friend istream& operator>> (istream&, Sector&);//перевантаження операції введення
    friend ostream& operator<< (ostream&, Sector&);//перевантаження операції виведення
    // конструктор ініціалізації 
    Sector(double x, double y, double R, double alpha);
    //метод отримання значення кута
    double Get_A();
    //метод встановлення значення кута
    void Set_A(double alpha);
    // перевантажений конструктор ініціалізації 
    Sector(Circle& c, double alpha);
    // конструктор ініціалізації за замовчуванням
    Sector();
    // конструктор копіювання 
    Sector(const Sector& sector);
    //деструктор
    ~Sector();
    //віртуальний метод переміщення 
    virtual void Move();
};

Sector::Sector(double x, double y, double R, double alpha) :Circle(x, y, R) // виклик конструктора базового класу
{
    this->x = x;
    this->y = y;
    this->R = R;
    this->alpha = alpha;
}
//метод отримання значення кута
double Sector::Get_A()
{
    return this->alpha;
}

//метод встановлення значення кута
void Sector::Set_A(double alpha)
{
    this->alpha = alpha;
}

// виклик конструктора копіювання базового класу
Sector::Sector(Circle& c, double alpha) :Circle(c) 
{
    this->alpha = alpha;
}

// виклик конструктора ініціалізації за замовчуванням базового класу
Sector::Sector() : Circle() 
{
    this->alpha = 0;
}

// виклик конструктора базового класу
Sector::Sector(const Sector& sector) : Circle(sector.x, sector.y, sector.R) 
{
    this->alpha = sector.alpha;
}

//деструктор
Sector::~Sector()
{

}

//віртуальний метод переміщення
void Sector::Move()
{
    double deltaX, deltaY;
    cout << "Викликано метод перемiщення СЕКТОРА КРУГА на площинi" << endl;
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
istream& operator>>(istream& is, Sector& S)
{
    double x, y;
    cout << "Введiть координати центру круга у форматi: (x,y) ->";
    char c;
    cin >> c;
    assert(c == '(');
    cin >> x;
    S.Set_X(x);
    cin >> c;
    assert(c == ',');
    cin >> y;
    S.Set_Y(y);
    cin >> c;
    assert(c == ')');
    cout << "Введiть радiус круга R=";
    cin >> S.R;
    cout << "Введiть центральний кут alpha(в радiанах): ";
    cin >> S.alpha;
    return is;
}

//перевантаження операції виведення
ostream& operator<<(ostream& os, Sector& S)
{
    os << "Центр круга знаходиться в точцi: " << '(' << S.x << ',' << S.y << ')' << endl;
    os << "Радiус круга R: " << S.R << endl;
    os << "Центральний кут alpha(в радiанах): " << S.alpha << endl;
    return os;
}