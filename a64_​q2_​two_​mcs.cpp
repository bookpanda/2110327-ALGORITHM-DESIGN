#include<bits/stdc++.h>
using namespace std;

pair<int,pair<int,int> > max_sum(vector<int> &v, vector<int> &qs, int st, int ed) {
    if(st<0 || ed>=v.size() || st>ed) return {-INT_MAX, {st, ed}};
    if(st==ed) return {v[st], {st,st}};

    int mid = (st+ed)/2;
    pair<int,pair<int,int> > lefthalf = max_sum(v, qs, st, mid);
    pair<int,pair<int,int> > righthalf = max_sum(v, qs, mid+1, ed);
    pair<int,pair<int,int> > maxhalf = max(lefthalf, righthalf);

    int leftmid = v[mid];
    int leftid=mid;
    for(int i=st;i<=mid;i++) {
        int sum = qs[mid] - qs[i-1];
        if(sum > leftmid) {
            leftmid = sum;
            leftid = i;
        }
    }
    int rightmid = v[mid+1];
    int rightid=mid+1;
    for(int i=mid+1;i<=ed;i++) {
        int sum = qs[i] - qs[mid];
        if(sum > rightmid) {
            rightmid = sum;
            rightid = i;
        }
    }
    pair<int,pair<int,int> > maxmid = {leftmid+rightmid, {leftid, rightid}};

    return max(maxhalf, maxmid);
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
    for(int i=1;i<n;i++) {
        qs.push_back(qs[i-1] + v[i]);
    }

    pair<int,pair<int,int> > firstmax = max_sum(v, qs, 0, n-1);
    // cout << "fm " << firstmax.first << "  left " << firstmax.second.first << "  right " << firstmax.second.second << "\n"; 
    
    pair<int,pair<int,int> > leftmax = max_sum(v, qs, 0, firstmax.second.first-1);
    pair<int,pair<int,int> > rightmax = max_sum(v, qs, firstmax.second.second+1, n-1);
    int aroundmax = max(leftmax.first, rightmax.first);

    if(aroundmax > 0) firstmax.first += aroundmax;

    cout << firstmax.first << "\n";
}