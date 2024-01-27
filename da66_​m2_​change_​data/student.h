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
    std::stack<std::vector<std::queue<int>>> s;
    while(!a.empty()) {
        for(int i=0;i<a.top().size();i++) {
            std::queue<int> q = a.top()[i];
            std::queue<int> q2;
            while(!q.empty()) {
                if(q.front()==from) {
                    q2.push(to);
                } else {
                    q2.push(q.front());
                }
                q.pop();
            }
            a.top()[i] = q2;
        }
        s.push(a.top());
        a.pop();
    }
    while(!s.empty()) {
        a.push(s.top());
        s.pop();
    }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    // your code here
    for(auto &x: a) {
        if(x.second.second == from)
        x.second.second = to;
        std::priority_queue<int> pq;
        while(!x.second.first.empty()) {
            if(x.second.first.top() == from)
                pq.push(to);
            else
                pq.push(x.second.first.top());
            x.second.first.pop();
        }
        x.second.first = pq;
    }
}

void change_3(std::set<std::pair<  std::list<int>, std::map<int, std::pair<int, string> >  > > &a, int from, int to)
{
    // your code here
    std::set<std::pair<  std::list<int>, std::map<int, std::pair<int, string> >  > >  ans; 
    for(auto &x: a) {
        std::list<int> l;
        for(auto &y: x.first) {
           if(y == from) l.push_back(to);
           else l.push_back(y);
        }

        std::map<int, std::pair<int, string> > m;
        for(auto &y: x.second) {
            int key = y.first;
            if(key == from) key = to;
            std::pair<int, string> val = y.second;
            if(val.first == from) val.first = to;
            m[key] = val;
        }

        ans.insert({l, m});


    }
    a = ans;
}

#endif
