#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// 将十进制数转换为P进制字符串
string toBaseStr(int num, int base) {
    if (num == 0) return "0";
    
    string res = "";
    while (num > 0) {
        int r = num % base;
        num /= base;
        
        if (r < 10) 
            res += ('0' + r); // 数字0-9
        else 
            res += ('A' + (r - 10)); // 大于9用字母
    }
    reverse(res.begin(), res.end()); // 反转字符串
    return res;
}

int main() {
    int P;
    cin >> P; // 读入进制数

    for (int i = 1; i < P; i++) { // 注意循环条件是 i < P
        for (int j = 1; j <= i; j++) {
            if (j > 1) cout << " "; // 控制空格输出
            
            // 输出乘数: 转换为P进制字符
            char ci = (i < 10) ? ('0' + i) : ('A' + i - 10);
            char cj = (j < 10) ? ('0' + j) : ('A' + j - 10);
            
            // 输出乘法表达式
            cout << ci << '*' << cj << '=' << toBaseStr(i*j, P);
        }
        cout << endl; // 每行结束
    }

    return 0;
}