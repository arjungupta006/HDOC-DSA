#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> q;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    stack<int> s;

    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
        if (!s.empty()) cout << " ";
    }

    return 0;
}
