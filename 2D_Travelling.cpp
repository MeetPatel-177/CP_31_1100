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
        int n,k,a,b;
        cin >> n >> k >> a >> b;
        vector<pair<ll,ll>> coor(n);
        for(int i=0; i<n; i++) cin >> coor[i].first >> coor[i].second;
        auto& start = coor[a-1];
        auto& end = coor[b-1];
        ll min_cost = LONG_LONG_MAX;
        //both inside
        if(a <= k && b <= k) {
            min_cost = 0;
        }
        //start inside and end outside
        else if(a <= k) {
            ll curr_cost = 0;
            for(int i=0; i<k; i++) {
                auto& curr_coor = coor[i];
                //we reached to curr from start in 0 then we will reach to end in 0
                curr_cost = abs(curr_coor.first - end.first) + abs(curr_coor.second - end.second);
                min_cost = min(min_cost, curr_cost);
            }
        }
        //start outside and end inside
        else if(b <= k) {
            ll curr_cost = 0;
            for(int i=0; i<k; i++) {
                auto& curr_coor = coor[i];
                //we reached to curr from start in curr_cost then we will reach to end in 0
                curr_cost = abs(curr_coor.first - start.first) + abs(curr_coor.second - start.second);
                min_cost = min(min_cost, curr_cost);
            }
        }
        //start outside and end outside
        else {
            //first possibility is directly go from start to end
            ll poss1 = abs(start.first - end.first) + abs(start.second - end.second);
            ll curr_cost_from_start = 0, curr_cost_from_end = 0;
            ll mini_cost_from_start = LONG_LONG_MAX;
            ll mini_cost_from_end = LONG_LONG_MAX;
            for(int i=0; i<k; i++) {
                auto& curr_coor = coor[i];
                curr_cost_from_start = abs(curr_coor.first - start.first) + abs(curr_coor.second - start.second);
                curr_cost_from_end = abs(curr_coor.first - end.first) + abs(curr_coor.second - end.second);
                mini_cost_from_start = min(mini_cost_from_start, curr_cost_from_start);
                mini_cost_from_end = min(mini_cost_from_end, curr_cost_from_end);
            }
            ll poss2 = LONG_LONG_MAX;
            //it k == 0 then we have to go directly so it will be possible only by poss1
            //now other thing is go from start to one point and then that point to any other
            //point in 0 rupees then from that point to end point in given cost.
            if(k != 0) poss2 = mini_cost_from_start + mini_cost_from_end;
            min_cost = min(poss1, poss2);
        }
        cout << min_cost << "\n";
    }
    return 0;
}