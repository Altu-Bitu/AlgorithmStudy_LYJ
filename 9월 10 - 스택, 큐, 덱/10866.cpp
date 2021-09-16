//
// Created by 이유정 on 2021/09/15.
//

#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

//push front
//void push_front(int num) {
//    dq.push_front(num);
//}

//push back
//void push_back(int num) {
//    dq.push_back(num);
//}

//empty
//int isempty() {
//    if (dq.empty()) return 1;
//    return 0;
//}


// pop front
//void pop_front() {
//    if (isempty() == 1)
//        cout << -1 << "\n";
//    else {
//        cout << dq.front() << "\n";
//        dq.pop_front();
//    }
//}

// pop back
//void pop_back() {
//    if (isempty() == 1)
//        cout << -1 << "\n";
//    else {
//        cout << dq.back() << "\n";
//        dq.pop_back();
//    }
//}

// size
//void dqsize() {
//    cout << dq.size() << "\n";
//}


//front
//void front() {
//    if (isempty() == 1)
//        cout << -1 << "\n";
//    else {
//        cout << dq.front() << "\n";
//    }
//}

//back
//void back() {
//    if (isempty() == 1)
//        cout << -1 << "\n";
//    else {
//        cout << dq.back() << "\n";
//    }
//}



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

//int main() {
//
//
//    int N, num;
//    string str;
//    cin >> N;
//
//    while (N--) {
//        cin >> str;


//        if (str.compare("push_front") == 0) {
//            cin >> num;
//            push_front(num);
//        } else if (str.compare("push_back") == 0) {
//            cin >> num;
//            push_back(num);
//        } else if (str.compare("pop_front") == 0) {
//            pop_front();
//        } else if (str.compare("pop_back") == 0) {
//            pop_back();
//        } else if (str.compare("size") == 0)
//            dqsize();
//        else if (str.compare("empty") == 0) {
//            cout << isempty() << "\n";
//        } else if (str.compare("front") == 0) {
//            front();
//        } else if (str.compare("back") == 0) {
//            back();
//        }
//        }
//
}