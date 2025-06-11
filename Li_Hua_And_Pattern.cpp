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
        int n,k;
        cin >> n >> k;
        vector<vector<int>>arr(n, vector<int>(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> arr[i][j];
            }
        }
        //180 rotation means a[i][j] = a[n-i-1][n-j-1]
        //90 clockwise rotation a[i][j] = (a[n-i-1][j])T = a[j][n-i-1]
        //90 anticlockwise or 270 clockwise rotation a[i][j] = (a[i][n-j-1])T = a[n-j-1][i]
        int changes_we_have = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(arr[i][j] != arr[n-i-1][n-j-1]) {
                    changes_we_have++;
                }
            }
        }
        changes_we_have >>= 1;
        int rem = k - changes_we_have;
        //when we have odd n then we will always have a middle element which can be changed any number of times because it dosen't depend on anyone when we don't have odd n then we have to take care of even and odd rems
        if((n & 1) && (rem >= 0)) {
            cout << "YES\n";
        }else {
            if(rem >= 0 && (rem & 1) == 0) {
                cout << "YES\n";
            }else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}