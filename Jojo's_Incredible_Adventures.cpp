#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define whole(x) (x).begin(), (x).end()

const int M = 1e9 + 7;

void setupIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

//here as we have to see for cyclic cases also so we can do s += s and then our s will be cyclic, we can do that also.
int main() {
    setupIO();
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        int max_continuous_1s = 0;
        int i = 0;
        while(i < n) {
            int curr_continuous_1s = 0;
            while(i < n && s[i] == '1') {
                curr_continuous_1s++;
                i++;
            }
            max_continuous_1s = max(max_continuous_1s, curr_continuous_1s);
            i++;
        }
        int front_1s = 0, back_1s = 0;
        i = 0;
        while(i < n && s[i] == '1') {
            front_1s++;
            i++;
        }
        if(i == n) back_1s = 0;
        else {
            i = n-1;
            while(i >= 0 && s[i] == '1') {
                back_1s++;
                i--;
            }
        }
        max_continuous_1s = max(max_continuous_1s, front_1s+back_1s);
        int m = max_continuous_1s;
        //if all 1's then n*n
        // 7 - 4*4   n is odd -> (n+1)/2*(n+1)/2
        // 8 - 4*5   n is even -> n/2*(n/2+1)
        if(m == n) {
            ll ans = 1LL*m*m;
            cout << ans << "\n";
            continue;
        }
        if(m & 1) {
            ll ans = 1LL*(m+1)/2*(m+1)/2;
            cout << ans << "\n";
        }else {
            ll ans = 1LL*m/2*(m/2+1);
            cout << ans << "\n";
        }
    }
    return 0;
}