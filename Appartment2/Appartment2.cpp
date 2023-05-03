// Appartment2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream>
#include <cstring>
#include"Appartment.h"
using namespace std;


int main()
{
    setlocale(0, "");
    // Создаем новый дом
    House myHouse;

    // Добавляем квартиры в дом и жильцов в квартиры
    Apartment ap1;
    ap1.addOccupant(Person("Иван", 30));
    ap1.addOccupant(Person("Маша", 25));
    myHouse.addApartment(ap1);

    Apartment ap2;
    ap2.addOccupant(Person("Саша", 40));
    ap2.addOccupant(Person("Катя", 35));
    ap2.addOccupant(Person("Юля", 12));
    myHouse.addApartment(ap2);

    // Выводим информацию о доме и его жильцах
    cout << "В моем доме " << myHouse.getApartmentsNumber() << " квартиры\n";
    for (int i = 0; i < myHouse.getApartmentsNumber(); i++) {
        cout << "В квартире " << i + 1 << myHouse.getApartment(i)->getOccupantsNumber() << " проживают жильцы:\n";
        for (int j = 0; j < myHouse.getApartment(i)->getOccupantsNumber(); j++) {
            cout << "\t" << myHouse.getApartment(i)->getOccupant(j)->getName() << " (" << myHouse.getApartment(i)->getOccupant(j)->getAge() << ")\n";
        }
    }

    return 0;
}