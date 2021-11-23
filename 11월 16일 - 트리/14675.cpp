//
// 14675번 - 단절점과 단절선
//

#include <iostream>
#include <vector>


using namespace std;

vector<int> v;

string isDivide(int type, int vertex) {
    if (type == 2) return "yes";
    else {
        if (v[vertex] > 1) return "yes"; //연결된 정점이 2개 이상이면 단절점
        else return "no";
    }
}


int main() {
    cin.tie(NULL); //cin , cout의 묶음을 풀어줌
    ios_base::sync_with_stdio(false); //c, c++버퍼를 분리


    int n, m;

    cin >> n;

    v.assign(n + 1, 0); //연결된 vertex수

    int a, b;
    for (int i = 1; i <= n - 1; i++) {
        cin >> a >> b;//a->b
        v[a]++;
        v[b]++;
    }


    cin >> m;

    while (m--) {
        cin >> a >> b;

        cout << isDivide(a, b) << "\n";


    }

}

