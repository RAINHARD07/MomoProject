#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

// Constants
const string Default_Pin = "0000"; // Default PIN
const float Default_Balance = 1000.00; // Default balance
const int Max_Pin_Tries = 3; // Maximum number of PIN tries before program exits

// Global variables
string pin = Default_Pin;
float balance = Default_Balance;

// Function prototypes
bool authenticate();
void resetPin();
void checkBalance();
void sendMoney();
//void exitProgram();

int main() {
    int choice;

    do {
        // Display menu
        cout << "Rainhard Mobile Money Service Platform" << endl; 
        cout << "1. Authenticate" << endl;
        cout << "2. Reset PIN" << endl;
        cout << "3. Check balance" << endl;
        cout << "4. Send money" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (!authenticate()) {
                    cout << "Authentication failed. Program will exit." << endl;
                    exit(0);
                }
                break;
            case 2:
                resetPin();
                break;
            case 3:
                checkBalance();
                break;
            case 4:
                sendMoney();
                break;
            case 5:
              exit(0);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    
}

// Authenticates the user by verifying their PIN
bool authenticate() {
    string userPin;
    int pinTries = 0;

    while (pinTries < Max_Pin_Tries) {
        cout << "Enter your PIN: ";
        cin >> userPin;

        if (userPin == pin) {
            cout << "Authentication successful." << endl;
            return true;
        }
        else {
            cout << "Authentication failed. Please try again." << endl;
            pinTries++;
        }
    }
    

    // If maximum number of PIN tries is reached, exit program
    if (pinTries == Max_Pin_Tries) {
        cout << "Maximum number of PIN tries reached. Program will exit." << endl;
         exit(0);
     }

    return false;
}

// Resets the user's PIN
void resetPin() {
    string newPin;

    if (authenticate()) {
        cout << "Enter your new PIN: ";
        cin >> newPin;
        pin = newPin;
        cout << "PIN reset successful." << endl;
    }
}

// Displays the user's balance
void checkBalance() {
    if (authenticate()) {
        cout << "Your balance is: " << balance << endl;
    }
}

// Sends money to another user
void sendMoney() {
    string recipient;
    float amount;

    if (authenticate()) {
        cout << "Enter recipient's mobile number: ";
        cin >> recipient;
        cout << "Enter amount to send: ";
        cin >> amount;

        if (amount > balance) {
            cout << "Insufficient balance. Transaction failed." << endl;
        }
        else {
            balance -= amount;
            cout << "Transaction successful. " << amount << " sent to " << recipient << "." << endl;
        }
    }
    
     return ; 
}




    
  

