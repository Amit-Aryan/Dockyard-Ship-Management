#include <iostream>
using namespace std;

// Ship structure with Linked List
struct Ship {
    int id;
    string name;
    string captain;
    string arrival;
    string departure;
    Ship* next;
};

Ship* head = NULL;

// Add Ship
void addShip() {
    Ship* newShip = new Ship;

    cout << "Enter Ship ID: ";
    cin >> newShip->id;

    cin.ignore();
    cout << "Enter Ship Name: ";
    getline(cin, newShip->name);

    cout << "Enter Captain Name: ";
    getline(cin, newShip->captain);

    cout << "Enter Arrival Time: ";
    getline(cin, newShip->arrival);

    cout << "Enter Departure Time: ";
    getline(cin, newShip->departure);

    newShip->next = NULL;

    if (head == NULL) {
        head = newShip;
    }
    else {
        Ship* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newShip;
    }

    cout << "Ship added successfully!\n";
}

// Display Ships
void displayShips() {

    if (head == NULL) {
        cout << "No ships available.\n";
        return;
    }

    Ship* temp = head;

    while (temp != NULL) {

        cout << "\nShip ID: " << temp->id;
        cout << "\nShip Name: " << temp->name;
        cout << "\nCaptain: " << temp->captain;
        cout << "\nArrival: " << temp->arrival;
        cout << "\nDeparture: " << temp->departure;
        cout << "\n-------------------------\n";

        temp = temp->next;
    }
}

// Search Ship
void searchShip() {

    int id;
    cout << "Enter Ship ID to search: ";
    cin >> id;

    Ship* temp = head;

    while (temp != NULL) {

        if (temp->id == id) {

            cout << "\nShip Found:\n";
            cout << "Name: " << temp->name << endl;
            cout << "Captain: " << temp->captain << endl;
            cout << "Arrival: " << temp->arrival << endl;
            cout << "Departure: " << temp->departure << endl;

            return;
        }

        temp = temp->next;
    }

    cout << "Ship not found.\n";
}

// Delete Ship
void deleteShip() {

    int id;
    cout << "Enter Ship ID to delete: ";
    cin >> id;

    Ship* temp = head;
    Ship* prev = NULL;

    if (temp != NULL && temp->id == id) {

        head = temp->next;
        delete temp;
        cout << "Ship deleted successfully.\n";
        return;
    }

    while (temp != NULL && temp->id != id) {

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Ship not found.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;

    cout << "Ship deleted successfully.\n";
}

// Main menu
int main() {

    int choice;

    while (true) {

        cout << "\n===== Ship Port Management System =====\n";
        cout << "1. Add Ship\n";
        cout << "2. Display Ships\n";
        cout << "3. Search Ship\n";
        cout << "4. Delete Ship\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                addShip();
                break;

            case 2:
                displayShips();
                break;

            case 3:
                searchShip();
                break;

            case 4:
                deleteShip();
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}