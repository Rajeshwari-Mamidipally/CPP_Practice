#include "Rajeshwari_Oct8_task3_StudentsPerformanceAnalyzer.h"
SubjectScore::SubjectScore()//default constructor
:
subjectName(""),
score(0),
grade(GradeLevel::Fail){}
SubjectScore::SubjectScore(std::string sName,int s,GradeLevel gl) //constructor
: subjectName(sName),score(s),grade(gl){}
void SubjectScore::display(){   //display function
    std::cout<<"Subject name : "<<getSubjectName()<<"\n"<<"score : "<<getScore()<<"\n"<<"grade : ";
    switch (grade) {
            case GradeLevel::Fail: std::cout << "Fail"; break;
            case GradeLevel::Pass: std::cout << "Pass"; break;
            case GradeLevel::Merit: std::cout << "Merit"; break;
            case GradeLevel::Distinction: std::cout << "Distinction"; break;
        
    }
    std::cout<<"\n";
}
//Method to add scores 
void Student::addScores(const SubjectScore& score){
    for(int i=0;i<max_size;i++){
        if(scores[i].getSubjectName()==""){
            scores[i]=score;
            return;
        }
    }
}
//method to calculate average
double Student::averageScore() const{
    int avg=0,validCount = 0;
    for(int i=0;i<max_size;i++){
        if (scores[i].getSubjectName() != "") {
        avg+=scores[i].getScore();
        validCount++;
    }
    }
    return validCount > 0 ? (avg/validCount) : 0.0;
}
//Method to count how many subjects are Distinction
int Student::count(){
    int c=0;
    for(int i=0;i<max_size;i++){
        if(scores[i].getGrade()==GradeLevel::Distinction){
            c++;
        }
    }
    return c;
}
//Method to print all Merit and Distinction scores 
void Student::printMeritAndDistinction(){
    for(int i=0;i<max_size;i++){
        if(scores[i].getGrade()==GradeLevel::Distinction||scores[i].getGrade()==GradeLevel::Merit){
            scores[i].display();
        }
    }

}
//displays all details
void Student::displayAll(){
    for(int i=0;i<max_size;i++){
        if(scores[i].getSubjectName()=="")return;
        else
        scores[i].display();
    }
}
