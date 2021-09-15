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

//    int ia = v[a - 'A'];
//    int ib = v[b - 'A'];

    cout << " c " << c << "\n";
    cout << " ia : " << a << " ib : " << b << "\n";

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


//    for (int i = 0; i < str.length(); i++) {
//
//        char c = str[i];
//        if (isalpha(c)) {
//            //A - 'A' = 0
//            int n = c - 'A';
//            str[i] = v[n];
//        }
//
//    }
//
//    cout << str;


//    s.push(str[0]);

    int i = 0;
    while (i < str.length()) {
        char c = str[i];
        cout << "============== [ i ] : " << i << "  ===========\n";

        if (isOperator(c)) {
            cout << " OPERATEOR " << "\n";
            double a = s.top();
            s.pop();
            cout << "pop : " << a << "\n";
            double b = s.top();
            s.pop();
            cout << "pop : " << b << "\n";

            double zz = cal(a, b, c);
            cout << "cal : " << zz << "\n";
            s.push(zz);

        } else {
            cout << " NUMBER " << "\n";
            double input = v[c - 'A'];
            s.push(input);
            cout << "push : " << c << "\n";
        }
        i++;


    }

}