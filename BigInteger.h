#ifndef BIGINTEGER_V1_0_BIGINTEGER_H
#define BIGINTEGER_V1_0_BIGINTEGER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <climits>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <chrono>
#include <ctime>
#include <list>
#include <deque>
#include <sstream>
#include <iterator>
using namespace std;
typedef long long int ll;
struct helper;
class BigInteger{
public:
    vector<int> mag;
    bool signum;
    BigInteger();
    explicit BigInteger(long long int);
    explicit BigInteger(string);
    BigInteger(const vector<int>& val,int sign){
        this->signum = sign;
        this->mag = val;
    }
    static void putInObject(vector<int> &value, ll transferredValue);
    friend ostream& operator<<(ostream& os,const BigInteger & num);
    friend istream& operator>>(istream& is,BigInteger & num);
    void printSelf() const;
    static void printSelf(const BigInteger& bigInteger);
    string toString() const;
    static string toString(const BigInteger& bigInteger);
    static void putInObject(vector<int> &value,const string& transferredValue);
    BigInteger(const BigInteger&);
    ~BigInteger();
    BigInteger add(const BigInteger&)const;
    BigInteger add(const long long&)const;
    BigInteger add(const string&)const;
    static int compareTo(vector<int> v1,vector<int> v2);
    int compareTo(const BigInteger&)const;
    int compareTo(const string&)const;
    int compareTo(const long long int&)const;
    BigInteger operator+() const ;
    BigInteger operator-() const;
    BigInteger& operator = (const BigInteger&);
    BigInteger& operator = (const long long int&);
    BigInteger& operator = (const string&);
    BigInteger sub(const BigInteger&)const;
    BigInteger sub(const long long int&)const;
    BigInteger sub(const string&)const;
    BigInteger operator+(const BigInteger& b2)const;
    BigInteger operator+(const long long int& b2)const;
    BigInteger operator+(const string& b2)const;
    BigInteger& operator+=(const BigInteger& b2);
    BigInteger& operator+=(const string& b2);
    BigInteger& operator+=(const long long int& b2);
    BigInteger operator-(const BigInteger& b2) const;
    BigInteger operator-(const long long int& b2) const;
    BigInteger operator-(const string& b2) const;
    BigInteger& operator-=(const BigInteger& b2);
    BigInteger& operator-=(const string& b2);
    BigInteger& operator-=(const long long int& b2);
    //pre
    BigInteger& operator++();
    //post
    BigInteger operator++(int dummy);
    //pre
    BigInteger& operator--();
    //post
    BigInteger operator--(int dummy);
    bool equals(const BigInteger& b2) const;
    bool equals(const long long int& b2) const;
    bool equals(const string& b2) const;
    bool lessThan(const BigInteger& b)const;
    bool lessThan(const long long int& b)const;
    bool lessThan(const string& b)const;
    bool operator < (const BigInteger& b) const;
    bool operator < (const string& b) const;
    bool operator < (const long long int& b) const;
    bool greaterThan(const BigInteger& b)const;
    bool greaterThan(const long long int& b)const;
    bool greaterThan(const string& b)const;
    bool operator > (const BigInteger& b) const;
    bool operator > (const string& b) const;
    bool operator > (const long long int& b) const;
    bool lessOrEqualTo(const BigInteger& b)const;
    bool lessOrEqualTo(const long long int& b)const;
    bool lessOrEqualTo(const string& b)const;
    bool operator <= (const BigInteger& b) const;
    bool operator <= (const long long int& b) const;
    bool operator <= (const string& b) const;
    bool greaterOrEqualTo(const BigInteger& b)const;
    bool greaterOrEqualTo(const long long int& b)const;
    bool greaterOrEqualTo(const string& b)const;
    bool operator >= (const BigInteger& b) const;
    bool operator >= (const string& b) const;
    bool operator >= (const long long int& b) const;
    bool equalTo(const BigInteger& b) const;
    bool equalTo(const long long int& b) const;
    bool equalTo(const string& b) const;
    bool operator == (const BigInteger& b) const;
    bool operator == (const string& b) const;
    bool operator == (const long long int& b) const;
    bool notEqualTo(const BigInteger& b)const;
    bool notEqualTo(const long long int& b)const;
    bool notEqualTo(const string& b)const;
    bool operator != (const BigInteger& b) const;
    bool operator != (const string& b) const;
    bool operator != (long long int b) const;
    BigInteger& toAbs();
    static BigInteger abs(const BigInteger&);
    static BigInteger abs(const string&);
    static BigInteger abs(const long long int&);
    BigInteger operator<<(long long y) const;
    BigInteger& operator<<(helper ip);
    BigInteger operator>>(const long long& y) const;
    BigInteger singleMul(const int& b) const;
    BigInteger mul(const BigInteger& b2)const;
    BigInteger mul(const string& b2)const;
    BigInteger mul(const long long int& b2)const;
    BigInteger operator*(const BigInteger& b2)const;
    BigInteger operator*(const string& b2)const;
    BigInteger operator*(const long long int& b2)const;
    BigInteger& operator*=(const BigInteger& b2);
    BigInteger& operator*=(const string& b2);
    BigInteger& operator*=(const long long int& b2);
    long long int toLonglongValue()const;
    friend short divHelp(BigInteger& b1,const BigInteger& b2);
    BigInteger div(const BigInteger& num,bool open=false)const;
    BigInteger div(const long long int& num)const;
    BigInteger div(const string& num)const;
    BigInteger operator/(const BigInteger& num)const;
    BigInteger operator/(const long long int& num)const;
    BigInteger operator/(const string& num)const;
    BigInteger& operator/=(const BigInteger& num);
    BigInteger& operator/=(const long long int& num);
    BigInteger& operator/=(const string& num);
    BigInteger operator%(const BigInteger & num)const;
    BigInteger operator%(const long long int& num)const;
    BigInteger operator%(const string& num)const;
    BigInteger& operator%=(const BigInteger & num);
    BigInteger& operator%=(const long long int& num);
    BigInteger& operator%=(const string& num);
    BigInteger mod(const BigInteger & num)const;
    BigInteger mod(const long long int& num)const;
    BigInteger mod(const string& num)const;
    BigInteger newton_sqrt()const;
    BigInteger excel_sqrt()const;
    static BigInteger value_of(const long long int&);
    static BigInteger value_of(const string&);
    static BigInteger value_of(const BigInteger&);
    BigInteger pow(int);
    static BigInteger pow(const BigInteger&,const int&);
    static BigInteger pow(const string&,const int&);
    static BigInteger pow(const long long int&,const int&);
    static BigInteger factorial(const int&);
    static BigInteger factorial(BigInteger);
    static BigInteger factorial(const string&);
    static BigInteger fibo(const long long int&);
    ll longlongValue() const;
    static ll longlongValue(const BigInteger&);

    static int bitLengthForInt(int &i);
};
static short sqrtDict[] = {0, 1 ,1 ,1 ,2 ,2 ,2 ,2 ,2 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9};
struct helper{

};
static helper ip;
static const long long LONG_MASK = 0xffffffff;

#endif //BIGINTEGER_V1_0_BIGINTEGER_H
