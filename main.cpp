#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    int id;
    int pass;
    int abs;
    string phone;
    string address;
    string email;
    string department;

public:
    Employee() {} // default constructor

    Employee(string n, int i, int p, string ph, string addr, string em, string dept) {
        name = n;
        id = i;
        pass = p;
        abs = 15;
        phone = ph;
        address = addr;
        email = em;
        department = dept;
    }

    int getId() {
        return id;
    }

    bool login(int id1, int pass1) {
        if (id == id1 && pass == pass1) {
            cout << "\n*****___Login Successful___*****\n";
            return true;
        }
        return false;
    }

    void Menu() {
        int choice;
        do {
            cout << "\n***===== MENU =====***\n";
            cout << "1. List of Holidays\n";
            cout << "2. Total Absents\n";
            cout << "3. Show Profile\n";
            cout << "4. Update Profile\n";
            cout << "5. Change Password\n";
            cout << "6. Logout\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch(choice) {
                case 1: Holidays(); break;
                case 2: Absents(); break;
                case 3: Profile(); break;
                case 4: Profile_update(); break;
                case 5: changePassword(); break;
                case 6: cout << "Logging out...\n"; break;
                default: cout << "Invalid Choice\n";
            }
        } while(choice != 6);
    }

    void Holidays() {
        cout << "\n---- Indian Holidays ----\n";
        cout << "1. Jan 26  - Republic Day\n";
        cout << "2. Mar 25  - Holi\n";
        cout << "3. Aug 15  - Independence Day\n";
        cout << "4. Oct 2   - Gandhi Jayanti\n";
        cout << "5. Nov 3   - Diwali\n";
    }

    void Absents() {
        cout << "\nTotal Absents: " << abs << " days\n";
    }

    void Profile() {
        cout << "\n|------*****---- Profile ----*****------|\n";
        cout << "| Name       : " << name << endl;
        cout << "| ID         : " << id << endl;
        cout << "| Phone      : " << phone << endl;
        cout << "| Email      : " << email << endl;
        cout << "| Department : " << department << endl;
        cout << "| Address    : " << address << endl;
        cout << "|_________________________________________|\n";
    }

    void Profile_update() {
        cout << "\n---- Update Profile ----\n";

        cout << "Enter Phone: ";
        cin >> phone;

        cout << "Enter Email: ";
        cin >> email;

        cout << "Enter Department: ";
        cin >> department;

        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, address);

        cout << "---Profile Updated Successfully---\n";
    }

    void changePassword() {
        int oldPass, newPass;
        cout << "Enter old password: ";
        cin >> oldPass;

        if (oldPass == pass) {
            cout << "Enter new password: ";
            cin >> newPass;
            pass = newPass;
            cout << "Password updated successfully\n";
        } else {
            cout << "Wrong password\n";
        }
    }
};

int main() {
    Employee e[5];

    string name, phone, address, email, department;
    int id, pass;

    cout << "***** STUDENT REGISTRATION *****\n";

    // Input for 5 students with unique ID condition
    for (int i = 0; i < 5; i++) {
        cout << "\nEnter details for Student " << i + 1 << endl;

        cout << "Enter Name: ";
        cin >> name;

        // Unique ID check
        while (true) {
            cout << "Enter ID: ";
            cin >> id;

            bool exists = false;
            for (int j = 0; j < i; j++) {
                if (e[j].getId() == id) {
                    exists = true;
                    break;
                }
            }

            if (exists) {
                cout << "ID already exists! Enter different ID.\n";
            } else {
                break;
            }
        }

        cout << "Enter Password: ";
        cin >> pass;

        cout << "Enter Phone: ";
        cin >> phone;

        cout << "Enter Email: ";
        cin >> email;

        cout << "Enter Department: ";
        cin >> department;

        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, address);

        e[i] = Employee(name, id, pass, phone, address, email, department);
    }

    cout << "\n***** STUDENT PORTAL LOGIN *****\n";

    int id1, pass1;
    cout << "Enter User ID: ";
    cin >> id1;
    cout << "Enter Password: ";
    cin >> pass1;

    bool found = false;

    // Check login for all 5 users
    for (int i = 0; i < 5; i++) {
        if (e[i].login(id1, pass1)) {
            e[i].Menu();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\n*****___Invalid Credentials___*****\n";
    }

    return 0;
}
