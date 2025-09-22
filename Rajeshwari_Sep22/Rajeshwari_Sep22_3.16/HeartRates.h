#include<string>
class HeartRates{
    public:
    HeartRates(std::string,std::string,int,int,int);  //constructur for initializing fname , lname, dob
    void setFirstName(std::string); //set function for first name
    void setLastName(std::string); //set function for last name
    void setBirthDay(int); //set function for birthday 
    void setBirthMonth(int);//set function for birthmonth
    void setBirthYear(int); //set function for birth year
    std::string getFirstName(); //get function of first name
    std::string getLastName(); //get function of last name
    int getBirthDay(); //get function of birth day
    int getBirthMonth(); //get function of birth month
    int getBirthYear(); //get function of birth year
    int getAge(); //functin to return age in years
    int getMaximumHeartRate(); //function to return max heart rate
    void getTargetHeartRate(); //function to get target heart rate
    private:
    std::string FirstName;
    std::string LastName;
    int BirthDay;
    int BirthMonth;
    int BirthYear;


};