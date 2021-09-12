/*
 *
 * 알튜비튜 - 0907
 * 9375번
 * 패션왕 신해빈
 *
 * 해빈이는 패션에 매우 민감해서 한번 입었던 옷들의 조합을 절대 다시 입지 않는다.
 * 해빈이가 가진 의상들이 주어졌을때 과연 해빈이는 알몸이 아닌 상태로 며칠동안 밖에 돌아다닐 수 있을까?
 *
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;


vector<long long> v;


int main() {

    int M;
    cin >> M;
    string c, cloth;

    while (M--) {
        if (M < 0)break;

        int N;
        cin >> N;
        map<string, long long> closet;
        if (N == 0) v.push_back(0);
        else {
            for (int i = 0; i < N; i++) {
                cin >> c >> cloth;


                auto it = closet.find(cloth);
                if (it == closet.end())
                    closet[cloth] = 1;//존재하지 않는 경우 추가
                else
                    it->second++; //존재하는 경우 갯수증가
            }

            long long n = 1;
            for (auto it = closet.begin(); it != closet.end(); it++) {
                n *= it->second;
            }

            if (closet.size() == 1) v.push_back(N);
            else v.push_back(n + N);
        }
        closet.clear();


    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }




//    string cloth, c;
//
//    for (int i = 0; i < N; i++) {
//        cin >> c >> cloth;
//
//        auto it = closet.find(cloth);
//        if (it == closet.end())
//            closet[cloth] = 1;//존재하지 않는 경우 추가
//        else
//            it->second++; //존재하는 경우 갯수증r
//    }





//    int n = 1;
//
//    for (auto it = closet.begin(); it != closet.end(); it++) {
//        n *= it->second;
//    }
//
//    if (closet.size() == 1) cout << N;
//    else cout << n + N;




}