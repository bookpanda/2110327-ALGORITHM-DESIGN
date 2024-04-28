#include<bits/stdc++.h>
using namespace std;
double W, ans=0;
struct Item {
    double w, v;

    bool operator<(const Item &other) const {
        return w > other.w;
    }

    void print() {
        cout << "item w = " << w << ", v = " << v << "\n";
    }
};
vector<Item> items;
vector<pair<double, Item> > itemsVal[110];
int n;

double hrt(int idx, double availW) {
    double sum = 0;
    for(int i=0;i<itemsVal[idx].size();i++) {
        double v = itemsVal[idx][i].second.v;
        double w = itemsVal[idx][i].second.w;
        if(availW >= w) {
            sum += v;
            availW -= w;
        } else {
            sum += (v/w) * availW;
            break;
        }
    }

    return sum;
}

void cook(int idx, double availW, double totalVal) {
    if(idx == n) {
        ans = max(ans, totalVal);
        return;
    }
    if(hrt(idx, availW) + totalVal < ans) return;

    double w = items[idx].w;
    double v = items[idx].v;
    if(w <= availW) {
        cook(idx+1, availW-w, totalVal + v);
    }
    cook(idx+1, availW, totalVal);
}

int main() {
    cin >> W >> n;
    items.resize(n);
    for(int i=0;i<n;i++) cin >> items[i].v;
    for(int i=0;i<n;i++) cin >> items[i].w;
    sort(items.begin(), items.end());
    // for(auto x: items) {
    //     x.print();
    // }
    double d = items[n-1].v / items[n-1].w;
    itemsVal[n-1].push_back({d, items[n-1]});
    for(int i=n-2;i>=0;i--) {
        itemsVal[i] = itemsVal[i+1];
        double d = items[i].v / items[i].w;
        itemsVal[i].push_back({d, items[i]});
        sort(itemsVal[i].begin(), itemsVal[i].end());
        reverse(itemsVal[i].begin(), itemsVal[i].end());
        // cout << "start i = " << i << "\n";
        // for(auto x: itemsVal[i]) {
        //     x.second.print();
        // }
    }
    cook(0, W, 0);
    cout << fixed << setprecision(4) << ans << "\n";
}