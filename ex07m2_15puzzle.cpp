#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> > ord={{3,3},{0,0},{0,1},{0,2},{0,3},{1,0},{1,1},{1,2},{1,3},{2,0},{2,1},{2,2},{2,3},{3,0},{3,1},{3,2}};
vector<int> reverseMoves = {1, 0, 3, 2};
struct State {
    int r, c;
    vector<vector<int> > board;
    vector<int> moves;

    State(int r, int c, vector<vector<int> > board, vector<int> moves) : r(r), c(c), board(board), moves(moves) {}
    State(const State &other) : r(other.r), c(other.c), board(other.board), moves(other.moves) {}
    void print() {
        cout << "------------\n";
        for(int i=0;i<4;i++) {
            for(int j=0;j<4;j++) {
                if(board[i][j] < 10) cout << " ";
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << moves.size() << " moves: ";
        for(int i=0;i<moves.size();i++) cout << moves[i] << " ";
        cout << "\n";
    }

    bool operator<(const State &other) const {
        return moves.size() < other.moves.size();
    }
};

bool checkMove(State &s, int dir) { //0 up, 1 down, 2 left, 3 right
    if(dir == 0) {
        if(s.r == 0) return false;
        swap(s.board[s.r][s.c], s.board[s.r-1][s.c]);
        s.r--;
    } else if(dir == 1) {
        if(s.r == 3) return false;
        swap(s.board[s.r][s.c], s.board[s.r+1][s.c]);
        s.r++;
    } else if(dir == 2) {
        if(s.c == 0) return false;
        swap(s.board[s.r][s.c], s.board[s.r][s.c-1]);
        s.c--;
    } else if(dir == 3) {
        if(s.c == 3) return false;
        swap(s.board[s.r][s.c], s.board[s.r][s.c+1]);
        s.c++;
    }
    s.moves.push_back(dir);

    return true;
}

int calHrt(State &s) {
    int sum = 0;
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            pair<int, int> corr = ord[s.board[i][j]];
            int difr = abs(i - corr.first);
            int difc = abs(j - corr.second);
            sum += difr+difc;
        }
    }

    return sum + s.moves.size();
}

int main() {
    State initState(0, 0, {}, {});
    initState.board.resize(4);
    for(int i=0;i<4;i++) {
        initState.board[i].resize(4);
        for(int j=0;j<4;j++) {
            cin >> initState.board[i][j];
            if(initState.board[i][j] == 0) {
                initState.r = i;
                initState.c = j;
            }
        }
    }

    priority_queue<pair<int, State> > pq;
    set<vector<vector<int> > > used;
    int ans = INT_MAX;
    pq.push({-calHrt(initState), initState});
    used.insert(initState.board);
    while(!pq.empty()) {
        int hrt = -pq.top().first;
        State s = pq.top().second;
        pq.pop();
        int lastMove = s.moves.size() == 0 ? -1 : s.moves.back();
        // s.print();
        // cout << "hrt = " << hrt << "\n";

        if(hrt == s.moves.size()) {
            ans = min(ans, hrt);
            break;
        }

        for(int i=0;i<4;i++) {
            if(lastMove != -1 && i == reverseMoves[lastMove]) continue;
            State ns(s);
            if(!checkMove(ns, i)) continue;
            if(used.find(ns.board) != used.end()) continue;
            int nhrt = calHrt(ns);
            pq.push({-nhrt, ns});
            used.insert(ns.board);
        }
    }

    cout << ans << "\n";
}