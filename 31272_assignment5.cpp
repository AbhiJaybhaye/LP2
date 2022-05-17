#include <bits/stdc++.h>
using namespace std;

bool mobileverify(string mn) {
    if (mn.length() == 10) {
        return true;
    }
    return false;
}

int main() {
    int choice1, choice2;
    cout << "Welcome in wifi's!" << endl;
    cout << "we provide broadband connection service\n"
         << endl;
    cout << "1.New Broadband Connection\n2.Renew Broadband\n3.Remove Connection\n4.Request Callback\n5.End chatbot" << endl;
    cout << "choose an option to start : ";
    cin >> choice1;
    string fname;
    string lname;
    string mn;
    string pc; // full name, mobile number, pincode
    bool confirmed = false;
    while (choice1 != 5) {
        switch (choice1) {
        case 1:
            cout << "\nThanks for choosing us" << endl;
            cout << "Please fill the form\n"
                 << endl;
            confirmed = false;
            while (!confirmed) {
                cout << "enter first name : ";
                cin >> fname;
                cout << "enter last name : ";
                cin >> lname;
                cout << "enter mobile number : ";
                cin >> mn;

                while (!mobileverify(mn)) {
                    cout << "\nonly 10 digit mobile number is allowed\n"
                         << endl;
                    cout << "enter mobile number : ";
                    cin >> mn;
                }

                cout << "enter pincode number : ";
                cin >> pc;

                cout << "\nPlease verify details => " << endl;
                cout << "First Name : " << fname << endl;
                cout << "Last Name : " << lname << endl;
                cout << "Mobile Number : " << mn << endl;
                cout << "Address : " << pc << endl;

                cout << "\n1. Proceed\n2. Change details\nEnter choice : ";
                cin >> choice2;

                if (choice2 == 1) {
                    confirmed = true;
                } else if (choice2 != 2) {
                    cout << "you have entered wrong option" << endl;
                }
            }

            cout << "\nThank you so much for filling details, we will get back to you very soon\n"
                 << endl;
            break;

        case 2:
            cout << "\nThanks for staying with us" << endl;
            cout << "Please give us your mobile number\n"
                 << endl;
            confirmed = false;
            while (!confirmed) {
                cout << "enter mobile number : ";
                cin >> mn;

                while (!mobileverify(mn)) {
                    cout << "\nonly 10 digit mobile number is allowed\n"
                         << endl;
                    cout << "enter mobile number : ";
                    cin >> mn;
                }

                cout << "\nPlease verify details => " << endl;
                cout << "Mobile Number : " << mn << endl;

                cout << "\n1. Proceed\n2. Change details\nEnter choice : ";
                cin >> choice2;

                if (choice2 == 1) {
                    confirmed = true;
                } else if (choice2 != 2) {
                    cout << "you have entered wrong option" << endl;
                }
            }

            cout << "\nThank you so much, Your broadband connection is renewed successfully.\n"
                 << endl;
            break;

        case 3:
            cout << "\nWe are sorry to hear that!" << endl;
            cout << "Please give us your mobile number\n"
                 << endl;
            confirmed = false;
            while (!confirmed) {
                cout << "enter mobile number : ";
                cin >> mn;

                while (!mobileverify(mn)) {
                    cout << "\nonly 10 digit mobile number is allowed\n"
                         << endl;
                    cout << "enter mobile number : ";
                    cin >> mn;
                }

                cout << "\nPlease verify details => " << endl;
                cout << "Mobile Number : " << mn << endl;

                cout << "\n1. Proceed\n2. Change details\nEnter choice : ";
                cin >> choice2;

                if (choice2 == 1) {
                    confirmed = true;
                } else if (choice2 != 2) {
                    cout << "you have entered wrong option" << endl;
                }
            }

            cout << "\nYour broadband connection will be removed soon.\n"
                 << endl;
            break;

        case 4:
            cout << "\nPlease give us your mobile number\n"
                 << endl;
            confirmed = false;
            while (!confirmed) {
                cout << "enter mobile number : ";
                cin >> mn;

                while (!mobileverify(mn)) {
                    cout << "\nonly 10 digit mobile number is allowed\n"
                         << endl;
                    cout << "enter mobile number : ";
                    cin >> mn;
                }

                cout << "\nPlease verify details => " << endl;
                cout << "Mobile Number : " << mn << endl;

                cout << "\n1. Proceed\n2. Change details\nEnter choice : ";
                cin >> choice2;

                if (choice2 == 1) {
                    confirmed = true;
                } else if (choice2 != 2) {
                    cout << "you have entered wrong option" << endl;
                }
            }

            cout << "\nOur service executive will call you very soon.\n"
                 << endl;
            break;

        default:
            cout << "\nPlease Enter valid choice\n"
                 << endl;
            break;
        }

        cout << "1.New Broadband Connection\n2.Renew Broadband\n3.Remove Connection\n4.Request Callback\n5.End chatbot" << endl;
        cout << "choose an option to start : ";
        cin >> choice1;
    }
}