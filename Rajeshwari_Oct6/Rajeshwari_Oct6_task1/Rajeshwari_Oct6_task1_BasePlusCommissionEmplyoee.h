#ifndef RAJESHWARI_OCT6_TASK1_BASEPLUSCOMMISSIONEMPLOYEE_H
#define RAJESHWARI_OCT6_TASK1_BASEPLUSCOMMISSIONEMPLOYEE_H
#include<string>
class CommissionEmployee{
    public:
    CommissionEmployee(const std::string&,const std::string&,const std::string&,double=0.0,double=0.0);//constructor
    ~CommissionEmployee();//destructor
    //setter and getter functions
    void setFirstName(const std::string&);
    std::string getFirstName() const;
    void setLastName(const std::string&);
    std::string getLastName() const;
    void setSocialSecurityNumber(const std::string&);
    std::string getSocialSecurityNumber() const;
    void setGrossSales(double);
    double getGrossSales() const;
    void setCommissionRate(double);
    double getCommissionRate() const;
    double earnings() const;
    void print() const;
    private:
    std::string firstName;
    std::string lastName;
    std::string socialSecurityNumber;
    double grossSales;
    double commissionRate; 

};
class BasePlusCommissionEmployee{
    public:
    BasePlusCommissionEmployee(const std::string&,const std::string&,const std::string&,double=0.0,double=0.0,double=0.0);//constructor
    ~BasePlusCommissionEmployee();//destructor
    //setter and getter functions
    void setBaseSalary(double);
    double getBaseSalary() const;
    double earnings() const;//earning function
    void print() const;
    private:
    CommissionEmployee commissionEmployee; 
    double baseSalary;


};
#endif