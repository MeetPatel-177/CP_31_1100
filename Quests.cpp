#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define pb push_back
#define all(x) (x).begin(), (x).end()

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
        int n, k;
        cin >> n >> k;
        vector<int>a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        vector<int>b(n);
        for(int i=0; i<n; i++) cin >> b[i];
        vector<int>pf_maxi_b(n);
        pf_maxi_b[0] = b[0];
        for(int i=1; i<n; i++) {
            pf_maxi_b[i] = max(pf_maxi_b[i-1], b[i]);
        }
        int pf_sum = 0;
        int maxi = 0, curr = 0;
        int i = 0;
        while(i <= min(k-1, n-1)) {
            int rem = k - i - 1;
            pf_sum += a[i];
            curr = pf_sum + rem*pf_maxi_b[i];
            maxi = max(maxi, curr);
            i++;
        }
        cout << maxi << "\n";
    }
    return 0;
}