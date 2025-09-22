#include<string>
using namespace std;
class GradeBook   //defining class
{
public:
GradeBook(string ,string); // constructor that initializes courseName and course instructors name    
void setCourseName( string ); // function that sets the course name
void setInstructorName(string);//function to set instructor name
string getInstructorName();//function to gets instructor name
string getCourseName(); // function that gets the course name      
void displayMessage(); // function that displays a welcome message 
private:
   string courseName; // course name for this GradeBook
   string instructorName;//instructor name for GradeBook
 };