//
// 큰 수 만들기
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


string solution(string number, int k) {
    string answer = "";


    int pop = 0;
    for (int i = 0; i <= number.size() - (k - pop); i++) {
        for (int j = i + 1; j <= number.size() - k; j++) {
            int a = number[i] - '0';
            int b = number[j] - '0';

            cout << a << " " << b << "\n";
            if (a < b) {
                pop++;
                number.erase(number.begin() + i);
                i--;
                j--;
                cout << number << "\n";
                cout << "poop" << pop << "\n";
                if (pop == k) return number;
                break;
            }

        }


    }

    return answer;
}

int main() {

    string number;
    cin >> number;

    int k;
    cin >> k;


    cout << solution(number, k);
}