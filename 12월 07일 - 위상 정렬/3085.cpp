//
// 3085번 - 사탕 게임
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
typedef pair<int, int> ii;

//우[0],좌[1],하[2],상[3]
int row[4] = {0, 0, 1, -1};
int col[4] = {1, -1, 0, 0};

//해당 방향으로 연속하는 char의 갯수
int findSubseq(vector<vector<char>> &board, char c, int dir, ii loc) {


    cout << "char is " << c << "\n";
    cout << "this is (" << loc.first << ", " << loc.second << ")\n";

    int res = 1;
    int cnt;
    for (int i = 0; i < 4; i++) {

        cnt = 0;
        int nr = loc.first;
        int nc = loc.second;


        while (nr != 0 && nr != board.size() - 1 && nc != 0 && nc != board.size() - 1) {

            nr += row[i];
            nc += col[i];

            cout << nr << " " << nc << "\n";

            if (board[nr][nc] != c) {//둘이 다르면 끝
                cout << "둘이 다르다. <종료> cnt : " << cnt + 1 << "\n";

                res = max(res, cnt + 1);

                break;


            }

            cnt++;//같으면 한글자 추가


        }
        cout << "범위 초과. <종료> cnt : " << cnt + 1 << "\n";
        res = max(res, cnt + 1);
    }

    return res;//자기자신


}


int main() {

    vector<vector<char>> board;

    int size;
    cin >> size;

    board.assign(size, vector<char>(size, '\0'));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 1;

    for (int i = 0; i < size; i++) {//마지막 행까지 검사해야함
        for (int j = 0; j < size - 1; j++) {

            //같은 행 옆 열
            char front = board[i][j];
            char back = board[i][j + 1];

            if (front == back) continue;//바꿔도 같은 경우는 스킵

            //둘을 바꾸었을 때 연속된 길이
            ans = max(ans, findSubseq(board, back, 1, {i, j}));//<-로 탐색
            ans = max(ans, findSubseq(board, front, 0, {i, j + 1}));//->로 탐색

        }
    }


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {

            //같은 행 옆 열
            char up = board[j][i];
            char down = board[j + 1][i];

            if (up == down) continue;//바꿔도 같은 경우는 스킵

            //둘을 바꾸었을 때 연속된 길이
            ans = max(ans, findSubseq(board, up, 2, {j + 1, i}));//
            ans = max(ans, findSubseq(board, down, 3, {j, i}));//->로 탐색

        }
    }

    cout << ans;


}