#include<iostream>
#include "Invoice.h"
int main(){
    Invoice invoice("12E","Hammer",6,50);
    std::cout<<"Invoice Amount : "<<invoice.getInvoiceAmount()<<'\n';
    return 0;
}
