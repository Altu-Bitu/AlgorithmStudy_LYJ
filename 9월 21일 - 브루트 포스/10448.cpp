//
// Created by 이유정 on 2021/09/27.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> tri(47, 0);


void eureka() {


    for (int i = 1; i <= 46; i++) {
        tri[i] = tri[i - 1] + i;
    }

}

bool isTri(int num) {
    for (int i = 1; i < tri.size(); i++) {
        for (int j = 1; j < tri.size(); j++) {
            for (int k = 1; k < tri.size(); k++) {
                if (tri[i] + tri[j] + tri[k] == num) {
//                    cout << tri[i] << " " << tri[j] << " " << tri[k] << "\n";
                    return true;
                }
            }
        }
    }
    return false;
}


int main() {

    int T, num;
    cin >> T;

    eureka();

    while (T--) {
        cin >> num;

        cout << isTri(num) << "\n";

    }


}
