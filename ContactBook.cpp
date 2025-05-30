#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct Contact
{
    string name;
    string phone;
    string email;
};

Contact addContact()
{
    string name;
    string phone;
    string email;
    cout << "Please enter contact name" << endl;
    cin >> name;
    cout << "Please enter contact phone" << endl;
    cin >> phone;
    cout << "Please enter contact email" << endl;
    cin >> email;
    Contact contact;
    contact.name = name;
    contact.phone = phone;
    contact.email = email;

    return contact;
}

void viewContacts(vector<Contact> contacts)
{
    cout << "\n--- Contacts List ---\n";
    for (int i = 0; i < contacts.size(); i++)
    {

        cout << "Name: " << contacts[i].name << ", Phone: " << contacts[i].phone << ", Email: " << contacts[i].email << endl;
    }
}

void searchContact(string searchText, vector<Contact> contacts)
{
    for (int i = 0; i < contacts.size(); i++)
    {
        if (contacts[i].name.find(searchText) != string::npos)
        {
            cout << "Name: " << contacts[i].name << ", Phone: " << contacts[i].phone << ", Email: " << contacts[i].email << endl;
        }
    }
}

vector<Contact> deleteContact(string searchText, vector<Contact> contacts)
{

    for (int i = 0; i < contacts.size(); i++)
    {
        if (contacts[i].name.find(searchText) != string::npos)
        {
            contacts.erase(contacts.begin() + i);
        }
    }
    return contacts;
}

int main()
{
    int choice;
    vector<Contact> contacts;

    do
    {
        cout << "1. Add Contact" << endl;
        cout << "2. View All Contacts" << endl;
        cout << "3. Search Contact by Name" << endl;
        cout << "4. Delete Contact by Name" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            contacts.push_back(addContact());
            cout << "Contact Added!" << endl;

            break;
        }
        case 2:
            viewContacts(contacts);
            break;
        case 3:
        {
            string searchText;
            cout << "Please enter name to search" << endl;
            cin >> searchText;
            searchContact(searchText, contacts);
            break;
        }
        case 4:
        {
            string searchText;
            cout << "Please enter name to delete" << endl;
            cin >> searchText;
            contacts = deleteContact(searchText, contacts);
            cout << "Contact deleted!" << endl;
            break;
        }
        case 5:
            exit(0);
            break;

        default:
            break;
        }

    } while (choice != 5);

    return 0;
}
