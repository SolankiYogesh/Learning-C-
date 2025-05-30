#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct User
{
    string username;
    string password;
};

int checkIsLogin(string username, string password)
{
    ifstream file("users.txt");
    int status;
    if (file)
    {
        string line;

        while (getline(file, line))
        {
            stringstream ss(line);
            string u, p;
            getline(ss, u, ',');
            getline(ss, p);

            if (u == username)
            {
                if (p == password)
                    return 200;
                else
                    return 205;
            }
        }
        return 404;
    }
    else
    {
        return 1;
    }
}

bool checkIsRegister(string username)
{
    ifstream file("users.txt");
    if (file)
    {
        string line;

        while (getline(file, line))
        {
            stringstream ss(line);
            string u;
            getline(ss, u, ',');

            if (u == username)
            {
                return true;
            }
        }
    }
    return false;
}
void showToast(int status)
{
    string text;
    switch (status)
    {
    case 200:
        text = "Login successful!";
        break;
    case 205:
        text = "Your password is wrong!";
        break;
    case 404:
        text = "user not found!";
        break;
    case 1:
        text = "";
        break;

    default:
        text = "something went wrong";
        break;
    }
    if (text.size() > 0)
    {
        cout << text << endl;
    }
}

void signUp()
{
    cin.ignore();
    string username, password;
    cout << "Enter username: " << endl;
    getline(cin, username);
    cout << "Enter password: " << endl;
    getline(cin, password);
    bool isRegistered = checkIsRegister(username);
    if (!isRegistered)
    {
        ofstream file("users.txt", ios::app);
        file << username << "," << password << endl;
        cout << "Registration successful!" << endl;
    }
    else
    {
        cout << "user already exist. Please login!" << endl;
        return;
    }
}

void login()
{
    cin.ignore();
    string username, password;
    cout << "Enter username: " << endl;
    getline(cin, username);
    cout << "Enter password: " << endl;
    getline(cin, password);
    showToast(checkIsLogin(username, password));
}

int main(int argc, char const *argv[])
{
    int choice;
    do
    {
        cout << "\n----- Welcome to Login System -----\n";
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            signUp();
            break;
        case 2:
            login();
            break;

        default:
            cout << "Please enter valid choice" << endl;
            break;
        }
    } while (choice != 3);
    return 0;
}
