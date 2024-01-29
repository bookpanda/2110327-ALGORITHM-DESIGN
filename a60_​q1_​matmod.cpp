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

int main() {
    int n,k;
    vector<int> v;

    cin >> n >> k;
    for(int i=0;i<4;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    stack<pair<int, vector<int> > > s;
    int m = n;
    while(m > 0) {
        if(s.empty()) {
            s.push({1, v});
            continue;
        }
        int mul = s.top().first;
        vector<int> matrix = s.top().second;
        s.push({mul*2, matrix_multiply(matrix, matrix, k)});

        m /= 2;
    }

    vector<int> ans = {1,0,0,1};
    while(!s.empty()) {
        int mul = s.top().first;
        vector<int> matrix = s.top().second;
        s.pop();
        if(n < mul) continue;
        // cout << "mul = " << mul << "\n";
        // cout << "[ " << matrix[0] << " " << matrix[1] << " " << matrix[2] << " " << matrix[3] << " ]\n";
        n -= mul;
        ans = matrix_multiply(ans, matrix, k);
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << "\n";
}