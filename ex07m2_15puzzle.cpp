#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > board;
vector<pair<int, int> > corPos = {{3,3},{0,0},{0,1},{0,2},{0,3},{1,0},{1,1},{1,2},{1,3},{2,0},{2,1},{2,2},{2,3},{3,0},{3,1},{3,2}};
vector<int> reverseMove = {1, 0, 3, 2}; //0 up, 1 down, 2, left, 3 right
struct State {
    int r;
    int c;
    vector<int> moves;
    vector<vector<int> > board;

    State(int r, int c, vector<int> moves, vector<vector<int> > board) : r(r), c(c), moves(moves), board(board) {}
    State(const State &other) : r(other.r), c(other.c), moves(other.moves), board(other.board) {}
    bool operator<(const State &other) const {
        return moves.size() < other.moves.size();
    }
    void print() {
        cout << "-------------\n";
        for(int i=0;i<4;i++) {
            for(int j=0;j<4;j++) {
                if(board[i][j] < 10) cout << " ";
                cout << board[i][j] << " ";
            } cout << "\n";
        }
        cout << "moves = " << moves.size() << " : ";
        for(int i=0;i<moves.size();i++) cout << moves[i] << " ";
        cout << "\n";
    }
};

bool canMove(State &s, int dir) {
    if(dir == 0) { //up
        if(s.r == 0) return false;
        swap(s.board[s.r][s.c], s.board[s.r-1][s.c]);
        s.r--;
    } else if(dir == 1) { //down
        if(s.r == 3) return false;
        swap(s.board[s.r][s.c], s.board[s.r+1][s.c]);
        s.r++;
    } else if(dir == 2) { //left
        if(s.c == 0) return false;
        swap(s.board[s.r][s.c], s.board[s.r][s.c-1]);
        s.c--;
    } else if(dir == 3) { //right
        if(s.c == 3) return false;
        swap(s.board[s.r][s.c], s.board[s.r][s.c+1]);
        s.c++;
    }
    s.moves.push_back(dir);
  
    return true;
}

int calHrt(State s) {
    int sum = 0;
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            pair<int, int> goal = corPos[s.board[i][j]];
            int errR = abs(goal.first - i);
            int errC = abs(goal.second - j);
            sum += errR + errC;
        }
    }
    return sum + s.moves.size();
}

int main() {
    pair<int, int> st;
    board.resize(4);
    for(int i=0;i<4;i++) {
        board[i].resize(4);
        for(int j=0;j<4;j++) {
            cin >> board[i][j];
            if(board[i][j] == 0) st = {i, j};
        }
    }

    set<vector<vector<int> > > visited;
    priority_queue<pair<int, State> > pq;
    State initState(st.first, st.second, {}, board);
    pq.push({1, initState});
    visited.insert(initState.board);
    int ans = INT_MAX;
    while(!pq.empty()) {
        int hrt = -pq.top().first;
        State s = pq.top().second;
        int lastMove = s.moves.size() == 0 ? -1 : s.moves.back();
        pq.pop();

        if(hrt == s.moves.size()) {
            ans = min(ans, int(s.moves.size()));
            break;
        }
        // s.print();

        for(int i=0;i<4;i++) {
            if(lastMove != -1 && reverseMove[lastMove] == i) continue;
            State ns(s);
            // cout << "move " << i << "\n";
            if(!canMove(ns, i)) {
                // cout << "cannot move\n";
                continue;
            }
            if(visited.find(ns.board) != visited.end()) continue;
            int hrt = calHrt(ns);
            pq.push({-hrt, ns});
            visited.insert(ns.board);
        }
    }

    cout << ans << "\n";
}