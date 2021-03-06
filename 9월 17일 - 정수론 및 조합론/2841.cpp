//2 8    8push
//2 10  10push
//2 12  12push
//2 10  12pop
//2 5   10pop 8 pop 5 push

// 다른 줄 끼리는 영향안감 -> 어쩌피 거기 팅길거아님
//1 5   1-5push
//2 3   2-3push
//2 5   2-5push
//2 7   2-7push
//2 4   2-4push 2-5pop 2-7pop
//1 5
//1 3   1-5pop 1-3push

/*
 * 샘플코드 참고 -> 생각한 방법은 맞았는데
 * 1. 기타의 줄수가 최대 6개라는 사실을 캐치못함
 * 2. 알고리즘을 구현하는 방식이 너무 정리되지 않게 짜여짐
 * */







#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<pair<int, int>> v;


vector<stack<int>> s(7);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int N, P; //음의 수 , 프렛의 수
    stack<int> stack;

    cin >> N >> P;

    v.assign(N, {0, 0});


    int l, p;//줄 번호, 프렛번호


    for (int i = 0; i < N; i++) {
        cin >> l >> p;
        v[i] = {l, p};


    }


    int ans = 0; //맨 처음 연주
    int line, fret;


    for (int i = 0; i < N; i++) {



        //현 입력
        line = v[i].first;
        fret = v[i].second;


        while (!s[line].empty() && s[line].top() > fret) {
            s[line].pop();
            ans++;
        }
        if (s[line].empty() || s[line].top() != fret) {
            ans++;
            s[line].push(fret);
        }
//
//
//        if (s[line].empty()) { //해당 줄 연주가 없음
////            cout << "line : " << line << " is empty" << "\n";
//            ans++;
//            s[line].push(fret);
//        } else {//s[line]스택에 뭔가 있음(이전 연주가 존재)
//
//            if (s[line].top() > fret) {
//
////                cout << "line : " << line << "\n";
////                cout << "line top: " << s[line].top() << "\n";
////                cout << "bigger than fret " << fret << "\n";
//
//                while (!s[line].empty() && s[line].top() > fret) {
//
////                    cout << "======start pop========" << "\n";
////                    cout << "now top is " << s[line].top() << "\n";
//
//
//                    s[line].pop();
//                    ans++;
//                }
//                //여기서
//                // 비었으면 -> 그냥 넣기
//                // 같으면 -> 아무것도 x
//                // 더커졌으면 -> 그냥 넣기
//                if (s[line].empty()) {
//
////                    cout << "======end pop========" << "\n";
////                    cout << " now empty " << "\n";
//                    s[line].push(fret);
//                    ans++;
//                } else {
////                    cout << "======start end========" << "\n";
////                    cout << "now top is " << s[line].top() << "\n";
//
//
//                    if (s[line].top() == fret) continue;
//                    s[line].push(fret);
//                    ans++;
//                }
//
//            } else if (s[line].top() < fret) {
//
////                cout << "line : " << line << "\n";
////                cout << "line top: " << s[line].top() << "\n";
////                cout << "less than fret " << fret << "\n";
//
//                ans++;
//                s[line].push(fret);
//            }
//            //같은 경우는 아무것도 안해도됨
//        }
//
////        cout << "===================================================" << "\n";


    }

    cout << ans;


}

