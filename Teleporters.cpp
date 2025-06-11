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
        int n, c;
        cin >> n >> c;
        vector<int>arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        for(int i=0; i<n; i++) {
            arr[i] = (i+1) + arr[i];
        }
        sort(whole(arr));
        int teleporters = 0;
        for(int i=0; i<n; i++) {
            if(c >= arr[i]) {
                teleporters++;
                c -= arr[i];
            }
        }
        cout << teleporters << "\n";
    }
    return 0;
}