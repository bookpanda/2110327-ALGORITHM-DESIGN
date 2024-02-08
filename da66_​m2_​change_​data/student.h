#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    // your code here
    std::stack<std::vector<std::queue<int>>> b;
    while(!a.empty()) {
        std::vector<std::queue<int>> v, tmp;
        v = a.top();
        for(int i=0;i<v.size();i++) {
            std::queue<int> q = v[i];
            std::queue<int> q2;
            while(!q.empty()) {
                if(q.front() == from) q2.push(to);
                else q2.push(q.front());
                q.pop();
            }
            tmp.push_back(q2);
        }
        b.push(tmp);
        a.pop();
    }
    while(!b.empty()) {
        a.push(b.top());
        b.pop();
    }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    // your code here
    for(auto &x: a) {
        if(x.second.second == from) x.second.second = to;
        std::priority_queue<int> pq, tmp;
        pq = x.second.first;
        while(!pq.empty()) {
            if(pq.top() == from) tmp.push(to);
            else tmp.push(pq.top());
            pq.pop();
        }
        x.second.first = tmp;
    }
}

void change_3(std::set<std::pair<  std::list<int>, std::map<int, std::pair<int, string> >  > > &a, int from, int to)
{
    // your code here
    std::set<std::pair<  std::list<int>, std::map<int, std::pair<int, string> >  > > b;
    for(auto &x: a) {
        std::list<int> l = x.first;
        for(auto &y: l) {
            if(y == from) y = to;
        }
        std::map<int, std::pair<int, string> > mp = x.second;
        for(auto &y: mp) {
            // if(y.first == from) y.first = to;
            if(y.second.first == from) y.second.first = to;
        }
        b.insert({l, mp});
    }
    a = b;
}

#endif
