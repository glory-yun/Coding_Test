#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// 톱니바퀴 상태 저장 (4개, 각 8개의 톱니)
int gears[4][8];

// 특정 톱니바퀴를 회전시키는 함수
void rotate(int idx, int dir) {
    if (dir == 1) { // 시계 방향
        int temp = gears[idx][7];
        for (int i = 7; i > 0; i--) {
            gears[idx][i] = gears[idx][i - 1];
        }
        gears[idx][0] = temp;
    } else { // 반시계 방향
        int temp = gears[idx][0];
        for (int i = 0; i < 7; i++) {
            gears[idx][i] = gears[idx][i + 1];
        }
        gears[idx][7] = temp;
    }
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 톱니바퀴 초기 상태 입력
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            gears[i][j] = s[j] - '0'; // 0: N극, 1: S극
        }
    }

    int k;
    cin >> k;

    while (k--) {
        int idx, dir;
        cin >> idx >> dir;
        idx--; // 1-based index를 0-based로 변환

        // 1. 회전 결정 단계
        // 어떤 톱니가 어떤 방향으로 회전할지 미리 저장
        // 0: 회전 안 함, 1: 시계, -1: 반시계
        vector<int> rotation_dirs(4, 0);
        rotation_dirs[idx] = dir;

        // 왼쪽으로 회전 전파
        for (int i = idx; i > 0; i--) {
            // 현재 톱니(i)의 왼쪽 날(6번)과 왼쪽 톱니(i-1)의 오른쪽 날(2번) 비교
            if (gears[i][6] != gears[i - 1][2]) {
                rotation_dirs[i - 1] = -rotation_dirs[i]; // 반대 방향으로 회전
            } else {
                break; // 극이 같으면 연쇄 중단
            }
        }

        // 오른쪽으로 회전 전파
        for (int i = idx; i < 3; i++) {
            // 현재 톱니(i)의 오른쪽 날(2번)과 오른쪽 톱니(i+1)의 왼쪽 날(6번) 비교
            if (gears[i][2] != gears[i + 1][6]) {
                rotation_dirs[i + 1] = -rotation_dirs[i]; // 반대 방향으로 회전
            } else {
                break; // 극이 같으면 연쇄 중단
            }
        }

        // 2. 회전 실행 단계
        // 결정된 정보에 따라 모든 톱니바퀴를 한 번에 회전
        for (int i = 0; i < 4; i++) {
            if (rotation_dirs[i] != 0) {
                rotate(i, rotation_dirs[i]);
            }
        }
    }

    // 최종 점수 계산
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        if (gears[i][0] == 1) { // 12시 방향이 S극(1)인 경우
            sum += pow(2, i);
        }
    }

    cout << sum << endl;

    return 0;
}