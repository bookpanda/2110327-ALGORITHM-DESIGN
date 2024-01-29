#include<bits/stdc++.h>
using namespace std;

int countOnes(string dna) {
    int cou = 0;
    for(auto x: dna)
        if(x == '1') cou++;
    return cou;
}

bool check(string dna, int lvl) {
    if(lvl == 0) return true;
    int mid = dna.size() / 2;
    string a="", b="";
    for(int i=0;i<mid;i++) {
        a += dna[i];
    }
    for(int i=mid;i<dna.size();i++) {
        b += dna[i];
    }
    int ca = countOnes(a);
    int cb = countOnes(b);
    // cout << "a = " << a << " , b = " << b << "\n"; 
    if(abs(ca - cb) > 1) return false;
    return check(a, lvl-1) && check(b, lvl-1);
}

int main() {
    int n, k;

    cin >> n >> k;
    int length = 1<<k;
    while(n--) {
        string str = "";
        for(int i=0;i<length;i++) {
            int a;
            cin >> a;
            str += to_string(a);
        }
        string ans = check(str, k) ? "yes" : "no";
        cout << ans << "\n";
    }
}