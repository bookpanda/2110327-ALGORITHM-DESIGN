#include<bits/stdc++.h>
using namespace std;
int n, k;

long long calGrass(vector<int> &qs, int l, int r) {
    if(l-1 < 0) return qs[r];
    return qs[r] - qs[l-1];
}

long long cook(vector<int> &v, vector<int> &qs, int l, int cap) {
    int high = n-1;
    int low = l;
    int mid = (high+low) / 2;
    long long ans = 0;
    while(low<=high) {
        long long totalcost = (mid-l+1) * k;
        long long totalGrass = calGrass(qs, l, mid);
        totalcost += totalGrass;
        // cout << "high=" << high << ", low=" << low << ", mid=" << mid << ", totalcost=" << totalcost << ", grass=" << totalGrass << "\n";
        if(totalcost <= cap) {
            ans = max(ans, totalGrass);
            low = mid+1;
        } else {
            high = mid-1;
        }
        mid = (high+low) / 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    vector<int> v, qs;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    qs.push_back(v[0]);
    for(int i=1;i<n;i++) qs.push_back(qs[i-1] + v[i]);
    while(m--) {
        int l, budget;
        cin >> l >> budget;
        long long ans = cook(v, qs, l, budget);
        cout << ans << "\n";
    }
}