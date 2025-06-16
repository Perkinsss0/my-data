#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 高精度加法：将数组b加到数组a上
void add(vector<int>& a, const vector<int>& b) {
    int carry = 0;
    int len = max(a.size(), b.size());
    
    for (int i = 0; i < len || carry; i++) {
        if (i == a.size()) 
            a.push_back(0);
            
        int add = carry + a[i] + (i < b.size() ? b[i] : 0);
        a[i] = add % 10;
        carry = add / 10;
    }
}

// 高精度乘低精度：数组a乘以整数b
void multiply(vector<int>& a, int b) {
    int carry = 0;
    
    for (int i = 0; i < a.size() || carry; i++) {
        if (i == a.size()) 
            a.push_back(0);
            
        long long product = a[i] * 1LL * b + carry;
        a[i] = product % 10;
        carry = product / 10;
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> fact = {1}; // 保存当前阶乘值（逆序存储）
    vector<int> sum = {0}; // 保存阶乘之和（逆序存储）
    
    for (int i = 1; i <= n; i++) {
        multiply(fact, i);    // 计算i的阶乘
        add(sum, fact);      // 将阶乘值加入总和
    }
    
    // 反向输出结果
    for (int i = sum.size() - 1; i >= 0; i--) {
        cout << sum[i];
    }
    
    return 0;
}