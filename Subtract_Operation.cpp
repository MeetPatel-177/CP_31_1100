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
        int n, k;
        cin >> n >> k;
        vector<int>arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        //ultimately what is happening here is that after applying all the operations we will ended up having difference of any two number as the last element so we have to find whether there exist any two numbers whose difference is equal to k if it is then we can make it as k otherwise not.
        sort(whole(arr));
        bool flag = 0;
        if(n == 1) {
            if(arr[0] == k) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        int i = 0, j = 1;
        while(i < n && j < n) {
            if(k == (arr[j] - arr[i])) {
                flag = 1;
                break;
            }else if(k < (arr[j] - arr[i])) {
                ++i;
            }else {
                ++j;
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}