#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;

void setupIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    setupIO();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        //when we are having the same letter second or more times then we will have the 
        //same strings of (n-i) number of strings so we have to delete it for distinct
        //total will be (1+2+3+...+n = n*(n+1)/2) and same we will calculate by loop
        vector<int> flag(26,0);
        long long total = 1LL*n*(n+1)/2;
        long long same = 0;
        for(int i=0; i<n; i++) {
            if(flag[s[i] - 'a'] == 1) {
                same += 1LL*(n - i);
            }
            flag[s[i] - 'a'] = 1;
        }
        cout << total - same << endl;
    }
    return 0;
}