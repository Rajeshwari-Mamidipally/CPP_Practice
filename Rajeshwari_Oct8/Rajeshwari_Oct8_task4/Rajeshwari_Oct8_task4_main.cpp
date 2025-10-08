#include "Rajeshwari_Oct8_task4_StudentsPerformanceAnalyzer.h"
using namespace std;

int main() {
    // Create sample students
    Student* students[3];
    students[0] = new Student("Alice");
    students[1] = new Student("Bob");
    students[2] = new Student("Charlie");

    // Add scores
    students[0]->addScores(SubjectScore("Math", 92, GradeLevel::Distinction));
    students[0]->addScores(SubjectScore("Physics", 78, GradeLevel::Merit));

    students[1]->addScores(SubjectScore("Math", 88, GradeLevel::Merit));
    students[1]->addScores(SubjectScore("Chemistry", 45, GradeLevel::Fail));

    students[2]->addScores(SubjectScore("Math", 95, GradeLevel::Distinction));
    students[2]->addScores(SubjectScore("English", 65, GradeLevel::Pass));

    // Display each student’s data
    for (int i = 0; i < 3; i++) students[i]->displayAll();

    // Global Function 1
    summarizeGrades(students, 3);

    // Global Function 2
    const SubjectScore* top = findTopScorer(students, 3, "Math");
    if (top)
    {
        std::cout<< "\nTop scorer in Math:\n";
        top->display();
    }
    else
        std::cout<< "No Math scores found.\n";

    // Global Function 3
    exportAllDistinctions(students, 3, "distinctions.txt");

    // Cleanup
    for (int i = 0; i < 3; i++) delete students[i];

    return 0;
}
