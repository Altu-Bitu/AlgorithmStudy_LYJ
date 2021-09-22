//
// Created by 이유정 on 2021/09/19.
//

#include <iostream>
#include <queue>

using namespace std;


//struct compare {
//
//
//    bool operator()(pair<int, int> &a, pair<int, int> &b) {
//
//        if (a.first != b.first)
//            return a.first > b.first; //오름차순
//        return a.second > b.second;//오름차순
//
//    }
//
//};

struct compare {


    bool operator()(int &a, int &b) {

        if (abs(a) != abs(b))
            return abs(a) > abs(b); //오름차순
        return a > b;//오름차순

    }

};


//priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
priority_queue<int, vector<int>, compare> pq;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, num;
    cin >> N;

    while (N--) {

        cin >> num;

        if (num != 0) {
//            pq.push({abs(num), num});
            pq.push(num);
        } else {

            if (pq.empty())cout << 0 << "\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }


        }


    }


}