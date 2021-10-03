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

stack<int> do_gnd;
stack<int> su_gnd;


bool check_su() {//도도의 그라운드top, 수연의 ground top
    //2 . 수연 체크
    if (!do_gnd.empty() && !su_gnd.empty()) { //둘다 empty아닐 떄만 가능
        return do_gnd.top() + su_gnd.top() == 5;
    }
    return false;
}

bool check_dodo() {

    if (do_gnd.empty() && su_gnd.empty()) return false;//둘다 빔

    //둘중 하나만 빔 

    if (do_gnd.empty()) {
        return su_gnd.top() == 5;
    }

    if (su_gnd.empty()) {
        return do_gnd.top() == 5;
    }

    // 둘다 안빔
    return (do_gnd.top() == 5 || su_gnd.top() == 5);

}


void dodoWin() {

    while (!su_gnd.empty()) {
        dodo.push_front(su_gnd.top());
        su_gnd.pop();
    }

    while (!do_gnd.empty()) {
        dodo.push_front(do_gnd.top());
        do_gnd.pop();
    }

}

void suWin() {


    while (!do_gnd.empty()) {
        suy.push_front(do_gnd.top());
        do_gnd.pop();
    }

    while (!su_gnd.empty()) {
        suy.push_front(su_gnd.top());
        su_gnd.pop();
    }

}

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

//        cout << "===================[ " << m << " ]=======================\n";

        //도도

        // 카드 내려두기
        if (emptyCheck()) break;
        do_gnd.push(dodo.back());
        dodo.pop_back();
        if (emptyCheck()) break;

        //종을 칠 수 있는가? -> 칠 수 있으면 치기
        do_res = check_dodo();
        if (do_res) dodoWin();
        else {
            su_res = check_su();
            if (su_res) suWin();
        }
        m--;
        if (m <= 0) break;


        //수연 카드 내려두기
        if (emptyCheck()) break;
        su_gnd.push(suy.back());
        suy.pop_back();
        if (emptyCheck()) break;

        //종을 칠 수 있는가? -> 칠 수 있으면 치기
        do_res = check_dodo();
        if (do_res) dodoWin();
        else {
            su_res = check_su();
            if (su_res) suWin();
        }
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
