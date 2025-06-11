#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define pb push_back
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
        int n,q;
        cin >> n >> q;
        vector<ll>a(n+1), x(q+1);
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=q; i++) cin >> x[i];
        vector<ll>addable(31,0);
        for(int i=1; i<=30; i++) {
            ll val = 0;
            int prev = i;
            for(int j=1; j<=q; j++) {
                if(x[j] <= prev) {
                    val += (1 << (x[j]-1));
                    prev = x[j]-1;
                }
            }
            addable[i] = val;
        }
        for(int i=1; i<=n; i++) {
            for(int j=30; j>=1; j--) {
                if((a[i] % (1 << j)) == 0) {
                    a[i] += addable[j];
                    break;
                }
            }
        }
        for(int i=1; i<=n; i++) cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}