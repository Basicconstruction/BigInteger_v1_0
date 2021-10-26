#include <iostream>
#include "BigInteger.h"
using namespace std;
int main() {
    clock_t a = clock();
    cout<<BigInteger(999).pow(999)<<endl;
    clock_t b = clock();
    cout<<b-a<<" ms"<<endl;
    return 0;
}
