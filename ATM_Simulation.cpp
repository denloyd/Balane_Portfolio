#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
#include <windows.h>
#define MAX 10

using namespace std;

struct Account {
    int accountNumber;
    string accountName;
    string contactNum, birthday;
    double balance;
    string pinCode;
};

class ATM {
private:
    Account acc[MAX];
    int account = 0;

public:
    void saveAccounts();
    void loadAccounts();
    void createAcc();
    void withdraw(int numAcc);
    void deposit(int numAcc);
    void balance(int numAcc);
    void fundTransfer(int numAcc);
    void changePin(int numAcc);
    int checker();
    void compareAccountInfo();
    void transactionMode(int numAcc);
};

void ATM::loadAccounts() {
    ifstream inputFile("D:\\ACCOUNTS.txt");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            if (line.find("Account number: ") != string::npos) {
                int accountNumber;
                string accountName, contactNum, birthday, pinCode;
                double balance;

                accountNumber = stoi(line.substr(line.find(":") + 2));
                getline(inputFile, line);
                accountName = line.substr(line.find(":") + 2);
                getline(inputFile, line);
                contactNum = line.substr(line.find(":") + 2);
                getline(inputFile, line);
                birthday = line.substr(line.find(":") + 2);
                getline(inputFile, line);
                balance = stod(line.substr(line.find(":") + 2));
                getline(inputFile, line);
                pinCode = line.substr(line.find(":") + 2);

                acc[account] = { accountNumber, accountName, contactNum, birthday, balance, pinCode };
                account++;
            }
        }
        inputFile.close();
    }
}

void ATM::saveAccounts() {
    ofstream outputFile("D:\\ACCOUNTS.txt");
    if (outputFile.is_open()) {
        for (int i = 0; i < account; i++) {
            outputFile << "Account number: " << acc[i].accountNumber << endl;
            outputFile << "Name: " << acc[i].accountName << endl;
            outputFile << "Contact number: " << acc[i].contactNum << endl;
            outputFile << "Birthday: " << acc[i].birthday << endl;
            outputFile << "Balance: " << acc[i].balance << endl;
            outputFile << "Pin Code: " << acc[i].pinCode << endl;
            outputFile << "-----------------------------------" << endl;
        }
        outputFile.close();
    } else {
        cerr << "Failed to open the file for writing." << endl;
    }
}
void ATM::createAcc() {
    int accountNumber;
    string accountName, birthday, contactNum, pinCode;
    double initialBalance;

    if (account < MAX) {
        while (true) {
            cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter account number (5 digits only): ";
            cin >> accountNumber;

            if (accountNumber >= 10000 && accountNumber <= 99999) {
                break; // Valid account number, exit the loop
            } else {
                cout << "\n\t\t\t\t\t\tInvalid account number. Please enter a 5-digits only account number." << endl;
            }
        }

        cout << "\n\t\t\t\t\t\tEnter account name: ";
        cin.ignore();
        getline(cin, accountName);

        cout << "\n\t\t\t\t\t\tEnter contact number: ";
        cin >> contactNum;

        while (true) {
            cout << "\n\t\t\t\t\t\tEnter birthday (YYYY-MM-DD): ";
            cin >> birthday;

            // Check if the birthday is in the correct format (YYYY-MM-DD)
            if (birthday.size() == 10 &&
                birthday[4] == '-' && birthday[7] == '-' &&
                isdigit(birthday[0]) && isdigit(birthday[1]) &&
                isdigit(birthday[2]) && isdigit(birthday[3]) &&
                isdigit(birthday[5]) && isdigit(birthday[6]) &&
                isdigit(birthday[8]) && isdigit(birthday[9])) {
                break; // Valid format, exit the loop
            } else {
                cout << "\n\t\t\t\t\t\tInvalid birthday format. Please enter a valid format (YYYY-MM-DD)." << endl;
            }
        }

        cout << "\n\t\t\t\t\t\tEnter initial balance(Min. 5000): ";
        cin >> initialBalance;

        cout << "\n\t\t\t\t\t\tEnter PIN (Max to 6 digits): ";
        cin.ignore();
        char c;
       pinCode = "";
        while (true) {
        c = _getch();
        if (c == 13) { // Enter key
            if (pinCode.length() <= 6) {
                break;
            } else {
                cout << "\nPIN should be up to 6 digits. Try again: ";
                pinCode = "";
            }
        } else if (c == 8) { // Backspace
            if (!pinCode.empty()) {
                cout << "\b \b";
                pinCode.pop_back();
            }
        } else if (c >= '0' && c <= '9') {
            if (pinCode.length() < 6) {
                cout << '*';
                pinCode += c;
            }
        }
    }

        acc[account] = { accountNumber, accountName, contactNum, birthday, initialBalance, pinCode };
        account++;
        cout << "\n\n\t\t\t\t\t\tAccount successfully created.\n\t\t\t\t\t\t";
        system("pause");
        saveAccounts();
    } else {
        cout << "Cannot create more accounts. Maximum limit reached.\n";
        system("pause");
    }
}


void ATM::withdraw(int numAcc) {
    int withdrawAmount;
    cout << "Enter the amount to withdraw: ";
    cin >> withdrawAmount;

    if (withdrawAmount > 0 && withdrawAmount <= acc[numAcc].balance) {
        acc[numAcc].balance -= withdrawAmount;
        cout << "Withdrawal successful. New balance: " << acc[numAcc].balance << endl;
        system("pause");
        saveAccounts();
    } else {
        cout << "Invalid withdrawal amount or insufficient balance." << endl;
        system("pause");
    }
}

void ATM::deposit(int numAcc) {
    double depositAmount;
    cout << "Enter the amount to deposit: ";
    cin >> depositAmount;

    if (depositAmount > 0) {
        acc[numAcc].balance += depositAmount;
        cout << "Deposit successful. New balance: " << acc[numAcc].balance << endl;
        system("pause");
        saveAccounts();
    } else {
        cout << "Invalid deposit amount." << endl;
        system("pause");
    }
}

void ATM::balance(int numAcc) {
    cout << "Account Balance: " << acc[numAcc].balance << endl;
    system("pause");
}

void ATM::fundTransfer(int numAcc) {
    if (account < 2) {
        cout << "You need at least two accounts to perform a fund transfer." << endl;
        system("pause");
        return;
    }

    int senderAccountNumber, receiverAccountNumber;
    double transferAmount;

    cout << "Enter your account number: ";
    cin >> senderAccountNumber;

    // Find the sender's account index
    int senderIndex = -1;
    for (int i = 0; i < account; i++) {
        if (acc[i].accountNumber == senderAccountNumber) {
            senderIndex = i;
            break;
        }
    }

    if (senderIndex == -1) {
        cout << "Sender account not found." << endl;
        system("pause");
        return;
    }

    cout << "Enter the recipient's account number: ";
    cin >> receiverAccountNumber;

    // Find the receiver's account index
    int receiverIndex = -1;
    for (int i = 0; i < account; i++) {
        if (acc[i].accountNumber == receiverAccountNumber) {
            receiverIndex = i;
            break;
        }
    }

    if (receiverIndex == -1) {
        cout << "Receiver account not found." << endl;
        system("pause");
        return;
    }

    cout << "Enter the amount to transfer: ";
    cin >> transferAmount;

    if (transferAmount <= 0 || transferAmount > acc[senderIndex].balance) {
        cout << "Invalid transfer amount or insufficient balance." << endl;
        system("pause");
    } else {
        acc[senderIndex].balance -= transferAmount;
        acc[receiverIndex].balance += transferAmount;
        cout << "Fund transfer successful." << endl;
        system("pause");

        // Update account information in the file
        saveAccounts();
    }
}

void ATM::changePin(int numAcc) {
    string currentPin, newPin;

    cout << "Enter your current PIN: ";
    cin.ignore();
    char c;
    currentPin = "";
    while (true) {
        c = _getch();
        if (c == 13) { // Enter key
            if (currentPin.length() <= 6) {
                break;
            } else {
                cout << "\nPIN should be up to 6 digits. Try again: ";
                currentPin = "";
            }
        } else if (c == 8) { // Backspace
            if (!currentPin.empty()) {
                cout << "\b \b";
                currentPin.pop_back();
            }
        } else if (c >= '0' && c <= '9') {
            if (currentPin.length() < 6) {
                cout << '*';
                currentPin += c;
            }
        }
    }

    if (currentPin != acc[numAcc].pinCode) {
        cout << "\nIncorrect current PIN." << endl;
        system("pause");
        return;
    }

    cout << "\nEnter your new PIN: ";
    newPin = "";
    while (true) {
        c = _getch();
        if (c == 13) { // Enter key
            if (newPin.length() <= 6) {
                break;
            } else {
                cout << "\nPIN should be up to 6 digits. Try again: ";
                newPin = "";
            }
        } else if (c == 8) { // Backspace
            if (!newPin.empty()) {
                cout << "\b \b";
                newPin.pop_back();
            }
        } else if (c >= '0' && c <= '9') {
            if (newPin.length() < 6) {
                cout << '*';
                newPin += c;
            }
        }
    }

    acc[numAcc].pinCode = newPin;
    cout << "\nPIN changed successfully." << endl;
    system("pause");


    // Update account information in the file
    saveAccounts();
}

int ATM::checker() {
    ifstream file;
    int p;
    bool driveOpened = false;
    do {
        file.open("D:\\ACCOUNTS.txt");
        if (file.is_open()) {
            driveOpened = true;
        } else {
            cout << "\n\n\t\t\t\t\tPLEASE INSERT YOUR ATM CARD";
            driveOpened = false;
        }
        file >> p >> p;
        file.close();
    } while (!driveOpened);
    return 0;
}

void ATM::compareAccountInfo() {
    bool accountFound = false;
    int accountIndex = -1; // To store the index of the logged-in account

    while (true) {
        int inputAccountNumber;
        string inputPinCode;
        cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter account number: ";
        cin >> inputAccountNumber;
        cout << "\n\t\t\t\t\t\tEnter PIN: ";
        cin.ignore(); // Clear any previous newline character
        char c;
        inputPinCode = "";
        while (true) {
        c = _getch();
        if (c == 13) { // Enter key
            if (inputPinCode.length() <= 6) {
                break;
            } else {
                cout << "\nPIN should be up to 6 digits. Try again: ";
                inputPinCode = "";
            }
        } else if (c == 8) { // Backspace
            if (!inputPinCode.empty()) {
                cout << "\b \b";
                inputPinCode.pop_back();
            }
        } else if (c >= '0' && c <= '9') {
            if (inputPinCode.length() < 6) {
                cout << '*';
               inputPinCode += c;
            }
        }
    }
        /*ifstream inputFile("D:\\ACCOUNTS.txt");
        if (!inputFile.is_open()) {
            cerr << "Error: Unable to open the file." << endl;
            // Handle the error, maybe exit the program or return an error code.
        }*/

        bool found = false;
        string line;

        while (getline(inputFile, line)) {
            if (line.find("Account number: ") != string::npos) {
                int fileAccountNumber;
                string accountName, birthday, contactNum;
                double initialBalance;
                string filePinCode;

                // Extract the account number
                fileAccountNumber = stoi(line.substr(line.find(":") + 2));

                // Read other information
                getline(inputFile, line); // Read the name line
                accountName = line.substr(line.find(":") + 2);

                getline(inputFile, line); // Read the birthday line
                contactNum = line.substr(line.find(":") + 2);

                getline(inputFile, line); // Read the birthday line
                birthday = line.substr(line.find(":") + 2);

                getline(inputFile, line); // Read the balance line
                initialBalance = stod(line.substr(line.find(":") + 2));

                getline(inputFile, line); // Read the PIN line
                filePinCode = line.substr(line.find(":") + 2);

                // Check if the entered PIN matches the stored PIN
                if (inputAccountNumber == fileAccountNumber && inputPinCode == filePinCode) {
                    found = true;
                    cout << "\n\n\t\t\t\t\t\tAccount found:\n";
                    cout << "\n\t\t\t\t\t\tYou can start your transaction\n\t\t\t\t\t\t";
                    system("pause");

                    // Update the accountIndex to point to the logged-in account
                    for (int i = 0; i < account; i++) {
                        if (acc[i].accountNumber == inputAccountNumber) {
                            accountIndex = i;
                            break;
                        }
                    }
                    accountFound = true;
                    break;
                }
            }
        }

       /* inputFile.close();

        if (!found) {
            cout << "\n\n\t\t\t\t\t\tAccount not found or incorrect PIN." << endl;
            cout << "\n\t\t\t\t\t\tPress any key to try again, or 'q' to quit: ";
            char choice;
            cin >> choice;

            if (choice == 'q' || choice == 'Q') {
                break; // Exit the loop and return to the main function
            }
        }*/

        if (accountFound) {
            transactionMode(accountIndex); // Pass the accountIndex to the transactionMode
            break;
        }
    }
}
void ATM::transactionMode(int numAcc) {
    // Use the accountIndex to access the account information in other functions
    int choice;
    while (true) {
        system("cls");
        cout << "\n\n";
        cout << "\t\t\t\t\t        _______ __  __        __  __          _____ _    _ _____ _   _ ______ " << endl;
        cout << "\t\t\t\t\t     /\\|__   __|  \\/  |      |  \\/  |   /\\   / ____| |  | |_   _| \\ | |  ____|" << endl;
        cout << "\t\t\t\t\t    /  \\  | |  | \\  / |      | \\  / |  /  \\ | |    | |__| | | | |  \\| | |__   " << endl;
        cout << "\t\t\t\t\t   / /\\ \\ | |  | |\\/| |      | |\\/| | / /\\ \\|      |  __  | | | | . ` |  __|  " << endl;
        cout << "\t\t\t\t\t  / ____ \\| |  | |  | |      | |  | |/ ____ \\ |____| |  | |_| |_| |\\  | |____ " << endl;
        cout << "\t\t\t\t\t /_/    \\_\\_|  |_|  |_|      |_|  |_/_/    \\_\\_____|_|  |_|_____|_| \\_|______|" << endl;
        cout << "\n\n";
        cout << "\n\n\t\t\t\t\tTRANSACTION MODE";
        cout << "\n\n\t\t\t\t\t1. WITHDRAW";
        cout << "\n\n\t\t\t\t\t2. CHECK BALANCE";
        cout << "\n\n\t\t\t\t\t3. DEPOSIT";
        cout << "\n\n\t\t\t\t\t4. FUND TRANSFER";
        cout << "\n\n\t\t\t\t\t5. CHANGE PIN";
        cout << "\n\n\t\t\t\t\t6. EXIT";

        cout << "\n\n\t\t\t\t\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system("cls");
                withdraw(numAcc);
                break;
            case 2:
                system("cls");
                balance(numAcc);
                break;
            case 3:
                system("cls");
                deposit(numAcc);
                break;
            case 4:
                system("cls");
                fundTransfer(numAcc);
                break;
            case 5:
                system("cls");
                changePin(numAcc);
                break;
            case 6:
                exit(0);
                break;

            default:
                cout << "\n\n\t\t\t\t\tInvalid choice. Please select a valid option.";
        }
    }
}
int main() {
    ATM atm;
    int choice;
    atm.loadAccounts();

    while (true) {
        system("cls");
        system("Color B");
        cout << "\n\n";
        cout << "\t\t\t\t\t        _______ __  __        __  __          _____ _    _ _____ _   _ ______ " << endl;
        cout << "\t\t\t\t\t     /\\|__   __|  \\/  |      |  \\/  |   /\\   / ____| |  | |_   _| \\ | |  ____|" << endl;
        cout << "\t\t\t\t\t    /  \\  | |  | \\  / |      | \\  / |  /  \\ | |    | |__| | | | |  \\| | |__   " << endl;
        cout << "\t\t\t\t\t   / /\\ \\ | |  | |\\/| |      | |\\/| | / /\\ \\|      |  __  | | | | . ` |  __|  " << endl;
        cout << "\t\t\t\t\t  / ____ \\| |  | |  | |      | |  | |/ ____ \\ |____| |  | |_| |_| |\\  | |____ " << endl;
        cout << "\t\t\t\t\t /_/    \\_\\_|  |_|  |_|      |_|  |_/_/    \\_\\_____|_|  |_|_____|_| \\_|______|" << endl;
        cout << "\n\n";
        cout << "\n\n\t\t\t\t\t\t\t\tMENU:\n";
        cout << "\n\n\t\t\t\t\t\t\t1. REGISTRATION MODULE\n";
        cout << "\n\n\t\t\t\t\t\t\t2. TRANSACTION MODULE\n";
        cout << "\n\n\t\t\t\t\t\t\tEnter your choice: ";
        system("Color 0");
        cin >> choice;

        switch (choice) {
            case 1:
                /*atm.checker();*/
                system("cls");
                atm.createAcc();
                break;
            case 2:
                /*atm.checker();*/
                system("cls");
                atm.compareAccountInfo();
                break;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }
}
