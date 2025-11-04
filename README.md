# 💰 Expense Tracker (C++ with SQLite)

### Author: Mutua

## Project Description

**Expense Tracker** is a simple C++ console application designed to help users record, view, and manage their daily expenses efficiently.  
The project uses **SQLite** as its database system to store and retrieve financial records locally.  

It allows users to:
- Add new expense entries with details like category, amount, and date.  
- View a list of all recorded expenses.  
- Delete specific expenses when needed.  
- View a total summary of spending.  

The main objective of this project is to demonstrate how to integrate **C++** with **SQLite**, handle user input, and perform CRUD (Create, Read, Update, Delete) operations within a desktop-based environment.  

---

## Technologies Used

- **Language:** C++  
- **Database:** SQLite  
- **IDE:** Code::Blocks  
- **Compiler:** GNU GCC Compiler  

---

## System Requirements

Before setting up, make sure you have the following installed:

- **Operating System:** Windows (recommended)  
- **Code::Blocks IDE** (with MinGW included)  
- **SQLite3 library files** (i.e., `sqlite3.c`, `sqlite3.h`, and `sqlite3.dll`)  

---

## Project Setup in Code::Blocks

Follow these steps carefully to set up and run the project successfully:

### 1. Install Code::Blocks
- Download Code::Blocks from the [official website](https://www.codeblocks.org/downloads/).
- During installation, choose the version that includes **MinGW Compiler**.
- After installation, open **Code::Blocks** and select:
  ```
  Settings → Compiler → GNU GCC Compiler
  ```

### 2. Create a New Project
- Go to **File → New → Project → Console Application → C++**  
- Click **Next**, enter your **Project Title** (e.g., *ExpenseTracker*), and select a directory to save it.  
- Finish the wizard to create the project.

### 3. Add Source Files
Inside your project folder:
- Replace the default `main.cpp` with your project’s `main.cpp` file.  
- Add the other two files:
  - `database.cpp`
  - `database.h`

You can do this by right-clicking **Sources** in Code::Blocks → *Add files...*

### 4. Add SQLite to the Project
- Download **SQLite3** from the [SQLite official site](https://www.sqlite.org/download.html).
- Copy these files into your project folder:
  - `sqlite3.c` (sqlite-amalgamation-3500400)
  - `sqlite3.h` (sqlite-amalgamation-3500400)
  - `sqlite3.dll`(sqlite-dll-win-x64-3500400)

Then:
1. In Code::Blocks, right-click your project → **Add files...** → add `sqlite3.c`.
2. Go to **Project → Build Options → Linker Settings**.
3. Under **Link libraries**, click **Add**, and add `sqlite3.dll` (or simply `sqlite3.lib` if using static linking).

### 5. Check Compiler Paths (Optional but Important)
- Go to:
  ```
  Settings → Compiler → Search Directories → Compiler
  ```
  and make sure the path to your SQLite header file (`sqlite3.h`) is included.

### 6. Build and Run
- Click **Build → Build and Run** or simply press `F9`.
- If setup is correct, the terminal will show your program’s menu:
  ```
  1. Add Expense
  2. View Expenses
  3. Delete Expense
  4. Exit
  ```

---

##  How It Works

The application uses SQLite to:
- Store all expense data in a local file-based database (`expenses.db`).
- Run SQL commands from within C++ for inserting, retrieving, and deleting data.  

Every time a user records an expense, a new entry is stored in the SQLite database, making the data persistent between program runs.

---

## References

- [SQLite Official Documentation](https://www.sqlite.org/docs.html)  
- [Code::Blocks IDE Guide](https://wiki.codeblocks.org/index.php/Main_Page)  
- [Stack Overflow - Using SQLite with C++](https://stackoverflow.com/questions/24000150/how-to-use-sqlite-in-c)

---

## Conclusion

This project provides a simple yet powerful example of how C++ applications can interact with an embedded database like SQLite.  
It’s an excellent foundation for building larger financial tracking systems, budget planners, or data management tools in C++.  

Feel free to fork, improve, and contribute to make it even better! 
