#include<bits/stdc++.h>
using namespace std;

bool check(string str, int lvl) {
    if(lvl == 1) return str == "01";
    int l = str.size();
    int mid = l/2;
    string a="", b="";
    for(int i=0;i<mid;i++) {
        a += str[i];
    }
    for(int i=mid;i<l;i++) {
        b += str[i];
    }
    // cout << "check string=" << str << "\n";
    // cout << "left " << a << ",   right " << b << "\n";
    bool res1 = check(a, lvl-1) && check(b, lvl-1);
    reverse(a.begin(), a.end());
    bool res2 = check(a, lvl-1) && check(b, lvl-1);
    return res1 || res2;
}

int main() {
    int n, k;
    cin >> n >> k;
    int length = 1 << k;
    for(int i=0;i<n;i++) {
        string str = "";
        for(int j=0;j<length;j++) {
            int a;
            cin >> a;
            str += to_string(a);
        }
        bool res = check(str, k);
        string ans = res ? "yes\n" : "no\n";
        cout << ans;
    }
}