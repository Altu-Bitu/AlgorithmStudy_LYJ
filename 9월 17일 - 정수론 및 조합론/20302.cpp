//
// 민트 초코
//

/*
 * 입력으로 받은 수의 절댓값을 전부 소인수 분해하여,
    * 이면, 소인수 분해되는 소인수의 지수를 +1
    / 이면, 소인수 분해되는 소인수의 지수를 -1
 * 지수가 음수인 소인수가 하나라도 존재하면 유리수
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 100000;//입력범위 -100000 ~ +100000 (절댓값으로 할 거라서 양수)

vector<int> prime(SIZE + 1, 0);//소인수분해표(?)
vector<int> exponent(SIZE + 1, 0); //각 소수의 지수를 저장

void isPrime() {

    //아레스토테네스의 체를 응용해 소인수 분해 표 만들기


    //모든 수가 소수라고 가정하고, 해당 칸안에 자기자신을 저장
    for (int i = 2; i <= SIZE; i++) {
        prime[i] = i;
    }

    for (int i = 2; i * i < SIZE; i++) {
        if (prime[i] == i) { // 해당 수(i)에가 소수일 경우에
            for (int j = i * i; j <= SIZE; j += i) { //해당 수(i)의 배수들은 i로 약분가능 -> i대입
                if (prime[j] == j) //별도로 지정된 소수가 없을 경우
                    prime[j] = i; // i는 j의 소인수중 최소 -> 왜 최소인지는 소인수 분해에서
            }
        }
    }

}

//소인수 분해 표 갱신
void countExponent(int a, char c) {

    int cnt;
    if (c == '*') cnt = 1; // *면 ++
    else cnt = -1;// / 이면 --

    while (a > 1) {
        exponent[prime[a]] += cnt; //소인수 분해하여 exponent칸 갱신
        a = a / prime[a]; //최소 소인수로 나누어 다른 소인수들의 값도 구해주어야함
    }

}

//연산이 끝난 후, 소인수의 지수에 음수 있는지 판단 -> 있다면 유리수 -> true 리턴
bool isRationalNumber() {
    for (int i = 2; i <= SIZE; i++) {
        if (exponent[i] < 0) //유리수라면
            return true;
    }
    return false;//정수
}


int main() {

    int N;
    cin >> N;

    int num;
    char op;

    isPrime();

    //맨 처음 수는 연산자가 없어서 '*'로 넣어줌
    cin >> num;
    if (num == 0) {
        cout << "mint chocolate" << "\n";
        return 0;
    }

    countExponent(num, '*');
    N--;

    while (N--) {

        cin >> op >> num;

        if (num == 0) {
            cout << "mint chocolate" << "\n";
            return 0;
        }

        // 부호는 상관없음
        countExponent(abs(num), op);

    }


    if (isRationalNumber())
        cout << "toothpaste" << "\n";
    else
        cout << "mint chocolate" << "\n";

    return 0;

}
