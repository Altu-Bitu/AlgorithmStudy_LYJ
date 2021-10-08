//
// N과 M(11)
// 핵심은
// 1. 입력한 수에 중복을 제거 하는 것 -> 중복인 것은 아무 의미가 없음 1개만 입력된 수도 여러번 나와도 상관없는 문제임 + 수열에는 중복이 없어야하므로
// 그래서 오히려 중복을 제거해버리고, 전부 한개만 있다 전재하에 순열을 만드는게 편하다.
// 2. 사전 순서 이므로 숫자를 정렬해서 시작하기
//
// 나는 그래서 맵(정렬, 중복없음)을 사용했는데
// vector를 사용해서 넣을때 중복을 체크해서 넣지않고(check bool 배열)이용 , sort로 정렬 후 시작 하면된다.
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

    //이 부분 수정 ->굳이 등장 횟수를 체크할 필요가 없음
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