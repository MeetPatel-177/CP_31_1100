#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define whole(x) (x).begin(), (x).end()

const int M = 1e9 + 7;

void setupIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    setupIO();
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int>ind[26];
        for(int i=0; i<n; i++) {
            ind[s[i] - 'a'].push_back(i);
        }
        int min_gap = INT_MAX;
        int diff_chars =  0;
        for(int i=0; i<26; i++) {
            if(!ind[i].empty()) {
                ++diff_chars;
                for(int j=0; j<ind[i].size()-1; j++) {
                    int curr_gap = (ind[i][j+1] - ind[i][j]);
                    min_gap = min(min_gap, curr_gap);
                }
            }
        }
        int dist_chars = min_gap;
        if(dist_chars < diff_chars) {
            cout << "NO\n";
        }else {
            cout << "YES\n";
        }
    }
    return 0;
}