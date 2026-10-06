#include <deque>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    cout << "===== STACK (LIFO) =====\n";
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top: " << st.top() << endl;
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    cout << "\n===== QUEUE (FIFO) =====\n";
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Front: " << q.front() << ", Back: " << q.back() << endl;
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    cout << "\n===== DEQUE (DOUBLE ENDED) =====\n" << endl;
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.push_front(1);
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;

    dq.pop_front();
    dq.pop_back();
    cout << "Sau pop_front() va pop_back(): ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}