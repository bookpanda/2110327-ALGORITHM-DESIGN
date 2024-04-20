#include<bits/stdc++.h>
using namespace std;
int n, k, ans=INT_MAX;
const int MAXBOOKS = 1005;
using BookBits = bitset<MAXBOOKS>;
struct Vendor {
    int p, m;
    BookBits books;

    bool operator<(const Vendor &other) const { //who comes first
        return p > other.p;
    }

    void print() {
        cout << "vendor p: " << p << ", " << m << " books: "; 
        for(int i=1;i<=1000;i++) {
            if(books[i]) cout << i << " ";
        }
        cout << "\n";
    }
};
vector<Vendor> vendor;
vector<BookBits> tail;

void cook(int vid, int price, BookBits books) {
    if((books | tail[vid]).count() < n) return;
    // cout << vid << ", p " << price << ", book cou=" << books.count() << "\n";
    if(books.count() == n) {
        ans = min(ans, price);
        return;
    }
    if(vid == k) return;

    BookBits newBooks = books | vendor[vid].books;
    int newPrice = price+vendor[vid].p; 
    if(newPrice < ans) cook(vid+1, newPrice, newBooks);

    cook(vid+1, price, books);
}

int main() {
    cin >> n >> k;
    vendor.resize(k);
    tail.resize(k);
    for(int i=0;i<k;i++) {
        cin >> vendor[i].p >> vendor[i].m;
        for(int j=0;j<vendor[i].m;j++) {
            int b;
            cin >> b;
            vendor[i].books[b] = 1;
        }
    }
    sort(vendor.begin(), vendor.end());
    // for(int i=0;i<k;i++) vendor[i].print();
    tail[k-1] = vendor[k-1].books;
    for(int i=k-2;i>=0;i--) {
        tail[i] = tail[i+1] | vendor[i].books;
    }
    cook(0, 0, 0);
    cout << ans << "\n";
}