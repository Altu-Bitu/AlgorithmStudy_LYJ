//
// N과 M(11)
//

#include <iostream>
#include <map>

using namespace std;

const int SIZE = 8;


map<int, int> m; // 자연수, 배열내 해당 자연수 등장 횟수(최대m)
int N, M;
int num[SIZE]; //(답배열) num배열이 전역변수 여야해서

void backtracking(int cnt) {

    if (cnt == M) { //길이가 M이되면 출력
        for (int i = 0; i < cnt; i++)
            cout << num[i] << " ";
        cout << "\n";
        return;
    }

    for (auto it = m.begin(); it != m.end(); it++) {
//        if (it->second < M) { //m번 이하로 등장했다면 아직쓸수있음
        num[cnt] = it->first; // 자연수
//            it->second++;// 해당 자연수 등장 횟수 +1
        //백트래킹
        backtracking(cnt + 1);
//            it->second--;//원래 상태로 되돌리기
    }
}


int main() {


    cin >> N >> M;

    int a;
    while (N--) {
        cin >> a;
        m.insert({a, 0});
    }

    backtracking(0);

}