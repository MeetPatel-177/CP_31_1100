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
        int neg = 0;
        ll sum = 0;
        for(int i=0; i<n; i++) {
            if(arr[i] < 0) {
                neg++;
                arr[i] = -arr[i];
            }
            sum += arr[i];
        }
        ll ans = 0;
        if(neg & 1) {
            int mini = *min_element(whole(arr));
            ans = sum - 2*mini;
        }else {
            ans = sum;
        }
        cout << ans << "\n";
    }
    return 0;
}