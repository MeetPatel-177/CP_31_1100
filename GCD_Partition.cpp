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
        //gcd is decreasing thing so it will possible to maximize it only when k = 2
        for(int i=1; i<n; i++) arr[i] += arr[i-1];
        ll max_score = 0;
        for(int i=1; i<n; i++) {
            ll b1 = arr[i-1];
            ll b2 = arr[n-1] - arr[i-1];
            ll curr_score = __gcd(b1, b2);
            max_score = max(max_score, curr_score);
        }
        cout << max_score << "\n";
    }
    return 0;
}