#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define whole(x) (x).begin(), (x).end()

const int M = 1e9 + 7;

void setupIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}
//log(n)*n
ll ans(vector<ll>& arr,int n, ll i, ll j, ll c) {
    if(i <= j) {
        ll mid = (i+j)/2;
        ll w = mid;
        ll curr = 0;
        for(int k=0; k<n; k++) {
            curr += ((2*w + arr[k])*(2*w + arr[k]));
            if(curr > c) break;
        }
        if(curr == c) return w;
        else if(curr > c) return ans(arr,n,i,mid-1,c);
        else return ans(arr,n,mid+1,j,c);
    }
}
int main() {
    setupIO();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ll c;
        cin >> c;
        vector<ll>arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        ll i = 0, j = INT_MAX;
        ll w = ans(arr,n, i, j, c);
        cout << w << "\n";
    }
    return 0;
}