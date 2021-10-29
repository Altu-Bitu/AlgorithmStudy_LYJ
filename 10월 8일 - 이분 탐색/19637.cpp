//
// 19637번 - IF문 좀 대신 써줘
//

/*
 * 경계를 알아내자
 */

#include <iostream>
#include <map>

using namespace std;

/**
 * 모든 캐릭터와 칭호를 매칭하는 브루트 포스를 사용하기엔 최대 연산 횟수 10^5 * 10^5 -> 100억!
 * 특정 전투력 '이하'까지 해당하는 칭호를 받을 수 있음
 * -> 이분 탐색
 *
 * 맵과 셋은 원소를 정렬된 상태로 저장하기 때문에 알고리즘 헤더 없이 자체적으로 이분 탐색 함수를 사용할 수 있음
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, string> title; //칭호와 그 칭호의 전투력 상한값

    int n, m, power;
    string name;

    //입력
    cin >> n >> m;
    while (n--) {
        cin >> name >> power;
        if (title[power].empty()) //같은 전투력이 입력된적이 없을 때에만 map에 추가 (같은 전투력이 입력되면 그냥 넘어감)
            title[power] = name;
    }

    //출력
    while (m--) {
        cin >> power; //전투력이 입력되면,
        cout << title.lower_bound(power)->second << '\n';//power이하에 해당되는 부분으로 이분탐색 후 해당 iter의 칭호 반환
    }
}

//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//typedef pair<string, int> si;
//
//vector<si> title;//칭호 저장
//vector<int> characters;//
//
//
//int findUpper(int left, int right, int target) {
//
//    while (left <= right) {
//
//        int mid = (left + right) / 2;
//
//        if (characters[mid] <= target) { //upper탐색 이니까 같아지면 mid에서 오른쪽에도 있는지 탐색해야함
//            left = mid + 1;
//        } else if (characters[mid] > target) {
//            right = mid - 1;
//        }
//
//    }
//
//
//    return right + 1;//해당 범위 이내인 마지막 인덱스
//}
//
//
//int main() {
//
//    int n, m;
//
//    cin >> n >> m;
//
//    title.assign(n, {"", 0});
//    for (int i = 0; i < n; i++) {
//        cin >> title[i].first >> title[i].second;
//    }
//
//    characters.assign(m, 0);
//    for (int i = 0; i < m; i++) {
//        cin >> characters[i];
//    }
//
//    //정렬
//    sort(characters.begin(), characters.end()); // 정렬해서 순서가 흐트러지면 안되는건가..? 입력순서대로 출력해야하나..?
//
//    int pst_idx = 0;//이전 값 저장
//    for (int i = 0; i < n - 1; i++) { //모든 칭호 경계에 대해서 (맨 마지막은 나머지라서 안해도됨)
//
//        int upper = findUpper(0, m - 1, title[i].second);
////
////        cout << "title : " << title[i].first << "\n";
////        cout << "upper : " << upper << "\n";
//
//        for (int j = 1; j <= upper - pst_idx; j++) {
//            cout << title[i].first << "\n";
//        }
//
//        pst_idx = upper;
//
//    }
//
//    for (int i = 1; i <= m - pst_idx; i++) {
//        cout << title[n - 1].first << "\n";
//    }
//
//}
//
