#include <bits/stdc++.h>
using namespace std;

void printList(list<int> &lst) {
    cout << "L -> ";
    for (const int& val : lst) {
        cout << val << " ";
    }
    cout << endl;
    cout << "R -> ";
    for (auto it = lst.rbegin(); it != lst.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    int Q;
    cin >> Q;

    list<int> l; 

    for (int i = 0; i < Q; ++i) {
        int X, V;
        cin >> X >> V;

        if (X == 0) {
            l.push_front(V);
        } else if (X == 1) {
            l.push_back(V);
        } else if (X == 2) {
            if (V >= 0 && V < l.size()) {
                auto it = l.begin();
                for (int j = 0; j < V; j++) {
                   it++; 
                }
                l.erase(it);
            }
        }
        printList(l);
    }

    return 0;
}
