#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;

vector<int> cook(int st, int ed) {
    int length = ed-st+1;
    if(length == 1) {
        return {v[st]};
    } else if(length == 2) {
        return {v[st]+v[ed], v[st]-v[ed]};
    }

    int mid = (st+ed) / 2;
    vector<int> left = cook(st, mid);
    vector<int> right = cook(mid+1, ed);
    vector<int> ans;
    for(int i=0;i<length/2;i++) {
        ans.push_back(left[i]+right[i]);
    }
    for(int i=0;i<length/2;i++) {
        ans.push_back(left[i]-right[i]);
    }
    return ans;
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    vector<int> ans = cook(0, n-1);
    for(auto x: ans) {
        cout << x << " ";
    }
}