#include "Rajeshwari_Oct6_task1_BasePlusCommissionEmplyoee.h"
#include<iostream>
#include<string>
//construcor
CommissionEmployee::CommissionEmployee(const std::string& first,const std::string& last,const std::string& ssn,double sales,double rate)
:firstName(first),lastName(last),socialSecurityNumber(ssn)
{
    setGrossSales(sales);
    setCommissionRate(rate);
    std::cout<<"\nCommissionEmployee constructor: "<<std::endl;
    print();
    std::cout<<"\n\n";
}
//destructor
CommissionEmployee::~CommissionEmployee()
{
    std::cout<<"\nCommissionEmployee destructor: "<<std::endl;
    print();
    std::cout<<"\n\n";
}
//set and get functions
//set first name
void CommissionEmployee::setFirstName(const std::string& first){
    firstName=first;
}
//return first name
std::string CommissionEmployee::getFirstName() const{
    return firstName;
}
//set last name
void CommissionEmployee::setLastName(const std::string& last){
    lastName=last;
}
//return last name
std::string CommissionEmployee::getLastName() const{
    return lastName;
}
//set social security number
void CommissionEmployee::setSocialSecurityNumber(const std::string& ssn){
    socialSecurityNumber=ssn;
}
//return social security number
std::string CommissionEmployee::getSocialSecurityNumber() const{
    return socialSecurityNumber;
}
//set gross sales amount
void CommissionEmployee::setGrossSales( double sales )
{
   grossSales = ( sales < 0.0 ) ? 0.0 : sales;
} 

// return gross sales amount
double CommissionEmployee::getGrossSales() const
{
    return grossSales;
} 
// set commission rate
void CommissionEmployee::setCommissionRate( double rate )
{
   commissionRate = ( rate > 0.0 && rate < 1.0 ) ? rate : 0.0;
} 
 // return commission rate
double CommissionEmployee::getCommissionRate() const
{
   return commissionRate;
} 

 // calculate earnings
double CommissionEmployee::earnings() const
{ 
    return getCommissionRate() * getGrossSales();
} 

 // print CommissionEmployee details
void CommissionEmployee::print() const
{   
   std::cout << "commission employee: "<< getFirstName() << ' ' << getLastName() << "\nsocial security number: " << getSocialSecurityNumber() << "\ngross sales: " << getGrossSales() << "\ncommission rate: " << getCommissionRate();
} 
//constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string& first,const std::string& last,const std::string& ssn,double sales,double rate,double salary)
:commissionEmployee(first,last,ssn,sales,rate){
    setBaseSalary(salary);
    std::cout<<"\nBasePlusCommissionEmployee constructor: "<<std::endl;
    print();
    std::cout<<"\n\n";
}
//destructor
BasePlusCommissionEmployee::~BasePlusCommissionEmployee(){
    std::cout<<"\nBasePiusCommissionEmployee destructor: "<<std::endl;
    print();
    std::cout<<"\n\n";

}
//set base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary){
    baseSalary=(salary<0.0)?0.0:salary;
}
//return base salary
double BasePlusCommissionEmployee::getBaseSalary() const{
    return baseSalary;
}
//returning earnings
double BasePlusCommissionEmployee::earnings() const{
    return getBaseSalary()+commissionEmployee.earnings();
}
//displayng salary
void BasePlusCommissionEmployee::print() const{
    std::cout<<"base-salaried";
    commissionEmployee.print();
    std::cout<<"\nbase salary: "<<getBaseSalary();
}