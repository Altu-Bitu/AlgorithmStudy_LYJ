//
// Created by 이유정 on 2021/09/23.
//

#include <iostream>
#include <vector>


using namespace std;

vector<int> arr;


int gcd(int a, int b) {

    if (b == 0) return a;

    return gcd(b, a % b);


}


int main() {

    int t;

    cin >> t;

    while (t--) {

        int num;
        cin >> num;
        arr.assign(num, 0);

        for (int i = 0; i < num; i++) {
            cin >> arr[i];
        }

        long long sum = 0;

        for (int i = 0; i < num; i++) {

            for (int j = 0; j < i; j++) {
                sum += gcd(arr[i], arr[j]);
            }

        }
        cout << sum << "\n";


    }


}