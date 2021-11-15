//
// 2615번 - 오목
//

#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> board(19, vector<int>(19, 0));

bool checkWin(int color, int x, int y) {

    // -> /
    int row[4] = {0, 1, 1, 1};
    int col[4] = {1, -1, 0, 1};

    int num = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            int nrow = x + row[i];
            int ncol = y + col[i];
            if (nrow >= 0 && ncol >= 0 && nrow < 19 && ncol < 19) {
                cout << nrow << " " << ncol << " ";
                if (board[nrow][ncol] != color) break;

                num++;
            }
        }
        if (num == 5) return true;

    }

    return false;


}


int main() {

    vector<vector<bool>> check(19, vector<bool>(19, false));

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) check[i][j] = true;
        }
    }

    bool blackWin = false;
    bool whiteWin = false;

    int bx, by, wx, wy;

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {

            if (!check[i][j]) {
                check[i][j] = true;
                if (!blackWin && board[i][j] == 1) {
                    blackWin = checkWin(1, i, j);
                    bx = i + 1;
                    by = j + 1;
                }

                if (!whiteWin && board[i][j] == 2) {
                    whiteWin = checkWin(2, i, j);
                    wx = i + 1;
                    wy = j + 1;
                }

            }

            if (whiteWin && blackWin) break;
        }
    }

    if (whiteWin && blackWin) cout << 0;
    else if (!whiteWin && !blackWin) cout << 0;
    else if (whiteWin) { cout << 2 << "\n" << wx << " " << wy; }
    else { cout << 1 << "\n" << bx << " " << by; }


}