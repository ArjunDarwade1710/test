#include <iostream>
using namespace std;

class Employee {
    int empID;
    char name[50];
    char email[30];
    char contactNo[15];  // Room for 10-digit numbers + '\0'

public:
    void getData();
    void display();
    void update(int id);
    void search(int id);
    int getID();  // Getter for empID
};

// Function to input employee data
void Employee::getData() {
    cout << "Enter Employee ID: ";
    cin >> empID;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Email: ";
    cin >> email;
    cout << "Enter Contact No: ";
    cin >> contactNo;
}

// Function to display employee data
void Employee::display() {
    cout << "\nEmployee ID: " << empID;
    cout << "\nName: " << name;
    cout << "\nEmail: " << email;
    cout << "\nContact No: " << contactNo << endl;
}

// Function to update employee details by ID
void Employee::update(int id) {
    if (empID == id) {
        int ch;
        do {
            cout << "\nWhat do you want to update?";
            cout << "\n1. Employee ID";
            cout << "\n2. Name";
            cout << "\n3. Email";
            cout << "\n4. Contact No";
            cout << "\n5. Exit";
            cout << "\nEnter your choice: ";
            cin >> ch;

            switch (ch) {
                case 1:
                    cout << "Enter new Employee ID: ";
                    cin >> empID;
                    break;
                case 2:
                    cout << "Enter new Name: ";
                    cin >> name;
                    break;
                case 3:
                    cout << "Enter new Email: ";
                    cin >> email;
                    break;
                case 4:
                    cout << "Enter new Contact No: ";
                    cin >> contactNo;
                    break;
                case 5:
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        } while (ch != 5);
    }
}

// Function to search for an employee by ID
void Employee::search(int id) {
    if (empID == id) {
        cout << "\nEmployee Found:\n";
        display();
    }
}

// Getter for empID
int Employee::getID() {
    return empID;
}

// Function to delete an employee by ID
void deleteEmployee(Employee empArr[], int &n, int delID) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (empArr[i].getID() == delID) {
            for (int j = i; j < n - 1; j++) {
                empArr[j] = empArr[j + 1];
            }
            n--;
            found = true;
            cout << "Employee deleted successfully.\n";
            break;
        }
    }
    if (!found) {
        cout << "Employee with ID " << delID << " not found.\n";
    }
}

// Main function
int main() {
    Employee empArr[50];
    int n, i, choice, id, t;

    cout << "Enter number of employees to add initially: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        empArr[i].getData();
    }

    do {
        cout << "\nMENU:";
        cout << "\n1. Insert";
        cout << "\n2. Update";
        cout << "\n3. Delete";
        cout << "\n4. Search";
        cout << "\n5. Display All";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number of employees to insert: ";
                cin >> t;
                for (i = n; i < n + t; i++) {
                    empArr[i].getData();
                }
                n += t;
                break;

            case 2:
                cout << "Enter Employee ID to update: ";
                cin >> id;
                for (i = 0; i < n; i++) {
                    empArr[i].update(id);
                }
                break;

            case 3:
                cout << "Enter Employee ID to delete: ";
                cin >> id;
                deleteEmployee(empArr, n, id);
                break;

            case 4:
                cout << "Enter Employee ID to search: ";
                cin >> id;
                for (i = 0; i < n; i++) {
                    empArr[i].search(id);
                }
                break;

            case 5:
                cout << "\nDisplaying all employee records:\n";
                for (i = 0; i < n; i++) {
                    empArr[i].display();
                }
                break;

            case 6:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}