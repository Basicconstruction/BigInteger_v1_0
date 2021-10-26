#include <iostream>
#include "BigInteger.h"
using namespace std;
int main() {
    clock_t a = clock();
//    cout<<BigInteger(999).pow(99).excel_sqrt()<<endl;
//    BigInteger x = BigInteger::factorial(1000);
    for(int i = 0;i< 10;i++){
        cout<<BigInteger::factorial(10000)<<endl;
    }
//    cout<<x.excel_sqrt()<<endl;
    clock_t b = clock();
    cout<<b-a<<" ms"<<endl;
    return 0;
}
