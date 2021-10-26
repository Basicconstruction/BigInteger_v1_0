#include <iostream>
#include "BigInteger.h"
using namespace std;
int main() {
    clock_t a = clock();
//    cout<<BigInteger(999).pow(99).excel_sqrt()<<endl;
//    BigInteger x = BigInteger::factorial(1000);
    for(int i = 0;i< 1;i++){
        cout<<BigInteger::pow(999,1999).excel_sqrt()<<endl;
    }
//    cout<<x.excel_sqrt()<<endl;
    clock_t b = clock();
    cout<<b-a<<" ms"<<endl;
    return 0;
}
