#include <iostream>
#include <fstream>
using namespace std;

const int MAX_BOOKS = 100;
const int MAX_STUDENTS = 100;

class Book {
	
	public:
	    int Bookid;
	    string Bookname;
	    string Authorname;
};

class Student {
	
	public:
	    int Studentid;
	    string Studentname;
	    string Department;
};

class Library {
	
	private:
	    string password;
	    Book books[MAX_BOOKS];
	    Student students[MAX_STUDENTS];
	    int bookCount;
	    int studentCount;

	public:
    
	Library() : password("12345"), bookCount(0), studentCount(0) {}

    bool login() {
        string pass;
        cout << "\n\n\t\t\tEnter librarian password: ";
        cin >> pass;
        return (pass == password);
    }

    void addBook() {
        if (bookCount < MAX_BOOKS) {
            Book newBook;
            cout << "\n\n\t\t\tEnter Book Name: ";
            getline(cin >> ws, newBook.Bookname);
            cout << "\n\n\t\t\tEnter Author Name: ";
            getline(cin >> ws, newBook.Authorname);
            cout << "\n\n\t\t\tEnter Book id: ";
            cin >> newBook.Bookid;
            books[bookCount++] = newBook;
            cout << "\n\n\t\t\t*Book Added Successfully*" << endl;
        } else {
            cout << "\n\n\t\t\t*Library is full. Cannot add more books.*" << endl;
        }
    }

    void listAllBooks() {
        
		if (bookCount == 0) {
			
            cout << "\n\n\t\t\t*No Book In Library*" << endl;
        } 
		
		else {
			
            cout << "\n\t\t\t\t\t-----List Of All Books------" << endl << endl;
            
			for (int i = 0; i < bookCount; i++) {
            
			    cout << "\n\n\t\t\t** " << i + 1 << "." << " **";
                cout << "\n\n\t\t\tBook Name is: " << books[i].Bookname;
                cout << "\n\n\t\t\tAuthor Name is: " << books[i].Authorname;
                cout << "\n\n\t\t\tBook ID is: " << books[i].Bookid;
            }
        }
    }

    void searchBookByName() {
    	
        string name;
        cout << "\n\n\t\t\tEnter Book Name: ";
        getline(cin >> ws, name);

        bool bookFound = false;
        
        for (int i = 0; i < bookCount; ++i) {

            const Book &book = books[i];

            if (book.Bookname == name) {

                displayBookDetails(book);
                bookFound = true;
                break;
            }
        }

        if (!bookFound) {

            cout << "\n\n\t\t\t*No Book Found*" << endl;
        }
    }

    void searchBookByAuthor() {

        string author;
        cout << "\n\n\t\t\tEnter Author Name: ";
        getline(cin >> ws, author);

        bool bookFound = false;
        
		for (int i = 0; i < bookCount; ++i) {
            
			const Book &book = books[i];
            
			if (book.Authorname == author) {
                displayBookDetails(book);
                bookFound = true;
            }
        }

        if (!bookFound) {
            cout << "\n\n\t\t\t*No Book Found*" << endl;
        }
    }

    void searchBookById() {
        
		int id;
        cout << "\n\n\t\t\tEnter Book ID: ";
        cin >> id;

        bool bookFound = false;
        
		for (int i = 0; i < bookCount; ++i) {
            
			const Book &book = books[i];
            
			if (book.Bookid == id) {
                
				displayBookDetails(book);
                bookFound = true;
                break;
            }
        }

        if (!bookFound) {
        
		    cout << "\n\n\t\t\t*No Book Found*" << endl;
        }
    }

    void displayBookDetails(const Book &book) {
        
		cout << "\n\t\t\t**";
        cout << "\n\n\t\t\tBook ID is: " << book.Bookid << endl;
        cout << "\n\n\t\t\tAuthor Name is: " << book.Authorname;
        cout << "\n\n\t\t\t**";
    }

    void deleteBook() {
        
        string bookName;
        cout << "\n\t\t\tEnter The Book Name To Delete: ";
        getline(cin >> ws, bookName);
        bool bookFound = false;

        for (int i = 0; i < bookCount; i++) {
            
			if (books[i].Bookname == bookName) {
                
				for (int j = i; j < bookCount - 1; j++) {
                
				    books[j] = books[j + 1];
                }
                
				bookCount--;
                cout << "\n\n\t\t\t*Book Deleted Successfully**" << endl;
                bookFound = true;
                break;
            }
        }

        if (!bookFound) {
           
		    cout << "\n\n\t\t\t*Book Not Found*" << endl;
        }

        cout << "\n\n\t\t\tPress Enter to continue...";
        cin.ignore();
        cin.get();
    }

    void saveLibraryData() {
        ofstream lib("library.txt");
        if (lib.is_open()) {
            lib << bookCount << endl;
            for (int i = 0; i < bookCount; i++) {
                lib << "I.D. \t\t: " << books[i].Bookid << endl;
                lib << "Book Name \t\t: " << books[i].Bookname << endl;
                lib << "Author Name\t: " << books[i].Authorname << endl;
            }
            lib.close();
        }
    }

    void loadLibraryData() {
        ifstream lib("library.txt");
        if (lib.is_open()) {
            string line;
            if (!(lib >> bookCount)) return;
            lib.ignore();
            for (int i = 0; i < bookCount; i++) {
                getline(lib, line); // Read I.D. line
                if (line.find(":") != string::npos) {
                    books[i].Bookid = stoi(line.substr(line.find(":") + 1));
                }

                getline(lib, line); // Read Book Name line
                if (line.find(":") != string::npos) {
                    books[i].Bookname = line.substr(line.find(":") + 1);
                    // Trim leading spaces
                    size_t first = books[i].Bookname.find_first_not_of(' ');
                    if (string::npos != first) {
                        books[i].Bookname = books[i].Bookname.substr(first);
                    }
                }

                getline(lib, line); // Read Author Name line
                if (line.find(":") != string::npos) {
                    books[i].Authorname = line.substr(line.find(":") + 1);
                    // Trim leading spaces
                    size_t first = books[i].Authorname.find_first_not_of(' ');
                    if (string::npos != first) {
                        books[i].Authorname = books[i].Authorname.substr(first);
                    }
                }
            }
            lib.close();
        }
    }

    void issueBook() {
        
        string bookName;
        cout << "\n\t\t\tEnter Book Name To Issue: ";
        getline(cin >> ws, bookName);

        size_t i;
        for (i = 0; i < bookCount; ++i) {
            if (books[i].Bookname == bookName) {
                Student student;
                cout << "\n\t\t\tEnter Your Student ID: ";
                cin >> student.Studentid;
                cout << "\n\t\t\tEnter Your Name: ";
                getline(cin >> ws, student.Studentname);
                cout << "\n\t\t\tEnter Your Department: ";
                getline(cin >> ws, student.Department);
                students[studentCount++] = student;
                cout << "\n\n\t\t\t*Book Issued Successfully*" << endl;
                break;
            }
        }

        if (i == bookCount) {
           
		    cout << "\n\n\t\t\t*Book Not Found or Already Issued*" << endl;
        }
    }

    void issuedBooks() {
    	
        if (studentCount == 0) {
            cout << "\n\n\t\t\t*No Book Issued*" << endl;
        } 
		
		else {
            
			cout << "\n\t\t\t\t\t-----List Of All Issued Books------" << endl;
           
		    for (int i = 0; i < studentCount; i++) {
                
				cout << "\n\n\t\t\t** " << i + 1 << "." << " **";
                cout << "\n\t\t\tBook Name: " << books[i].Bookname;
                cout << "\n\n\t\t\tStudent ID: " << students[i].Studentid;
                cout << "\n\n\t\t\tStudent Name: " << students[i].Studentname;
                cout << "\n\n\t\t\tStudent Department: " << students[i].Department;
            }
        }
    }

    void totalBooks() {
        
		cout << "\n\t\t\t\t\t--------TOTAL BOOKS--------" << endl << endl;
        cout << "\n\n\t\t\tTotal Books In Library: " << bookCount << endl;
        
		if (bookCount == 0) {
            
			cout << "\n\n\t\t\t*No Book In Library*" << endl;
        }
    }
};

int main() {
	
    Library library;
    library.loadLibraryData();

    while (true) {

		int choice;
		home:
		cout << "\n\t\t\tChoose Any One Option." << endl;
        cout << "\n\n\t\t\t1. Librarian" << endl;
        cout << "\n\t\t\t2. Student" << endl;
        cout << "\n\t\t\t3. Exit" << endl;
        cout << "\n\t\t\tEnter your Choice: ";
        cin >> choice;
		
		system("cls");
		
        switch (choice) {
            
			case 1: {
                
				if (library.login()) {
                	
					system("cls");
					cout << endl << endl;
                	
                    while (true) {
                    
					    cout << "\n\t\t\t1. Add Book" << endl;
                        cout << "\n\t\t\t2. View List of All Books" << endl;
                        cout << "\n\t\t\t3. Search Books" << endl;
                        cout << "\n\t\t\t4. Show List of Issued Books" << endl;
                        cout << "\n\t\t\t5. Delete Book" << endl;
                        cout << "\n\t\t\t6. Check Total Books in Library" << endl;
                        cout << "\n\t\t\t7. Go to Main Menu" << endl;
                        cout << "\n\t\t\t8. Exit" << endl;
                        cout << "\n\n\t\t\tEnter your Choice: ";
                        cin >> choice;
                        
						system("cls");
						cout << endl << endl;

                        switch (choice) {
                        
						    case 1:
                                library.addBook();
                                library.saveLibraryData();
                                break;
                            
							case 2:
                                library.listAllBooks();
                                break;
                            
							case 3: {
                                int searchChoice;
                                cout << "\n\t\t\t1. Search By Book Name" << endl;
                                cout << "\n\t\t\t2. Search By Author Name" << endl;
                                cout << "\n\t\t\t3. Search By Book ID" << endl;
                                cout << "\n\t\t\t4. Go Back" << endl;
                                cout << "\n\n\t\t\tEnter your Choice: ";
                                cin >> searchChoice;

                                switch (searchChoice) {
                                    
									case 1:
                                        library.searchBookByName();
                                        break;
                                    
									case 2:
                                        library.searchBookByAuthor();
                                        break;
                                    
									case 3:
                                        library.searchBookById();
                                        break;
                                   
								    case 4:
                                        break;
                                    
									default:
                                        cout << "\n\n\t\t\t-------Invalid Entry------" << endl;
                                        break;
                                }
                                
								break;
                            }
                            
							case 4:
                                library.issuedBooks();
                                break;
                            
							case 5:
                                library.deleteBook();
                                library.saveLibraryData();
                                break;
                            
							case 6:
                                library.totalBooks();
                                break;
                            
							case 7:
								goto home;	
                                break;
                            
							case 8:
                                exit(0);
                            
							default:
                                cout << "\n\n\t\t\t-------Invalid Entry------" << endl;
                        }
                    }
                } 
				
				else {
                    
					cout << "\n\n\t\t\t*Incorrect Password*" << endl;
                    cout << "\n\n\t\t\tTry Again....";
                    cin.ignore();
                    cin.get();
                }
                
                break;
            }
            
            case 2: {
                
				while (true) {
					
                    cout << "\n\t\t\t1. List of All Books in Library" << endl;
                    cout << "\n\t\t\t2. Search Books in Library" << endl;
                    cout << "\n\t\t\t3. Issue Book" << endl;
                    cout << "\n\t\t\t4. Go to Main Menu" << endl;
                    cout << "\n\t\t\t5. Exit" << endl;
                    cout << "\n\n\t\t\tEnter your Choice: ";
                    cin >> choice;

                    switch (choice) {
                        
						case 1:
                            library.listAllBooks();
                            break;
                        
						case 2: {
                        
						    int searchChoice;
                            cout << "\n\t\t\t1. Search By Book Name" << endl;
                            cout << "\n\t\t\t2. Search By Author Name" << endl;
                            cout << "\n\t\t\t3. Search By Book ID" << endl;
                            cout << "\n\t\t\t4. Go Back" << endl;
                            cout << "\n\n\t\t\tEnter your Choice: ";
                            cin >> searchChoice;

                            switch (searchChoice) {
                        
						        case 1:
                                    library.searchBookByName();
                                    break;
                        
						        case 2:
                                    library.searchBookByAuthor();
                                    break;
                        
						        case 3:
                                    library.searchBookById();
                                    break;
                        
						        case 4:
						        	goto home;
                                    break;
                        
						        default:
                                    cout << "\n\n\t\t\t-------Invalid Entry------" << endl;
                                    break;
                            }
                        
						    break;
                        }
                        
						case 3:
                            library.issueBook();
                            break;
                        
						case 4:
							goto home;
                            break;
                        
						case 5:
                            exit(0);
                        
						default:
                            cout << "\n\n\t\t\t-------Invalid Entry------" << endl;
                    }
                }
            }
            
			case 3:
				
                exit(0);
            
			default:
                cout << "\n\n\t\t\t-------Invalid Entry------" << endl;
        }
    }
    
    return 0;
}
