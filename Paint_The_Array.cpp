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
        vector<ll>arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        ll gcd1 = 0, gcd2 = 0;
        for(int i=0; i<n; i++) {
            if(i & 1) {
                gcd2 = __gcd(gcd2, arr[i]);
            }else {
                gcd1 = __gcd(gcd1, arr[i]);
            }
        }
        int flag1 = 1, flag2 = 1;
        for(int i=1; i<n; i+=2) {
            if(arr[i] % gcd1 == 0) {
                flag1 = 0;
                break;
            }
        }
        for(int i=0; i<n; i+=2) {
            if(arr[i] % gcd2 == 0) {
                flag2 = 0;
                break;
            }
        }
        if(flag1) cout << gcd1 << "\n";
        else if(flag2) cout << gcd2 << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}