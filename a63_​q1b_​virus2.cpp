#include<bits/stdc++.h>
using namespace std;

int countOnes(string &str, int st, int ed) {
    int cou=0;
    for(int i=st;i<=ed;i++) if(str[i] == '1') cou++;
    return cou;
}

bool check(string &str, int st, int ed) {
    // cout << "check " << st << " to " << ed << "\n";
    if(st >= ed || ed-st==1) return true;
    int mid = (st+ed)/2;
    bool left = check(str, st, mid);
    bool right = check(str, mid+1, ed);
    int lone = countOnes(str, st, mid);
    int rone = countOnes(str, mid+1, ed);
    return abs(lone-rone)<2 && left && right;    
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
        bool res = check(str, 0, length-1);
        string ans = res ? "yes\n" : "no\n";
        cout << ans;
    }
}