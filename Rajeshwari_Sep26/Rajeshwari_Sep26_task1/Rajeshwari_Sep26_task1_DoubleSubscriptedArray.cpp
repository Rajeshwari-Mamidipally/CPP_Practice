#include<iostream>
#include<iomanip>
#include<cstdlib>
#include "DoubleSubscriptedArray.h"
DoubleSubscriptedArray::DoubleSubscriptedArray(int r,int c) //constructor
    : rows(r > 0 ? r : 1), columns(c > 0 ? c : 1), size(rows * columns){
    ptr=new int[size];
    for(int i=0;i<size;i++)
    ptr[i]=0;
}
    

DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray &arrayToCopy) //copy constructor
:size(arrayToCopy.size),rows(arrayToCopy.rows),columns(arrayToCopy.columns)
{
    ptr=new int[size];
    for(int i=0;i<size;i++)
    ptr[i]=arrayToCopy.ptr[i];
}
DoubleSubscriptedArray::~DoubleSubscriptedArray(){ //destructor
    delete[] ptr;
}
int DoubleSubscriptedArray::getSize() const{// Returns the total number of elements in the array
    return size;
}
// Overloaded Assignment Operator (=)
const DoubleSubscriptedArray &DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray &right){
    if(&right != this){
        rows=right.rows;
        columns=right.columns;
        if(size!=right.size){
            delete[] ptr;
            size=right.size;
            ptr=new int[size];
        }
        for(int i=0;i<size;i++)
        ptr[i]=right.ptr[i];
    }
    return *this;
}
// Equality Operator (==)
bool DoubleSubscriptedArray::operator==(const DoubleSubscriptedArray &right) const{
    if(size!=right.size)
    return false;
    for(int i=0;i<size;i++)
    {
        if(ptr[i]!=right.ptr[i])
        return false;
    }
    return true;

}
// Inequality Operator (!=)
bool DoubleSubscriptedArray::operator!=(const DoubleSubscriptedArray &right) const{
    return !(*this==right);
}
// Overloaded Function Call Operator ()
int &DoubleSubscriptedArray::operator()(int row,int col){
    if (row < 0 || row >= rows || col < 0 || col >= columns) {
        std::cerr << "Error: Subscript (" << row << ", " << col << ") out of range.\n";
        exit(1);
    }

    return ptr[row*columns+col];

}
// Const version of operator()
const int &DoubleSubscriptedArray::operator()(int row,int col) const{
    if (row < 0 || row >= rows || col < 0 || col >= columns) {
        std::cerr << "Error: Subscript (" << row << ", " << col << ") out of range.\n";
        exit(1);
    }
    return ptr[row*columns+col];
}
// Overloaded Subscript Operator []
int &DoubleSubscriptedArray::operator[](int subscript){
    if(subscript<0||subscript>=size){
        std::cerr<<"\nError: Subscript "<<subscript<<" out of range"<<std::endl;
        exit(1);
    }
    return ptr[subscript];
}
// Const version of operator[]
int DoubleSubscriptedArray::operator[](int subscript) const{
    if(subscript<0 || subscript>=size){
        std::cerr<<"\nError: Subscript "<<subscript<<" out of range"<<std::endl;
        exit(1);
    }
    return ptr[subscript];
}
// Overloaded Input Operator (>>)
std::istream &operator>>(std::istream &input, DoubleSubscriptedArray &a)
{
    for(int i=0;i<a.size;i++)
    input>>a.ptr[i];
    return input;
}
// Overloaded Output Operator (<<)
std::ostream &operator<<(std::ostream &output, const DoubleSubscriptedArray &a){
    int i;
    for(i=0;i<a.size;i++){
        output<<std::setw(5)<<a.ptr[i];
        if((i+1)%a.columns==0)
        output<<std::endl;

    }
    if(a.size%a.columns!=0){
        output<<std::endl;
    }
    return output;
}