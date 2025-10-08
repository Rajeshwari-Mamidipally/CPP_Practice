#include "Rajeshwari_Oct8_task4_StudentsPerformanceAnalyzer.h"
#include <fstream>
SubjectScore::SubjectScore() //default constructor
:subjectName(""),score(0),grade(GradeLevel::Fail){}
SubjectScore::SubjectScore(std::string sName,int s,GradeLevel gl)  //constructor
: subjectName(sName),score(s),grade(gl){}
void SubjectScore::display()const{  //displays details
    std::cout<<"Subject name : "<<getSubjectName()<<"\n"<<"score : "<<getScore()<<"\n"<<"grade : ";
    switch (grade) {
            case GradeLevel::Fail: std::cout << "Fail"; break;
            case GradeLevel::Pass: std::cout << "Pass"; break;
            case GradeLevel::Merit: std::cout << "Merit"; break;
            case GradeLevel::Distinction: std::cout << "Distinction"; break;
        
    }
    std::cout<<"\n";
}
void Student::addScores(const SubjectScore& score){  //Method to add scores 
    for(int i=0;i<max_size;i++){
        if(scores[i].getSubjectName()==""){
            scores[i]=score;
            return;
        }
    }
}
double Student::averageScore() const{   //Method to compute average score 
    int avg=0,validCount = 0;
    for(int i=0;i<max_size;i++){
        if (scores[i].getSubjectName() != "") {
        avg+=scores[i].getScore();
        validCount++;
    }
    }
    return validCount > 0 ? (avg/validCount) : 0.0;
}
int Student::count(){  ////Method to count how many subjects are Distinction
    int c=0;
    for(int i=0;i<max_size;i++){
        if(scores[i].getGrade()==GradeLevel::Distinction){
            c++;
        }
    }
    return c;
}
void Student::printMeritAndDistinction(){  //Method to print all Merit and Distinction scores
    for(int i=0;i<max_size;i++){
        if(scores[i].getGrade()==GradeLevel::Distinction||scores[i].getGrade()==GradeLevel::Merit){
            scores[i].display();
        }
    }

}
void Student::displayAll(){   //displaying all details
    for(int i=0;i<max_size;i++){
        if(scores[i].getSubjectName()=="")return;
        else
        scores[i].display();
    }
}
// Aggregates grade distribution across multiple students. 
void summarizeGrades(Student* students[], int studentCount) {
    int fail = 0, pass = 0, merit = 0, distinction = 0;

    for (int i = 0; i < studentCount; i++) {  //Iterates through all students and their scores. 
        if (students[i] == nullptr) continue;
        SubjectScore* arr = students[i]->getScores();
        for (int j = 0; j < 10; j++) {  //Computes total counts of each GradeLevel across all subjects.
            if (arr[j].getSubjectName() == "") continue;
            switch (arr[j].getGrade()) {
                case GradeLevel::Fail: fail++; break;
                case GradeLevel::Pass: pass++; break;
                case GradeLevel::Merit: merit++; break;
                case GradeLevel::Distinction: distinction++; break;
            }
        }
    }
    std::cout<< "\nGrade Summary Across All Students\n";
    std::cout<< "Fail: " << fail << "\nPass: " << pass<< "\nMerit: " << merit << "\nDistinction: " << distinction << "\n";
}
//Finds the highest score for a given subject across all students. 
const SubjectScore* findTopScorer(Student* students[], int studentCount, const std::string& subject) {
    const SubjectScore* top = nullptr;
    int highest = -1;
    for (int i = 0; i < studentCount; i++) {
        if (students[i] == nullptr) continue;
        SubjectScore* arr = students[i]->getScores();
        for (int j = 0; j < 10; j++) {
            if (arr[j].getSubjectName() == subject && arr[j].getScore() > highest) { //Searches for the subject in each student’s scores. 
                highest = arr[j].getScore();
                top = &arr[j];
            }
        }
    }
    return top;
}

void exportAllDistinctions(Student* students[], int studentCount, const std::string& filename) { // Print all Distinction scores across students
    std::ofstream fout(filename);
    if (!fout) {
        std::cerr << "Error opening file: " << filename << "\n";
        return;
    }
    fout << "All Distinction Scores\n";
    for (int i = 0; i < studentCount; i++) { //Iterates through all students and scores. 
        if (students[i] == nullptr) continue;
        SubjectScore* arr = students[i]->getScores();
        for (int j = 0; j < 10; j++) {
            if (arr[j].getSubjectName() != "" && arr[j].getGrade() == GradeLevel::Distinction) {  //Display subject name, score, and student index or name
                fout << "Student: " << students[i]->getStudentName()<< ", Subject: " << arr[j].getSubjectName()<< ", Score: " << arr[j].getScore() << "\n";
            }
        }
    }
    fout.close();
    std::cout<< "All distinctions exported to " <<filename <<"\n";
}