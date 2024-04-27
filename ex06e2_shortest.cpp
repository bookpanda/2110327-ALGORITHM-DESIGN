#include<bits/stdc++.h>
using namespace std;
int n, m, st;
vector<pair<int, pair<int, int> > > edges;
vector<int> sp;

int main() {
    cin >> n >> m >> st;
    sp.resize(n);
    for(int i=0;i<n;i++) sp[i] = 9999999;
    for(int i=0;i<m;i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({w, {a, b}});
    }

    sp[st] = 0;
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<edges.size();j++) {
            int a = edges[j].second.first;
            int b = edges[j].second.second;
            int w = edges[j].first;
            if(sp[b] > sp[a] + w) {
                sp[b] = sp[a] + w;
            }
        }
    }

    bool negcycle = false;
    for(int j=0;j<edges.size();j++) {
        int a = edges[j].second.first;
        int b = edges[j].second.second;
        int w = edges[j].first;
        if(sp[b] > sp[a] + w) {
            negcycle = true;
            break;
        }
    }

    if(negcycle) cout << "-1\n";
    else for(int i=0;i<n;i++) cout << sp[i] << " ";
}