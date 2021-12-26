#pragma once
#include <iostream>
#include "Point.h"
#include "Circle.h"
using namespace std;

class FigureCircles
{
private:
    //����� ������
    int size;
    //����� ��'���� ���� ����
    Circle* arr;
public:
    // ����������� ���� 
    class Iterator
    {
    private:
        // �������� �� ������� ����� 
        Circle* i;
    public:
        //����������� �����������
        explicit Iterator(Circle* i);
        //����������� ���������
        Iterator(const Iterator& x);
        //������������� �������� ���������
        Iterator& operator=(const Iterator x);
        //������������� �������� ������������ ���������
        Circle operator*() const;
        // ������������� �������� ����������� ���������� ���������
        Iterator operator++();
        // ������������� �������� ����������� ���������� ���������
        Iterator operator--();
        // ������������� �������� ������������ ���������� ���������
        Iterator operator++(int);
        // ������������� �������� ������������ ���������� ���������
        Iterator operator--(int);
        // ������������� �������� ������� ��������� �� ������ ����� ������� 
        Iterator operator + (int n);
        // ������������� �������� ������� ��������� �� ������ ����� ������� 
        Iterator operator - (int n);
        // ������������� �������� ������� ��������� �� ������ ����� ������� 
        Iterator operator += (int n);
        //������������� �������� �������� �� ������
        bool operator == (const Iterator x) const;
        //������������� �������� �������� �� ��������
        bool operator != (const Iterator x) const;
        //������������� �������� �������� ���������
        bool operator < (const Iterator& x) const;
        //������������� �������� �������� ���������
        bool operator > (const Iterator& x) const;
        //������������� �������� ���������� ���������
        bool operator <= (const Iterator& x) const;
        //������������� �������� ���������� ���������
        bool operator >= (const Iterator& x) const;
        //������������� �������� �������� ���� ���������
        friend int operator - (const Iterator x, const Iterator y);
    };
    //������� ������� ����������� �������� ������
    Iterator begin();
    //������� ������� �������� �������� ������
    Iterator end();
    //����������
    ~FigureCircles();
    //����������� �� �������������
    FigureCircles();
    //����������� 
    FigureCircles(int size);
    //���������� ������ � ������
    void ReadArrayConsole();
    //������� �� �������� ���� ��
    double DistanceCenters(Point P1, Point P2);
    //��������, �� ���� �������������
    bool CirclesIntersect(Circle C1, Circle C2);
    //����������� ����������� ������� �������� �� � ����� ��
    void CountCirclesIntersectedMax();
};

//����������� �����������
FigureCircles::Iterator::Iterator(Circle* i = 0)
{
    this->i = i;
}

//����������� ���������
FigureCircles::Iterator::Iterator(const Iterator& x)
{
    this->i = x.i;
}

//������������� �������� ���������
FigureCircles::Iterator& FigureCircles::Iterator::operator=(const Iterator x)
{
    i = x.i;
    return *this;
}

//������������� �������� ������������ ���������
Circle FigureCircles::Iterator::operator*() const
{
    return *i;
}

// ������������� �������� ����������� ���������� ���������
FigureCircles::Iterator FigureCircles::Iterator::operator++()
{
    ++i;
    return *this;
}

// ������������� �������� ����������� ���������� ���������
FigureCircles::Iterator FigureCircles::Iterator::operator--()
{
    --i;
    return *this;
}

// ������������� �������� ������������ ���������� ���������
FigureCircles::Iterator FigureCircles::Iterator::operator++(int)
{
    i++;
    return *this;
}

// ������������� �������� ������������ ����������� ���������
FigureCircles::Iterator FigureCircles::Iterator::operator--(int)
{
    i--;
    return *this;
}

// ������������� �������� ������� ��������� �� ������ ����� ������� 
FigureCircles::Iterator FigureCircles::Iterator::operator + (int n)
{
    return Iterator(i + n);
}

// ������������� �������� ������� ��������� �� ������ ����� ������� 
FigureCircles::Iterator FigureCircles::Iterator::operator - (int n)
{
    return Iterator(i - n);
}

// ������������� �������� ������� ��������� �� ������ ����� ������� 
FigureCircles::Iterator FigureCircles::Iterator::operator += (int n)
{
    i += n;
    return *this;
}

//������������� �������� �������� �� ������
bool FigureCircles::Iterator::operator == (const Iterator x)   const
{
    return i == x.i;
}

//������������� �������� �������� �� ��������
bool FigureCircles::Iterator::operator != (const Iterator x) const
{
    return i != x.i;
}

//������������� �������� �������� ���������
bool FigureCircles::Iterator::operator < (const Iterator& x) const
{
    return i < x.i;
}

//������������� �������� �������� ���������
bool FigureCircles::Iterator::operator > (const Iterator& x) const
{
    return i > x.i;
}

//������������� �������� ���������� ���������
bool FigureCircles::Iterator::operator <= (const Iterator& x) const
{
    return i <= x.i;
}

//������������� �������� ���������� ���������
bool FigureCircles::Iterator::operator >= (const Iterator& x) const
{
    return i >= x.i;
}

//������������� �������� �������� ���� ���������
int operator - (const FigureCircles::Iterator x, const FigureCircles::Iterator y)
{
    return x.i - y.i;
}

//������� ������� ����������� �������� ������
FigureCircles::Iterator FigureCircles::begin()
{
    return Iterator(&arr[0]);
}

//������� ������� �������� �������� ������
FigureCircles::Iterator FigureCircles::end()
{
    return Iterator(&arr[size]);
}

//����������
FigureCircles::~FigureCircles()
{
    if (arr)
    {
        delete[] arr;
    }
    arr = NULL;
}

//����������� �� �������������
FigureCircles::FigureCircles()
{
    this->size = 0;
    this->arr = NULL;
}

//����������� 
FigureCircles::FigureCircles(int size)
{
    this->size = size;
    this->arr = new Circle[size];
}

//���������� ������ � ������
void FigureCircles::ReadArrayConsole()
{

    if (arr == NULL)
    {
        cout << "����i�� ����i� ������ ��'���i� ����� ����: ";
        cin >> size;
        this->arr = new Circle[size];
    }

    //������� �������� �������� ������
    int count = 0;

    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
        count++;
    }
    //���� ������� �� �� �������� ������, �� ��������� ��������� � �������� ���'���
    if (count < size)
    {
        throw("������� ����� �������� ������, �� �����������");
        delete[] arr;

    }
}


//������� �� �������� ���� ��
double FigureCircles::DistanceCenters(Point P1, Point P2)
{
    return sqrt(pow((P1.Get_X() - P2.Get_X()), 2) + pow((P1.Get_Y() - P2.Get_Y()), 2));
}

//��������, �� ���� �������������
bool FigureCircles::CirclesIntersect(Circle C1, Circle C2)
{
    return(DistanceCenters(Point(C1.Get_X(), C1.Get_Y()), Point(C2.Get_X(), C2.Get_Y())) < C1.Get_R() + C2.Get_R());
}

//����������� ����������� ������� �������� �� � ����� ��
void FigureCircles::CountCirclesIntersectedMax()
{
    //����������� ������� �������� ��
    int max_count = 0;
    for (Iterator i = begin(); i != end(); ++i)
    {
        //������� �������� ��� ������� �������� ����
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

    cout << "����������� �i���i��� �������i� �i� " << max_count << endl;
}