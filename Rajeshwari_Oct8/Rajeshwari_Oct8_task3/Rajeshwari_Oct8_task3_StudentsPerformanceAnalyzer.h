#ifndef RAJESHWARI_OCT8_TASK3_STUDENTPERFORMANCEANALYZER_H
#define RAJESHWARI_OCT8_TASK3_STUDENTPERFORMANCEANALYZER_H
#include<iostream>
#include<string>
//enum
enum class GradeLevel{ Fail, Pass, Merit, Distinction};
class SubjectScore{
    private:
    std::string subjectName;
    int score; 
    GradeLevel grade;
    public:
    SubjectScore(); //default constructor
    SubjectScore(std::string subjectName,int score,GradeLevel grade);  //constructor
    //set and get funcions
    void setSubjectName(std::string name){
        subjectName=name;
    }
    void setScore(int score_){
        score=score_;
    }
    void setGrade(GradeLevel g){
        grade=g;
    }
    std::string getSubjectName() const {return subjectName;}
    int getScore() const {return score;}
    GradeLevel getGrade()const{return grade;}
    void display(); //display function

};
class Student{
    private:
    int max_size=10;
    SubjectScore* scores=new SubjectScore[max_size];
    public:
    void addScores(const SubjectScore& score); //adding scores
    double averageScore() const; //finding average
    int count(); //finding count of distinction subjects
    void printMeritAndDistinction(); //prints merit and distinction subject details
    void displayAll(); //displays all details


};
#endif