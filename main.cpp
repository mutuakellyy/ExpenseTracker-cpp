#include "database.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Database db("expenses.db");
    db.createTable();

    int choice;
    do {
        cout << "\n=== Expense Tracker Menu ===\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Delete Expense\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string category, date;
            double amount;
            cout << "Enter category: ";
            cin >> category;
            cout << "Enter amount: ";
            cin >> amount;
            cout << "Enter date (YYYY-MM-DD): ";
            cin >> date;
            db.addExpense(category, amount, date);
        }
        else if (choice == 2) {
            db.viewExpenses();
        }
        else if (choice == 3) {
            int id;
            cout << "Enter expense ID to delete: ";
            cin >> id;
            db.deleteExpense(id);
        }
    } while (choice != 4);

    cout << "Goodbye!\n";
    return 0;
}
