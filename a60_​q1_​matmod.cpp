#include<bits/stdc++.h>
using namespace std;

vector<int> matrix_multiply(const vector<int> &M,const vector<int> &N,int k) {
    vector<int> v;
    v.push_back((M[0]*N[0] + M[1]*N[2]) % k);
    v.push_back((M[0]*N[1] + M[1]*N[3]) % k);
    v.push_back((M[2]*N[0] + M[3]*N[2]) % k);
    v.push_back((M[2]*N[1] + M[3]*N[3]) % k);
    return v;
}

vector<int> modex(vector<int> &x, int n, int k) {
    if(n == 1) return x;
    vector<int> res = modex(x, n/2, k);
    vector<int> ans = matrix_multiply(res, res, k);
    if(n % 2 == 0) {
        return ans;
    } else {
        return matrix_multiply(ans, x, k);
    }
}

int main() {
    int n,k;
    vector<int> v;

    cin >> n >> k;
    for(int i=0;i<4;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    vector<int> ans = modex(v, n, k);
    cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << "\n";
}