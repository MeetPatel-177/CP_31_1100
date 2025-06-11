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
        int n;
        cin >> n;
        vector<ll>arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        for(int i=0; i<n; i++) {
            arr[i] = arr[i]*M + i;
        }
        //val = arr[i]/M
        //ind = arr[i]%M
        sort(whole(arr));
        vector<ll>pf_sum(n,0);
        pf_sum[0] = arr[0]/M;
        for(int i=1; i<n; i++) {
            ll val = arr[i]/M;
            pf_sum[i] = pf_sum[i-1] + val;
        }
        vector<int>ans(n);
        int i = 0;
        while(i < n) {
            int j = i;
            while(i+1 < n && pf_sum[i] >= (arr[i+1]/M)) {
                i++;
            }
            for(int k=j; k<=i; k++) {
                int ind = arr[k]%M;
                ans[ind] = i;
            }
            i++;
        }
        for(int i=0; i<n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}