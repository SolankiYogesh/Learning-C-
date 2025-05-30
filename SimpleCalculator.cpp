#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
    char choice;
    int first;
    int second;
    char operation;
    do
    {
        system("clear");
        cout << "Enter first number: ";
        cin >> first;
        cout << endl;
        cout << "Enter second number: ";
        cin >> second;
        cout << endl;
        cout << "Enter operation (+, -, *, /, %): ";
        cin >> operation;
        cout << endl;
        int result;
        bool isError = false;
        switch (operation)
        {
        case '/':
        {
            if (operation == '/' && second == 0)
            {
                cout << "Error: Cannot divide by zero." << endl;
                isError = true;
                break;
            }
            result = first / second;
            break;
        }
        case '%':
        {

            result = first % second;
            break;
        }
        case '+':
        {

            result = first + second;
            break;
        }
        case '-':
        {

            result = first - second;
            break;
        }
        case '*':
        {

            result = first * second;

            break;
        }

        default:
            cout << "you enter wrong operation choice" << endl;
            isError = true;
            break;
        }
        if (!isError)
        {
            cout << "Result:" << first << " " << operation << " " << second << " " << "= " << result << endl;
        }

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;
        if (!(choice == 'y' || choice == 'n'))
        {
            cout << "Please enter valid choice";
        }
    } while (choice == 'y');
    cout << "Goodbye!";
    return 0;
}
