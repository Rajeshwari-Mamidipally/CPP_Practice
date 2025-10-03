#ifndef RAJESHWARI_SEP26_TASK3_HUGEINT_H
#define RAJESHWARI_SEP26_TASK3_HUGEINT_H
#include<string>
class HugeInt{
    friend std::ostream &operator<<( std::ostream &, const HugeInt & );
    public:
    static const int digits = 30;
    HugeInt( long = 0 );
    HugeInt( const std::string & );
    HugeInt operator+( const HugeInt & ) const;
    HugeInt operator+( int ) const; 
    HugeInt operator+( const std::string & ) const;
    HugeInt operator*(const HugeInt &) const;
    HugeInt operator*(int) const;
    HugeInt operator*(const std::string &)const;
    HugeInt operator/(const HugeInt &) const;
    HugeInt operator/(int) const;
    HugeInt operator/(const std::string &)const;
    bool operator==(const HugeInt &) const;
    bool operator==(int) const;
    bool operator==(const std::string &)const;
    bool operator!=(const HugeInt &) const;
    bool operator!=(int) const;
    bool operator!=(const std::string &)const;
    bool operator<=(const HugeInt &) const;
    bool operator<=(int) const;
    bool operator<=(const std::string &)const;
    bool operator>=(const HugeInt &) const;
    bool operator>=(int) const;
    bool operator>=(const std::string &)const;
    bool operator<(const HugeInt &) const;
    bool operator<(int) const;
    bool operator<(const std::string &)const;
    bool operator>(const HugeInt &) const;
    bool operator>(int) const;
    bool operator>(const std::string &)const;

    private:
    short integer[ digits ];

};

#endif
