#include<iostream>
#include<string>
#include "Rajeshwari_Oct6_task5_Package.h"
//constructor
Package::Package(const std::string& sName, const std::string& sAddress,const std::string& sCity, const std::string&sState, const std::string& sZip,const std::string& rName, const std::string& rAddress,const std::string& rCity, const std::string& rState, const std::string& rZip,double w, double c)
:
senderName(sName),
senderAddress(sAddress),
senderCity(sCity),
senderState(sState),
senderZipCode(sZip),
recipientName(rName),
recipientAddress(rAddress),
recipientCity(rCity),
recipientState(rState),
recipientZipCode(rZip)
{
    weight_=(w>0)?w:0.0;
    costPerOunce=(c>0)?c:0.0;
}
//destructor
Package::~Package(){}
//calculateing cost
double Package::calculateCost()const{
    return weight_*costPerOunce;
}
//constructor
TwoDayPackage::TwoDayPackage(const std::string& sName,const std::string& sAddress,const std::string& sCity, const std::string& sState, const std::string& sZip,const std::string& rName, const std::string& rAddress,const std::string& rCity, const std::string& rState, const std::string& rZip,double w, double c,double ff)
: Package(sName,sAddress,sCity,sState,sZip,rName,rAddress,rCity,rState,rZip,w,c),
flatFee(ff){}
//destructor
TwoDayPackage::~TwoDayPackage(){}
//calculateCost function it calculates the cost by adding flat fee 
double TwoDayPackage::calculateCost() const{
    return Package::calculateCost()+flatFee;
}
//constructor
OvernightPackage::OvernightPackage(const std::string& sName, const std::string& sAddress,const std::string& sCity, const std::string&sState, const std::string& sZip,const std::string& rName, const std::string& rAddress,const std::string& rCity, const std::string& rState, const std::string& rZip,double w, double c,double af)
:
Package(sName,sAddress,sCity,sState,sZip,rName,rAddress,rCity,rState,rZip,w,c),
additionalFee(af){}
//destructor
OvernightPackage::~OvernightPackage(){}
//calculate cost by adding additional fee per ounce
double OvernightPackage::calculateCost() const{
    return getWeight() * (getCostPerOunce() + additionalFee);
}
