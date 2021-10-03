//
// 뱀
//

#include <iostream>
#include <deque>
#include <queue>


using namespace std;
typedef pair<int, int> ii;
typedef pair<int, char> ic;


const int SIZE = 100;
const int TOP = 0;
const int BOT = 1;
const int LEFT = 2;
const int RIGHT = 3;


int board[SIZE + 2][SIZE + 2] = {0};
deque<ii> snake;
queue<ic> direction;

void initBoard(int n) {

    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            if (i == 0 || i == n + 1 || j == 0 || j == n + 1)
                board[i][j] = 1;
        }
    }

}

//지금 향하는 방향과, 틀 방향을 입력하면, 앞으로 향할 방향을 리턴하는 함수
int changeDir(int now, char dir) {

    switch (now) {
        case TOP:
            if (dir == 'L') return LEFT;
            else if (dir == 'D') return RIGHT;
            break;
        case BOT:
            if (dir == 'L') return RIGHT;
            else if (dir == 'D') return LEFT;
            break;
        case LEFT:
            if (dir == 'L') return BOT;
            else if (dir == 'D') return TOP;
            break;
        case RIGHT:
            if (dir == 'L') return TOP;
            else if (dir == 'D') return BOT;
            break;
        default:
            break;
    }
}


void move(int x, int y) {


    ii tmp;

    // 이동했는데 사과가 있는지 확인
    if (board[x][y] == 2) {
        board[x][y] = 0;// 있음 remove apple
    } else {
        tmp = snake.back();
        board[tmp.first][tmp.second] = 0;
        snake.pop_back(); // 없음 tail pop
    }

    //아니면 이동하기 push front
    snake.push_front({x, y});
    board[x][y] = 1;


}


int main() {

    int n, k;

    cin >> n >> k;

    //경계 초기화
    initBoard(n);
    //뱀 시작위치
    snake.push_front({1, 1});
    board[1][1] = 1;

    // 사과 배치
    int i, j, l;
    while (k--) {
        cin >> i >> j;
        board[i][j] = 2;//사과
    }

    cin >> l;

    int a;
    char d;
    while (l--) {
        cin >> a >> d;
        direction.push({a, d});
    }

    int sec = 0;
    int cur_dir = RIGHT;
    ii top;

    int x, y;
    while (true) {
        // 이동
        top = snake.front();
        sec++;

        if (cur_dir == TOP) {
            x = top.first - 1;
            y = top.second;
        } else if (cur_dir == BOT) {
            x = top.first + 1;
            y = top.second;
        } else if (cur_dir == RIGHT) {
            x = top.first;
            y = top.second + 1;
        } else if (cur_dir == LEFT) {
            x = top.first;
            y = top.second - 1;
        }


        //벽과 부딪힘 or 본인 몸과 부딪힘
        if (board[x][y] == 1) break;

        move(x, y);

        //x초가 끝난 뒤

        //방향 전환 여부 확인
        if (sec == direction.front().first) {
            //방향을 전환
            cur_dir = changeDir(cur_dir, direction.front().second);
            //pop
            direction.pop();
        }


    }

    cout << sec;




//    for (int i = 0; i < n + 2; i++) {
//        for (int j = 0; j < n + 2; j++) {
//            cout << board[i][j] << " ";
//        }
//        cout << "\n";
//    }
//
//    while (!direction.empty()) {
//        cout << direction.front().first << " " << direction.front().second << "\n";
//        direction.pop();
//    }


}
