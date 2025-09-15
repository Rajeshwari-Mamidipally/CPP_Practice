#include<iostream>
#include <iomanip>
using namespace std;
enum Genre{   //Enum for Genre
     FICTION,
     NONFICTION, 
     SCIENCE, 
     HISTORY, 
     TECHNOLOGY
};
class Book  //Book class
{
private:
    int m_bookID;
    float m_rating ;
    double m_price;
    char m_availabilityStatus;
    bool m_isReferenceOnly ;
    std::string m_title ;
    Genre m_genre ;
public:
    Book()    //Default constructor
    :  m_bookID(0), 
       m_rating(0.0),
       m_price(0.0), 
       m_availabilityStatus('A'), 
       m_isReferenceOnly(false), 
       m_title("Untitled"), 
       m_genre(FICTION){} 
    Book(int bookID,float rating,double price,char availabilityStatus,bool isReferenceOnly,const string& title,Genre genre)   //Parameterized Constructor
    :  m_bookID(bookID), 
       m_rating(rating),
       m_price(price), 
       m_availabilityStatus(availabilityStatus), 
       m_isReferenceOnly(isReferenceOnly), 
       m_title(title), 
       m_genre(genre){} 

    ~Book(){ //Destructor
        cout << "Book object with ID : " << m_bookID << " destroyed." << endl;
    }
    //Getters
    int GetBookID() const{return m_bookID;}
    float GetRating() const{return m_rating;}
    double GetPrice() const{return m_price;}
    char GetAvailabilityStatus() const{return m_availabilityStatus;}
    bool GetIsReferenceOnly() const{return m_isReferenceOnly;}
    string GetTitle() const{return m_title;}
    Genre GetGenre() const{return m_genre;}
    //Setters
    void SetBookId(int id){m_bookID=id;}
    void SetRating(float rating){m_rating=rating;}
    void SetPrice(double price){m_price=price;}
    void SetAvailabilityStatus(char availabilityStatus){m_availabilityStatus=availabilityStatus;}
    void SetIsReferenceOnly(bool IsReferenceOnly){m_isReferenceOnly=IsReferenceOnly;}
    void SetTitle(string title){m_title=title;}
    void SetGenre(Genre genre){m_genre=genre;}

    void updateAvailability(bool isBorrowed) { ///update Availability
        if(isBorrowed){
            m_availabilityStatus='B';
        }else{
            m_availabilityStatus='A';
        }
    }
    void displayDetails() const{   //Display book details
        cout<<"__Book Details__"<<endl;
        cout<<"Book Id : "<<m_bookID<<'\n';
        cout<<"Rating : "<<m_rating<<'\n';
        cout<<"Price : "<<m_price<<'\n';
        cout<<"AvailabilityStatus : "<<m_availabilityStatus<<'\n';
        cout<<"IsReferenceOnly : "<<m_isReferenceOnly<<'\n';
        cout<<"Title : "<<m_title<<'\n';
        cout<<"Genre : "<<m_genre<<'\n';
    }

};
//Global functions
void markAsReference(Book &book) {
    book.SetIsReferenceOnly(true);
   cout << "Book [" << book.GetTitle() << "] is now marked as Reference Only.\n";

}
bool isAffordable(const Book &book, const double budget) {
    if(book.GetPrice()<=budget){return true;}
    else{return false;}
}
 void printFormattedBookList(const Book books[], const int size) {
    cout << "\nID   | Title                | Price   | Rating | Status     | Reference\n";
    cout << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < size; i++) {
        if (books[i].GetBookID() == 0) continue; // Skip empty slots
        cout << left << setw(5) << books[i].GetBookID() << " | "
             << setw(20) << books[i].GetTitle().substr(0, 20) << " | "
             << setw(7) << books[i].GetPrice() << " | "
             << setw(6) << books[i].GetRating() << " | "
             << setw(10) << (books[i].GetAvailabilityStatus() == 'A' ? "Available" : "Borrowed") << " | "
             << (books[i].GetIsReferenceOnly() ? "Yes" : "No") << "\n";
    }
}
 int main(){
    
    Book library[3];
    int choice;
     do {
        cout << "\n=== Book Management Menu ===\n";
        cout << "1. Add book details\n";
        cout << "2. Mark a book as reference-only\n";
        cout << "3. Check if a book is affordable\n";
        cout << "4. Update availability\n";
        cout << "5. Display a book's details\n";
        cout << "6. Display all books\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

       if (choice == 1) {
            int index;
            cout << "Enter slot number (0-2): ";
            cin >> index;
            if (index < 0 || index > 2) {
                cout << "Invalid slot number!\n";
                continue;
            }

            int id;
            float rating;
            double price;
            string title;
            int genreChoice;

            cout << "Enter Book ID: ";
            cin >> id;
            cout << "Enter Rating (0.0 - 5.0): ";
            cin >> rating;
            while (rating < 0.0 || rating > 5.0) {
                cout << "Invalid rating! Enter Rating again (0.0 - 5.0): ";
                cin >> rating;
            }
            cout << "Enter Price: ";
            cin >> price;
            while (price <= 0) {
                cout << "Price must be positive. Enter Price again: ";
                cin >> price;
            }
            cin.ignore(); 
            cout << "Enter Title: ";
            getline(cin, title);
            while (title.empty()) {
                cout << "Title cannot be empty. Enter Title again: ";
                getline(cin, title);
            }

            cout << "Select Genre [0-Fiction, 1-NonFiction, 2-Science, 3-History, 4-Technology]: ";
            cin >> genreChoice;
            while (genreChoice < 0 || genreChoice > 4) {
                cout << "Invalid genre! Select again: ";
                cin >> genreChoice;
            }

            library[index] = Book(id, rating, price, 'A', false, title, static_cast<Genre>(genreChoice));
            cout << "Book added successfully!\n";
        }
        else if (choice == 2) {
            int index;
            cout << "Enter slot number (0-2): ";
            cin >> index;
            if (index >= 0 && index < 3 && library[index].GetBookID() != 0) {
                markAsReference(library[index]);
            } else {
                cout << "Invalid slot or no book found!\n";
            }
        }
        else if (choice == 3) {
            int index;
            double budget;
            cout << "Enter slot number (0-2): ";
            cin >> index;
            if (index >= 0 && index < 3 && library[index].GetBookID() != 0) {
                cout << "Enter your budget: ";
                cin >> budget;
                if (isAffordable(library[index], budget))
                    cout << "The book is affordable.\n";
                else
                    cout << "The book is NOT affordable.\n";
            } else {
                cout << "Invalid slot or no book found!\n";
            }
        }
        else if (choice == 4) {
            int index;
            cout << "Enter slot number (0-2): ";
            cin >> index;
            if (index >= 0 && index < 3 && library[index].GetBookID() != 0) {
                int status;
                cout << "Enter 1 for Borrowed, 0 for Available: ";
                cin >> status;
                library[index].updateAvailability(status == 1);
                cout << "Availability updated successfully!\n";
            } else {
                cout << "Invalid slot or no book found!\n";
            }
        }
        else if (choice == 5) {
            int index;
            cout << "Enter slot number (0-2): ";
            cin >> index;
            if (index >= 0 && index < 3 && library[index].GetBookID() != 0) {
                library[index].displayDetails();
            } else {
                cout << "Invalid slot or no book found!\n";
            }
        }
        else if (choice == 6) {
            printFormattedBookList(library, 3);
        }
        else if (choice == 7) {
            cout << "Exiting program. Goodbye!\n";
        }
        else {
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}



