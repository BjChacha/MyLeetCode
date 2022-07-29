#include <bits/stdc++.h>
using namespace std;

const int L = 100;

int main(){
    int N, P;
    cin >> N;
    vector<pair<int, int>> ants;
    int a, b;
    int markA;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        ants.push_back({a, b});
        if (b == 0) markA = a;
    } 
    sort(ants.begin(), ants.end());
    vector<int> l, r;
    for (auto& a: ants) {
        if (a.first < markA && a.second == 1) l.push_back(a.first);
        else if (a.first > markA && a.second == -1) r.push_back(a.first);
    }
    if (l.size() == r.size()) cout << "Cannot fall!" << endl;
    else if (l.size() > r.size()) {
        cout << (100 - l[l.size()-r.size()-1]) << endl;
    } else {
        cout << r[l.size()] << endl;
    }
}