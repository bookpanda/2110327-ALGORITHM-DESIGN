#include<bits/stdc++.h>
using namespace std;
int n, k, ans;

const int MAX_BOOKS = 1000;
using BookBits = bitset<MAX_BOOKS>;

struct Vendor {
    int price;
    BookBits books;
    bool operator<(const Vendor& other) const {
        return price > other.price;
    }
};
vector<Vendor> vendor;
vector<BookBits> bookTail;

void sss(int vid, int price, BookBits currBooks) {
    if((currBooks | bookTail[vid]).count() < n) return;
    if(vid == k) {
        if(currBooks.count() == n) ans = min(ans, price);
        return;
    }

    int newPrice = price + vendor[vid].price;
    if(newPrice < ans) {
        BookBits nextBooks = currBooks | vendor[vid].books;
        sss(vid+1, newPrice, nextBooks);
    }

    sss(vid+1, price, currBooks);
}

int main() {
    cin >> n >> k;
    vendor.resize(k);
    bookTail.resize(k);

    for(int i=0;i<k;i++) {
        int p, m;
        cin >> p >> m;
        vendor[i].price = p;
        for(int j=0;j<m;j++) {
            int b;
            cin >> b;
            vendor[i].books[b-1] = 1; //input 1-based, we want 0-based
        }
    }
    sort(vendor.begin(), vendor.end());

    bookTail[k-1] = vendor[k-1].books;
    for(int i=k-2;i>=0;i--) {
        bookTail[i] = bookTail[i+1] | vendor[i].books;
    }

    ans = INT_MAX;

    sss(0, 0, 0);
    cout << ans << "\n";
}