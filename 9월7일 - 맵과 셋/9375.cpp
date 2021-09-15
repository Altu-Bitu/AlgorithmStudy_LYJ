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

using namespace std;

/**
 * 같은 종류의 옷이 각각 몇 벌 있는지만 알면 됨
 */
int main() {
    int t, n;
    string outfit, kind;

    cin >> t;
    while (t--) {
        map<string, int> m;

        //입력
        cin >> n;
        while (n--) {
            cin >> outfit >> kind;
            m[kind]++;
        }

        //연산
        int result = 1;
        for (auto iter = m.begin(); iter != m.end(); iter++)
            result *= (iter->second + 1); //해당 종류의 옷을 입기(iter->second:해당옷의 수 ) + 안 입기(1)

        //출력
        //알몸인 경우 제외수(모든 종류의 옷을 하나도 입지않음 경우)
        cout << result - 1 << '\n';
    }
}
//
//#include <iostream>
//#include <map>
//#include <vector>
//
//using namespace std;
//
//
//vector<long long> v;
//
//
//int main() {
//
//    int M;
//    cin >> M;
//    string c, cloth;
//
//    while (M--) {
//        if (M < 0)break;
//
//        int N;
//        cin >> N;
//        map<string, long long> closet;
//        if (N == 0) v.push_back(0);
//        else {
//            for (int i = 0; i < N; i++) {
//                cin >> c >> cloth;
//
//
//                auto it = closet.find(cloth);
//                if (it == closet.end())
//                    closet[cloth] = 1;//존재하지 않는 경우 추가
//                else
//                    it->second++; //존재하는 경우 갯수증가
//            }
//
//            long long n = 1;
//            for (auto it = closet.begin(); it != closet.end(); it++) {
//                n *= it->second;
//            }
//
//            if (closet.size() == 1) v.push_back(N);
//            else v.push_back(n + N);
//        }
//        closet.clear();
//
//
//    }
//
//    for (int i = 0; i < v.size(); i++) {
//        cout << v[i] << "\n";
//    }




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