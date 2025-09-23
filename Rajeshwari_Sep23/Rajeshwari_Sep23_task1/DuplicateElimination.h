#include<string>
class DuplicateElimination{
    public:
    DuplicateElimination();       // Constructor
    void readNumbers();              // Reads numbers with validation
    void displayUnique() const;      // Displays unique numbers
     bool isDuplicate(int num) const;
    private:
    static int  const sizeOfArray=20; //Array size
    int array[sizeOfArray]; //define array with size
    int count; 

};