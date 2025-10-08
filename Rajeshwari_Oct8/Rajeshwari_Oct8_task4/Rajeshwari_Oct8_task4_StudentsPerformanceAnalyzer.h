#ifndef RAJESHWARI_OCT8_TASK4_STUDENTPERFORMANCEANALYZER_H
#define RAJESHWARI_OCT8_TASK4_STUDENTPERFORMANCEANALYZER_H
#include<iostream>
#include<string>

enum class GradeLevel{ Fail, Pass, Merit, Distinction};
class SubjectScore{
    private:
    std::string subjectName;
    int score; 
    GradeLevel grade;
    public:
    SubjectScore(); //default constructor
    SubjectScore(std::string subjectName,int score,GradeLevel grade);//constructor
    //set and get functions
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
    void display()const; //displays details

};
class Student{
    private:
    int max_size=10;
    std::string studentName;
    SubjectScore* scores=new SubjectScore[max_size];
    public:
    Student(std::string name = "") : studentName(name) {} //constructor
    ~Student() { delete[] scores; }  //destructor
    void addScores(const SubjectScore& score);    //Method to add scores 
    double averageScore() const;  //Method to compute average score 
    int count();  //Method to count how many subjects are Distinction
    void printMeritAndDistinction();  //Method to print all Merit and Distinction scores
    void displayAll();
    SubjectScore* getScores() const { return scores; }
    std::string getStudentName() const { return studentName; }


};
void summarizeGrades(Student* students[], int studentCount);  // Aggregates grade distribution across multiple students.
const SubjectScore* findTopScorer(Student* students[], int studentCount, const std::string& subject); //Finds the highest score for a given subject across all students. 
void exportAllDistinctions(Student* students[], int studentCount, const std::string& filename);  // Print all Distinction scores across students

#endif