// 숫자 할리 갈리 게임

#include <iostream>
#include <deque>
#include <stack>


/*
 * 그라운드 (stack)
 * 수연
 * 도도
 *
 * 본인 덱(deque)
 * 수연
 * 도도
 *
 *
 */

using namespace std;

deque<int> dodo;
deque<int> suy;

deque<int> do_gnd;
deque<int> su_gnd;
int winner;

bool check_su() {//도도의 그라운드top, 수연의 ground top
    //2 . 수연 체크
    if (!do_gnd.empty() && !su_gnd.empty()) { //둘다 empty아닐 떄만 가능
        return do_gnd.back() + su_gnd.back() == 5;
    }
    return false;
}

bool check_dodo(int card) {

    return card == 5;
//    if (do_gnd.empty() && su_gnd.empty()) return false;//둘다 빔
//
//    //둘중 하나만 빔
//
//    if (do_gnd.empty()) {
//        return su_gnd.top() == 5;
//    }
//
//    if (su_gnd.empty()) {
//        return do_gnd.top() == 5;
//    }
//
//    // 둘다 안빔
//    return (do_gnd.top() == 5 || su_gnd.top() == 5);

}


void win() {

    if (winner == 1) { //dodo win
        while (!su_gnd.empty()) {
            dodo.push_front(su_gnd.front());
            su_gnd.pop_front();
        }

        while (!do_gnd.empty()) {
            dodo.push_front(do_gnd.front());
            do_gnd.pop_front();
        }
    } else if (winner == 2) { //수연 win
        while (!do_gnd.empty()) {
            suy.push_front(do_gnd.front());
            do_gnd.pop_front();
        }

        while (!su_gnd.empty()) {
            suy.push_front(su_gnd.front());
            su_gnd.pop_front();
        }
    }
    winner = 0;

}

//void suWin() {
//
//
//    while (!do_gnd.empty()) {
//        suy.push_front(do_gnd.front());
//        do_gnd.pop_front();
//    }
//
//    while (!su_gnd.empty()) {
//        suy.push_front(su_gnd.front());
//        su_gnd.pop_front();
//    }
//
//}

bool emptyCheck() {

    if (dodo.empty()) {
        cout << "su";
        return true;
    } else if (suy.empty()) {
        cout << "do";
        return true;
    }

    return false;

}


int main() {

    int n, m;
    int a, b;

    cin >> n >> m;


    while (n--) {

        cin >> a >> b;

        dodo.push_back(a);
        suy.push_back(b);
    }


    bool do_res = false, su_res = false;

    while (true) {

        //도도

        // 카드 내려두기
        do_gnd.push_back(dodo.back());
        dodo.pop_back();
        if (emptyCheck()) break;

        //종을 칠 수 있는가? -> 칠 수 있으면 치기
        do_res = check_dodo(do_gnd.back());
        su_res = check_su();


        if (do_res) winner = 1;
        else if (su_res) winner = 2;
        win();

        m--;
        if (m <= 0) break;


        //수연 카드 내려두기
        su_gnd.push_back(suy.back());
        suy.pop_back();
        if (emptyCheck()) break;

        //종을 칠 수 있는가? -> 칠 수 있으면 치기
        do_res = check_dodo(su_gnd.back());
        su_res = check_su();

        if (do_res) winner = 1;
        else if (su_res) winner = 2;
        win();

        m--;
        if (m <= 0) break;


    }

    if (m <= 0) {
        if (dodo.size() > suy.size()) cout << "do\n";
        else if (dodo.size() < suy.size()) cout << "su\n";
        else cout << "dosu\n";
    }

//    while (!dodo.empty()) {
//        cout << dodo.front() << " " << suyeon.front() << "\n";
//        dodo.pop_front();
//        suyeon.pop_front();
//    }


}
