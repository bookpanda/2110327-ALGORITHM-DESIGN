#include<bits/stdc++.h>
using namespace std;

int n, k;
int cou = 1;
void cook(vector<int> &v, int st, int ed) {
    if(ed - st == 1) return;
    if(cou > k) return;
    if(cou == k) {
        for(auto x: v) cout << x << " ";
        exit(0);
    }

    int mid = (st + ed) / 2;
    for (int i=0;i<mid-st;i++) {
        swap(v[st+i], v[mid+i]);
    }

    cou += 2;
    if(cou > k) return;
    if(cou == k) {
        for(auto x: v) cout << x << " ";
        exit(0);
    }

    cook(v, st, mid);
    cook(v, mid, ed);
}

int main() {
    cin >> n >> k;
    vector<int> v;
    for(int i=1;i<=n;i++) {
        v.push_back(i);
    }
    cook(v, 0, n);
    if(cou != k) {
        cout << "-1\n";
        return 0;
    }
    for(auto x: v) {
        cout << x << " ";
    }
}