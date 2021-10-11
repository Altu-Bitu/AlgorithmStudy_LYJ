//
// 222 - 풀링
//


#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int>> matrix;
matrix input;


//2x2 matrix -> 1x4 vector 로 (정렬해서 2번쨰로 큰값 찾기)
vector<int> makeArr(int row, int col) {
    vector<int> v(4, 0);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            v[i + j] = input[i + row][j + col];
        }
    }

    return v;
}

//conquer 1x4 사이즈에서 2번째로 큰 수를 반환
int conquer(vector<int> combine) {

    sort(combine.begin(), combine.end(), greater<int>());
    return combine[1];
}

//input을 반으로 나누는 함수
matrix divide(int size, int row, int col, int num) {
    vector<int> combine = {0, 0, 0, 0};

    if (size == 1) return input[row][col];

    if (size == 2) {
        makeArr(row, col);
        sort(v.begin(), v.end(), greater<int>());
        combine[num] = v[1];
        return combine[num];
        //두번째로 큰 수는 combine[1]

    }

    int sub_size = size / 2;
    int num = 0;
    //num 0:(0, 0), 1:(0, ss), 2:(ss, 0), 3:(ss, ss)
    for (int i = 0; i <= sub_size; i += sub_size) {
        for (int j = 0; j <= sub_size; j += sub_size) {
            int sub = divide(sub_size, row + i, col + j, num);
            combine[num] = sub;
            num++;

        }
    }
    divide()

}


int main() {


    int n;
    cin >> n;

    input.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }


    divide(n);

}
