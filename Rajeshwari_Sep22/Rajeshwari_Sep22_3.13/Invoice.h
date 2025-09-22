#include<string>
class Invoice{
    public:
    Invoice(std::string,std::string,int,int); //constructor initialize part number,part description,int quantity,int price
    void setNumber(std::string); //function to set part number
    void setDescription(std::string);//function to set part description
    void setQuantity(int);//function to set quantity
    void setPrice(int);  //function to set price
    std::string getNumber(); //function to get part number
    std::string getDescription();//function to get part description
    int getQuantity();//function to get quantity
    int getPrice();//function to get price
    int getInvoiceAmount();//function to get invoice amount
    private:
    std::string partNumber; 
    std::string partDescription;
    int quantity;
    int price;
};