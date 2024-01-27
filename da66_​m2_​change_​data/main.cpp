#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>

#include "student.h"

using namespace std;

// Add your code in student.h
void change_1(stack<vector<queue<int>>> &a, int from, int to);
void change_2(map<string, pair<priority_queue<int>, int>> &a, int from, int to);
void change_3(set<pair<list<int>, map<int, pair<int, string>>>> &a, int from, int to);

// Code already provided below
stack<vector<queue<int>>> input_1();
map<string, pair<priority_queue<int>, int>> input_2();
set<pair<list<int>, map<int, pair<int, string>>>> input_3();
void print_1(stack<vector<queue<int>>> a);
void print_2(map<string, pair<priority_queue<int>, int>> a);
void print_3(set<pair<list<int>, map<int, pair<int, string>>>> a);

int main()
{
    int x, from, to;
    cin >> x >> from >> to;

    if (x == 1)
    {
        stack<vector<queue<int>>> a;
        a = input_1();
        change_1(a, from, to);
        print_1(a);
    }
    else if (x == 2)
    {
        map<string, pair<priority_queue<int>, int>> a;
        a = input_2();
        change_2(a, from, to);
        print_2(a);
    }
    else if (x == 3)
    {
        set<pair<list<int>, map<int, pair<int, string>>>> a;
        a = input_3();
        change_3(a, from, to);
        print_3(a);
    }
}

stack<vector<queue<int>>> input_1()
{
    stack<vector<queue<int>>> a;
    int sSize, vSize, qSize, ip;
    cin >> sSize;
    for (int i = 0; i < sSize; i++)
    {
        cin >> vSize;
        vector<queue<int>> v(vSize);
        for (int j = 0; j < vSize; j++)
        {
            queue<int> q;
            cin >> qSize;
            for (int k = 0; k < qSize; k++)
            {
                cin >> ip;
                q.push(ip);
            }
            v[j] = q;
        }
        a.push(v);
    }
    return a;
}
map<string, pair<priority_queue<int>, int>> input_2()
{
    map<string, pair<priority_queue<int>, int>> a;
    int mSize, pqSize, ip, ipPair;
    string ipKey;
    cin >> mSize;
    for (int i = 0; i < mSize; i++)
    {
        cin >> ipKey;
        priority_queue<int> pq;
        cin >> pqSize;
        for (int j = 0; j < pqSize; j++)
        {
            cin >> ip;
            pq.push(ip);
        }
        cin >> ipPair;
        a[ipKey] = {pq, ipPair};
    }
    return a;
}
set<pair<list<int>, map<int, pair<int, string>>>> input_3()
{
    set<pair<list<int>, map<int, pair<int, string>>>> a;
    int sSize, mSize, lSize, ip, ipKey;
    string ipPair;
    cin >> sSize;
    for (int i = 0; i < sSize; i++)
    {
        cin >> lSize;
        list<int> l;
        for (int j = 0; j < lSize; j++)
        {
            cin >> ip;
            l.push_back(ip);
        }
        cin >> mSize;
        map<int, pair<int, string>> m;
        for (int j = 0; j < mSize; j++)
        {
            cin >> ipKey >> ip >> ipPair;
            m[ipKey] = {ip, ipPair};
        }
        a.insert({l, m});
    }
    return a;
}

void print_1(stack<vector<queue<int>>> a)
{
    while (!a.empty())
    {
        vector<queue<int>> v = a.top();
        a.pop();
        for (auto &q : v)
        {
            while (!q.empty())
            {
                int i = q.front();
                q.pop();
                cout << i << ",";
            }
            cout << " ";
        }
        cout << "\n";
    }
}
void print_2(map<string, pair<priority_queue<int>, int>> a)
{
    auto it = a.begin();
    while (it != a.end())
    {
        cout << it->first << ":";
        while (!it->second.first.empty())
        {
            cout << it->second.first.top() << " ";
            it->second.first.pop();
        }
        cout << "," << it->second.second << "\n";
        it++;
    }
}
void print_3(set<pair<list<int>, map<int, pair<int, string>>>> a)
{
    auto it = a.begin();
    while (it != a.end())
    {
        for (auto &i : it->first)
        {
            cout << i << " ";
        }
        cout << " | ";
        auto it2 = it->second.begin();
        while (it2 != it->second.end())
        {
            cout << it2->first << ":" << it2->second.first << "," << it2->second.second << " ";
            it2++;
        }
        cout << "\n";
        it++;
    }
}