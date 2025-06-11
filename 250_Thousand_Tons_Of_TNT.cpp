#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define pb push_baci
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
        vector<ll>arr(n+10);
        for(int i=1; i<=n; i++) cin >> arr[i];
        vector<ll>pf_sum(n+10);
        for(int i=1; i<=n; i++) {
            pf_sum[i] = pf_sum[i-1] + arr[i];
        }
        vector<int>poss_k;
        for(int i=1; i*i<=n; i++) {
            if(n % i == 0) {
                poss_k.push_back(i);
                poss_k.push_back(n/i);
            }
        }
        int sz = poss_k.size();
        ll curr_diff = 0;
        ll maxi_diff = 0;
        //logn
        for(int i=0; i<sz; i++) {
            int k = poss_k[i];
            ll curr_mini = LONG_LONG_MAX;
            ll curr_maxi = 0;
            //n/k
            for(int j=1; j<=n; j+=k) {
                ll curr_sum = pf_sum[j+k-1] - pf_sum[j-1];
                curr_maxi = max(curr_maxi, curr_sum);
                curr_mini = min(curr_mini, curr_sum);
            }
            curr_diff = curr_maxi - curr_mini;
            maxi_diff = max(maxi_diff, curr_diff);
        }
        cout << maxi_diff << "\n";
    }
    return 0;
}