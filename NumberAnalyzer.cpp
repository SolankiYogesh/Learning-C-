#include <iostream>
#include <stdio.h>

using namespace std;

void isOddOrEven(int number)
{
    if (number % 2 == 0)
    {
        cout << "- The number is even." << endl;
    }
    else
    {
        cout << "- The number is odd." << endl;
    }
}

void isPositive(int number)
{
    if (number == 0)
    {
        cout << "- The number is zero." << endl;
    }
    else if (number > 0)
    {
        cout << "- The number is positive." << endl;
    }

    else
    {
        cout << "- The number is negative." << endl;
    }
}

void isPrime(int number)
{
    int count = 0;
    for (int i = 0; i <= number; i++)
    {
        if (number % i == 0)
        {
            count++;
        }
    }
    if (count > 2)
    {
        cout << "- The number is not a prime." << endl;
    }
    else
    {
        cout << "- The number is a prime." << endl;
    }
}

int main(int argc, char const *argv[])
{
    int number;
    char choice;
    do
    {
        system("clear");
        cout << "Enter a number: ";
        cin >> number;
        cout << "Results:" << endl;
        isOddOrEven(number);
        isPositive(number);
        isPrime(number);
        cout << "Do you want to analyze another number? (y/n): ";
        cin >> choice;
        if (!(choice == 'y' || choice == 'n'))
        {
            cout << "Please enter valid choice";
        }
    } while (choice == 'y');

    cout << "Goodbye!";
    return 0;
}
