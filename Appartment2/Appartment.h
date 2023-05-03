#pragma once
#include <iostream>
#include <cstring>
using namespace std;

// ����� �������
class Person {
private:
    string name;
    int age;
public:
    Person(const string& n, int a) : name(n), age(a) {}

    void setName(const string& n) {//������ �����
        name = n;
    }

    void setAge(int a) {// ������ ��������
        age = a;
    }

    string getName() const {// ������ �����
        return name;
    }

    int getAge() const {// ������ ��������
        return age;
    }
};

// ����� ��������
class Apartment {
private:
    static const int MAX_OCCUPANTS = 5;
    Person** occupants;
    int occupantsNumber;
public:
    Apartment() : occupants(new Person* [MAX_OCCUPANTS]), occupantsNumber(0) {}

    // ����������� �����������
    Apartment(const Apartment& other) : occupants(new Person* [MAX_OCCUPANTS]), occupantsNumber(other.occupantsNumber) {
        for (int i = 0; i < occupantsNumber; i++) {
            occupants[i] = new Person(*(other.occupants[i]));
        }
    }
    // ����������
    ~Apartment() {
        for (int i = 0; i < occupantsNumber; i++) {
            delete occupants[i];
        }
        delete[] occupants;
    }
    // ������� ���������� ������
    void addOccupant(const Person& newOccupant) {
        if (occupantsNumber >= MAX_OCCUPANTS) {
            cout << "������ �������� ������ �������\n";
            return;
        }
        occupants[occupantsNumber++] = new Person(newOccupant);
    }
    // ������� ���������� �������
    int getOccupantsNumber() const {
        return occupantsNumber;
    }

    const Person* getOccupant(int index) const {
        if (index < 0 || index >= occupantsNumber) {
            return nullptr;
        }
        return occupants[index];
    }
    //����������� ��������� ������������
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
//����� ���
class House {
private:
    static const int MAX_APARTMENTS = 10;
    Apartment* apartments;
    int apartmentsNumber;
public:
    House() : apartments(new Apartment[MAX_APARTMENTS]), apartmentsNumber(0) {}

    // ����������� �����������
    House(const House& other) : apartments(new Apartment[MAX_APARTMENTS]), apartmentsNumber(other.apartmentsNumber) {
        for (int i = 0; i < apartmentsNumber; i++) {
            apartments[i] = other.apartments[i];
        }
    }

    ~House() {
        delete[] apartments;
    }
    //���������� ��������
    void addApartment(const Apartment& newApartment) {
        if (apartmentsNumber >= MAX_APARTMENTS) {
            cout << "������ �������� ������ ������� \n";
            return;
        }
        apartments[apartmentsNumber++] = newApartment;
    }


    //������� ���������� �������
    int getApartmentsNumber() const {
        return apartmentsNumber;
    }

    const Apartment* getApartment(int index) const {
        if (index < 0 || index >= apartmentsNumber) {
            return nullptr;
        }
        return &(apartments[index]);
    }
    // ����������� ��������� ������������
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