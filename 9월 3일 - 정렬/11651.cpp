/*
 * 알튜비튜 - 0903
 * 11651번
 *
 * 좌표 정렬하기 2
 * 2차원 평면 위의 점 N개가 주어진다.
 * 좌표를 y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> p;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {

    if (a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;

}

int main() {

    int N, X, Y;
    cin >> N;

    p.assign(N, {0, 0});

    for (int i = 0; i < N; i++) {
        cin >> X >> Y;
        p[i].first = X;
        p[i].second = Y;
    }

    sort(p.begin(), p.end(), compare);

    for (int i = 0; i < N; i++) {
        cout << p[i].first << " " << p[i].second << "\n";
    }

}
