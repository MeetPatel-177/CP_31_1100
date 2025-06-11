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
        //we can add a element equals sum of some elements of the array so we are going by sorting why because when we add a new element it must come from smaller element than itself.
        sort(whole(arr));
        bool flag = 1;
        if(arr[0] != 1) flag = 0;
        else {
        ll sum = 1LL;
        int i = 1;
            while(i < n) {
                if(sum >= arr[i]) {
                    sum += (1LL*arr[i]);
                    i++;
                }else {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag) cout << "YES" << "\n";
        else cout << "NO\n";
    }
    return 0;
}