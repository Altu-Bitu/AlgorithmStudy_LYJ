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

    //first : row , second : col
    ii king_pos = make_pair(king[1] - '0', king[0] - 'A' + 1);
    ii stone_pos = make_pair(stone[1] - '0', stone[0] - 'A' + 1);

//    cout << "king pos : " << king_pos.first << " " << king_pos.second;
//    cout << "stone pos : " << stone_pos.first << " " << stone_pos.second;

    string move;
    while (n--) {
        cin >> move;
        ii dir = findDirection(move);

//        cout << "==========================================================\n";
//        cout << "======================START===================\n";
//        cout << "==========================================================\n";
//        cout << "king pos : " << king_pos.first << " " << king_pos.second << "\n";
//        cout << "stone pos : " << stone_pos.first << " " << stone_pos.second << "\n";


        int row = king_pos.first - stone_pos.first;
        int col = king_pos.second - stone_pos.second;
//        cout << "==========================================================\n";
//        cout << "row : " << row << " col : " << col << "\n";

//주의 1 . 차이가 1이어야함 ( 이동했을 때 돌과 "같은"위치에 존재할때만 돌을 옮기는 것)
        string state = "NONE";
        if (col == 0) { //같은 col에 존재
            if (row == 1)state = "B";
            else if (row == -1) state = "T";
//            state = row > 0 ? "B" : "T";
        } else if (row == 0) {
            if (col == 1)state = "L";
            else if (col == -1) state = "R";
//            state = col > 0 ? "L" : "R";
        } else if (abs(col) == abs(row)) {
            if (col == 1) {//LEFT
                if (row == 1)state = "LB";
                else if (row == -1) state = "LT";
//                state = row > 0 ? "LB" : "LT";
            } else if (col == -1) {
                if (row == 1)state = "RB";
                else if (row == -1) state = "RT";
            }
//                state = row > 0 ? "RB" : "RT";
        }

//        cout << "==========================================================\n";
//        cout << "state : " << state << "\n";


        if (state == move) { //돌과 방향이 같음

//            ii new_king = make_pair(king_pos.first + dir.first, king_pos.second + dir.second);
            ii new_stone = make_pair(stone_pos.first + dir.first, stone_pos.second + dir.second);
//            cout << "==========================================================\n";
//            cout << "king new pos : " << new_king.first << " " << new_king.second << "\n";
//            cout << "stone new pos : " << new_stone.first << " " << new_stone.second << "\n";
            if (new_stone.first > 0 && new_stone.first < 9 && new_stone.second > 0 && new_stone.second < 9) {
//                king_pos = new_king;
                stone_pos = new_stone;
            }


        }
//        else {

        ii new_king = make_pair(king_pos.first + dir.first, king_pos.second + dir.second);
//            cout << "==========================================================\n";
//            cout << "king new pos : " << new_king.first << " " << new_king.second << "\n";

        if (new_king != stone_pos && new_king.first > 0 && new_king.first < 9 && new_king.second > 0 &&
            new_king.second < 9)
            king_pos = new_king;

//        }

    }

    cout << char(king_pos.second + 'A' - 1) << king_pos.first << "\n";
    cout << char(stone_pos.second + 'A' - 1) << stone_pos.first;


}

