#include <iostream>
#include "BigInteger.h"
using namespace std;
int main() {
    clock_t a = clock();
//    cout<<BigInteger(999).pow(99).excel_sqrt()<<endl;
//    BigInteger x = BigInteger::factorial(1000);
    for(int i = 0;i< 1;i++){
//        cout<<BigInteger::fibo(30001)<<endl;
//        cout<<BigInteger::pow(-5,999)<<endl;
        cout<<BigInteger(-5)*7*-4*8*-2<<endl;
        cout<<BigInteger(8)*BigInteger(-2)<<endl;
        cout<<BigInteger(-9).pow(3)<<endl;
    }
//    cout<<x.excel_sqrt()<<endl;
    clock_t b = clock();
    cout<<b-a<<" ms"<<endl;
    return 0;
}
