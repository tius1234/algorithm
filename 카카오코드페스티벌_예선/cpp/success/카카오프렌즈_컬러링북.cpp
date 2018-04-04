// https://programmers.co.kr/learn/courses/30/lessons/1829?language=cpp


#include <iostream>
#include <vector>

using namespace std;

int floodFill(vector<vector<int>> &picture, int aa, int bb, int target) {

    int retVal = 1;
    picture[aa][bb] = 0;

    // 상
    if (aa - 1 >= 0 && picture[aa-1][bb] == target) {
        retVal += floodFill(picture, aa-1, bb, target);
    }

    // 하
    if (aa + 1 <= picture.size()-1 && picture[aa+1][bb] == target) {
        retVal += floodFill(picture, aa+1, bb, target);
    }

    // 좌
    if (bb - 1 >= 0 && picture[aa][bb-1] == target) {
        retVal += floodFill(picture, aa, bb-1, target);
    }

    // 우
    if (bb + 1 <= picture[aa].size()-1 && picture[aa][bb+1] == target) {
        retVal += floodFill(picture, aa, bb+1, target);
    }

    return retVal;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {

    int cateNum = 0;
    int maxFill = 0;
    vector<int> resultVec;
    for (int ii=0; ii<picture.size(); ii++) {
        for (int jj=0; jj<picture[ii].size(); jj++) {

            if (picture[ii][jj] == 0) {
                continue;
            }

            // 여기서 floodFill 알고리즘을 이용.
            int retVal = floodFill(picture, ii, jj, picture[ii][jj]);

            // 응답값으로 cateNum, maxFill
            cateNum += 1;
            maxFill = maxFill > retVal ? maxFill : retVal;
        }
    }

    resultVec.push_back(cateNum);
    resultVec.push_back(maxFill);

    return resultVec;
}

int main()
{
    int inputX = 6;
    int inputY = 4;

    vector<int> resultVec;

    vector< vector<int> > inputMatrix = {
        {1, 1, 1, 0},
        {1, 2, 2, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 3},
        {0, 0, 0, 3}
    };

    resultVec = solution(inputX, inputY, inputMatrix);

    printf("1 : %d\n", resultVec[0]);
    printf("2 : %d\n", resultVec[1]);

    return 0;
}
