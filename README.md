let's start
===
设计作用  
--
release v1.0.0  
当你打算在你的项目中嵌入gmp或其包装类之前，你可以先试着使用本项目来替换这些。  
因为本项目没有任何编译依赖，只需要将项目嵌入即可。不过本项目的C++版本可能比较高，
主要就是auto的使用（尽管我们在可以避让这一点）。你需要根据你的项目的C++版本来修正
项目代码。在项目前期作为测试来说，本项目足够，但是有一些不支持的，比如2进制移位，相应的提供的
是10进制移位，这也是导致项目效率相对较低的原因。因为使用2进制来计算效率高，但是也会更加的复杂。
所以对于2进制，你需要进行模拟。对于&^|<<>>的2进制模式均没有提供。这也不是项目的主要目的。    
这个项目被设计用来提供对大整数的支持，并提供了一系列的操作符重载来简化操作。  
可以嵌入作为一个计算项目的支持文件。尽管效率并非很好，但是效率也算得上是可以看的。  
可以用来支持 个人开发的计算器，转码器等。  

内存结构:
```cpp
公有成员
bool signum 用于存储一个数字是正数还是负数，这里默认定义0的signum=true//need to update.
vector<int> value 用于存储一个数的数据。存储的值为 0-9999
    存储规则:类似于cpu的数字存储方式采用小端存储的方式。
    示例:  10000-> 
        0 1
          123456->
        3456 12
        备注:为什么不采用大端存储？
        这是为了效率的考量。为了尽量提高程序的效率，如果采用大端存储，当进行 加法 运算时
        如果采用大端存储需要考虑进位，这在大端存储的形式代表着 向 vector的首位添加项目，
        由于vector的子项占用内存是连续排列的，这意味着需要先把原有的子项向后移动一位，
        然后把新项放置在首位，这会很严重地效率消耗(时间复杂度是O(n))。
        而采用小端存储时，只需要在vector地末端插入新项，时间复杂度是O(1).

```
声明一个对象并初始化
--
```cpp
构造函数声明
BigInteger();
explicit BigInteger(long long int);
explicit BigInteger(string);


BigInteger x;          x = 0;
BigInteger x(10)       x = 10;
BigInteger* p = new BigInteger(12);     p-> BigInteger(12);
前两种方法都会对对象进行初始化，默认初始化是 0

在初始化之后我们也可以使用
BigInteger d;     d = 0;
d = 1234;         d = 1234;

额外:
当数字足够大，比如大于 2 ^ 63-1 = 9223372036854775807
你需要使用字符串进行初始化，因为long long int 已经不足以囊括他。
使用字符串初始化地方式和数字一样，也可以通过字符串赋值。
``` 
基本操作
--
```cpp
使用BigInteger时，就像和使用 int 一样，支持+-*/%
示例:
BigInteger x(100);
x = x + 1;
x = x - 1;
x = x * 100;
x = x / 100;
x += 1;
x -= 1;
x *= 100;
x /= 100;
x = x % 3;
x %= 2;
x++;
x--;
甚至还可以直接使用原始方法(重载调用地方法)
+  ->   add
-  ->   sub
*  ->   mul
/  ->   div
%  ->   mod
示例:
    x = x.add(1);
    ....
对于这些操作，你也可以作用于 字符串，而不仅仅是 可以被推导到 long long int的值。
例如:
BigInteger x("100");
x += "1234";
x *= "134";

注意:
这个原生设计时不支持链式操作，比如 x.add(12).add(13).add(15);
尽管可以进行支持，但是考虑到add方法被众多方法使用,+号重载也是调用的add方法，这样的话会导致奇怪的
现象，比如
BigInteger x(100);
x+x+3;
cout<<x<<endl;    "203"
当然也可以设置为，对于+的重载设置为不可链式对于add设置为可链式。而且并非复杂，但是事实上写
需要重新拷贝add的一大串代码到operator+,会改变很多方法的声明。
所以没有提供对链式操作的支持。
.....
```
查看结果
--
```cpp
那么问题来了，如何查看结果呢?
有以下成员函数
toString()   返回字符串形式
    示例:
        BigInteger x(999);
        cout<<x.toString()<<endl;
        "999"
printSelf()  直接输出 类似于内存中数据的存储形式。
    示例:
        BigInteger y(99999);
        y.printSelf();
        9999 9 +
不过，如果仅仅直接输出数据，可以直接使用
    BigInteger y(999);
    std::cout<<y;
    备注：你也可以 使用std::cin>>y;来输入数据
toString()和prinfSelf()也有静态函数版本

static string toString(const BigInteger& bigInteger);
static void putInObject(vector<jbyte> &value,const string& transferredValue);
    示例:
        BigInteger x(112);
        string d = BigInteger::toString(x);
        cout<<d<<endl;

        BigInteger x(112);
        BigInteger::printSelf(x);
```
进行比较
--
```cpp
进行比较
>    ->greaterThan
<    ->lessThan
>=   ->greaterOrEqualTo
<=   ->lessOrEqualTo
==   ->equals,equalTo
!=   ->notEqualTo
使用示例
bool x = BigInteger(100)>199;
bool y = BigInteger(188).lessThan(199);
```

内置的基本函数
--
```cpp
内置的基本函数

成员函数
BigInteger pow(int);
使用示例:
    std::cout<<BigInteger(199).pow(999);
备注:
int 的表示范围已经足够大了。

静态函数
static BigInteger pow(BigInteger&,const int&);
static BigInteger pow(const string&,const int&);
static BigInteger pow(const long long int&,const int&);
static BigInteger factorial(const int&);
static BigInteger factorial(BigInteger);
static BigInteger factorial(const string&);
static BigInteger fibo(const long long int&);
使用示例:
    cout<<BigInteger::pow(BigInteger(199),100);
    cout<<BigInteger::pow(999,999);
    cout<<BigInteger::pow("999",999);
    cout<<BigInteger::factorial(1000);
    cout<<BigInteger::factorial(BigInteger(1000));
    cout<<BigInteger::factorial("1000");
    cout<<BigInteger::fibo(1000);
备注:有些我们没有实现，实际上对于这factorial int 已经足够作为参数，甚至short就已经足够，因为
计算阶乘是一个耗时的操作。对于Fibonacci数列，int也已经足够了。因为尽管我们的设计是使用尽可能大
的数，但是考虑到性能问题，很多东西依旧无法表示，是相当耗时的行为。

在使用的时候，尽量使用int型数字
比如:使用pow时,factorial，fibo时常用的操作是
cout<<BigInteger(999).pow(999);
cout<<BigInteger::factorial(10000);
cout<<BigInteger::fibo(10000);
```
额外进行扩展
--
```cpp
BigInteger operator<<(long long y) const;
BigInteger operator>>(const long long& y) const;
x = 100;
x<<2;    ->      x = 10000;
x = 123;
x>>2;    ->      x = 1;
这两个是10进制的移位函数。
尤其是<<,被应用在乘法的构建。
```
使用示例
--
```cpp
clock_t begin = clock();
for(int i = 0;i<1;i++){
    cout<<BigInteger(999).pow(99)-BigInteger(999).pow(99).excel_sqrt().pow(2)<<endl;
    BigInteger *x = new BigInteger(0);
    *x = BigInteger(999).pow(99)/BigInteger(999).pow(99).excel_sqrt();
    cout<<*x<<endl;
    BigInteger y = BigInteger(999).pow(99).mod(BigInteger(999).pow(99).excel_sqrt());
    cout<<y<<endl;
    cout<<(((*x) * BigInteger(999).pow(99).excel_sqrt()+y) == BigInteger(999).pow(99)?"true":"false");
}
clock_t end = clock();
cout<<endl<<end-begin<<"ms"<<endl;

---output:
504357043537230224403818104856985579375392063109852346587655295806487996311782938786119122436843090692294903254800577215
27806795342785448683795207783
300948142535997006897791156452603268672720621383126034090785508072767585766750508704752007560412692094713609658473280585
88219188780734175482449383597
203408901001233217506026948404382310702671441726726312496869787733720410545032430081367114876430398597581293596327296629
39587606562051273201345824187
true
1026ms //need to update the newly data.
```
Performance Testing
==
test platform
--
CLion 2021.2  
Build \#CL-212.4746.93, built on July 27, 2021  
Runtime version: 11.0.11+9-b1504.13 amd64  
VM: OpenJDK 64-Bit Server VM by JetBrains s.r.o.  
Windows 10 10.0  
GC: G1 Young Generation, G1 Old Generation  
Memory: 2000M  
Cores: 16  
Registry: run.processes.with.pty=TRUE  
Non-Bundled Plugins: com.kite.intellij (1.9.4)  
gun mingw  
Amd Ryzen 7 4000  
microsoft window 11  

本项目的测试数据暂时还没有添加，但是目前的状态时，相对于vector列有大约10%-50%的速度优化.(很可能更多内存)
--
本项目:
factorial(10000) 1841ms
fibo(10000) 131ms
fibo(50000) 695ms
pow(3,10000) 276ms
pow(3,10000).excel_sqrt() 14290 ms
pow(999,999) 159ms
pow(199,200) 28ms


|aspect|string|python|vector|java|julia|
|:---: | :---:|:---:|:---:|:---:|:---:|
|factorial(10) | | | | | |
| 100 | 67ms|0|3ms|6ms|0.024215 s|
|1000|17930ms|0|955ms|21ms|0.070049 s|
|10000|>>10s|0.34375s|22996ms|516ms|0.546226 s|
|100000| |50.875s| |29551.0ms|  30.027473 s |
|pow(2 ** x)(10)| | |single| | |
|100|12ms|0|37ms|0|0.023329|
|1000|730ms|0|324ms|0|0.026742|
|10000|8234ms / one|0|4344ms|16ms|0.110875|
|100000| |0.125s|15459ms/single|200ms|3.518582 s|
|1000000| |12.5625s|null|1504.0ms|155.85642 s(get one and mul 10)|
|fibo(10)| | | | | |
|100|10ms| |24ms|2ms/0ms|0.058215 s/0.023118 s|
|1000|277ms| |208ms|11ms/3ms|0.061844 s/ 0.026205 s|
|10000|26977ms| |2641ms|62ms/41ms| 0.130s/0.084748|
|100000|null|null|null|1531.0ms|null/2.615493 s|  


***在计算Fibonacci序列时，对java和julia分别采用了两种算法来进行计算，大致可以说明赋值要快于从字典中查找值。***
```python
#计算pow(2,x)  python
import time
start = time.process_time()
for i in range(10):
    print(2**10000)
end = time.process_time()
print(end-start)
```

```python
#就算factorial  python
import time
start = time.process_time()
for i in range(10):
    res = 1
    for j in range(1,100000):
        res *= j
        print(res)
end = time.process_time()
print(end-start)
```

```julia
#julia
function factorial(i)
    res = BigInt(1)
    for j in collect(1:i)
        res *= j
    end
    return res
end
```
```julia
#julia
function pow2(i,n=2)
    res = BigInt(1)
    for j in collect(1:i)
        res *= n
    end
    return res
end
```
```julia
#julia
known = Dict(0=>BigInt(0), 1=>BigInt(1))
function fibonacci(n)
    if n ∈ keys(known)
        return known[n]
    end
    res = fibonacci(n-1) + fibonacci(n-2)
    known[n] = res
    res
end
#fun2
function fibonacci2(n)
    x = BigInt(1)
    y = BigInt(0)
    z = BigInt(1)
    for k in collect(2:n)
        x = y
        y = z
        z = x + y
    end
    z
end
```
```java
//java
import javax.xml.crypto.Data;
import java.math.BigInteger;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

public class BoostUp {
    public static BigInteger myfibo(HashMap<Integer,BigInteger> hm,int x){
        if(hm.containsKey(x)){
            return hm.get(x);
        }
        BigInteger res =  myfibo(hm,x-2).add(myfibo(hm,x-1));
        hm.put(x,res);
        return res;
    }
    public static BigInteger myFibo2(int p){
        BigInteger x = new BigInteger("1");
        BigInteger y = new BigInteger("0");
        BigInteger z = new BigInteger("1");
        for (int h = 2; h <= p; h++) {
            x = y;
            y = z;
            z = x.add(y);
        }
        return z;
    }
//    public static BigInteger help(int i)
    public static void myPow(int x){
        BigInteger v = new BigInteger("2");
        System.out.println(v.pow(x));
    }
    public static void myFactorial(int x){
        BigInteger v = new BigInteger("1");
        for(int i = 1;i<=x;i++){
            v = v.multiply(BigInteger.valueOf(i));
        }
        System.out.println(v);
    }
    public static void main(String[] args){
        double predata = new Date().getTime();
        for(int i = 0;i <10;i++){
//            myPow(1000);
            HashMap<Integer,BigInteger> map = new HashMap<>();
            map.put(0,new BigInteger("0"));
            map.put(1,new BigInteger("1"));
//            myFactorial(100000);
//            System.out.println(myfibo(map,100000));
            System.out.println(myFibo2(100000));
        }
        System.out.println((new Date().getTime()-predata)+"ms");
    }
}

```