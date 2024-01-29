#include<bits/stdc++.h>
using namespace std;
map<pair<string,int>, bool> visited;

bool check(string dna, int lvl) {
    if(visited.find({dna, lvl}) != visited.end()) return visited[{dna, lvl}];
    if(lvl == 1) {
        return dna == "01";
    }
    int mid = dna.size() / 2;
    string a = "", b = "";
    for(int i=0;i<mid;i++) {
        a += dna[i];
    }
    for(int i=mid;i<dna.size();i++) {
        b += dna[i];
    }
    bool res1 = (check(a, lvl-1) && check(b, lvl-1));
    reverse(a.begin(), a.end());
    bool res2 = (check(a, lvl-1) && check(b, lvl-1));
    visited[{dna, lvl}] = res1 || res2;
    return res1 || res2;
}

int main() {
    int n, k;

    cin >> n >> k;

    int length = (1<<k);
    while(n--) {
        string str = "";
        for(int i=0;i<length;i++) {
            int a;
            cin >> a;
            str += to_string(a);
        }
        // cout << "string = " << str << "\n";
        string ans = check(str, k) ? "yes" : "no";
        cout << ans << "\n";
    }

}