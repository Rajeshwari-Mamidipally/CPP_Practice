
#include <iostream>
#include "GradeBook.h"
using namespace std;
// constructor initializes courseName and instructor name with strings supplied as argument
GradeBook::GradeBook( string CourseName,string InstructorName )
{
   setCourseName( CourseName ); // call set function to initialize courseName
   setInstructorName(InstructorName);//function to initialize instructor name
} 
 
void GradeBook::setCourseName(string name) // function to set the course name
{
     courseName = name; // store the course name in the object
}

string GradeBook::getCourseName()    // function to get the course name
{
return courseName; // return object's courseName
} 

void GradeBook::setInstructorName(string name){ //function to set the instructor name
    instructorName =name;  //stores instructor name
}

string GradeBook::getInstructorName(){  //function to get instructor name
return instructorName; //return instructor name
}
 
void GradeBook::displayMessage()  // display a welcome message to the GradeBook user
{ 
  cout <<"Welcome to the grade book for " << getCourseName()<< "!" << endl;
  cout<<"This course is presented by: "<<getInstructorName()<<endl;
}