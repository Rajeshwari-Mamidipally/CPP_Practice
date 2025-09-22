#include <string>
class HealthProfile {
public:
    // Constructor
    HealthProfile(std::string fName, std::string lName, std::string gen,
                  int day, int month, int year,
                  double h, double w);

    // Setters
    void setFirstName(std::string fName);
    void setLastName(std::string lName);
    void setGender(std::string gen);
    void setBirthDay(int day);
    void setBirthMonth(int month);
    void setBirthYear(int year);
    void setHeight(double h);
    void setWeight(double w);
    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getGender() const;
    int getBirthDay() const;
    int getBirthMonth() const;
    int getBirthYear() const;
    double getHeight() const;
    double getWeight() const;
    int getAge();                       // function to find  Age in years
    int getMaximumHeartRate();          // function to find  Maximum heart rate
    void getTargetHeartRate();          // function to find  Target heart rate range
    double getBMI();                    // function to find  Body Mass Index
    void displayBMIChart();             // function to find BMI categories
    private:
    std::string firstName;
    std::string lastName;
    std::string gender;
    int birthDay;
    int birthMonth;
    int birthYear;
    double height; // in inches
    double weight; // in pounds
};
