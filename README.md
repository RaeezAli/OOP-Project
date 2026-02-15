# Library Management System

A robust and simple C++ console-based Library Management System designed as an OOP project. This system allows for managing book inventories, student records, and book issuance with persistent data storage.

## 🚀 Features

### Librarian Portal

- **Secure Access**: Password-protected login (Default: `12345`).
- **Inventory Management**: Add, delete, and list all books.
- **Search Capabilities**: Find books by Name, Author, or ID.
- **Reporting**: View total books and a list of all issued books.
- **Data Persistence**: Automatically saves library data to `library.txt`.

### Student Portal

- **Browse Books**: View the entire collection available.
- **Search**: Quickly find specific books.
- **Issue Books**: Students can register themselves and issue books.

## 🛠️ Enhancements & Bug Fixes

- **Multi-word Support**: Fixed issues where spaces in titles or names would crash the interface.
- **Improved Data Loading**: The system now correctly parses and loads human-readable records from the data file.
- **Robust Input**: Uses modern C++ input handling to prevent menu skipping.

## 📦 Getting Started

### Prerequisites

- A C++ compiler (like `g++`) installed on your system.

### Compilation

Open your terminal in the project directory and run:

```powershell
g++ main.cpp -o library_system.exe
```

### Running the App

Execute the compiled file:

```powershell
./library_system.exe
```

## 📂 Project Structure

- `main.cpp`: Core logic containing `Library`, `Book`, and `Student` classes.
- `library.txt`: Persistent storage file for all book records.
- `README.md`: Project documentation.

## 🤝 Contributing

Feel free to fork this project and add features like multi-book issuance, due date tracking, or a graphical interface!
