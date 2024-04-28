#include<bits/stdc++.h>
using namespace std;
int n, k, ans = INT_MAX;
using BookBits = bitset<1010>;
struct Vendor {
    int price, amount;
    BookBits books;

    bool operator<(const Vendor &other) {
        return books.count() > other.books.count();
    }
};
vector<Vendor> vendors;
vector<BookBits> tail;

void cook(int idx, BookBits books, int price) {
    if((books | tail[idx]).count() < n) return;
    if(books.count() == n) {
        ans = min(ans, price);
        return;
    }
    if(idx == k) return;
    // cout << "idx " << idx << ", price" << price << "\n";
    // for(int i=1;i<=n;i++) {
    //     cout << books[i];
    // } cout << "\n\n";

    BookBits newBooks = books | vendors[idx].books;
    int newPrice = price + vendors[idx].price;
    if(newPrice < ans) cook(idx+1, newBooks, newPrice);
    cook(idx+1, books, price);
}

int main() {
    cin >> n >> k;
    vendors.resize(k);
    tail.resize(k);
    for(int i=0;i<k;i++) {
        cin >> vendors[i].price >> vendors[i].amount;
        for(int j=0;j<vendors[i].amount;j++) {
            int b;
            cin >> b;
            vendors[i].books[b] = 1;
        }
    }
    sort(vendors.begin(), vendors.end());
    
    tail[k-1] = vendors[k-1].books;
    for(int i=k-2;i>=0;i--) {
        tail[i] = tail[i+1] | vendors[i].books;
    }

    cook(0, 0, 0);
    cout << ans << "\n";
}