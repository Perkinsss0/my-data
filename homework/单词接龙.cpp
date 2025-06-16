#include <iostream>
#include <vector>
using namespace std;

vector<string> words;
vector<vector<int>> overlap;
vector<int> used;
char start_char;
int n, max_length = 0;

// 计算两个单词可能的最小重叠长度
int calculate_overlap(const string &a, const string &b) {
    int min_len = min(a.size(), b.size());
    for (int k = 1; k < min_len; k++) { // 从最小重叠长度1开始尝试
        bool match = true;
        for (int i = 0; i < k; i++) {
            if (a[a.size() - k + i] != b[i]) {
                match = false;
                break;
            }
        }
        if (match) return k; // 找到匹配返回重叠长度
    }
    return 0; // 找不到重叠或重合部分等于整个单词
}

// 深度优先搜索函数
void dfs(int last_word, int current_length) {
    if (current_length > max_length) 
        max_length = current_length; // 更新最大长度

    for (int i = 0; i < n; i++) {
        if (used[i] >= 2) continue; // 每个单词最多用两次
        
        int ol = overlap[last_word][i];
        if (ol == 0) continue; // 不能拼接

        // 尝试添加新单词
        used[i]++;
        dfs(i, current_length + words[i].size() - ol); // 加上新单词的长度减去重叠部分
        used[i]--; // 回溯
    }
}

int main() {
    cin >> n;
    words.resize(n);
    used.assign(n, 0);
    overlap.resize(n, vector<int>(n)); // 初始化重叠矩阵
    
    // 读取单词
    for (int i = 0; i < n; i++)
        cin >> words[i];
    cin >> start_char;
    
    // 预处理计算所有单词对的重叠长度
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            overlap[i][j] = calculate_overlap(words[i], words[j]);
    
    // 以所有匹配起始字符的单词作为龙的头
    for (int i = 0; i < n; i++) {
        if (words[i][0] == start_char) {
            used[i]++; // 记录使用
            dfs(i, words[i].size()); // 开始搜索
            used[i]--;
        }
    }
    
    cout << max_length << endl;
    return 0;
}
