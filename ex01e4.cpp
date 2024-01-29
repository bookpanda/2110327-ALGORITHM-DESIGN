#include<bits/stdc++.h>
using namespace std;

int main() {
    int x, n, k;
    long long ans = 1;

    cin >> x >> n >> k;
    int m = n;
    stack<pair<int,long long> > s;
    while(m > 0) {
        if(s.empty())
            s.push({1, x%k});
        else
            s.push({s.top().first*2, (s.top().second*s.top().second)%k});
        m/=2;
    }
    // for(int i=0;i<n;i++) {
    //     ans *= x;
    //     ans %= k;
    // }
    while(!s.empty()) {
        int pow = s.top().first;
        long long val = s.top().second;
        s.pop();
        // cout << "pow = " << pow << " , val = " << val << "\n";
        if(n < pow) continue;
        
        n -= pow;
        ans *= val;
        ans %= k;
    }
    cout << ans << "\n";
}