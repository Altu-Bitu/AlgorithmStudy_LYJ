//
// Created by  on 2021/09/21.
//

#include <iostream>

using namespace std;


long calCof(int N, int K) {

    if (K == 0) return 1;

    long a = 1, b = 1;

    for (int i = 0; i < K; i++) {

        a *= N - i;
        if (i == 0) continue;
        b *= i;

    }

    return a / (b * K);

}


int main() {

    int N, K;
    cin >> N >> K;


    // (n n-1 n-2 ... 1) / (n-k n-k-1 ... 1) * ( k k-1 ... 1 )  =
    //  n! / (n-k)! * k!


    cout << calCof(N, K);


}