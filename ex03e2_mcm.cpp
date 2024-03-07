#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
map<pair<int,int>, int> dp;

int cook(int st, int ed) {
    if(st >= ed) return 0;
    if(dp.find({st, ed}) != dp.end()) return dp[{st, ed}];


    int totalcost = INT_MAX;
    for(int i=st+1;i<=ed;i++) {
        int cost = v[st] * v[i] * v[ed+1];
        totalcost = min(totalcost, cost + cook(st, i-1) + cook(i, ed));
    }
    dp[{st, ed}] = totalcost;
    // cout << "st= " << st << ", ed = " << ed << ", ans = " << totalcost << "\n";

    return totalcost;
}

int main() {
    cin >> n;
    for(int i=0;i<=n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int ans = cook(0, n-1);
    cout << ans << "\n";
}