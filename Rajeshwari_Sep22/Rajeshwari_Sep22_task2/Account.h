class Account{
    public:
    Account(int);   //constructor to intialize balance
    void setBalance(int); //set balance
    int getBalance();//return balance
    void credit(int);//credit balance
    void debit(int);//debit balance
    private:
    int balance;

};
