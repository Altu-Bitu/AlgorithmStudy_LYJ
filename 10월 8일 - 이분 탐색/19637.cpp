//
// 19637번 - IF문 좀 대신 써줘
//

/*
 * 경계를 알아내자
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<string, int> si;

vector<si> title;//칭호 저장
vector<int> characters;//


int findUpper(int left, int right, int target) {

    while (left <= right) {

        int mid = (left + right) / 2;

        if (characters[mid] <= target) { //upper탐색 이니까 같아지면 mid에서 오른쪽에도 있는지 탐색해야함
            left = mid + 1;
        } else if (characters[mid] > target) {
            right = mid - 1;
        }

    }


    return right + 1;//해당 범위 이내인 마지막 인덱스
}


int main() {

    int n, m;

    cin >> n >> m;

    title.assign(n, {"", 0});
    for (int i = 0; i < n; i++) {
        cin >> title[i].first >> title[i].second;
    }

    characters.assign(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> characters[i];
    }

    //정렬
    sort(characters.begin(), characters.end()); // 정렬해서 순서가 흐트러지면 안되는건가..? 입력순서대로 출력해야하나..?

    int pst_idx = 0;//이전 값 저장
    for (int i = 0; i < n - 1; i++) { //모든 칭호 경계에 대해서 (맨 마지막은 나머지라서 안해도됨)

        int upper = findUpper(0, m - 1, title[i].second);
//
//        cout << "title : " << title[i].first << "\n";
//        cout << "upper : " << upper << "\n";

        for (int j = 1; j <= upper - pst_idx; j++) {
            cout << title[i].first << "\n";
        }

        pst_idx = upper;

    }

    for (int i = 1; i <= m - pst_idx; i++) {
        cout << title[n - 1].first << "\n";
    }

}

