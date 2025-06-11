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
        //the only catch here was that we can make all elements only equal to the last element of the array because whatever subarray we choose we can never change the value of the last element of the array.
        //every time we will pick the biggest subarray in which we contain the same element.
        int same_as_last = 1;
        int i = n-2;
        while(i >= 0 && (arr[i] == arr[i+1])) {
            ++same_as_last;
            --i;
        }
        int ope = 0;
        while(i >= 0) {
            if(arr[i] == arr[n-1]) {
                ++same_as_last;
                --i;
            }else {
                ++ope;
                i -= same_as_last;
                same_as_last <<= 1;
            }
        }
        cout << ope << "\n";
    }
    return 0;
}