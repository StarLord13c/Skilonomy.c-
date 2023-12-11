#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <cstdlib> // для функцій rand() та srand()
#include <ctime> 
using namespace std;

class Human // базовий класс
{
protected:
    string name;
    int age;
    string sex;
public:
    Human(string x = "...", int y = 0, string z = "...") : name(x), age(y), sex(z) {}
    virtual void print() const // віртуальний метод
    {
        cout << "Ім'я: " << name << "\nВік: " << age << "\nСтать: " << sex << endl;
    }
};

class Adress // класс адреса
{
private:
    string sity;
    string street;
    int housenum;
public:
    Adress(string x = "...", string y = "...", int z = 0) : sity(x), street(y), housenum(z) {}
    void printAdress() const
    {
        cout << "Місто: " << sity << "; Вулиця: " << street << "; Номер будинку: " << housenum << endl;
    }
};

class Grades // класс для оцінок
{
private:
    vector<int> grades;
public:
    Grades()
    {
        srand(time(nullptr)); // генеруємо 6 випадкових оцінок у межах від 1 до 10
        for (int i = 0; i < 6; ++i)
        {
            grades.push_back(rand() % 10 + 1);
        }
    }
    void printGrades() const
    {
        cout << "Оцінки за семестр: [ ";
        for (size_t i = 0; i < grades.size(); ++i)
        {
            cout << grades[i];
            if (i < grades.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << " ]" << endl;
    }
};

class Student : public Human // дочірній класс студент
{
private:
    int money;
    Adress address;
    Grades grades; // додавання об'єкту класу Grades
public:
    Student(string x, int y, string z, int m, Adress adr) : Human(x, y, z), money(m), address(adr) {}
    void print() const override
    {
        Human::print();
        cout << "Стипендія: " << money << endl;
        address.printAdress();
        grades.printGrades(); // виклик методу для виведення оцінок
        cout << "---------------------------------------------------" << endl;
    }
};

class Teacher : public Human // клас-нащадок вчитель
{
private:
    int money;
    Adress address;
    string status;
public:
    Teacher(string x, int y, string z, int m, string s, Adress adr) : Human(x, y, z), money(m), status(s), address(adr) {}

    void print() const override // перевизначаємо метод базовго класу
    {
        Human::print();
        cout << "Зарплата: " << money << "\nСтатус: " << status << endl;
        address.printAdress();
        cout << "---------------------------------------------------" << endl;
    }
};

class Collection // новий класс колекція для двух класів студент і вчитель
{
private:
    vector<Student> students;
    vector<Teacher> teachers;
public:
    void addStudent(const Student& student)
    {
        students.push_back(student);
    }
    void addTeacher(const Teacher& teacher)
    {
        teachers.push_back(teacher);
    }
    void printAll() const // вивід всіх людей
    {
        cout << "Студенти:" << endl;
        for (const auto& student : students)
        {
            student.print();
        }
        cout << "\nВчителі:" << endl;
        for (const auto& teacher : teachers)
        {
            teacher.print();
        }
    }
};
