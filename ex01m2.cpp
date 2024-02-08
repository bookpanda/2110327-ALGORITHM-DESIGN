#include<bits/stdc++.h>
using namespace std;

int merge_sort(vector<int> &v, int st, int ed) {
    if(st == ed) return 0;
    int mid = (st + ed) / 2;
    int invl = merge_sort(v, st, mid);
    int invr = merge_sort(v, mid+1, ed);

    vector<int> tmp;
    int li=st, ri=mid+1;
    int inv = 0;
    while(li<=mid && ri<=ed) {
        if(v[li] <= v[ri]) {
            tmp.push_back(v[li++]);
        } else { // left > right
            inv += mid - li + 1;
            tmp.push_back(v[ri++]);
        }
    }
    while(li<=mid) tmp.push_back(v[li++]);
    while(ri<=ed) tmp.push_back(v[ri++]);
    for(int i=st;i<=ed;i++) {
        v[i] = tmp[i-st];
    }
    return inv + invl + invr;
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int inv = merge_sort(v, 0, n-1);
    cout << inv << "\n";

    // for(int i=0;i<v.size();i++) {
    //     cout << v[i] << " ";
    // }
}