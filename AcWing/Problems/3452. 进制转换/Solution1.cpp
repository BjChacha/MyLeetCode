#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> charToNum = {
    {'0', 0},
    {'1', 1},
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    {'a', 10},
    {'b', 11},
    {'c', 12},
    {'d', 13},
    {'e', 14},
    {'f', 15}
};

int main() {
    string s;
    while (cin >> s) {
        int res = 0, sign = 1, i = 2;;
        if (s[0] == '-') {
            sign = -1;
            i ++;
        }
        while (i < s.length()) 
            res = res * 16 + charToNum[tolower(s[i++])];
        cout << res * sign << endl;;
    }
}
