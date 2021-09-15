/*
 * 알튜비튜 - 0907
 * 19636번
 *
 * 요요 시뮬레이션
 * 길이가 N인 정수 배열 A와 B가 있다. 다음과 같이 함수 S를 정의하자.
 * S = A[0]×B[0] + ... + A[N-1]×B[N-1]
 * S의 값을 가장 작게 만들기 위해 A의 수를 재배열하자. 단, B에 있는 수는 재배열하면 안 된다.
 * S의 최솟값을 출력하는 프로그램을 작성하시오.
 *
 */

#include <iostream>
#include <cmath>


using namespace std;


int main() {

    int W0, L0, T, D, L, A;
    bool danger1 = false, danger2 = false;

    cin >> W0 >> L0 >> T >> D >> L >> A;

    int W1, W2 = W0; // 다이어트 후 몸무게(기초 대사량 고려X, 고려O)

    //기초대사량의 변화를 고려하지 않은 경우

    W1 = W0 + D * (L - (L0 + A));
    if (W1 <= 0) {
        danger1 = true;
    }

// 단순 계산을 굳이 D번 반복중임 , 위의 코드로 변경
//    for (int i = 0; i < D; i++) {
//        W1 += change1;
//
//        if (W1 <= 0) {
//            danger1 = true;
//            break;
//        }
//    }


    int L1 = L0; //변화하는 일일 기초 대사량
    for (int i = 0; i < D; i++) {


        int change2 = L - (L1 + A);
        W2 += change2;


        if (abs(change2) > T)
            L1 += floor((double) change2 / 2.0); //ceil,floor연산시 double주의



        if (W2 <= 0 || L1 <= 0) {
            danger2 = true;
            break;
        }

    }



    //일일 기초 대사량 변화 X
    if (danger1)
        cout << "Danger Diet" << "\n";
    else
        cout << W1 << " " << L0 << "\n";

    //일일 기초 대사량 변화 O
    if (danger2)
        cout << "Danger Diet" << "\n";
    else {
        cout << W2 << " " << L1 << " ";

        if (L0 - L1 > 0) cout << "YOYO";
        else cout << "NO";
    }


}