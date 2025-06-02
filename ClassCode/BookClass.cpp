
#include <stdio.h>
#include <iostream>
using namespace std;

class Book
{
private:
    string title;
    string author;
    int year;

public:
    Book(string n, string a, int y)
    {
        this->title = n;
        this->author = a;
        this->year = y;
    }

    void updateYear(int y)
    {
        year = y;
        cout << "Updating year for" << '...' << title;
    }

    void display()
    {
        cout << "Title: " << title << ", Author: " << author << ", Year: " << year << endl;
    }
};

int main()
{
    Book book1("C++ Basics", "John Doe", 2010), book2("Learn OOP", "Jane Smith", 2015), book3("Algorithms", "Mike Ross", 2020);
    book1.display();
    book2.display();
    book3.display();
    book2.updateYear(2022);
    book2.display();

    return 0;
}
