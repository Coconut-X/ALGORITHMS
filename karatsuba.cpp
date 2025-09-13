#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

using ll = long long;

int multiplySingleBit(const string &a, const string &b){
    return (a[0] - '0') * (b[0] - '0');
}

string addBitStrings(const string &X, const string &Y){
    string product = "";
    int carry = 0;

    for (int i = X.size()-1, j = Y.size()-1; i >= 0 || j >= 0 || carry; i--, j--){
        int sum = carry;
        if(i >= 0) sum += X[i] - '0';
        if(j >= 0) sum += Y[j] - '0';
        product += (sum % 2) + '0';
        carry = sum / 2;
    }
    reverse(product.begin(), product.end());
    return product;
}

int makeEqual(string &X, string &Y){
    int xs = X.size(), ys = Y.size();
    if(xs < ys) X = string(ys - xs, '0') + X;
    else if(ys < xs) Y = string(xs - ys, '0') + Y;

    if(X.size() % 2) X = '0' + X;
    if(Y.size() % 2) Y = '0' + Y;

    return max(X.size(), Y.size());
}

__int128_t multiply(string X, string Y){

    if(X.size() == 1 && Y.size() == 1)
        return multiplySingleBit(X,Y);

    int n = makeEqual(X,Y);
    int half = n/2;

    string XL = X.substr(0,half), XR = X.substr(half);
    string YL = Y.substr(0,half), YR = Y.substr(half);

    __int128_t XLYL = multiply(XL,YL);
    __int128_t XRYR = multiply(XR,YR);

    string XL_PLUS_XR = addBitStrings(XL, XR);
    string YL_PLUS_YR = addBitStrings(YL, YR);

    __int128_t Z = multiply(XL_PLUS_XR, YL_PLUS_YR);

    return (XLYL << (2*half)) + ((Z - XLYL - XRYR) << half) + XRYR;
}

string toBinary(__int128_t n){
    if(n == 0) return "0";
    string res = "";
    while(n){
        res += (n%2) + '0';
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}


ostream& operator<<(ostream& os, __int128 value) {
    if (value == 0) {
        os << "0";
        return os;
    }

    if (value < 0) {
        os << "-";
        value = -value;
    }

    string s;
    while (value > 0) {
        int digit = value % 10;
        s.push_back('0' + digit);
        value /= 10;
    }
    reverse(s.begin(), s.end());
    os << s;
    return os;
}



int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    // __int128_t a = 1234567899999, b = 1000000000000;
    __int128_t a = 10, b = -5;
    // ll a = 1234567899999, b = 1000000000000;
    string a_bin = toBinary(a);
    string b_bin = toBinary(b);

    __int128_t result = multiply(a_bin, b_bin);
    cout << "Product: " << result << endl;
}
