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
        int n, x;
        cin >> n >> x;
        int s = 0;
        vector<int>a(n);
        for(int i=0; i<3; i++) {
            for(int j=0; j<n; j++) cin >> a[j];
            for(int j=0; j<n; j++) {
                if((x | a[j]) != x) break;
                s |= a[j];
            }
            a.clear();
        }
        if(s == x) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}