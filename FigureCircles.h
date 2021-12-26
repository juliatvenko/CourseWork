#pragma once
#include <iostream>
#include "Point.h"
#include "Circle.h"
using namespace std;

class FigureCircles
{
private:
    //розмір масиву
    int size;
    //масив об'єктів типу КОЛО
    Circle* arr;
public:
    // Ітераторний клас 
    class Iterator
    {
    private:
        // вказівник на елемент даних 
        Circle* i;
    public:
        //конструктор ініціалізації
        explicit Iterator(Circle* i);
        //конструктор копіювання
        Iterator(const Iterator& x);
        //перевантажена операція присвоєння
        Iterator& operator=(const Iterator x);
        //перевантажена операція розіменування ітератора
        Circle operator*() const;
        // перевантажена операція префіксного інкременту ітератора
        Iterator operator++();
        // перевантажена операція префіксного декременту ітератора
        Iterator operator--();
        // перевантажена операція постфіксного інкременту ітератора
        Iterator operator++(int);
        // перевантажена операція постфіксного декременту ітератора
        Iterator operator--(int);
        // перевантажена операція зміщення ітератора на задане число позицій 
        Iterator operator + (int n);
        // перевантажена операція зміщення ітератора на задане число позицій 
        Iterator operator - (int n);
        // перевантажена операція зміщення ітератора на задане число позицій 
        Iterator operator += (int n);
        //перевантажена операція перевірки на рівність
        bool operator == (const Iterator x) const;
        //перевантажена операція перевірки на нерівність
        bool operator != (const Iterator x) const;
        //перевантажена операція строгого порівняння
        bool operator < (const Iterator& x) const;
        //перевантажена операція строгого порівняння
        bool operator > (const Iterator& x) const;
        //перевантажена операція нестрогого порівняння
        bool operator <= (const Iterator& x) const;
        //перевантажена операція нестрогого порівняння
        bool operator >= (const Iterator& x) const;
        //перевантажена операція віднімання двох ітераторів
        friend int operator - (const Iterator x, const Iterator y);
    };
    //повертає позицію початкового елемента масиву
    Iterator begin();
    //повертає позицію кінцевого елемента масиву
    Iterator end();
    //деструктор
    ~FigureCircles();
    //конструктор за замовчуванням
    FigureCircles();
    //конструктор 
    FigureCircles(int size);
    //зчитування масиву з консолі
    void ReadArrayConsole();
    //відстань між центрами двох кіл
    double DistanceCenters(Point P1, Point P2);
    //перевірка, чи кола перетинаються
    bool CirclesIntersect(Circle C1, Circle C2);
    //знаходження максимальної кількості перетинів кіл у масиві кіл
    void CountCirclesIntersectedMax();
};

//конструктор ініціалізації
FigureCircles::Iterator::Iterator(Circle* i = 0)
{
    this->i = i;
}

//конструктор копіювання
FigureCircles::Iterator::Iterator(const Iterator& x)
{
    this->i = x.i;
}

//перевантажена операція присвоєння
FigureCircles::Iterator& FigureCircles::Iterator::operator=(const Iterator x)
{
    i = x.i;
    return *this;
}

//перевантажена операція розіменування ітератора
Circle FigureCircles::Iterator::operator*() const
{
    return *i;
}

// перевантажена операція префіксного інкременту ітератора
FigureCircles::Iterator FigureCircles::Iterator::operator++()
{
    ++i;
    return *this;
}

// перевантажена операція префіксного декременту ітератора
FigureCircles::Iterator FigureCircles::Iterator::operator--()
{
    --i;
    return *this;
}

// перевантажена операція постфіксного інкременту ітератора
FigureCircles::Iterator FigureCircles::Iterator::operator++(int)
{
    i++;
    return *this;
}

// перевантажена операція постфіксного денкременту ітератора
FigureCircles::Iterator FigureCircles::Iterator::operator--(int)
{
    i--;
    return *this;
}

// перевантажена операція зміщення ітератора на задане число позицій 
FigureCircles::Iterator FigureCircles::Iterator::operator + (int n)
{
    return Iterator(i + n);
}

// перевантажена операція зміщення ітератора на задане число позицій 
FigureCircles::Iterator FigureCircles::Iterator::operator - (int n)
{
    return Iterator(i - n);
}

// перевантажена операція зміщення ітератора на задане число позицій 
FigureCircles::Iterator FigureCircles::Iterator::operator += (int n)
{
    i += n;
    return *this;
}

//перевантажена операція перевірки на рівність
bool FigureCircles::Iterator::operator == (const Iterator x)   const
{
    return i == x.i;
}

//перевантажена операція перевірки на нерівність
bool FigureCircles::Iterator::operator != (const Iterator x) const
{
    return i != x.i;
}

//перевантажена операція строгого порівняння
bool FigureCircles::Iterator::operator < (const Iterator& x) const
{
    return i < x.i;
}

//перевантажена операція строгого порівняння
bool FigureCircles::Iterator::operator > (const Iterator& x) const
{
    return i > x.i;
}

//перевантажена операція нестрогого порівняння
bool FigureCircles::Iterator::operator <= (const Iterator& x) const
{
    return i <= x.i;
}

//перевантажена операція нестрогого порівняння
bool FigureCircles::Iterator::operator >= (const Iterator& x) const
{
    return i >= x.i;
}

//перевантажена операція віднімання двох ітераторів
int operator - (const FigureCircles::Iterator x, const FigureCircles::Iterator y)
{
    return x.i - y.i;
}

//повертає позицію початкового елемента масиву
FigureCircles::Iterator FigureCircles::begin()
{
    return Iterator(&arr[0]);
}

//повертає позицію кінцевого елемента масиву
FigureCircles::Iterator FigureCircles::end()
{
    return Iterator(&arr[size]);
}

//деструктор
FigureCircles::~FigureCircles()
{
    if (arr)
    {
        delete[] arr;
    }
    arr = NULL;
}

//конструктор за замовчуванням
FigureCircles::FigureCircles()
{
    this->size = 0;
    this->arr = NULL;
}

//конструктор 
FigureCircles::FigureCircles(int size)
{
    this->size = size;
    this->arr = new Circle[size];
}

//зчитування масиву з консолі
void FigureCircles::ReadArrayConsole()
{

    if (arr == NULL)
    {
        cout << "Введiть розмiр масиву об'єктiв класу коло: ";
        cin >> size;
        this->arr = new Circle[size];
    }

    //кількість введених елементів масиву
    int count = 0;

    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
        count++;
    }
    //якщо введено не всі елементи масиву, то завершити виконання і звільнити пам'ять
    if (count < size)
    {
        throw("введено менше елементів масиву, ніж очікувалося");
        delete[] arr;

    }
}


//відстань між центрами двох кіл
double FigureCircles::DistanceCenters(Point P1, Point P2)
{
    return sqrt(pow((P1.Get_X() - P2.Get_X()), 2) + pow((P1.Get_Y() - P2.Get_Y()), 2));
}

//перевірка, чи кола перетинаються
bool FigureCircles::CirclesIntersect(Circle C1, Circle C2)
{
    return(DistanceCenters(Point(C1.Get_X(), C1.Get_Y()), Point(C2.Get_X(), C2.Get_Y())) < C1.Get_R() + C2.Get_R());
}

//знаходження максимальної кількості перетинів кіл у масиві кіл
void FigureCircles::CountCirclesIntersectedMax()
{
    //максимальна кількість перетинів кіл
    int max_count = 0;
    for (Iterator i = begin(); i != end(); ++i)
    {
        //кількість перетинів для кожного окремого кола
        int count = 0;

        for (Iterator j = begin(); j != end(); ++j)
        {
            count += CirclesIntersect(*i, *j);
        }

        if (max_count < count)
        {
            max_count = count;
        }
    }

    cout << "Максимальна кiлькiсть перетинiв кiл " << max_count << endl;
}