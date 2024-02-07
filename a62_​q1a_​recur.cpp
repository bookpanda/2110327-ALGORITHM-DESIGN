#include<bits/stdc++.h>
using namespace std;

void gen_mtx(vector<vector<int> > &v, int a, int b, int top, int bottom, int left, int right) {
    // cout << "a " << a << ", b " << b << ", top " << top << ", bottom " << bottom << ", left " << left << ", right " << right << "\n";
    if(top > bottom || left > right) return;
    if(a == 0) {
        v[top][left] = b;
        // cout << "v[" << top << "][" << left << "] = " << b << "\n";
        return;
    }

    int midr = (top + bottom) / 2;
    int midc = (left + right) / 2;
    gen_mtx(v, a-1, b,   top,       midr,   left,   midc);
    gen_mtx(v, a-1, b-1, top,       midr,   midc+1, right);
    gen_mtx(v, a-1, b+1, midr+1,    bottom, left,   midc);
    gen_mtx(v, a-1, b,   midr+1,    bottom, midc+1, right);
    return;
}

int main() {
    int a, b;

    cin >> a >> b;

    vector<vector<int> > v;
    v.resize(1 << a);
    for(int i=0;i<v.size();i++) v[i].resize(1 << a);
    gen_mtx(v, a, b, 0, (1 << a)-1, 0, (1 << a)-1);

    for(int i=0;i<v.size();i++) {
        for(int j=0;j<v[0].size();j++) {
            // cout << "i " << i << ", j " << j << ", v=" << v[i][j] << "\n";
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}