//
// Created by 이유정 on 2021/09/19.
//

#include <iostream>
#include <queue>

using namespace std;


priority_queue<long long, vector<long long>, greater<long long>> q;//최소힙

int main() {

    int n, m, num;

    cin >> n >> m;

    while (n--) {
        cin >> num;
        q.push(num);
    }

    long long sum = 0;

    while (m--) {

        long long a, b;
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();

        long long c = a + b;

        q.push(c);
        q.push(c);

    }

    while (!q.empty()) {

        sum += q.top();
        q.pop();
    }

    cout << sum;

}