#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "Classes.cpp"
using namespace std;

void main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

    Collection collection;
    Student student1("Vlad Meme", 18, "male", 3000, Adress("Kherson", "Nichna", 8));
    Student student2("Anna Bebra", 19, "female", 1200, Adress("Kherson", "Sirena", 79));
    Student student3("Valera Dzmik", 20, "male", 0, Adress("Kherson", "Sirena", 79));
    Teacher teacher1("Alex Monter", 35, "male", 20000, "teacher", Adress("Kherson", "Nova", 54));

    collection.addStudent(student1);
    collection.addStudent(student2);
    collection.addStudent(student3);
    collection.addTeacher(teacher1);

    collection.printAll();
}
