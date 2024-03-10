#include<bits/stdc++.h>
using namespace std;
int n;

int getSum(int st, int ed, vector<int> &qs) {
    if(st-1 < 0) return qs[ed];
    return qs[ed] - qs[st-1];
}

int mcs(int st, int ed, vector<int> &v, vector<int> &qs) {
    if(st > ed) return -INT_MAX;
    if(st == ed) return v[st];

    int mid = (st + ed) / 2;
    int maxhalf = max(mcs(st, mid, v, qs), mcs(mid+1, ed, v, qs));

    int left = v[mid];
    for(int i=mid-1;i>=st;i--) {
        left = max(left, getSum(i, mid, qs));
    }
    int right = v[mid+1];
    for(int i=mid+2;i<=ed;i++) {
        right = max(right, getSum(mid+1, i, qs));
    }

    return max(maxhalf, left+right);
}


int main() {
    cin >> n;
    vector<vector<int> > v(n, vector<int>(n));
    vector<vector<int> > t(n, vector<int>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> v[i][j];
        }
    }

    for(int i=0;i<n;i++) {
        int r = 0;
        int c = i;
        vector<int> tmp;
        while(r<n && c<n) {
            tmp.push_back(v[r++][c++]);
        }
        t.push_back(tmp);
    }
    for(int i=1;i<n;i++) {
        int r = i;
        int c = 0;
        vector<int> tmp;
        while(r<n && c<n) {
            tmp.push_back(v[r++][c++]);
        }
        t.push_back(tmp);
    }

    int ans = -INT_MAX;
    for(int i=0;i<t.size();i++) {
        vector<int> tmp = t[i];
        vector<int> qs(tmp.size());
        qs[0] = tmp[0];
        for(int i=1;i<tmp.size();i++) qs[i] = qs[i-1] + tmp[i];
        int sum = mcs(0, tmp.size()-1, tmp, qs);
        ans = max(ans, sum);
    }
    cout << ans << "\n";
}