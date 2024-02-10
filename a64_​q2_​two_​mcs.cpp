#include<bits/stdc++.h>
using namespace std;

int findSum(int st, int ed, vector<int> &qs) {
    if(st-1 < 0) return qs[ed];
    return qs[ed] - qs[st-1];
}

pair<int, pair<int,int> > mcs(int st, int ed, vector<int> &v, vector<int> &qs) {
    if(st > ed) return {-INT_MAX, {st, ed}};
    if(st == ed) return {v[st], {st, ed}};

    int mid = (st+ed) / 2;
    pair<int, pair<int,int> > lefthalf = mcs(st, mid, v, qs);
    pair<int, pair<int,int> > righthalf = mcs(mid+1, ed, v, qs);
    pair<int, pair<int,int> > maxhalf = max(lefthalf, righthalf);

    int left = v[mid];
    int stidx=mid;
    for(int i=st;i<mid;i++) {
        int sum = findSum(i, mid, qs);
        if(sum > left) {
            left = sum;
            stidx = i;
        }
    }
    int right = v[mid+1];
    int edidx=mid+1;
    for(int i=mid+2;i<=ed;i++) {
        int sum = findSum(mid+1, i, qs);
        if(sum > right) {
            right = sum;
            edidx = i;
        }
    }
    // cout << "leftsum=" << left << ", id=" << stidx << ", rightsum=" << right << ", id=" << edidx << "\n";
    pair<int, pair<int,int> > middle = {left+right, {stidx, edidx}};
    pair<int, pair<int,int> > ans = max(maxhalf, middle);
    // cout << st << ", " << ed << ", st=" << ans.second.first << ", ed=" << ans.second.second << ", sum=" << ans.first << "\n";

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<int> v, qs;
    cin >> n;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    qs.push_back(v[0]);
    for(int i=1;i<n;i++) qs.push_back(qs[i-1] + v[i]);

    pair<int, pair<int,int> > sum1 = mcs(0, n-1, v, qs);
    // cout << "sum1=" << sum1.first << ", from " << sum1.second.first << " to " << sum1.second.second << "\n";
    pair<int, pair<int,int> > leftsum = mcs(0, sum1.second.first-1, v, qs);
    pair<int, pair<int,int> > rightsum = mcs(sum1.second.second+1, n-1, v, qs);
    int maxhalf = max(leftsum.first, rightsum.first);

    if(maxhalf < 0) {
        cout << sum1.first << "\n";
    } else cout << sum1.first + maxhalf << "\n";
}