//비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.
//
//add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
//remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
//check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
//toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
//all: S를 {1, 2, ..., 20} 으로 바꾼다.
//empty: S를 공집합으로 바꾼다.

#include <iostream>
#include <set>

using namespace std;

// 우선순위 큐 문제가 아닌건지??
// 우선순위 큐 문제 아니다!
// 출력이 0 / 1 이므로 1.비트마스킹 2.bool배열문제
// https://iagreebut.tistory.com/198



set<int> s;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int M, num;
    string str;

    cin >> M;

    while (M--) {

        cin >> str;

        if (str == "add") { //삽입
            cin >> num;
            s.insert(num);

        } else if (str == "remove") {// 삭제
            cin >> num;
            s.erase(num);

        } else if (str == "check") { // 검색
            cin >> num;
            auto it = s.find(num);
            if (it == s.end()) cout << 0 << "\n";
            else cout << 1 << "\n";

        } else if (str == "toggle") { // 검색 + 삽입or삭제
            cin >> num;
            auto it = s.find(num);
            if (it == s.end()) s.insert(num);
            else s.erase(num);
        } else if (str == "all") { // 삽입
            for (int i = 1; i <= 20; i++) {
                s.insert(i);
            }
        } else if (str == "empty") {
            s.clear();
        }

    }
}