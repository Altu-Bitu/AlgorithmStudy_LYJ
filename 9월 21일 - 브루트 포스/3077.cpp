#include <iostream>
#include <vector>
#include <map>

//map 2002 추월과 유사한 문제 -> 굳이 string으로 비교할 필요 없음 순서만 맞으면됨

using namespace std;

int main() {

    int N;
    cin >> N;

    map<string, int> ans;
    vector<string> hyun;

    hyun.assign(N, "");

    string input;

    //현우가 쓴 정답
    for (int i = 0; i < N; i++) {
        cin >> hyun[i];
    }

    // 원래 정답 + 순서 저장
    for (int i = 0; i < N; i++) {
        cin >> input;
        ans[input] = i;
    }

    // 현우가 쓴 정답을 순서 배열로 변경
    vector<int> hyun_i;
    for (int i = 0; i < N; i++) {
        hyun_i.push_back(ans[hyun[i]]);
    }


    int cor = 0;
    //n(n-1)/2 번 돌면서 순서가 맞으면 ++
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (hyun_i[i] < hyun_i[j])cor++;
        }


    }

    int total = N * (N - 1) / 2;
    cout << cor << "/" << total;


}