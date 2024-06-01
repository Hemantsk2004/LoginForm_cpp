#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class temp {
    string username, email, password;
    fstream file;
public:
    void Login();
    void SignUP();
    void Forgot();
} obj;

void temp::SignUP() {
    cout << "Enter Username: ";
    cin.ignore(); // To clear the buffer
    getline(cin, username);           //getline(): Reads an entire line of input, including spaces
    cout << "Enter Email address: ";
    getline(cin, email);
    cout << "Enter Password: ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);    //(ios::app), which means new data will be added at the end of the file.  //ios::out--used for data writing   ios::in--used for data
    if (file.is_open()) {
        file << username << "*" << email << "*" << password << endl;
        file.close();
        cout << "Sign-Up successful!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}

void temp::Login() {
    string searchuser, searchpass;
    cout << "--------------Login--------------" << endl;
    cout << "Enter Username: ";
    cin.ignore(); // To clear the buffer
    getline(cin, searchuser);
    cout << "Enter Password: ";
    getline(cin, searchpass);

    file.open("loginData.txt", ios::in);
    if (file.is_open()) {
        while (getline(file, username, '*')) {
            getline(file, email, '*');
            getline(file, password);

            if (username == searchuser) {
                if (password == searchpass) {
                    cout << "Account login successful" << endl;
                    file.close();
                    return;
                } else {
                    cout << "Incorrect password" << endl;
                    file.close();
                    return;
                }
            }
        }
        cout << "Username not found, try again" << endl;
        file.close();
    } else {
        cout << "Error opening file!" << endl;
    }
}

void temp::Forgot() {
    string searchuser, searchemail;
    cout << "Enter username: ";
    cin.ignore(); // To clear the buffer
    getline(cin, searchuser);
    cout << "Enter Email: ";
    getline(cin, searchemail);

    file.open("loginData.txt", ios::in);
    if (file.is_open()) {
        while (getline(file, username, '*')) {
            getline(file, email, '*');
            getline(file, password);

            if (username == searchuser && email == searchemail) {
                cout << "Account Found" << endl;
                cout << "Your Password: " << password << endl;
                file.close();
                return;
            }
        }
        cout << "Account not found! Enter correct username and email." << endl;
        file.close();
    } else {
        cout << "Error opening file!" << endl;
    }
}

int main() {
    char choice;
        cout << "-->1. Login" << endl;
        cout << "-->2. Sign-Up" << endl;
        cout << "-->3. Forgot password" << endl;
        cout << "-->4. Exit" << endl;
        cout << "If you don't have an account, please Sign-Up." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            obj.Login();
            break;
        case '2':
            obj.SignUP();
            break;
        case '3':
            obj.Forgot();
            break;
        case '4':
            return 0;
        default:
            cout << "Invalid Input" << endl;
        }

    return 0;
}