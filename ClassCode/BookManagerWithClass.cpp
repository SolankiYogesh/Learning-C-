#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Book
{
private:
    string title;
    string author;
    int year;

public:
    Book(const string &t, const string &a, const int &y) : title(t), author(a), year(y) {}

    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    int getYear() const
    {
        return year;
    }

    void update(string newAuthor, int newYear)
    {
        author = newAuthor;
        year = newYear;
        cout << "Book updated!\n";
    }

    void display() const
    {
        cout << "Title: " << title << ", Author: " << author << ", Year: " << year << endl;
    }
};

// 🔄 Function Declarations
void addBook(vector<Book> &books)
{
    int year;
    string title, author;

    cout << "Enter title: ";
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter year: ";
    cin >> year;
    Book b(title, author, year);
    books.push_back(b);
}
void viewBooks(const vector<Book> &books)
{
    cout << "\n----- Books -----\n";
    for (int i = 0; i < books.size(); i++)
    {
        books[i].display();
    }
}
void searchBook(const vector<Book> &books, string title)
{
    bool isFound = false;
    cout << "\n----- Books -----\n";
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].getTitle().find(title) != string::npos)
        {
            books[i].display();
            isFound = true;
        }
    }
    if (!isFound)
    {
        cout << "no records found!" << endl;
    }
}
void updateBook(vector<Book> &books, string title)
{
    bool isFound = false;
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].getTitle().find(title) != string::npos)
        {
            int year;
            string author;

            cout << "Enter author to update: ";
            getline(cin, author);
            cout << "Enter year to update: ";
            cin >> year;
            books[i].update(author, year);
            isFound = true;
        }
    }
    if (!isFound)
    {
        cout << "no records found to update!" << endl;
    }
}
void deleteBook(vector<Book> &books, string title)
{
    bool isFound = false;
    for (int i = books.size() - 1; i >= 0; i--)
    {
        if (books[i].getTitle().find(title) != string::npos)
        {
            cout << books[i].getTitle() << " deleted!" << endl;
            books.erase(books.begin() + i);
            isFound = true;
        }
    }

    if (!isFound)
    {
        cout << "no records found to delete!" << endl;
    }
}

void saveToFile(const vector<Book> &books)
{
    ofstream file("books.txt");
    for (int i = 0; i < books.size(); i++)
    {
        file << books[i].getTitle() << "," << books[i].getAuthor() << "," << books[i].getYear() << endl;
    }
    file.close();
}

void loadFromFile(vector<Book> &books)
{
    ifstream file("books.txt");
    string line;
    if (file)
    {
        while (getline(file, line))
        {

            string title, author, year;
            stringstream ss(line);
            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, year);
            Book b(title, author, stoi(year));
            books.push_back(b);
        }
    }
}

int main()
{
    vector<Book> books;
    int choice;
    string title;
    loadFromFile(books);
    do
    {
        cout << "\n----- Book Manager -----\n";
        cout << "1. Add Book\n2. View All Books\n3. Search Book\n4. Update Book\n5. Delete Book\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // flush buffer

        switch (choice)
        {
        case 1:
            addBook(books);
            saveToFile(books);
            break;
        case 2:
            viewBooks(books);
            break;
        case 3:
            cout << "Enter title to search: ";
            getline(cin, title);
            searchBook(books, title);
            break;
        case 4:
            cout << "Enter title to update: ";
            getline(cin, title);
            updateBook(books, title);
            saveToFile(books);
            break;
        case 5:
            cout << "Enter title to delete: ";
            getline(cin, title);
            deleteBook(books, title);
            saveToFile(books);
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
