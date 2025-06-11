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
    int n, q;
    cin >> n >> q;
    vector<int>arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int>ind(51);
    for(int i=0; i<n; i++) {
        if(ind[arr[i]] == 0) {
            ind[arr[i]] = (i+1);
        }
    }
    while(q--) {
        int a;
        cin >> a;
        cout << ind[a] << " ";
        for(int i=1; i<=50; i++) {
            if(ind[i] < ind[a]) {
                ind[i]++;
            }
        }
        ind[a] = 1;
    }
    cout << "\n";
    return 0;
}