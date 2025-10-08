#include "Rajeshwari_Oct8_task3_StudentsPerformanceAnalyzer.h"
int main(){
    Student obj;//creating object
    //adding sample scores
    obj.addScores(SubjectScore("Math",92,GradeLevel::Distinction));
    obj.addScores(SubjectScore("Physics",78,GradeLevel::Merit));
    obj.addScores(SubjectScore("Chemistry",65,GradeLevel::Pass));
    obj.addScores(SubjectScore("History",45,GradeLevel::Fail));
    obj.addScores(SubjectScore("English",88,GradeLevel::Distinction));
    //displaying all scores
    std::cout<<"Displaying all scores\n";
    obj.displayAll();
    std::cout<<"Average of scores : "<<obj.averageScore()<<"\n"; //displaying average score
    std::cout<<"Displaying Distinction subjects count : "<<obj.count()<<"\n"; //displaying count of distinction subjects
    std::cout<<"Displaying top scorers : "<<"\n"; //displaying top scorers (merit and distinction)
    obj.printMeritAndDistinction();
    
    return 0;
}