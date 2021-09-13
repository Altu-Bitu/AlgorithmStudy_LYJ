/*
 *
 * 알튜비튜 - 0907
 * 14425번
 * 문자열 집합
 *
 * 총 N개의 문자열로 이루어진 집합 S가 주어진다.
 * 입력으로 주어지는 M개의 문자열 중에서 집합 S에 포함되어 있는 것이
 * 총 몇 개인지 구하는 프로그램을 작성하시오.
 *
 */


#include <iostream>
#include <set>
#include <string>


using namespace std;

set<string> s;

int main() {

    int N, M;
    string str;
    cin >> N >> M;

//    for (int i = 0; i < N; i++) {
//        cin >> str;
//        s.insert(str);
//    }
//    N재사용 x이므로 while로 변경
    while (N--) {
        cin >> str;
        s.insert(str);

    }

    int cnt = 0;
//    for (int j = 0; j < M; j++) {
//        cin >> str;
//        if (s.find(str) != s.end()) cnt++;
//    }
//  M재사용 x이므로 while로 변경
    while (M--) {
        cin >> str;
        if (s.find(str) != s.end()) cnt++;
    }

    cout << cnt;

}