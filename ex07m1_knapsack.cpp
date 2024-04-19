#include<bits/stdc++.h>
using namespace std;
double W, ans;
int n;

struct Item {
    double w, v;
    bool operator<(const Item &other) const {
        return w > other.w;
    }
} item[105], frac[105][105];

bool compare(const Item &a, const Item &b) {
    return a.v*b.w > b.v*a.w;
}

double hrt(int step, double w) {
    int i = step;
    double sumP = 0;
    while(i < n) {
        if(w >= frac[step][i].w) {
            w -= frac[step][i].w;
            sumP += frac[step][i].v;
        } else {
            sumP += (frac[step][i].v / frac[step][i].w) * w;
            break;
        }
        i++;
    }

    return sumP;
}

void knap(int step, double sumP, double sumW) {
    if(sumW > W) return;
    if(step == n) {
        if(sumP > ans) ans = sumP;
        return;
    }
    if(hrt(step, W - sumW) + sumP < ans) return;

    knap(step+1, sumP + item[step].v, sumW + item[step].w);
    knap(step+1, sumP, sumW);
}

int main() {
    cin >> W >> n;
    for(int i=0;i<n;i++) cin >> item[i].v;
    for(int i=0;i<n;i++) cin >> item[i].w;
    sort(item, item+n);

    for(int i=n-1;i>=0;i--) {
        for(int j=i;j<n;j++) {
            frac[i][j] = item[j];
        }
        sort(frac[i]+i, frac[i]+n, compare);
    }

    knap(0, 0.0, 0.0);
    cout << fixed << setprecision(4) << ans << "\n";
}