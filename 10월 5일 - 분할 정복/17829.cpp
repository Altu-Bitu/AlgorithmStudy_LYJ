//
// 222 - 풀링
//


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> matrix;
matrix input;


//conquer : 2번째로 큰 수를 반환
void conquer(int size, int row, int col) {

    vector<int> combine = {0, 0, 0, 0};

/*
 * size 2인 경우
 * [0][1]
 * [2][3]
 *
 *
 * size 4인 경우
 * [0][ ][1][ ]
 * [ ][ ][ ][ ]
 * [2][ ][3][ ]
 * [ ][ ][ ][ ]
 *
 * 이렇게 하려고 size/2로 나눈만큼 더해서 4개 저장
 */
    int sub_size = size / 2;

    int _row[4] = {0, 0, sub_size, sub_size};
    int _col[4] = {0, sub_size, 0, sub_size};

    for (int i = 0; i < 4; i++) {
        combine[i] = input[row + _row[i]][col + _col[i]];
    }
    //
//    combine[0] = input[row][col];
//    combine[1] = input[row][col + sub_size];
//    combine[2] = input[row + sub_size][col];
//    combine[3] = input[row + sub_size][col + sub_size];

    //정렬
    sort(combine.begin(), combine.end(), greater<int>());

    // [0]부분에 2번쨰로 큰 값을 저장 -> 다음 size커졌을때 다들[0]기준으로 검사하려고
    input[row][col] = combine[1];

}

//input을 반으로 나누는 함수
void divide(int size, int row, int col) {

    //2개인 경우 구해서 리턴
    if (size == 2) {
        conquer(size, row, col);
        return;
    }


    //divide & combine?
    int sub_size = size / 2;
    //(0, 0), (0, ss), (ss, 0), (ss, ss)
    for (int i = 0; i <= sub_size; i += sub_size) {
        for (int j = 0; j <= sub_size; j += sub_size) {
            divide(sub_size, row + i, col + j); //subsize로 구하기
        }
    }
    conquer(size, row, col);//sub_size*2 (size)로 돌아와서 구하기
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

    divide(n, 0, 0);

    //최종적으로 [0][0]자리로 구해짐
    cout << input[0][0];

}
