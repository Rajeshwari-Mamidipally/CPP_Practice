#ifndef RAJESHWARI_OCT6_TASK5_PACKAGE_H
#define RAJESHWARI_OCT6_TASK5_PACKAGE_H
#include<string>
class Package{
    public:
    //constructor
    Package(const std::string& senderName,const std::string& senderAddress,const std::string& senderCity,const std::string& senderState,const std::string& senderZipCode,const std::string& recipientName,const std::string& recipientAddress,const std::string& recipientCity,const std::string& recipientState,const std::string& recipientZipCode,double weight,double cost);
    ~Package(); //destructor
    double  calculateCost()const; //calculate cost
    double getWeight() const { return weight_; } //get weight
    double getCostPerOunce() const { return costPerOunce; } //get cost per ounce
    private:
    std::string senderName, senderAddress, senderCity, senderState, senderZipCode;
    std::string recipientName, recipientAddress, recipientCity, recipientState, recipientZipCode;
    double weight_;        
    double costPerOunce; 


};
class TwoDayPackage : public Package{
    public:
    //constructor
    TwoDayPackage(const std::string& senderName,const std::string& senderAddress,const std::string& senderCity,const std::string& senderState,const std::string& senderZipCode,const std::string& recipientName,const std::string& recipientAddress,const std::string& recipientCity,const std::string& recipientState,const std::string& recipientZipCode,double weight,double cost,double flatFee);
    ~TwoDayPackage(); //destructor
    double calculateCost() const; //calculate cost
    private:
    double flatFee;


};
class OvernightPackage : public Package{
    public:
    //constructor
    OvernightPackage(const std::string& senderName,const std::string& senderAddress,const std::string& senderCity,const std::string& senderState,const std::string& senderZipCode,const std::string& recipientName,const std::string& recipientAddress,const std::string& recipientCity,const std::string& recipientState,const std::string& recipientZipCode,double weight,double cost,double additionalCost);
    ~OvernightPackage();//destructor
    double calculateCost() const; //calculate cost
    private:
    double additionalFee;

};
#endif