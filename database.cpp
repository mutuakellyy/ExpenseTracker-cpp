#include "database.h"
#include <iostream>
#include <iomanip>

Database::Database(const std::string& filename) {
    int rc = sqlite3_open(filename.c_str(), &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        db = nullptr;
    } else {
        std::cout << "Connected to database successfully.\n";
    }
}

Database::~Database() {
    if (db) sqlite3_close(db);
}

void Database::createTable() {
    std::string sql = "CREATE TABLE IF NOT EXISTS Expenses("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "Category TEXT,"
                      "Amount REAL,"
                      "Date TEXT);";
    int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

void Database::addExpense(const std::string& category, double amount, const std::string& date) {
    std::string sql = "INSERT INTO Expenses (Category, Amount, Date) VALUES ('" +
                      category + "', " + std::to_string(amount) + ", '" + date + "');";
    int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error inserting data: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Expense added successfully!\n";
    }
}

void Database::viewExpenses() {
    std::string sql = "SELECT * FROM Expenses;";
    sqlite3_stmt* stmt;

    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to fetch data.\n";
        return;
    }

    std::cout << std::left << std::setw(5) << "ID"
              << std::setw(15) << "Category"
              << std::setw(10) << "Amount"
              << std::setw(12) << "Date" << std::endl;
    std::cout << "----------------------------------------\n";

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char* category = sqlite3_column_text(stmt, 1);
        double amount = sqlite3_column_double(stmt, 2);
        const unsigned char* date = sqlite3_column_text(stmt, 3);

        std::cout << std::setw(5) << id
                  << std::setw(15) << category
                  << std::setw(10) << amount
                  << std::setw(12) << date << std::endl;
    }

    sqlite3_finalize(stmt);
}

void Database::deleteExpense(int id) {
    std::string sql = "DELETE FROM Expenses WHERE ID=" + std::to_string(id) + ";";
    int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error deleting data: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Expense deleted successfully!\n";
    }
}
