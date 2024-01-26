#include<bits/stdc++.h>
using namespace std;

int bs(vector<int> &v, int ub) {
    int high = v.size()-1;
    int low = 0;
    int mid = (high+low)/2;
    int ans = -1;
    while(low<=high) {
        if(v[mid] > ub) {
            high = mid-1;
        } else {
            ans = max(ans, mid);
            low = mid+1;
        }
        mid = (high+low)/2;
    }
    return ans;
}

int main() {
    int n,m;
    vector<int> v;

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    for(int i=0;i<m;i++) {
        int a;
        cin >> a;
        cout << bs(v, a) << "\n";
    }
}