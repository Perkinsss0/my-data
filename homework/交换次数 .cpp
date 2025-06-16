#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int cntA = 0, cntB = 0, cntT = 0;
    for (char c : s) {
        if (c == 'A') cntA++;
        else if (c == 'B') cntB++;
        else if (c == 'T') cntT++;
    }
    
    vector<vector<char>> permutations = {
        {'B', 'A', 'T'},
        {'B', 'T', 'A'},
        {'A', 'B', 'T'},
        {'A', 'T', 'B'},
        {'T', 'A', 'B'},
        {'T', 'B', 'A'}
    };
    
    int ans = INT_MAX;
    for (auto& perm : permutations) {
        char X = perm[0], Y = perm[1], Z = perm[2];
        int cntX = 0, cntY = 0, cntZ = 0;
        if (X == 'A') cntX = cntA;
        else if (X == 'B') cntX = cntB;
        else if (X == 'T') cntX = cntT;
        if (Y == 'A') cntY = cntA;
        else if (Y == 'B') cntY = cntB;
        else if (Y == 'T') cntY = cntT;
        if (Z == 'A') cntZ = cntA;
        else if (Z == 'B') cntZ = cntB;
        else if (Z == 'T') cntZ = cntT;
        
        int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
        for (int i = 0; i < cntX; i++) {
            if (s[i] == Y) a++;
            else if (s[i] == Z) b++;
        }
        for (int i = cntX; i < cntX + cntY; i++) {
            if (s[i] == X) c++;
            else if (s[i] == Z) d++;
        }
        for (int i = cntX + cntY; i < n; i++) {
            if (s[i] == X) e++;
            else if (s[i] == Y) f++;
        }
        
        int direct_swaps = min(a, c) + min(b, e) + min(d, f);
        int total_mismatches = a + b + c + d + e + f;
        int cost = (2 * total_mismatches - direct_swaps) / 3;
        if (cost < ans) {
            ans = cost;
        }
    }
    cout << ans << endl;
    return 0;
}