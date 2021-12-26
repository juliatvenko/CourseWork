#include <iostream>
#include "Point.h"
#include "Circle.h"
#include "Sector.h"
#include "FigureCircles.h"

using namespace std;

int main()
{
    setlocale(0, "");
    try
    {
        Point point;
        cin >> point;
        cout << endl;
        point.Move();
        Point point2(point);
        cout <<"Копiюємо точку: "<< point2;

        Point result = point2 * 4;
        cout << endl << "Результат множення точки на задане число: "<< result;
        result = point2 + point;
        cout << "Результат додавання точки: " << result;
        result = point2 - point;
        cout << "Результат вiднiмання точки: " << result;
        result = point2 / 2;
        cout << "Результат дiлення точки на задане число: " << result << endl;

        Circle circle(result, 5);
        cout << circle << endl;
        Sector sector(circle, 0.5);
        cout << sector << endl;

        Sector cSector;
        cin >> cSector;
        Circle* pCircle = &cSector;
        // пізнє зв'язування, викликається Sector::Move()
        pCircle->Move(); 
        cout << endl << *pCircle <<endl;
        Circle& addrCircle = cSector;
        // пізнє зв'язування, викликається Sector::Move()
        addrCircle.Move(); 
        cout << endl << addrCircle << endl;

        cout << endl;
        FigureCircles fc;
        fc.ReadArrayConsole();
        fc.CountCirclesIntersectedMax();
    }
    
    catch (const exception& ex)
    {
        cout << "Виникла помилка: " << ex.what() << endl;
    }
    return 0;
}

