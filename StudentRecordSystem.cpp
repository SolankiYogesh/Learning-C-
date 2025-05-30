#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct Student
{
    string name;
    int rollNumber;
    int marks;
};

Student addStudent()
{
    string name;
    int rollNumber, marks;
    cin.ignore();
    cout << "Please enter name" << endl;
    getline(cin, name);
    cout << "Please enter roll number" << endl;
    cin >> rollNumber;
    cout << "Please enter marks" << endl;
    cin >> marks;

    Student student;
    student.name = name;
    student.rollNumber = rollNumber;
    student.marks = marks;

    return student;
}

void viewStudents(vector<Student> students)
{
    if (students.size() > 0)
    {
        cout << "\n--- Student List ---\n";
    }
    for (int i = 0; i < students.size(); i++)
    {

        cout << "Name: " << students[i].name << ", Roll: " << students[i].rollNumber << ", Marks: " << students[i].marks << endl;
    }
}

void searchStudent(int rollNumber, vector<Student> students)
{

    bool isFound = false;
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].rollNumber == rollNumber)
        {
            cout << "Name: " << students[i].name << ", Roll: " << students[i].rollNumber << ", Marks: " << students[i].marks << endl;
            isFound = true;
        }
    }
    if (!isFound)
    {
        cout << "No student found" << endl;
    }
}

void addToFile(Student student)
{
    ofstream file("students.txt", ios::app);
    file << student.name << "," << student.rollNumber << "," << student.marks << endl;
    file.close();
}

bool deleteAllRecords()
{
    char choice;
    cout << "Are you sure you want to delete all records? (y/n): " << endl;
    cin >> choice;
    if (choice == 'y')
    {
        ofstream file("students.txt", ios::trunc);
        file.close();
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    int choice;
    vector<Student> students;
    ifstream file("students.txt");
    string line;
    if (file)
    {
        while (getline(file, line))
        {
            stringstream ss(line);
            string name, rollNumber, marks;

            getline(ss, name, ',');
            getline(ss, rollNumber, ',');
            getline(ss, marks);

            Student student;
            student.name = name;
            student.rollNumber = stoi(rollNumber); // copied from google i dont know how to convert string to int
            student.marks = stoi(marks);
            students.push_back(student);
        }
    }

    do
    {
        cout << "----- Student Record System -----" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. View Students" << endl;
        cout << "3. Search Student by Roll Number" << endl;
        cout << "4. Delete All Records" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Student student = addStudent();
            students.push_back(student);
            addToFile(student);
            cout << "Student Added!" << endl;
            break;
        }
        case 2:
            viewStudents(students);
            break;
        case 3:
        {
            int rollNumber;
            cout << "Please enter rollNumber" << endl;
            cin >> rollNumber;
            searchStudent(rollNumber, students);
            break;
        }
        case 4:
        {
            bool isPermit = deleteAllRecords();
            if (isPermit)
            {
                students.clear();
                cout << "All records deleted!" << endl;
            }

            break;
        }
        case 5:
            exit(0);
            break;

        default:
            cout << "Please enter valid choice" << endl;
            break;
        }

    } while (choice != 5);

    return 0;
}
