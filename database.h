#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>

class Database {
private:
    sqlite3* db;
    char* errMsg = 0;

public:
    Database(const std::string& filename);
    ~Database();
    void createTable();
    void addExpense(const std::string& category, double amount, const std::string& date);
    void viewExpenses();
    void deleteExpense(int id);
};

#endif
