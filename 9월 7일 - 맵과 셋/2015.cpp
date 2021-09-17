/*
 *
 * 알튜비튜 - 0907
 * 2015번
 * 수들의 합4
 *
 * A[1], A[2], ..., A[N]의 N개의 정수가 저장되어 있는 배열이 있다.
 * 이 배열 A의 부분합이란 1 ≤ i ≤ j ≤ N인 정수 i와 j에 대해 A[i]부터 A[j]까지의 합을 말한다.
 * N과 A[1], A[2], ..., A[N]이 주어졌을 때,
 * 이러한 N×(N+1)/2개의 부분합 중 합이 K인 것이 몇 개나 있는지를 구하는 프로그램을 작성하시오.
 *
 */

#include <iostream>
#include <vector>


using namespace std;

vector<int> arr;
vector<int> ans;


//map(합 ,횟수 )

int main() {

    int N, K;
    cin >> N >> K;

    arr.assign(N, 0);
    ans.assign(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

//    int sum = 0, cnt = 0;
//    for (int j = 0; j < N; j++) {
//
//        for (int k = j; k < N; k++) {
//            sum += arr[k];
//            if (sum == K) cnt++;
//        }
//        sum = 0;
//    }


    int sum, cnt = 0;
    for (int j = 0; j < N; j++) {
        if (j != 0) {
            ans[j] = ans[j - 1] + arr[j];
        } else ans[0] = arr[0];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (ans[j] - ans[i] == K) cnt++;
        }
    }


    cout << cnt;

}