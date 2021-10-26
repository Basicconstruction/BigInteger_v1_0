#include <iterator>
#include "BigInteger.h"
using namespace std;
ostream& operator<<(ostream& os,const BigInteger & num){
    char fillc = os.fill('0');
    auto it = num.mag.rbegin();
    if(!num.signum){
        os<<"-";
    }
    os<<*it++;
    for(;it!=num.mag.rend(); it++){
        os<<std::setw(4)<<*it;
    }
    os<<setfill(fillc);
    return os;
}
istream &operator>>(istream & is, BigInteger & num) {
    string s;
    getline(cin,s,'\n');
    BigInteger tmp(s);
    num.signum = tmp.signum;
    num.mag = tmp.mag;
    return is;
}

void BigInteger::putInObject(vector<int>& value,ll transferredValue){
    for(int & it : value){
        it = static_cast<int>(transferredValue%10000);
        transferredValue/=10000;
    }
}
string BigInteger::toString() const{
    return BigInteger::toString(*this);
}
string BigInteger::toString(const BigInteger& bigInteger){
    string s;
    s+= bigInteger.signum ? "" : "-";
    ostringstream os;
    std::vector<int>::const_reverse_iterator it = bigInteger.mag.rbegin();
    os<<*it;
    ++it;
    for(;it!=bigInteger.mag.rend(); it++){
        int r = *it;
        if(r>=1000){
            os<<r;
        }else if(r>=100){
            os<<0<<r;
        }else if(r>=10){
            os<<"00"<<r;
        }else{
            os<<"000"<<r;
        }
    }
    s+= os.str();
    return s;
}
void BigInteger::printSelf() const {
    BigInteger::printSelf(*this);
}
void BigInteger::printSelf(const BigInteger& bigInteger){
    std::ostream_iterator<int> out(std::cout," ");
    copy(bigInteger.mag.begin(), bigInteger.mag.end(), out);
    std::cout<<((bigInteger.signum)?'+':'-')<<std::endl;
}

void BigInteger::putInObject(vector<int> &value,const string& transferredValue){
    typedef vector<int>::reverse_iterator vri;
    typedef string::const_iterator sci;
    vri it = value.rbegin();
    sci sit = transferredValue.begin();
    int first = transferredValue.length()%4;
    if(first!=0){
        int res = 0;
        while(first--){
            res *= 10;
            res += static_cast<int>(static_cast<short>(*sit++-'0'));
        }
        *it = res;
        it++;
    }
    for(;it!=value.rend();it++){
        *it = static_cast<int>(*sit-'0')*1000+static_cast<int>(*(++sit)-'0')*100
                +static_cast<int>(*(++sit)-'0')*10+static_cast<int>(*(++sit)-'0');
        sit++;
    }
}

int BigInteger::compareTo(vector<int> v1, vector<int> v2) {
    //假设每个序列都是数据完好的，比如0->[0]而不会是[0][0][0],如果这样会使得错误的快捷比较。这是需要保证的。
    typedef vector<int>::reverse_iterator VJi;
    if(v1.size()>v2.size()){
        return 1;
    }else if(v1.size()<v2.size()){
        return -1;
    }else{
        VJi it1 = v1.rbegin();
        VJi it2 = v2.rbegin();
        for(;it1!=v1.rend();it1++,it2++){
            if(*it1>*it2){
                return 1;
            }else if(*it1<*it2){
                return -1;
            }
        }
        return 0;

    }
}
BigInteger BigInteger::value_of(const long long int& num) {
    return BigInteger(num);
}
BigInteger BigInteger::value_of(const string& num) {
    return BigInteger(num);
}
BigInteger BigInteger::value_of(const BigInteger &num) {
    return num;
}
BigInteger BigInteger::pow(int times){
    return BigInteger::pow(*this,times);
}
BigInteger BigInteger::pow(const BigInteger& bigInteger, const int& times) {
    if(times == 0){
        return BigInteger::value_of(1);
    }else if(times == 1){
        return bigInteger;
    }
    BigInteger res;
    res = 1;
    for(int i = 0; i < times; i++){
        res *= bigInteger;
    }
    return res;
}
BigInteger BigInteger::pow(const string& num, const int& times) {
    BigInteger tmp(num);
    return BigInteger::pow(tmp,times);
}

BigInteger BigInteger::pow(const long long int& num, const int& times) {
    BigInteger tmp(num);
    return BigInteger::pow(tmp,times);
}

BigInteger BigInteger::factorial(BigInteger num) {
    if(num == 0){
        return BigInteger(1);
    }
    BigInteger res;
    for(;num>=1;num--){
        res *= num;
    }
    return res;
}

BigInteger BigInteger::factorial(const string& num) {
    return BigInteger::factorial(BigInteger(num));
}
BigInteger BigInteger::factorial(const int& num) {
    if(num==0||num==1){
        return BigInteger(1);
    }
    BigInteger res(1);
    for(int i = 2;i<num;i++){
        res *= BigInteger(i);
    }
    return res;
}
BigInteger BigInteger::fibo(const long long int& p) {
    if (p == 0) {
        return BigInteger(0);
    } else if (p == 1) {
        return BigInteger(1);
    } else {
        BigInteger x(1);
        BigInteger y(0);
        BigInteger z(1);
        for (int h = 2; h <= p; h++) {
            x = y;
            y = z;
            z = x.add(y);
        }
        return z;
    }
}
ll BigInteger::longlongValue() const {
    return BigInteger::longlongValue(*this);
}
ll BigInteger::longlongValue(const BigInteger &num) {
    ll res = 0;
    vector<int>::const_reverse_iterator it = num.mag.rbegin();
    res += (*it++);
    while(it!=num.mag.rend()){
        res *= 10000;
        res += *it;
        it++;
    }
    return res;
}

short divHelp(BigInteger &b1, const BigInteger &b2){
    for (short k = 2; k <= 9; ++k) {
        if (b1 == (b2 * k)) {
            return k;
        }
        else if (b1 < (b2 * k)) {
            return --k;
        }
        else {

        }
    }
    return 9;
}
long long int BigInteger::toLonglongValue()const{
    long long int res = 0;
    vector<int> vec = (*this).mag;
    vector<int>::const_reverse_iterator it = vec.rbegin();
    while(it!=vec.rend()){
        res *= 100;
        res += (*it);
        it++;
    }
    return this->signum?res:-res;
}
BigInteger::~BigInteger() = default;//并没有指针型对象，无需显式释放空间
BigInteger::BigInteger(long long int initNum) {
    if (initNum >= 0) {
        signum = true;
    }
    else {
        initNum = -initNum;
        signum = false;
    }
    int p = 4;
    ll tmp = initNum;
    tmp/=10000;
    while(tmp>0){
        tmp/=10000;
        p+=4;
    }
    int eff_size = p/4;
    this->mag = vector<int>(eff_size);
    putInObject(this->mag, initNum);
}
BigInteger::BigInteger(string initStr) {
    //ignore initStr such as "000123";
    if(initStr[0]=='+'){
        this->signum = true;
        initStr = string(initStr.begin()+1,initStr.end());
    }else if(initStr[0]=='-'){
        this->signum = false;
        initStr = string(initStr.begin()+1,initStr.end());
    }else{
        this->signum = true;
    }
    unsigned int size = initStr.size();
    size = size % 4==0?size/4:size/4+1;
    this->mag = vector<int>(size);
    putInObject(this->mag, initStr);
}
BigInteger::BigInteger(const BigInteger &bigInteger) {
    this->signum = bigInteger.signum;
    this->mag = vector<int>(bigInteger.mag);//like .assign()
}
BigInteger::BigInteger(){
    this->signum = true;
    this->mag = vector<int>(1, 0);
}
//
// Created by hay boy on 2021/10/3.
//
#include <iterator>
#include "BigInteger.h"

BigInteger BigInteger::add(const BigInteger &num) const {
    short carry = 0;
    vector<int> tem = this->mag;
    vector<int> added = num.mag;
    vector<int> longOne, shortOne;
    if ((this->signum && num.signum) || (!this->signum && !num.signum)) {
        if (tem.size() >= added.size()) {
            longOne = tem;
            shortOne = added;
        } else {
            longOne = added;
            shortOne = tem;
        }
        vector<int>::iterator it = longOne.begin();
        vector<int>::iterator it2 = shortOne.begin();
        for (; it != longOne.end(); it++) {
            if (it2 != shortOne.end()) {
                int tmp = (*it) + (*it2) + carry;
                if (tmp >= 10000) {
                    carry = 1;
                    *it = tmp - 10000;
                } else {
                    carry = 0;
                    *it = tmp;
                }
                it2++;
            } else {
                int tmp = (*it) + carry;
                if (tmp >= 10000) {
                    carry = 1;
                    *it = tmp - 10000;
                } else {
                    carry = 0;
                    *it = tmp;
                }
            }
        }
        if (carry > 0) {
            longOne.push_back(1);
        }
        BigInteger res;
        res.signum = this->signum;
        res.mag.swap(longOne);
        return res;
    } else {
        int cres = compareTo(tem, added);
        BigInteger res;
        if (cres == 0) {
            return BigInteger(0);
        } else if (cres == 1) {
            res.signum = this->signum;
            longOne = tem;
            shortOne = added;
        } else {
            res.signum = !this->signum;
            longOne = added;
            shortOne = tem;
        }
        vector<int>::iterator it = longOne.begin();
        vector<int>::iterator it2 = shortOne.begin();
        for (; it != longOne.end(); it++) {
            if (it2 != shortOne.end()) {
                int tmp = (*it) - (*it2) - carry;
                if (tmp < 0) {
                    tmp = tmp + 10000;
                    carry = 1;
                } else {
                    carry = 0;
                }
                *it = tmp;
                it2++;
            } else {
                int tmp = (*it) - carry;
                if (tmp < 0) {
                    tmp = tmp + 10000;
                    carry = 1;
                } else {
                    carry = 0;
                }
                *it = tmp;
            }
        }
        assert(carry == 0);
        res.mag.swap(longOne);
        std::vector<int>::iterator back_i = res.mag.end() - 1;
        for (; back_i != res.mag.begin(); back_i--) {
            if (*back_i == 0) {
                res.mag.erase(back_i);
            } else {
                break;
            }
        }
        return res;

    }
}

BigInteger BigInteger::add(const long long &num) const {
    BigInteger b2(num);
    return add(b2);
}

BigInteger BigInteger::add(const string &num) const {
    BigInteger b2(num);
    return add(b2);
}


int BigInteger::compareTo(const BigInteger &num) const {
    if (this->signum && !num.signum) {
        return 1;
    } else if (!this->signum && num.signum) {
        return -1;
    } else {
        int getSignal = compareTo((*this).mag, num.mag);
        if (getSignal == 0) {
            return 0;
        } else {
            return getSignal * (this->signum ? 1 : -1);
        }
    }
}

int BigInteger::compareTo(const long long int &num) const {
    BigInteger b2(num);
    return compareTo(b2);
}

int BigInteger::compareTo(const string &num) const {
    BigInteger b2(num);
    return compareTo(b2);
}


BigInteger BigInteger::sub(const BigInteger &num) const {
    BigInteger b2 = -num;
    return this->add(b2);
}

BigInteger BigInteger::sub(const long long &num) const {
    BigInteger b0(num);
    BigInteger b2 = -b0;
    return this->add(b2);
}

BigInteger BigInteger::sub(const string &num) const {
    BigInteger b0(num);
    BigInteger b2 = -b0;
    return this->add(b2);
}

bool BigInteger::equals(const BigInteger &num) const {
    if (this->compareTo(num) == 0) {
        return true;
    } else {
        return false;
    }
}

bool BigInteger::equals(const long long int &num) const {
    if (this->compareTo(num) == 0) {
        return true;
    } else {
        return false;
    }
}

bool BigInteger::equals(const string &num) const {
    if (this->compareTo(num) == 0) {
        return true;
    } else {
        return false;
    }
}


BigInteger BigInteger::abs(const BigInteger &num) {
    BigInteger b2 = num;
    b2.signum = true;
    return b2;
}

BigInteger BigInteger::abs(const string &num) {
    BigInteger b2 = BigInteger(num);
    b2.signum = true;
    return b2;
}

BigInteger BigInteger::abs(const long long int &num) {
    BigInteger b2 = BigInteger(num);
    b2.signum = true;
    return b2;
}

BigInteger BigInteger::singleMul(const int &b) const {
    if (b == 0) {
        return {};
    } else if (b == 1) {
        return *this;
    }
    BigInteger tis = *this;
    int expr;
    int push = 0;
    for(int & i : tis.mag){
        expr = i*b+push;
        if(expr>=10000){
            push = expr / 10000;
            expr %= 10000;
        }else{
            push = 0;
        }
        i = expr;
    }
    if(push>0){
        tis.mag.push_back(push);
    }
    return tis;
}

BigInteger BigInteger::mul(const BigInteger &b2) const {
    BigInteger res;
    BigInteger tis = *this;
    vector<int>::const_reverse_iterator rit = b2.mag.rbegin();
    for (; rit != b2.mag.rend(); rit++) {
        res << ip;
        res += tis.singleMul(*rit);
    }
    res.signum = (this->signum == b2.signum);
    return res;
}

BigInteger BigInteger::mul(const long long int &b2) const {
    return this->mul(BigInteger(b2));
}

BigInteger BigInteger::mul(const string &b2) const {
    return this->mul(BigInteger(b2));
}


bool BigInteger::lessThan(const BigInteger &b) const {
    return this->compareTo(b) < 0;
}

bool BigInteger::lessThan(const long long int &b) const {
    return this->compareTo(b) < 0;
}

bool BigInteger::lessThan(const string &b) const {
    return this->compareTo(b) < 0;
}


bool BigInteger::greaterThan(const BigInteger &b) const {
    return this->compareTo(b) > 0;
}

bool BigInteger::greaterThan(const long long int &b) const {
    return this->compareTo(b) > 0;
}

bool BigInteger::greaterThan(const string &b) const {
    return this->compareTo(b) > 0;
}


bool BigInteger::lessOrEqualTo(const BigInteger &b) const {
    return this->compareTo(b) <= 0;
}

bool BigInteger::lessOrEqualTo(const long long int &b) const {
    return this->compareTo(b) <= 0;
}

bool BigInteger::lessOrEqualTo(const string &b) const {
    return this->compareTo(b) <= 0;
}


bool BigInteger::greaterOrEqualTo(const BigInteger &b) const {
    return this->compareTo(b) >= 0;
}

bool BigInteger::greaterOrEqualTo(const long long int &b) const {
    return this->compareTo(b) >= 0;
}

bool BigInteger::greaterOrEqualTo(const string &b) const {
    return this->compareTo(b) >= 0;
}


bool BigInteger::equalTo(const BigInteger &b) const {
    return this->compareTo(b) == 0;
}

bool BigInteger::equalTo(const string &b) const {
    return this->compareTo(b) == 0;
}

bool BigInteger::equalTo(const long long int &b) const {
    return this->compareTo(b) == 0;
}


bool BigInteger::notEqualTo(const BigInteger &b) const {
    return this->compareTo(b) != 0;
}

bool BigInteger::notEqualTo(const long long int &b) const {
    return this->compareTo(b) != 0;
}

bool BigInteger::notEqualTo(const string &b) const {
    return this->compareTo(b) != 0;
}


BigInteger BigInteger::div(const BigInteger &num, bool open) const {
    if (open && this->lessThan(BigInteger(9223372036854775807))) {
        return BigInteger((*this).toLonglongValue() / num.toLonglongValue());
    }
    if (num.equalTo(BigInteger(0))) {
        throw runtime_error("num shouldn't be the zero");
    }
    BigInteger tmp;
    if (num.equalTo(BigInteger(1))) {
        return *this;
    } else if (num.equalTo(BigInteger(-1))) {
        tmp = *this;
        tmp.signum = !tmp.signum;
        return tmp;
    }
    if (compareTo(num.mag, (*this).mag) == 1) {
        return BigInteger(0);
    }
    tmp.mag = (*this).mag;
    tmp.signum = true;
    string s = tmp.toString();
    size_t len = s.length();
    size_t p = 0;
    for (; p < len;) {
        BigInteger y(string(s.begin(), s.begin() + 1 + p));
        if (y < num) {
            p++;
        } else {
            break;
        }
    }
    BigInteger *t = new BigInteger(string(s.begin(), s.begin() + 1 + p));
    short cal;
    int newp = p;
    BigInteger res;
    while (true) {
        if (*t < num) {
            res = (res << 1);
        } else {
            cal = divHelp(*t, num);
            res = (res << 1).add(cal);//unpredict problem when use +
        }
        tmp -= ((num * cal) << (len - 1 - newp));
        if (res.toString().length() == len - p) {
            break;
        }
        newp++;
        {
            BigInteger foyer = (*t).sub((num * cal));
            if (foyer.equalTo(BigInteger(0))) {
                t = new BigInteger(static_cast<int>((*this).toString()[newp] - '0'));
            } else {
                *t = (foyer << 1).add(static_cast<int>((*this).toString()[newp] - '0'));
            }
        }
        cal = 0;
    }
    res.signum = ((*this).signum == num.signum);
    return res;
}

BigInteger BigInteger::div(const long long int &num) const {
    BigInteger ft(num);
    return div(ft);
}

BigInteger BigInteger::div(const string &num) const {
    BigInteger ft(num);
    return div(ft);
}


BigInteger BigInteger::mod(const BigInteger &num) const {
    if (this->lessThan(BigInteger(9223372036854775807))) {
        return BigInteger((*this).toLonglongValue() % num.toLonglongValue());
    }
    if (compareTo(num.mag, (*this).mag) == 1) {
        if (this->signum) {
            return *this;
        } else {
            return (*this) + num;
        }
    }
    BigInteger tmp = (*this);
    if (!this->signum) {
        while (tmp.lessThan(BigInteger(0))) {
            tmp += num;
        }
    }
    string s = tmp.toString();
    size_t len = s.length();
    size_t p = 0;
    //    BigInteger b = num;
    for (; p < len;) {
        BigInteger y(string(s.begin(), s.begin() + 1 + p));
        if (y < num) {
            p++;
        } else {
            break;
        }
    }
    BigInteger *t = new BigInteger(string(s.begin(), s.begin() + 1 + p));
    short cal;
    int newp = p;
    int resultLen = 0;
    while (true) {
        if (*t < num) {
        } else {
            cal = divHelp(*t, num);
        }
        resultLen++;
        tmp -= ((num * cal) << (len - 1 - newp));
        if (resultLen == len - p) {
            break;
        }
        newp++;
        {
            BigInteger foyer = (*t).sub((num * cal));
            if (foyer.equalTo(BigInteger(0))) {
                t = new BigInteger(static_cast<int>((*this).toString()[newp] - '0'));
            } else {
                *t = (foyer << 1).add(static_cast<int>((*this).toString()[newp] - '0'));
            }
        }
        cal = 0;
    }
    return tmp;

}

BigInteger BigInteger::mod(const long long int &num) const {
    return mod(BigInteger(num));
}

BigInteger BigInteger::mod(const string &num) const {
    return mod(BigInteger(num));
}

BigInteger &BigInteger::toAbs() {
    this->signum = true;
    return *this;
}

BigInteger BigInteger::newton_sqrt() const {
    BigInteger res(1);
    bool t = true;
    while (t) {
        res = (res + (*this) / res) / 2;
        t = (res * res <= (*this) && (res + 1) * (res + 1) > (*this)) ||
                (res * res >= (*this) && (res - 1) * (res - 1) < (*this));
        t = !t;
        cout << t << endl;
    }
    return (res * res <= (*this) && (res + 1) * (res + 1) > (*this)) ? res : res - 1;
}

BigInteger BigInteger::excel_sqrt() const {
    short len;
    short ori;
    short num = short(*(this->mag.rbegin()));
    ori = sqrtDict[num];
    len = this->mag.size();
    BigInteger res(ori);
    res = res << len;
    bool t = true;
    while (t) {
        res = (res + (*this) / res) / 2;
        t = (res * res <= (*this) && (res + 1) * (res + 1) > (*this)) ||
                (res * res >= (*this) && (res - 1) * (res - 1) < (*this));
        t = !t;
    }
    return (res * res <= (*this) && (res + 1) * (res + 1) > (*this)) ? res : res - 1;
}
#include "BigInteger.h"
using std::vector;
using std::list;
using std::deque;
BigInteger& BigInteger::operator = (const BigInteger& num)= default;
BigInteger& BigInteger::operator=(const long long int& num) {
    *this = BigInteger(num);
    return *this;
}
BigInteger &BigInteger::operator=(const string& num) {
    *this = BigInteger(num);
    return *this;
}
BigInteger BigInteger::operator+() const {
    return *this;
}

BigInteger BigInteger::operator-()const{
    BigInteger b2 = *this;
    b2.signum = !b2.signum;
    return b2;
}

BigInteger& BigInteger::operator+=(const BigInteger& num) {
    *this = this->add(num);
    return *this;
}
BigInteger& BigInteger::operator+=(const string&num) {
    *this = this->add(num);
    return *this;
}
BigInteger& BigInteger::operator+=(const long long int& num) {
    *this = this->add(num);
    return *this;
}


BigInteger& BigInteger::operator-=(const BigInteger& num) {
    *this = this->sub(num);
    return *this;
}
BigInteger& BigInteger::operator-=(const string& num) {
    *this = this->sub(num);
    return *this;
}
BigInteger& BigInteger::operator-=(const long long int& num) {
    *this = this->sub(num);
    return *this;
}


//pre
BigInteger& BigInteger::operator++() {
    (*this) += 1;
    return *this;
}
//post
BigInteger BigInteger::operator++(int dummy) {
    BigInteger x = *this;
    (*this) += 1;
    return x;
}
//pre
BigInteger& BigInteger::operator--() {
    (*this) -= 1;
    return *this;
}
//post
BigInteger BigInteger::operator--(int dummy) {
    BigInteger x = BigInteger(*this);
    (*this) -= 1;
    return x;
}


BigInteger BigInteger::operator<<(long long int y) const {
    //bigger
    assert(y>=0);
    BigInteger b2 = *this;
    if(*this==0){
        return BigInteger(0);
    }
    if(y%4==0){
        vector<int> vi = b2.mag;
        deque<int> di(vi.begin(),vi.end());
        for(long long i = 0;i<y/4;i++){
            di.push_front(0);
        }
        b2.mag = vector<int>(di.begin(), di.end());
    }else{
        vector<int> vi = b2.mag;
        ostringstream os;
        std::vector<int>::const_reverse_iterator it = vi.rbegin();
        os<<(*it++);
        for(;it!=vi.rend();){
            int r = *it++;
            if(r>=1000){
                os<<r;
            }else if(r>=100){
                os<<"0"<<r;
            }else if(r>=10){
                os<<"00"<<r;
            }else{
                os<<"000"<<r;
            }
        }
        string s = os.str()+string(y%4,'0');
        vi.resize(s.length()%4==0?s.length()/4:s.length()/4+1);
        BigInteger::putInObject(vi,s);
        deque<int> di(vi.begin(),vi.end());
        y = y - y%4;
        for(long long i = 0;i<y/4;i++){
            di.push_front(0);
        }
        b2.mag = vector<int>(di.begin(), di.end());
    }
    return b2;
}

BigInteger& BigInteger::operator<<(helper isp){
    if(this->equals(BigInteger(0))){
        return *this;
    }
    int a[] = {0};
    copy(a,a+1,std::inserter(this->mag, this->mag.begin()));
    return *this;
}


BigInteger BigInteger::operator>>(const long long int& y) const {
    //smaller
    assert(y>=0);
    BigInteger b2 = *this;
    vector<int> vi = b2.mag;
    ostringstream os;
    std::vector<int>::const_reverse_iterator it = vi.rbegin();
    os<<short(*it);
    ++it;
    for(;it!=vi.rend();it++){
        int r = *it;
        if(int(r)>=10){
            os<<(short)r;
        }else{
            os<<0<<short(r);
        }
    }
    string s = os.str();
    if(y>=s.length()){
        return BigInteger(0);
    }
    size_t len_new = s.length() - y;
    vi.resize(len_new%2==0?len_new/2:len_new/2+1);
    BigInteger::putInObject(vi,string(s.begin(),s.begin()+int(len_new)));
    b2.mag = vi;
    return b2;
}
BigInteger BigInteger::operator*(const BigInteger& b2)const{
    return this->mul(b2);
}
BigInteger BigInteger::operator*(const string& b2)const{
    return this->mul(b2);
}
BigInteger BigInteger::operator*(const long long int& b2)const{
    return this->mul(b2);
}

BigInteger &BigInteger::operator*=(const BigInteger &b2) {
    (*this).mag = this->mul(b2).mag;
    return *this;
}

BigInteger &BigInteger::operator*=(const string &b2) {
    (*this).mag = this->mul(b2).mag;
    return *this;
}

BigInteger &BigInteger::operator*=(const long long int& b2) {
    (*this).mag = this->mul(b2).mag;
    return *this;
}


bool BigInteger::operator<(const string &b) const {
    BigInteger tmp(b);
    return this->lessThan(tmp);
}
bool BigInteger::operator < (const BigInteger& b) const {
    return this->compareTo(b) < 0;
}
bool BigInteger::operator<(const long long int& b) const {
    BigInteger tmp(b);
    return this->lessThan(tmp);
}


bool BigInteger::operator > (const BigInteger& b) const {
    return this->compareTo(b) > 0;
}
bool BigInteger::operator>(const string& b) const {
    BigInteger tmp(b);
    return this->greaterThan(tmp);
}
bool BigInteger::operator>(const long long int& b) const {
    BigInteger tmp(b);
    return this->greaterThan(tmp);
}


bool BigInteger::operator <= (const BigInteger& b) const {
    return this->compareTo(b) <= 0;
}
bool BigInteger::operator<=(const string& b) const {
    BigInteger tmp(b);
    return this->lessOrEqualTo(tmp);
}
bool BigInteger::operator<=(const long long int& b) const {
    BigInteger tmp(b);
    return this->lessOrEqualTo(tmp);
}


bool BigInteger::operator >= (const BigInteger& b) const {
    return this->compareTo(b) >= 0;
}
bool BigInteger::operator>=(const string& b) const {
    BigInteger tmp(b);
    return this->greaterOrEqualTo(tmp);
}
bool BigInteger::operator>=(const long long int& b) const {
    BigInteger tmp(b);
    return this->greaterOrEqualTo(tmp);
}

bool BigInteger::operator == (const BigInteger& b) const {
    return this->equals(b);
}
bool BigInteger::operator==(const string& b) const {
    BigInteger tmp(b);
    return this->equalTo(tmp);
}
bool BigInteger::operator==(const long long int& b) const {
    BigInteger tmp(b);
    return this->equalTo(tmp);
}

bool BigInteger::operator!=(const string &b) const {
    BigInteger tmp(b);
    return this->notEqualTo(tmp);
}

bool BigInteger::operator != (const BigInteger& b) const {
    return !this->equals(b);
}
bool BigInteger::operator!=(long long int b) const {
    BigInteger tmp(b);
    return this->notEqualTo(tmp);
}


BigInteger BigInteger::operator/(const BigInteger& num)const{
    return div(num);
}
BigInteger BigInteger::operator/(const long long int& num)const{
    return div(BigInteger(num));
}
BigInteger BigInteger::operator/(const string& num)const{
    return div(BigInteger(num));
}


BigInteger BigInteger::operator%(const BigInteger & num)const{
    return mod(num);
}
BigInteger BigInteger::operator%(const long long int& num)const{
    return mod(BigInteger(num));
}
BigInteger BigInteger::operator%(const string& num)const{
    return mod(BigInteger(num));
}


BigInteger BigInteger::operator+(const BigInteger &b2) const{
    return add(b2);
}
BigInteger BigInteger::operator+(const long long int& b2) const{
    return add(BigInteger(b2));
}
BigInteger BigInteger::operator+(const string& b2) const{
    return add(BigInteger(b2));
}


BigInteger BigInteger::operator-(const BigInteger &b2) const {
    return sub(BigInteger(b2));
}
BigInteger BigInteger::operator-(const long long int& b2) const {
    return sub(BigInteger(b2));
}
BigInteger BigInteger::operator-(const string& b2) const {
    return sub(BigInteger(b2));
}


BigInteger& BigInteger::operator/=(const BigInteger &num) {
    *this = div(num);
    return *this;
}

BigInteger& BigInteger::operator/=(const long long int& num) {
    *this = div(num);
    return *this;
}

BigInteger& BigInteger::operator/=(const string& num) {
    *this = div(num);
    return *this;
}

BigInteger& BigInteger::operator%=(const BigInteger &num) {
    *this = mod(num);
    return *this;
}

BigInteger& BigInteger::operator%=(const long long int& num) {
    *this = mod(num);
    return *this;
}

BigInteger& BigInteger::operator%=(const string& num) {
    *this = mod(num);
    return *this;
}









