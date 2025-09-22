#include<iostream>
#include "Invoice.h"
Invoice::Invoice(std::string number_,std::string descrption_,int qty,int price_){
    setNumber(number_);
    setDescription(descrption_);
    setQuantity(qty);
    setPrice(price_);

}
void Invoice::setNumber(std::string num){ //sets part number
    partNumber=num;
}
std::string Invoice::getNumber(){ //returns part number
    return partNumber;
}
void Invoice::setDescription(std::string descrption_){ //sets part description
    partDescription=descrption_;

}
std::string Invoice::getDescription(){//returns part description
    return partDescription;
}
void Invoice::setQuantity(int qty){ //sets quantity according to validation
    if(qty<=0){
        quantity=0;
    }
    else{
    quantity=qty;
    }
}
int Invoice::getQuantity(){ //returns quantity
    return quantity;
}
void Invoice::setPrice(int price_){ //sets price
    if(price_<=0){
        price=0;
    }
    else{
        price=price_;
    }

}
int Invoice::getPrice(){ //returns price
    return price;
}
int Invoice::getInvoiceAmount(){ //returns invoice amount(multiplication of quantity and price)
    return quantity*price;
}
