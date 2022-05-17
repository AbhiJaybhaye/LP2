/*
 * Problem Statement :-

        Implement any one of the following Expert System.

            I.)   Information Management
            II.)  Hospitals and Medical Facilities
            III.) Help Desk Management
            IV.)  Employee Performance Evaluation
            V.)   Stock Market Trading
            VI.)  Airline Scheduling And Cargo Schedules
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "\n\n\t\t ___ Welcome to COVID-19 Expert system ___\n";

    int covidSuspisionCounter = 0;
    int severity = 0;
    int oxylevel = 0;
    int temp = 0;

    vector<string> ques1 =
        {
            "Does the patient have cough and cold? (yes/no) = ",
            "Is the patient able to recognize smell and taste? (yes/no) = ",
            "Is the patient suffering from sore throat? (yes/no) = ",
            "Is the patient suffering from headache? (yes/no) = ",
            "Is the patient suffering from BP/ diabetes? (yes/no) = ",
            "Has the patient come in a contact of a Covid suspicious person? (yes/no) = "};

    vector<string> ques2 =
        {
            "What is patient's body temparature? (float value) = ",
            "What is the oxygen level? (int value) = ",
            "How many vaccines has the patient taken? (int value) = ",
            "What is patient's age? (int value) = "};

    for (int i = 0; i < ques1.size(); i++) {
        string ans;

        cout << "\n\t " << ques1[i];
        cin >> ans;

        if (i != 1 && ans == "yes") {
            covidSuspisionCounter += 1;
        } else if (i == 1 && ans == "no") {
            covidSuspisionCounter += 1;
        } else {
            cout << "\n\t "
                 << "Please enter correct choice ( yes/no )" << endl;
            i--;
        }
    }

    for (int i = 0; i < ques2.size(); i++) {
        cout << "\n\t " << ques2[i];
        if (i == 0) {
            float ans;
            cin >> ans;

            if (ans >= 101.0) {
                severity += 2;
                covidSuspisionCounter += 1;
                temp = 1;
            } else if (ans < 101.0 && ans >= 99.6) {
                severity += 1;
            } else {
                severity += 0;
            }
        } else if (i == 1) {
            int ans;
            cin >> ans;

            if (ans >= 94) {
                severity += 0;
            } else if (ans < 94 and ans > 87) {
                severity += 1;
            } else {
                severity += 2;
                covidSuspisionCounter += 1;
                oxylevel = 1;
            }
        } else if (i == 2) {
            int ans;
            cin >> ans;

            if (ans == 0) {
                severity += 2;
            } else if (ans == 1) {
                severity += 1;
            } else if (ans == 2) {
                severity += 0;
            } else {
                cout << "\n\t"
                     << " Please Enter correct count of vaccines ( <=2 ) " << endl;
                i--;
            }
        } else if (i == 3) {
            int ans;
            cin >> ans;

            if (ans > 12 and ans < 31) {
                severity += 0;
            } else if (ans > 31 and ans < 51) {
                severity += 1;
            } else {
                severity += 2;
            }
        }
    }

    cout << "\n\t --------------- Conclusion --------------- \n\n";

    if (covidSuspisionCounter > 3) {
        cout << "\n\t The patient is probably covid positive\n";

        if (severity < 3) {
            cout << "\n\t It looks like the symptoms are mild \n\t Home Quarantine\n";
        } else if (severity >= 3 and severity < 6) {
            cout << "\n\t The patient can get an admission in the general ward\n";
        } else {
            cout << "\n\t The patient looks critical\n";
        }
    } else {
        cout << "\n\t It looks like patient is not Covid positive\n";
    }

    if (oxylevel == 1) {
        cout << "\n\t Keep monitoring patient's oxygen level\n";
    }
    if (temp == 1) {
        cout << "\n\t Keep monitoring patient's body temperature\n";
    }

    cout << "\n\t I hope this will help you with diagnosis, Thank you !" << endl;
    return 0;
}
