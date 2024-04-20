#include<bits/stdc++.h>
using namespace std;
double W, ans=0;
int n;

struct Item {
    double w, v;

    bool operator<(const Item &other) const {
        return w < other.w;
    }
};
vector<Item> items;
vector<vector<Item> > frac;

bool compare(const Item &a, const Item &b) {
    return a.v*b.w > b.v*a.w;
}

double hrt(int idx, double w) {
    double v = 0;
    for(int i=idx;i<n;i++) {
        if(w >= frac[idx][i].w) {
            w -= frac[idx][i].w;
            v += frac[idx][i].v;
        } else {
            v += (frac[idx][i].v / frac[idx][i].w) * w;
            break;
        }
    }

    return v;
}

void cook(int idx, double sumW, double sumV) {
    if(sumW > W) return;
    if(hrt(idx, W-sumW) + sumV < ans) return; 
    if(idx == n) {
        ans = max(ans, sumV);
        return;
    }

    // cout << "start idx " << idx << ", w=" << sumW << ", v = " << ans << "\n";
    cook(idx+1, sumW, sumV);
    cook(idx+1, sumW+items[idx].w, sumV+items[idx].v);
}

int main() {
    cin >> W >> n;
    items.resize(n);
    frac.resize(n);
    for(int i=0;i<n;i++) cin >> items[i].v;
    for(int i=0;i<n;i++) cin >> items[i].w;

    for(int i=n-1;i>=0;i--) {
        frac[i].resize(n);
        for(int j=i;j<n;j++) {
            frac[i][j].w = items[j].w;
            frac[i][j].v = items[j].v;
        }
        sort(frac[i].begin()+i, frac[i].end(), compare);
    }
    cook(0, 0, 0);

    cout << fixed << setprecision(4) << ans << "\n";
}