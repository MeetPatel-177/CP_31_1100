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
        int gcd = 0;
        //we have to make arr[i]%x == arr[n-i-1]%x so when we take difference of both that diff will represent how much is the one number bigger than the second so we can mod both with that number so both will be equal and it will be palindrome now we can take any divisor of that diff all answer will be same so at the end we will take gcd for all the diffs
        for(int i=0; i<n/2; i++) {
            gcd = __gcd(gcd, abs(arr[i] - arr[n-i-1]));
        }
        cout << gcd << "\n";
    }
    return 0;
}