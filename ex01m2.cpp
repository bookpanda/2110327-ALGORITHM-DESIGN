#include<bits/stdc++.h>
using namespace std;
int n, inv=0;
vector<int> v; 

void merge_sort(int st, int ed) {
    if(st >= ed) return;

    int mid = (st + ed) / 2;
    merge_sort(st, mid);
    merge_sort(mid+1, ed);

    vector<int> tmp;
    int lid = st, rid = mid+1;

    while(lid<=mid && rid<=ed && lid < rid) {
        if(v[lid] <= v[rid])
            tmp.push_back(v[lid++]);
        else {
            tmp.push_back(v[rid++]);
            inv += mid-lid+1;
        }
    }
    while(lid<=mid) tmp.push_back(v[lid++]);
    while(rid<=ed) tmp.push_back(v[rid++]);

    for(int i=st;i<=ed;i++) {
        v[i] = tmp[i-st];
    }
    return;
}

int main() {
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }

    merge_sort(0, n-1);
    // for(auto x: v) {
    //     cout << x << " ";
    // } cout << "\n";
    cout << inv << "\n";
}