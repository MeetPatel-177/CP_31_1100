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
        ll n;
        cin >> n;
        ll ans = 0;
        //ans = 337*n*(4*n*n + 3*n - 1)
        //long long has range of 9.22*10^18 so no worries for the term
        ll term = (4*n*n + 3*n - 1)%M;
        ans = (term*n)%M;
        ans = (ans*337)%M;
        cout << ans << "\n";
    }
    return 0;
}