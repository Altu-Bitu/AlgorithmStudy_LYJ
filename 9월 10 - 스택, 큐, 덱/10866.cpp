//
// Created by 이유정 on 2021/09/15.
//

#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;


int main() {


    int N, num;
    string str;
    cin >> N;

    while (N--) {
        cin >> str;

        if (str == "push_front") {
            cin >> num;
            dq.push_front(num);
        } else if (str == "push_back") {
            cin >> num;
            dq.push_back(num);
        } else if (str == "pop_front") {
            if (dq.empty()) cout << -1 << "\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        } else if (str == "pop_back") {
            if (dq.empty()) cout << -1 << "\n";
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        } else if (str == "size")
            cout << dq.size() << "\n";
        else if (str == "empty") {
            if (dq.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        } else if (str == "front") {
            if (dq.empty()) cout << -1 << "\n";
            else
                cout << dq.front() << "\n";
        } else if (str == "back") {
            if (dq.empty()) cout << -1 << "\n";
            else {
                cout << dq.back() << "\n";
            }
        }
    }

}