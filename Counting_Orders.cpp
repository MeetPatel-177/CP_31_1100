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
        vector<int>a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        sort(whole(a), greater<int>());
        sort(whole(b), greater<int>());
        ll ans = 1;
        int i = 0, j = 0;
        while(j < n) {
            while(i < n && (b[j] < a[i])) {
                i++;
            }
            //j is already taken so now remaining will be (i-j) so that much possibility will be there 
            ll poss = (i - j);
            if(poss == 0) {
                ans = 0;
                break;
            }
            ans = (ans * poss)%M;
            j++;
        }
        cout << ans << "\n";
    }
    return 0;
}