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
        int n,x;
        cin >> n >> x;
        vector<ll>arr(n+1);
        for(int i=1; i<=n; i++) cin >> arr[i];
        sort(whole(arr));
        vector<ll>pf_sum(n+1);
        for(int i=1; i<=n; i++) {
            pf_sum[i] = pf_sum[i-1] + arr[i];
        }
        ll max_water_inside = 0, max_height_inside = 0;
        ll tot_rem = 0;
        for(int i=n; i>=1; i--) {
            ll h = arr[i];
            ll rem = i-1;
            ll water_needed = h*rem - pf_sum[rem];
            if(water_needed <= x) {
                max_water_inside = water_needed;
                max_height_inside = h;
                tot_rem = i;
                break;
            }
        }
        ll rem_water = x - max_water_inside;
        ll ans = max_height_inside + (rem_water/tot_rem);
        cout << ans << "\n";
    }
    return 0;
}