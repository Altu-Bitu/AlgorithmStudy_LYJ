/*
 *
 * 알튜비튜 - 0907
 * 4358번
 * 생태학
 *
 * 생태학에서 나무의 분포도를 측정하는 것은 중요하다.
 * 그러므로 당신은 미국 전역의 나무들이 주어졌을 때,
 * 각 종이 전체에서 몇 %를 차지하는지 구하는 프로그램을 만들어야 한다.
 *
 */

#include <iostream>
#include <map>

using namespace std;

map<string, int> tree;
string name;
int cnt = 0;

int main() {

//    int N;
//    cin >> N;
//    cin.ignore();
//
//    for (int i = 0; i < N; i++) {
//        getline(cin, name);
//        cnt++;
//
//        //존재하지 않는 경
//        tree[name]++; //이렇게하면 자동으로 증가한다!
//
//        for (auto iter = tree.begin(); iter != tree.end(); iter++) {
//            cout << iter->first << " " << iter->second << "\n";
//        }
//
//        auto it = tree.find(name);
//        if (it == tree.end())
//            tree[name] = 1;
//        else
//            it->second++;
//    }


    while (true) {
        getline(cin, name);
        if (cin.eof() == true) break; //eof까지 입력받기


        cnt++;

        tree[name]++;
// 아래 코드와 위 한줄이 동일하다!
//        auto it = tree.find(name);
//        if (it == tree.end())
//            tree[name] = 1;//존재하지 않는 경우 추가
//        else
//            it->second++; //존재하는 경우 갯수증가

    }

    for (auto iter = tree.begin(); iter != tree.end(); iter++) {
        cout << fixed;
        cout.precision(4);
        cout << iter->first << " " << (double) iter->second / (double) cnt * 100 << "\n";
    }


}