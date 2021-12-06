//
// 16235번 - 나무 재태크
//

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int> tp;


int main() {

    cin.tie(NULL); //cin , cout의 묶음을 풀어줌
    ios_base::sync_with_stdio(false); //c, c++버퍼를 분리


    int n, m, k;

    cin >> n >> m >> k;//땅의 w, 나무의 수, 년

    vector<vector<int>> feed(n, vector<int>(n, 0));//겨울 양분
    vector<vector<int>> ground(n, vector<int>(n, 5)); //땅

    deque<tp> tree;// pq는 시간초과 이므로 deque를 이용해 1회만 정렬 (어쩌피 새로 추가되는 나무는 나이가 제일 적다) 

//    priority_queue<tp, vector<tp>, greater<>> tree;


    queue<tp> tree_tmp;
    queue<tp> die;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> feed[i][j];
        }
    }

    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        tree.push_back({c, a - 1, b - 1}); //나무를 저장 (위치, 나이) -> 나이어린순으로 priority queue
    }

    sort(tree.begin(), tree.end(), greater<tp>());// 나이어린걸 뒤로 priority queue


    while (k--) {

        //봄
        while (!tree.empty()) {//모든 나무에대해 (어린나무(뒷쪽부터)
            int age = get<0>(tree.back());
            int x = get<1>(tree.back());
            int y = get<2>(tree.back());
            tree.pop_back();


            if (ground[x][y] >= age) {//양분을 먹을 수 있음
                ground[x][y] -= age;//양분을 먹음
                age++;//나이가 증가
                tree_tmp.push({age, x, y});//어린나무가 앞쪽에 쌓임(?)
            } else {
                //양분을 먹을 수 없음 -> 죽기
                die.push({age, x, y});
            }
        }


        //여름
        while (!die.empty()) {
            int age = get<0>(die.front());
            int x = get<1>(die.front());
            int y = get<2>(die.front());
            die.pop();

            ground[x][y] += age / 2;//나무의 나이를 2로 나눈 값이 해당 칸의 양분이 됨

        }

        //가을
        int row[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int col[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!tree_tmp.empty()) {//나이적은 나무 부터 꺼내짐
            int age = get<0>(tree_tmp.front());
            int x = get<1>(tree_tmp.front());
            int y = get<2>(tree_tmp.front());
            tree_tmp.pop();

            tree.push_front({age, x, y});//쓴 나무 버리면 안됨(앞쪽으로 넣어주기)

            if (age % 5 == 0) {//나이가 5의배수
                for (int i = 0; i < 8; i++) {
                    int nr = x + row[i];
                    int nc = y + col[i];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                        tree.push_back({1, nr, nc});//해당 위치에 나이가 1살인 나무가 생김 -> 1은 어쩌피 제일 작은 수 이므로 뒤에 넣어준다
                    }

                }
            }


        }

        //겨울
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ground[i][j] += feed[i][j]; //양분을 공급
            }
        }

    }


    cout << tree.size();
}
