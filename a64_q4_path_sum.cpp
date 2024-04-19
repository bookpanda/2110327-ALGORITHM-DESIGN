#include<bits/stdc++.h>
using namespace std;
int n, m, visited[25][20005], found[20005];
vector<pair<int, int> > al[25];
vector<int> k;
using NodeBits = bitset<20>;
struct Entry {
    int node;
    int sum;
    NodeBits used;

    Entry(int node, int sum, NodeBits used) : node(node), sum(sum), used(used) {}
};

int main() {
    cin >> n >> m;
    k.resize(8);
    for(int i=0;i<8;i++) {
        cin >> k[i];
    }
    for(int i=0;i<m;i++) {
        int a, b, w;
        cin >> a >> b >> w;
        al[a].push_back({w, b});
        al[b].push_back({w, a});
    }

    queue<Entry> q;
    // queue<pair<int, pair<int, int> > > q;
    for(int i=0;i<n;i++) {
        Entry entry(i, 0, (1 << i));
        q.push(entry);
        // q.push({i, {0, 0}});
    }
    while(!q.empty()) {
        Entry curr = q.front();
        q.pop();

        // cout << "node " << curr.node << ", w=" << curr.sum << "\n";
        for(auto &[w, nn]: al[curr.node]) {
            int nw = w + curr.sum;
            NodeBits nb;
            nb[nn] = 1;
            // cout << "curr bits : " << curr.used << "\n";
            // cout << "nb   bits : " << nb << "\n";
            if(visited[nn][nw] == 0 && (curr.used & nb).count() == 0) {
                visited[nn][nw] = 1;
                found[nw] = 1;
                nb |= curr.used;
                // cout << "go nb    = " << nb << "\n";
                Entry entry(nn, nw, nb);
                q.push(entry);
            }
        }
    }

    for(int i=0;i<8;i++) {
        if(found[k[i]]) cout << "YES\n";
        else cout << "NO\n";
    }
}