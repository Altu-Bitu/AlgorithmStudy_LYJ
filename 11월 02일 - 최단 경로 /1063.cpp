//
// 1063번 - 킹
//


#include <iostream>

using namespace std;
typedef pair<int, int> ii;

//이동해야할 방향의 좌표를 리턴
ii findDirection(string dir) {

    if (dir == "R")
        return make_pair(0, 1);//row, col
    else if (dir == "L")
        return make_pair(0, -1);
    else if (dir == "B")
        return make_pair(-1, 0);
    else if (dir == "T")
        return make_pair(1, 0);
    else if (dir == "RT")
        return make_pair(1, 1);
    else if (dir == "LT")
        return make_pair(1, -1);
    else if (dir == "RB")
        return make_pair(-1, 1);
    else if (dir == "LB")
        return make_pair(-1, -1);

}


int main() {

    string king, stone;

    int n;

    cin >> king >> stone >> n;

    //first : row , second : col (A = 1)
    ii king_pos = make_pair(king[1] - '0', king[0] - 'A' + 1);
    ii stone_pos = make_pair(stone[1] - '0', stone[0] - 'A' + 1);


    string move;
    while (n--) {
        cin >> move;
        ii dir = findDirection(move);

        //stone과 king의 위치관계 파악
        int row = king_pos.first - stone_pos.first;
        int col = king_pos.second - stone_pos.second;

        //주의 1 . 이동했을 때 돌과 "같은"위치에 존재할때만 돌을 옮기는 것 -> 차이 범위 -1~1
        string state = "NONE";
        if (col == 0) { //같은 col에 존재
            if (row == 1)state = "B";
            else if (row == -1) state = "T";
        } else if (row == 0) { // 같은 row 에 존재
            if (col == 1)state = "L";
            else if (col == -1) state = "R";
        } else if (abs(col) == 1 && abs(row) == 1) { //대각선 경로 어딘가
            if (col == 1) {//LEFT
                if (row == 1)state = "LB";
                else if (row == -1) state = "LT";
            } else if (col == -1) {
                if (row == 1)state = "RB";
                else if (row == -1) state = "RT";
            }
        }


        if (state == move) { //돌과 방향이 같음 -> 돌이 이동하기 위한 조건

            //돌을 이동시킴
            ii new_stone = make_pair(stone_pos.first + dir.first, stone_pos.second + dir.second);

            //범위 내에 있을 때만 이동
            if (new_stone.first > 0 && new_stone.first < 9 && new_stone.second > 0 && new_stone.second < 9) {
                stone_pos = new_stone;
            }


        }

        //킹은 항상 이동
        ii new_king = make_pair(king_pos.first + dir.first, king_pos.second + dir.second);

        //범위 내에 존재 && 돌과 겹칠수는 없음
        if (new_king != stone_pos && new_king.first > 0 && new_king.first < 9 && new_king.second > 0 &&
            new_king.second < 9)
            king_pos = new_king;
    }

    //col부터 출력 (알파벳으로 변환)
    cout << char(king_pos.second + 'A' - 1) << king_pos.first << "\n";
    cout << char(stone_pos.second + 'A' - 1) << stone_pos.first;


}

