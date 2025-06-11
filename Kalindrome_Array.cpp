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
        int ele1 = 0, ele2 = 0;
        int i = 0, j = n-1;
        while(i <= j) {
            if(arr[i] == arr[j]) {
                ++i;
                --j;
            }else {
                ele1 = arr[i];
                ele2 = arr[j];
                break;
            }
        }
        int flag = 1;
        int dupi = i, dupj = j;
        i = dupi, j = dupj - 1;
        while(i <= j) {
            if(arr[i] == arr[j]) {
                ++i;
                --j;
            }else if(arr[i] == ele2) {
                ++i;
            }else if(arr[j] == ele2) {
                --j;
            }else {
                flag = 0;
                break;
            }
        }
        if(flag) {
            cout << "YES\n";
            continue;
        }
        flag = 1;
        i = dupi + 1, j = dupj;
        while(i <= j) {
            if(arr[i] == arr[j]) {
                ++i;
                --j;
            }else if(arr[i] == ele1) {
                ++i;
            }else if(arr[j] == ele1) {
                --j;
            }else {
                flag = 0;
                break;
            }
        }
        if(flag) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}