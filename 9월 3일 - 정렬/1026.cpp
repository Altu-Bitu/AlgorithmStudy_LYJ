/*
 * 알튜비튜 - 0903
 * 1026번
 *
 * 보물
 * 길이가 N인 정수 배열 A와 B가 있다. 다음과 같이 함수 S를 정의하자.
 * S = A[0]×B[0] + ... + A[N-1]×B[N-1]
 * S의 값을 가장 작게 만들기 위해 A의 수를 재배열하자. 단, B에 있는 수는 재배열하면 안 된다.
 * S의 최솟값을 출력하는 프로그램을 작성하시오.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A;
vector<int> B;


int main() {

    int N;

    cin >> N;

    A.assign(N, 0);
    B.assign(N, 0);


    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i] * B[i];
    }

    cout << sum;
}


