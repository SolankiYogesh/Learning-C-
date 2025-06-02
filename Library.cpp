#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct Book
{
    string title;
    string author;
    int year;
};

// ✅ Load books from file
vector<Book> loadBooks()
{
    vector<Book> books;
    ifstream file("books.txt");
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string title, author, yearStr;
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, yearStr);
        Book b = {title, author, stoi(yearStr)};
        books.push_back(b);
    }
    return books;
}

// ✅ Save all books to file (overwrite)
void saveBooks(const vector<Book> &books)
{
    ofstream file("books.txt", ios::trunc);
    for (const auto &b : books)
    {
        file << b.title << "," << b.author << "," << b.year << endl;
    }
}

// ✅ Add book
void addBook(vector<Book> &books)
{
    Book b;
    cin.ignore();
    cout << "Enter title: ";
    getline(cin, b.title);
    cout << "Enter author: ";
    getline(cin, b.author);
    cout << "Enter year: ";
    cin >> b.year;
    books.push_back(b);
    saveBooks(books);
    cout << "Book added!\n";
}

// ✅ View books
void viewBooks(const vector<Book> &books)
{
    cout << "\n--- Book List ---\n";
    for (const auto &b : books)
    {
        cout << "Title: " << b.title << ", Author: " << b.author << ", Year: " << b.year << endl;
    }
}

// ✅ Search by title
void searchBook(const vector<Book> &books)
{
    cin.ignore();
    string title;
    cout << "Enter title to search: ";
    getline(cin, title);
    bool found = false;
    for (const auto &b : books)
    {
        if (b.title == title)
        {
            cout << "Found: " << b.title << " by " << b.author << " (" << b.year << ")\n";
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Book not found.\n";
}

// ✅ Update book
void updateBook(vector<Book> &books)
{
    cin.ignore();
    string title;
    cout << "Enter title to update: ";
    getline(cin, title);
    bool updated = false;
    for (auto &b : books)
    {
        if (b.title == title)
        {
            cout << "Enter new author: ";
            getline(cin, b.author);
            cout << "Enter new year: ";
            cin >> b.year;
            updated = true;
            break;
        }
    }
    if (updated)
    {
        saveBooks(books);
        cout << "Book updated!\n";
    }
    else
    {
        cout << "Book not found.\n";
    }
}

// ✅ Delete book
void deleteBook(vector<Book> &books)
{
    cin.ignore();
    string title;
    cout << "Enter title to delete: ";
    getline(cin, title);
    bool deleted = false;
    for (auto it = books.begin(); it != books.end(); ++it)
    {
        if (it->title == title)
        {
            books.erase(it);
            deleted = true;
            break;
        }
    }
    if (deleted)
    {
        saveBooks(books);
        cout << "Book deleted!\n";
    }
    else
    {
        cout << "Book not found.\n";
    }
}

// 🔁 Menu
int main()
{
    vector<Book> books = loadBooks();
    int choice;
    do
    {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n2. View Books\n3. Search by Title\n4. Update Book\n5. Delete Book\n6. Exit\n";
        cout << "Choose: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addBook(books);
            break;
        case 2:
            viewBooks(books);
            break;
        case 3:
            searchBook(books);
            break;
        case 4:
            updateBook(books);
            break;
        case 5:
            deleteBook(books);
            break;
        case 6:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
    } while (choice != 6);
    return 0;
}
