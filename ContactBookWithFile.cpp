#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>

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
    cin.ignore();
    cout << "Please enter contact name" << endl;
    getline(cin, name);
    cout << "Please enter contact phone" << endl;
    getline(cin, phone);
    cout << "Please enter contact email" << endl;
    getline(cin, email);
    Contact contact;
    contact.name = name;
    contact.phone = phone;
    contact.email = email;

    return contact;
}

void viewContacts(vector<Contact> contacts)
{
    if (contacts.size() > 0)
    {
        cout << "\n--- Contacts List ---\n";
    }
    for (int i = 0; i < contacts.size(); i++)
    {

        cout << "Name: " << contacts[i].name << ", Phone: " << contacts[i].phone << ", Email: " << contacts[i].email << endl;
    }
}

void searchContact(string searchText, vector<Contact> contacts)
{
    bool isFound = false;
    for (int i = 0; i < contacts.size(); i++)
    {
        if (contacts[i].name.find(searchText) != string::npos)
        {
            cout << "Name: " << contacts[i].name << ", Phone: " << contacts[i].phone << ", Email: " << contacts[i].email << endl;
            isFound = true;
        }
    }
    if (!isFound)
    {
        cout << "No contact found" << endl;
    }
}

vector<Contact> deleteContact(string searchText, vector<Contact> contacts)
{
    vector<Contact> updated;
    char choice;
    bool isFound = false;
    for (int i = 0; i < contacts.size(); i++)
    {
        if (contacts[i].name.find(searchText) == string::npos)
        {

            updated.push_back(contacts[i]);
        }
        else
        {
            cout << "Are you sure you want to delete this contact? (y/n)";
            cin >> choice;
            if (choice == 'n')
            {
                updated.push_back(contacts[i]);
            }
            isFound = true;
        }
    }

    if (!isFound)
    {
        cout << "No contact found" << endl;
    }
    return updated;
}

void addToFile(vector<Contact> contacts)
{
    ofstream file("contacts.txt");
    file.clear();
    for (int i = 0; i < contacts.size(); i++)
    {
        file << contacts[i].name << "," << contacts[i].phone << "," << contacts[i].email << endl;
    }
    file.close();
}

int main()
{

    int choice;
    vector<Contact> contacts;
    ifstream file("contacts.txt");
    string line;
    if (file)
    {
        while (getline(file, line))
        {
            string words[3];
            int index = 0;
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] != ',')
                {
                    words[index] += line[i];
                }
                else
                {
                    index++;
                }
            }
            Contact contact;
            contact.name = words[0];
            contact.phone = words[1];
            contact.email = words[2];
            contacts.push_back(contact);
        }
    }

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
            Contact contact = addContact();
            contacts.push_back(contact);
            addToFile(contacts);
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
            addToFile(contacts);
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
