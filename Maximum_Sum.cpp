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
        int n, k;
        cin >> n >> k;
        vector<ll>arr(n+1);
        for(int i=1; i<=n; i++) cin >> arr[i];
        sort(whole(arr));
        vector<ll>pf_sum(n+1);
        for(int i=1; i<=n; i++) {
            pf_sum[i] = pf_sum[i-1] + arr[i];
        }
        int count = 0;
        //we are doing for all partitions which we can make we can take 0 min and all max to all min and 0 max
        //0 - k  pfsum[n-k+count]
        //1- k-1   pfsum[n-k+count] - pfsum[2*count]
        ll max_sum = 0;
        while(count <= k) {
            ll curr_sum = pf_sum[n - k + count] - pf_sum[2*count];
            max_sum = max(max_sum, curr_sum);
            count++;
        }
        cout << max_sum << "\n";
    }
    return 0;
}