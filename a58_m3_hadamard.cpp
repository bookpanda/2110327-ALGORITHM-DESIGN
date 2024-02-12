#include<bits/stdc++.h>
using namespace std;

vector<int> cook(int c1, int c2, vector<int> &v) {
    if(c1 == c2) return {v[c1]};
    if(c2 - c1 == 1) return {v[c1] + v[c2], v[c1] - v[c2]};

    int midc = (c1 + c2) / 2;
    vector<int> top =       cook(c1,     midc, v);
    vector<int> bottom =    cook(midc+1, c2, v);

    vector<int> ans;
    for(int i=0;i<top.size();i++) {
        ans.push_back(top[i] + bottom[i]);
    }
    for(int i=0;i<bottom.size();i++) {
        ans.push_back(top[i] - bottom[i]);
    }

    return ans;
}

int main() {
    //instead of matrix, we remember which r, c has how many 1/-1
    int n;
    vector<int> v;
    cin >> n;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    vector<int > hnm = cook(0, n-1, v);
    // cout << hnm.size() << "\n";
    for(int i=0;i<n;i++) {
        cout << hnm[i] << " ";
    }
}