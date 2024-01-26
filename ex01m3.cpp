#include<bits/stdc++.h>
using namespace std;
int n,m;

long long bsa(vector<int> &v, long long cap) {
    cap -= n;
    if(cap < 1) return 0;
    long long high = LLONG_MAX;
    long long low = 0;
    long long mid = (high+low)/2;
    long long ans = LLONG_MAX;
    while(low<=high) {
        // cout << "mid = " << mid << "\n";
        long long sum=0;
        for(int i=0;i<n;i++) {
            sum += mid / v[i];
        }
        // cout << "     sum = " << sum << "\n";
        if(sum >= cap || sum < 0) {
            if(sum >=0)
            ans = min(ans, mid);
            high = mid-1;
        } else if(sum < cap) {
            low = mid+1;
        }
        mid = (high+low)/2;
    }
    return ans;
}

int main() {
    vector<int> v;

    cin >> n >> m;

    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for(int i=0;i<m;i++) {
        long long a;
        cin >> a;
        cout << bsa(v, a) << "\n";
    }  
}