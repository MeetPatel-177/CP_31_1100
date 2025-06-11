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
        int n;
        cin >> n;
        vector<int>arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        int i = 0;
        int maxi_sum = *max_element(all(arr));
        while(i+1 < n) {
            int curr_sum = arr[i];
            while((i+1 < n) && ((arr[i]+arr[i+1]) & 1) != 0) {
                if(curr_sum < 0) curr_sum = 0;
                curr_sum += arr[i+1];
                maxi_sum = max(maxi_sum, curr_sum);
                i++;
            }
            i++;
        }
        cout << maxi_sum << "\n";
    }
    return 0;
}