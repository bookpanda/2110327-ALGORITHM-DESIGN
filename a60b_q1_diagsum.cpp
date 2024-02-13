#include<bits/stdc++.h>
using namespace std;

int getSum(int st, int ed, vector<int> &qs) {
    if(st-1 < 0) return qs[ed];
    return qs[ed] - qs[st-1];
}

int mcs(int st, int ed, vector<int> &v, vector<int> &qs) {
    if(st > ed) return -INT_MAX;
    if(st == ed) return v[st];

    int mid = (st+ed) / 2;
    int lefthalf = mcs(st, mid, v, qs);
    int righthalf = mcs(mid+1, ed, v, qs);
    int maxhalf = max(lefthalf, righthalf);

    int left = v[mid];
    for(int i=st;i<=mid;i++) {
        left = max(left, getSum(i, mid, qs));
    }
    int right = v[mid+1];
    for(int i=mid+1;i<=ed;i++) {
        right = max(right, getSum(mid+1, i, qs));
    }

    return max(maxhalf, left+right);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > v;
    for(int i=0;i<n;i++) {
        vector<int> tmp;
        for(int j=0;j<n;j++) {
            int a;
            cin >> a;
            tmp.push_back(a);
        }
        v.push_back(tmp);
    }

    vector<pair<int, int> > start;
    for(int i=n-1;i>=0;i--) {
        start.push_back({i, 0});
    }
    for(int i=1;i<n;i++) {
        start.push_back({0, i});
    }

    int maxdiag = -INT_MAX;
    for(auto x: start) {
        int r = x.first;
        int c = x.second;
        // cout << "r=" << r << ", c=" << c << "\n";
        vector<int> in, qs;
        while(r<n && c<n) {
            in.push_back(v[r][c]);
            r++;
            c++;
        }
        qs.push_back(in[0]);
        for(int i=1;i<in.size();i++) qs.push_back(qs[i-1] + in[i]);
        int ans = mcs(0, in.size()-1, in, qs);
        maxdiag = max(maxdiag, ans);
    }
    cout << maxdiag << "\n";
}