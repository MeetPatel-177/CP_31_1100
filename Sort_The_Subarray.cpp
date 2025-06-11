#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define whole(x) (x).begin(), (x).end()

const int M = 1e9 + 7;

void setupIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

//this code is for if we sort 1 or more subarrays annd then want to find the longest subarray for this question this much things is not needed because we are just sorting one subarray but still this is more general version of the given problem.
int main() {
    setupIO();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int>a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        int max_len = 0;
        int more_poss = 0;
        int l = 0, r = 0;
        int i = 0, j = 0;
        while(i < n) {
            if(a[i] == b[i]) {
                if(i+1 < n && b[i] <= b[i+1]) {
                    more_poss++;
                }else {
                    more_poss = 0;
                }
            }else {
                j = i;
                while(i+1 < n && (b[i] <= b[i+1])) {
                    i++;
                }
                j -= more_poss;
                more_poss = 0;
                int curr_len = i-j+1;
                if(curr_len > max_len) {
                    max_len = curr_len;
                    l = j+1;
                    r = i+1;
                }
            }
            i++;
        }
        cout << l << " " << r << "\n";
    }
    return 0;
}