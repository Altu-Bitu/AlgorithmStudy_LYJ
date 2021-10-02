//
// Created by 이유정 on 2021/09/27.
//

#include <iostream>

using namespace std;

int main() {

    int B, R;

    cin >> R >> B;


    int mul = B + R;
    int sum = (R + 4) / 2;

    int L, W = 1;
    L = sum - W;
    while (W <= L) {


        if (L * W == mul) break;
        W++;
        L = sum - W;

    }

    cout << L << " " << W;


}