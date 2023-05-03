#pragma once
#include <iostream>
#include <cstring>
using namespace std;

// класс человек
class Person {
private:
    string name;
    int age;
public:
    Person(const string& n, int a) : name(n), age(a) {}

    void setName(const string& n) {//сеттер имени
        name = n;
    }

    void setAge(int a) {// сеттер возраста
        age = a;
    }

    string getName() const {// геттер имени
        return name;
    }

    int getAge() const {// геттер возраста
        return age;
    }
};

// класс квартира
class Apartment {
private:
    static const int MAX_OCCUPANTS = 5;
    Person** occupants;
    int occupantsNumber;
public:
    Apartment() : occupants(new Person* [MAX_OCCUPANTS]), occupantsNumber(0) {}

    // Конструктор копирования
    Apartment(const Apartment& other) : occupants(new Person* [MAX_OCCUPANTS]), occupantsNumber(other.occupantsNumber) {
        for (int i = 0; i < occupantsNumber; i++) {
            occupants[i] = new Person(*(other.occupants[i]));
        }
    }
    // деструктор
    ~Apartment() {
        for (int i = 0; i < occupantsNumber; i++) {
            delete occupants[i];
        }
        delete[] occupants;
    }
    // функция добавления жильца
    void addOccupant(const Person& newOccupant) {
        if (occupantsNumber >= MAX_OCCUPANTS) {
            cout << "Нельзя добавить больше жильцов\n";
            return;
        }
        occupants[occupantsNumber++] = new Person(newOccupant);
    }
    // подсчет количества жильцов
    int getOccupantsNumber() const {
        return occupantsNumber;
    }

    const Person* getOccupant(int index) const {
        if (index < 0 || index >= occupantsNumber) {
            return nullptr;
        }
        return occupants[index];
    }
    //определение оператора присваивания
    Apartment& operator=(const Apartment& other) {
        if (this == &other) {
            return *this;
        }
        for (int i = 0; i < occupantsNumber; i++) {
            delete occupants[i];
        }
        delete[] occupants;
        occupants = new Person * [MAX_OCCUPANTS];
        occupantsNumber = other.occupantsNumber;
        for (int i = 0; i < occupantsNumber; i++) {
            occupants[i] = new Person(*(other.occupants[i]));
        }
        return *this;
    }
};
//класс дом
class House {
private:
    static const int MAX_APARTMENTS = 10;
    Apartment* apartments;
    int apartmentsNumber;
public:
    House() : apartments(new Apartment[MAX_APARTMENTS]), apartmentsNumber(0) {}

    // Конструктор копирования
    House(const House& other) : apartments(new Apartment[MAX_APARTMENTS]), apartmentsNumber(other.apartmentsNumber) {
        for (int i = 0; i < apartmentsNumber; i++) {
            apartments[i] = other.apartments[i];
        }
    }

    ~House() {
        delete[] apartments;
    }
    //добавление квартиры
    void addApartment(const Apartment& newApartment) {
        if (apartmentsNumber >= MAX_APARTMENTS) {
            cout << "Нельзя добавить больше квартир \n";
            return;
        }
        apartments[apartmentsNumber++] = newApartment;
    }


    //подсчет количества квартир
    int getApartmentsNumber() const {
        return apartmentsNumber;
    }

    const Apartment* getApartment(int index) const {
        if (index < 0 || index >= apartmentsNumber) {
            return nullptr;
        }
        return &(apartments[index]);
    }
    // определения оператора присваивания
    House& operator=(const House& other) {
        if (this == &other) {
            return *this;
        }
        delete[] apartments;
        apartments = new Apartment[MAX_APARTMENTS];
        apartmentsNumber = other.apartmentsNumber;
        for (int i = 0; i < apartmentsNumber; i++) {
            apartments[i] = other.apartments[i];
        }
        return *this;
    }
};