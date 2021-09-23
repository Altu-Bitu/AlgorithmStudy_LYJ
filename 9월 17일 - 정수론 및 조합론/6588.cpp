//
// 골드바흐의 추측
//

#include <iostream>
#include <vector>

using namespace std;

vector<bool> is_prime;

//에라스토테네스의 체
bool isPrime(int n) {


    if (n <= 1) {
        is_prime.assign(n + 1, false);
        return false;
    };

    is_prime.assign(n + 1, true); //처음엔 전부 true

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i])//해당 칸이 true면
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    }
    return true;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;

    while (cin >> num) {
        if (num == 0) break;

        bool res = isPrime(num);

        if (!res) {
            cout << "Goldbach's conjecture is wrong." << "\n";
            continue;
        }

        if (is_prime[2]) {
            if (is_prime[num - 2]) {
                cout << num << " = " << 2 << " + " << num - 2 << "\n";
                continue;
            }
        }


        for (int i = 3; i < num - 1; i += 2) {
            if (is_prime[i]) {
                if (is_prime[num - i]) {
                    cout << num << " = " << i << " + " << num - i << "\n";
                    break;
                }
            }
            if (i == num - 2) cout << "Goldbach's conjecture is wrong." << "\n";
        }


    }


}