/*
 *
 * 알튜비튜 - 0907
 * 18870번
 * 좌표 압축
 *
 * 수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다. 이 좌표에 좌표 압축을 적용하려고 한다.
 * Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표의 개수와 같아야 한다.
 * X1, X2, ..., XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N를 출력해보자.
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

multimap<int, int> m;
vector<int> ans;

int main() {

    cin.tie(NULL); //cin , cout의 묶음을 풀어줌
    ios_base::sync_with_stdio(false); //c, c++버퍼를 분리

    int N, num;
    cin >> N;
    ans.assign(N, 0);

    for (int i = 0; i < N; i++) {

        cin >> num;
        m.insert(make_pair(num, i));

    }

    int j = 0;
    int min = 0, bkey;
    for (auto iter = m.begin(); iter != m.end(); iter++) {

        int value = (*iter).second; //index
        int key = (*iter).first; //number


        if (j == 0) {
            ans[value] = min;
            bkey = key;
            j++;
        } else {

            if (key > bkey) {
                key = ++min;
            } else {
                key = min;
            }
            ans[value] = key;
            bkey = (*iter).first;
        }


    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }


}