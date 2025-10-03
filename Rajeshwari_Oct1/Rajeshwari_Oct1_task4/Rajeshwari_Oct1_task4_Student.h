#ifndef RAJESHWARI_OCT1_TASK4_STUDENT_H
#define RAJESHWARI_OCT1_TASK4_STUDENT_H

#include <iostream>
#include <string>

//Base Class Student
class Student {
protected:
    std::string name;
    std::string studentID;
    std::string department;
public:
    Student(const std::string& n, const std::string& id, const std::string& dept);
    virtual ~Student() {}

    virtual void displayInfo() const;
    virtual std::string getLevel() const;
};

//Undergraduate
class UndergraduateStudent : public Student {
protected:
    int year;
    int creditsEarned;
public:
    UndergraduateStudent(const std::string& n, const std::string& id, const std::string& dept,int y, int credits);
    void displayInfo() const override;
    std::string getLevel() const override;
};

// Specific Years
class Freshman : public UndergraduateStudent {
public:
    Freshman(const std::string&, const std::string&, const std::string&, int, int);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class Sophomore : public UndergraduateStudent {
public:
    Sophomore(const std::string&, const std::string&, const std::string&, int, int);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class Junior : public UndergraduateStudent {
public:
    Junior(const std::string&, const std::string&, const std::string&, int, int);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class Senior : public UndergraduateStudent {
public:
    Senior(const std::string&, const std::string&, const std::string&, int, int);
    void displayInfo() const override;
    std::string getLevel() const override;
};

// Honors / Exchange Seniors
class HonorsSenior : public Senior {
    std::string thesisTitle;
public:
    HonorsSenior(const std::string&, const std::string&, const std::string&, int, int, const std::string&);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class ExchangeSenior : public Senior {
    std::string homeUniversity;
public:
    ExchangeSenior(const std::string&, const std::string&, const std::string&, int, int, const std::string&);
    void displayInfo() const override;
    std::string getLevel() const override;
};

//Graduate
class GraduateStudent : public Student {
protected:
    std::string advisor;
public:
    GraduateStudent(const std::string&, const std::string&, const std::string&, const std::string&);
    void displayInfo() const override;
    std::string getLevel() const override;
};

// Masters
class MastersStudent : public GraduateStudent {
public:
    MastersStudent(const std::string&, const std::string&, const std::string&, const std::string&);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class ThesisMastersStudent : public MastersStudent {
    std::string thesisTitle;
public:
    ThesisMastersStudent(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class NonThesisMastersStudent : public MastersStudent {
    std::string projectTitle;
public:
    NonThesisMastersStudent(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
    void displayInfo() const override;
    std::string getLevel() const override;
};

// Doctoral
class DoctoralStudent : public GraduateStudent {
protected:
    int yearsInProgram;
    std::string dissertationTitle;
public:
    DoctoralStudent(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, int);
    void displayInfo() const override;
    std::string getLevel() const override;
};

// PhD / PostDoc
class PhDCandidate : public DoctoralStudent {
public:
    PhDCandidate(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, int);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class PostDocFellow : public DoctoralStudent {
    std::string researchGrant;
public:
    PostDocFellow(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
    void displayInfo() const override;
    std::string getLevel() const override;
};

#endif

