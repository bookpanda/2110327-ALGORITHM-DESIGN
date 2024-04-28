#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > fb = {{3,3},{0,0},{0,1},{0,2},{0,3},{1,0},{1,1},{1,2},{1,3},{2,0},{2,1},{2,2},{2,3},{3,0},{3,1},{3,2}};
int reverseMove[] = {1, 0, 3, 2};
struct Board {
    vector<vector<int> > table;
    int r, c, move, hrt;

    bool operator<(const Board &other) const {
        return hrt > other.hrt;
    }
    Board(const Board &other ) : table(other.table), r(other.r), c(other.c), move(other.move), hrt(other.hrt)  {}
    Board(vector<vector<int> > table, int r, int c, int move, int hrt) : table(table), r(r), c(c), move(move), hrt(hrt)  {}
    void print() {
        cout << "board r = " << r << ", c = " << c << ", move = " << move << ", hrt = " << hrt << "\n";
        for(int i=0;i<4;i++) {
            for(int j=0;j<4;j++) {
                if(table[i][j] < 10) cout << " ";
                cout << table[i][j] << " ";
            } cout << "\n";
        }
        cout << "\n";
    }
};

int calHrt(Board board) {
    int sum = 0;
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            pair<int,int> corr = fb[board.table[i][j]];
            int difr = abs(i - corr.first);
            int difc = abs(j - corr.second);
            sum += difr + difc;
        }
    }

    return sum + board.move;
}

bool checkMove(Board &b, int dir) {
    if(dir == 0) {
        if(b.r == 0) return false;
        swap(b.table[b.r][b.c], b.table[b.r-1][b.c]);
        b.r--;
    } else if(dir == 1) {
        if(b.r == 3) return false;
        swap(b.table[b.r][b.c], b.table[b.r+1][b.c]);
        b.r++;
    } else if(dir == 2) {
        if(b.c == 0) return false;
        swap(b.table[b.r][b.c], b.table[b.r][b.c-1]);
        b.c--;
    } else if(dir == 3) {
        if(b.c == 3) return false;
        swap(b.table[b.r][b.c], b.table[b.r][b.c+1]);
        b.c++;
    }
    b.move++;

    return true;
}

int main() {
    Board init({}, 0, 0, 0, 0);
    init.table.resize(4);
    for(int i=0;i<4;i++) {
        init.table[i].resize(4);
        for(int j=0;j<4;j++) {
            cin >> init.table[i][j];
            if(init.table[i][j] == 0) {
                init.r = i;
                init.c = j;
            }
        }
    }
    init.move = 0;
    init.hrt = calHrt(init);

    set<vector<vector<int> > > used;
    priority_queue<pair<Board, int> > pq;
    pq.push({init, -1});
    used.insert(init.table);
    while(!pq.empty()) {
        Board b = pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        // b.print();
        if(b.hrt - b.move == 0) {
            cout << b.move << "\n";
            break;
        }

        int revMove = prev == -1 ? -1 : reverseMove[prev];
        for(int i=0;i<4;i++) { //0 up, 1 down, 2 left, 3 right
            if(i == revMove) continue;
            Board nb = b;
            // if(b.move > 2) continue;
            if(!checkMove(nb, i)) continue;
            if(used.find(nb.table) != used.end()) continue;
            nb.hrt = calHrt(nb);
            pq.push({nb, i});
            used.insert(nb.table);
        }        
    }
}