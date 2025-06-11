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
        vector<int>arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        //which two elements can we swap ? now see we have to choose a X that is present in the array so then we will choose two supermasks of X i.e., pi&X = X and pj&X = X, so then choose pi and X and swap them then choose pi and pj swap them then choose pj and X swap them now observe whatever swap we done & of pairs is always X so it can be done after this operation we get pi and pj on the right place and X is a supermask of answer now the final answer will be any submask of X.
        //whenever we find any element which is not at the correct position we have to make a swap to place it on it's correct place, so the answer must be a submask of the first swap that we do so the answer will be and of all the numbers which are not at their correct places initially.
        int ans = INT_MAX;
        for(int i=0; i<n; i++) {
            if(i != arr[i]) {
                ans = ans&arr[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}