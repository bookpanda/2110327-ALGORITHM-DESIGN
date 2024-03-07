#include<bits/stdc++.h>
using namespace std;
int n, k, m; 
vector<int> food, qs;

int getSum(int st, int ed) {
    if(st-1 < 0) return qs[ed];
    return qs[ed] - qs[st-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> m;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        food.push_back(a-m);
    }
    qs.push_back(food[0]);
    for(int i=1;i<n;i++) qs.push_back(qs[i-1] + food[i]);
    for(int i=0;i<k;i++) {
        int p, w;
        cin >> p >> w;
        p--;

        int high = n-1;
        int low = p;
        int mid = (high+low)/2;
        int ans = INT_MAX;
        while(low <= high) {
            int sum = getSum(p, mid);
            if(sum >= w) {
                ans = min(ans, mid);
                high = mid-1;
                mid = (high+low)/2;
            } else {
                low = mid+1;
                mid = (high+low)/2;
            }
        }
        cout << ans+1 << "\n";
    }
}