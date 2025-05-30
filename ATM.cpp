#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
  int balance = 1000;
  int choice;

  cout << "Welcome to the ATM" << endl;
checkBalance:
  cout << "Your starting balance is:" << balance << endl;
startAgain:
  cout << "1. Check Balance" << endl;
  cout << "2. Deposit Money" << endl;
  cout << "3. Withdraw Money" << endl;
  cout << "4. Exit" << endl;
  cin >> choice;

  switch (choice)
  {
  case 1:
    goto checkBalance;
    break;
  case 2:
  {
    int amount;
  enterAmountAgain:
    cout << "Enter amount to deposit:";
    cin >> amount;
    if (amount <= 0)
    {
      cout << "Please enter valid amount" << endl;
      goto enterAmountAgain;
    }
    else
    {
      balance += amount;
      cout << "Deposit successful. New balance:" << balance << endl;
      goto startAgain;
    }

    break;
  }
  case 3:
  {
    int amount;
  enterAmountToWithDraw:
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    if (amount <= 0)
    {
      cout << "Please enter valid amount" << endl;
      goto enterAmountToWithDraw;
    }
    else if (amount > balance)
    {
      cout << "you dont have enough amount to withdraw" << endl;
      goto enterAmountToWithDraw;
    }
    else
    {
      balance -= amount;
      cout << "Withdrawal successful. New balance:" << balance << endl;
      goto startAgain;
    }
    break;
  }
  case 4:
  {
    cout << "Thank you for using the ATM!" << endl;
    exit(0);
  }
  break;

  default:
  {
    cout << "Please enter valid choice" << endl;
    goto startAgain;
  }
  break;
  }
}

// By AI
// #include <iostream>
// using namespace std;

// void showMenu() {
//     cout << "\n1. Check Balance" << endl;
//     cout << "2. Deposit Money" << endl;
//     cout << "3. Withdraw Money" << endl;
//     cout << "4. Exit" << endl;
//     cout << "Choose an option: ";
// }

// int main() {
//     int balance = 1000;
//     int choice;

//     cout << "Welcome to the ATM" << endl;

//     do {
//         showMenu();
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Your current balance is: " << balance << endl;
//                 break;

//             case 2: {
//                 int amount;
//                 cout << "Enter amount to deposit: ";
//                 cin >> amount;
//                 if (amount > 0) {
//                     balance += amount;
//                     cout << "Deposit successful. New balance: " << balance << endl;
//                 } else {
//                     cout << "Invalid amount. Try again." << endl;
//                 }
//                 break;
//             }

//             case 3: {
//                 int amount;
//                 cout << "Enter amount to withdraw: ";
//                 cin >> amount;
//                 if (amount <= 0) {
//                     cout << "Invalid amount. Try again." << endl;
//                 } else if (amount > balance) {
//                     cout << "Insufficient balance." << endl;
//                 } else {
//                     balance -= amount;
//                     cout << "Withdrawal successful. New balance: " << balance << endl;
//                 }
//                 break;
//             }

//             case 4:
//                 cout << "Thank you for using the ATM!" << endl;
//                 break;

//             default:
//                 cout << "Invalid choice. Please try again." << endl;
//         }

//     } while (choice != 4);

//     return 0;
// }
