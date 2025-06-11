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
        int n, l, r;
        cin >> n >> l >> r;
        int flag = 1;
        vector<int>ans;
        //what are we doing here is that we have r now in order to get the number divisible by i we are substracting extra thing which is present in it i.e. r%i that is (r - r%i) now if it is greater than l then it is fine because it is in range but when it gets out of range it can'e be the part of array so flag = 0 now for all i we are pushing the number which we made divisible by i and at the end we will print it.
        for(int i=1; i<=n; i++) {
            if((r - r%i) < l) {
                flag = 0;
                break;
            }
            ans.push_back(r-r%i);
        }
        if(!flag) cout << "NO\n";
        else {
            cout << "YES\n";
            for(int i=0; i<n; i++) {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}