//
// 골드바흐의 추측
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> is_prime;


//에라스토테네스의 체
void isPrime(int n) {


    if (n <= 1) {
        is_prime.assign(n + 1, false);
        return;
    };

    is_prime.assign(n + 1, true); //처음엔 전부 true

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {//해당 칸이 true면
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }


    }


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;

    isPrime(1000000); // 미리 구해두기 매 case마다 구하는건 비효율적이다.

    while (cin >> num) {
        if (num == 0) break;

        int range = round((double) num / 2.0);

        for (int i = 3; i <= range; i += 2) { //2어쩌피 짝수라 안됨 + 2배수 검사할 필요없음 + 절반까지만 해도 상관없음(후자는 num-i)에서 걸림
            if (is_prime[i] && is_prime[num - i]) {
                cout << num << " = " << i << " + " << num - i << "\n";
                break;
            }
            if (i == range) cout << "Goldbach's conjecture is wrong." << "\n";
        }


    }


}