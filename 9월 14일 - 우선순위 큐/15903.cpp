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

//        long long a, b;
//        a = q.top();
//        q.pop();
//        b = q.top();
//        q.pop();
//
//
//        long long c = a + b;
//
//        q.push(c);
//        q.push(c);

//가독성을 위해 반복문으로 선언도 가능
        vector<long long> num(2);

        //카드의 총 수량은 변하지 않고, 카드의 개수 최솟값은 2이기 때문에 empty 체크를 하지 않아도 됨
        for (int i = 0; i < 2; i++) { //가장 숫자가 작은 카드 2장 뽑기
            num[i] = q.top();
            q.pop();
        }
        for (int i = 0; i < 2; i++) //계산 한 값을 덮어 쓰기
            q.push(num[0] + num[1]);


    }

    while (!q.empty()) {

        sum += q.top();
        q.pop();
    }

    cout << sum;

}