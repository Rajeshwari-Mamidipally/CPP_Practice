#ifndef DOUBLESUBSCRIPTEDARRAY_H
#define DOUBLESUBSCRIPTEDARRAY_H
#include<iostream>
class DoubleSubscriptedArray{
    friend std::ostream &operator<<( std::ostream &, const DoubleSubscriptedArray & );
    friend std::istream &operator>>( std::istream &, DoubleSubscriptedArray & );
    public:
    DoubleSubscriptedArray(int=1,int=1);
    DoubleSubscriptedArray(const DoubleSubscriptedArray &);
    ~DoubleSubscriptedArray();
    int getSize() const;
    const DoubleSubscriptedArray &operator=(const DoubleSubscriptedArray &);
    bool operator==(const DoubleSubscriptedArray &) const;
    bool operator!=(const DoubleSubscriptedArray &) const;
   
    int &operator[](int);
    int operator[](int)const;
    int &operator()(int,int);
    const int &operator()(int,int)const;
    private:
    int rows;
    int columns;
    int *ptr;
    int size;
    
};
#endif