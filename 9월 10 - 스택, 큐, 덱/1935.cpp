//
// Created by 이유정 on 2021/09/15.
//

#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

stack<double> s;
vector<int> v;


bool isOperator(char c) {

    if (c == '*' || c == '/' || c == '+' || c == '-')
        return true;
    return false;

}

double cal(double a, double b, char c) {


    switch (c) {
        case '+':
            return b + a;
        case '*':
            return b * a;
        case '/':
            return b / a;
        case '-':
            return b - a;
        default:
            break;
    }
    return -1;


}

int main() {

    int N, num;
    string str;

    cin >> N;
    cin.ignore();

    getline(cin, str);
    v.assign(N, 0);
//    cout << str;

    for (int i = 0; i < N; i++) {
        cin >> num;
        v[i] = num;
    }


    int i = 0;
    double ans;
    while (i < str.length()) {
        char c = str[i];
//        cout << "============== [ i ] : " << i << "  ===========\n";

        if (isOperator(c)) {
//            cout << " OPERATEOR " << "\n";
            double a = s.top();
            s.pop();
//            cout << "pop : " << a << "\n";
            double b = s.top();
            s.pop();
//            cout << "pop : " << b << "\n";

            ans = cal(a, b, c);
//            cout << "cal : " << ans << "\n";
            s.push(ans);

        } else {
//            cout << " NUMBER " << "\n";
            double input = v[c - 'A'];
            s.push(input);
//            cout << "push : " << c << "\n";
        }
        i++;


    }
    cout << fixed;
    cout.precision(2);
    cout << ans;


}