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
        int n;
        cin >> n;
        vector<int>arr(n+10);
        for(int i=1; i<=n; i++) cin >> arr[i];
        vector<int>pf(n+10), sf(n+10);
        for(int i=1; i<=n; i++) {
            pf[i] = pf[i-1] + arr[i];
        }
        for(int i=n; i>=1; i--) {
            sf[i] = sf[i+1] + arr[i];
        }
        int i = 1, j = n;
        int maxi = 0;
        while(i < j) {
            if(pf[i] == sf[j]) {
                int curr = i + (n-j+1);
                maxi = max(maxi, curr);
                ++i;
                --j;
            }else if(pf[i] > sf[j]) {
                --j;
            }else {
                ++i;
            }
        }
        cout << maxi << "\n";
    }
    return 0;
}