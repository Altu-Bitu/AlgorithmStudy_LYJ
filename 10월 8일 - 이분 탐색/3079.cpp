//
// 3079번 - 입국심사
//

/*
 * 사람 수 : m명
 * 입국 심사대 수 : n개
 * 입국 심사를 받는 데 걸리는 시간의 최솟값은?
 *
 * 최소 시간이 k 일 때, m명이 모두 심사를 받을 수 있는가?
 *
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> t;


long long immigration(long long k) { // k : 주어진 시간(최소 시간)

    long long sum = 0;
    for (int i = 0; i < t.size(); i++) {

        sum += k / t[i];


    }


    return sum;//k시간 내에 심사 받을 수 있는 사람의 수
}

long long lowerSearch(long long left, long long right, int target) { //target = m

    while (left <= right) {

        long long mid = (left + right) / 2;
        long long res = immigration(mid);


        if (res < target) { //심사 받을 수 있는 사람의 수가 적음 -> 시간을 더줘야함
            left = mid + 1;
        } else if (res >= target) { //심사 받을 수 있는 사람의 수가 많음 -> 시간 좀 더 줄여도 됨

            right = mid - 1;
        }

    }

    return right + 1;
}


int main() {

    int n, m;

    cin >> n >> m;


    //입국 심사 걸리는 시간
    t.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    long long min = *min_element(t.begin(), t.end());
    long long max = *max_element(t.begin(), t.end());

    //min : 아무리 적어도 제일 빨리처리하는 사람의 초보다 빨라질 순없는
    //max : 제일오래걸리는 사람한테 m명이 다 받았을 경우?
    cout << lowerSearch(min, max * m, m);

}