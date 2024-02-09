#include<bits/stdc++.h>
using namespace std;
int a, b, c, d;

vector<int> mul(vector<int> &a, vector<int> &b, int k) {
    int tl = (a[0]*b[0])%k + (a[1]*b[2])%k;
    int tr = (a[0]*b[1])%k + (a[1]*b[3])%k;
    int bl = (a[2]*b[0])%k + (a[3]*b[2])%k;
    int br = (a[2]*b[1])%k + (a[3]*b[3])%k;
    return {tl%k, tr%k, bl%k, br%k};
}

vector<int> cook(vector<int> &v, int n, int k) {
    if(n == 0) return {1,0,0,1};
    vector<int> res = cook(v, n/2, k);
    res = mul(res, res, k);
    if(n % 2 == 1) {
        vector<int> one = {a, b, c, d};
        res = mul(res, one, k);
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    cin >> a >> b >> c >> d;
    vector<int> v = {a,b,c,d};
    vector<int> ans = cook(v, n, k);
    cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << "\n";
}