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
		//what we are doing is just storing the biggest index in which the arr[i] present why because we need to find maximum value of (i+j) so we are storing highest index and we have constraints as arr[i] 1000 so we can expect a O(n^2) approach so we are doing the same after storing the largest index we are iterating through whole array and find the maximum pair it will take O(arr[i]^2 * log(arr[i]))
		vector<int>ind(1001,-1);
		for(int i=0; i<n; i++) {
			ind[arr[i]] = i;
		}
		int maxi = -1;
		int curr = 0;
		for(int i=0; i<1001; i++) {
			if(ind[i] != -1) {
				for(int j=i; j<1001; j++) {
					if(ind[j] != -1) {
						if(__gcd(i,j) == 1) {
							curr = ind[i]+ind[j]+2;
							maxi = max(curr, maxi);
						}
					}
				}
			}
		}
		cout << maxi << "\n";
	}
	return 0;
}