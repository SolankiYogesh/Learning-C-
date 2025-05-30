#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct Book
{
    string title;
    string author;
    int year;
};

Book addBook()
{
    int year;
    string title;
    string author;
    cout << "Please enter book title" << endl;
    cin >> title;
    cout << "Please enter book author" << endl;
    cin >> author;
    cout << "Please enter book publish year" << endl;
    cin >> year;
    Book book;
    book.title = title;
    book.author = author;
    book.year = year;

    return book;
}

void viewBooks(Book books[], int size)
{
    cout << "\n--- Books List ---\n";
    for (int i = 0; i < size; i++)
    {
        if (books[i].title == "")
        {
            return;
        }
        cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", Year: " << books[i].year << endl;
    }
}

void searchBook(string searchText, Book books[])
{
    for (int i = 0; i < 10; i++)
    {
        if (books[i].title == searchText)
        {
            cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", Year: " << books[i].year << endl;
        }
    }
}

int main()
{
    int choice;
    Book books[10];
    int currentIndex = 0;
    do
    {
        cout << "1. Add Book" << endl;
        cout << "2. View All Books" << endl;
        cout << "3. Search Book by Title" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (currentIndex > 9)
            {
                cout << "You can't add more than 10 books" << endl;
                break;
            }
            books[currentIndex] = addBook();
            cout << "Book Added!" << endl;
            currentIndex++;
            break;
        }
        case 2:
            viewBooks(books, currentIndex);
            break;
        case 3:
        {
            string searchText;
            cout << "Please enter title search" << endl;
            cin >> searchText;
            searchBook(searchText, books);
            break;
        }
        case 4:
            exit(0);
            break;

        default:
            break;
        }

    } while (choice != 4);

    return 0;
}
