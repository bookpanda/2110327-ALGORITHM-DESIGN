#include<bits/stdc++.h>
using namespace std;

bool cook(string a, string b) {
    if(a == b) return true;
    if(a.size()==1 && a!=b) return false;
    int mida = a.size() / 2;
    int midb = b.size() / 2;
    string a1 = a.substr(0, mida);
    string a2 = a.substr(mida, a.size());
    string b1 = b.substr(0, midb);
    string b2 = b.substr(midb, b.size());
    // cout << "a = " << a << ",  b = " << b << "\n";
    // cout << a1 << ", " << a2 << "\n";
    // cout << b1 << ", " << b2 << "\n";
    return (cook(a1, b1) && cook(a2, b2)) || (cook(a1, b2) && cook(a2, b1));
}

int main() {
    string a,b;

    cin >> a >> b;
    bool res = cook(a, b);
    string ans = res ? "YES\n" : "NO\n";
    cout << ans;
}