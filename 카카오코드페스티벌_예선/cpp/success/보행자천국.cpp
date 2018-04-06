// https://programmers.co.kr/learn/courses/30/lessons/1832


#include <vector>

using namespace std;

int MOD = 20170805;

void findRoad(int ii, int jj, vector<vector<int>> &city_map, vector< vector<int> > &hVec, vector< vector<int> > &vVec) {

    if (city_map[ii-1][jj-1] == 0) {

        hVec[ii][jj] = (hVec[ii][jj] + hVec[ii][jj-1] + vVec[ii-1][jj]) % MOD;
        vVec[ii][jj] = (vVec[ii][jj] + hVec[ii][jj-1] + vVec[ii-1][jj]) % MOD;
    }
    else if (city_map[ii-1][jj-1] == 1) {

        hVec[ii][jj] = 0;
        vVec[ii][jj] = 0;
    }
    else if (city_map[ii-1][jj-1] == 2) {

        hVec[ii][jj] = hVec[ii][jj-1];
        vVec[ii][jj] = vVec[ii-1][jj];
    }

    return;
}

int solution(int m, int n, vector<vector<int>> city_map) {

    vector< vector<int> > hVec(m+1, vector<int>(n+1, 0));
    vector< vector<int> > vVec(m+1, vector<int>(n+1, 0));

    hVec[1][1] = 1;
    vVec[1][1] = 1;

    int answer = 0;

    for (int ii=1; ii<m+1; ii++) {
        for (int jj=1; jj<n+1; jj++) {
            findRoad(ii, jj, city_map, hVec, vVec);
        }
    }

    return (hVec[m][n-1] + vVec[m-1][n]) % MOD;
}

int main()
{
    int m = 3;
    int n = 6;

    vector< vector<int> > city_map = {
        {0, 2, 0, 0, 0, 2},
        {0, 0, 2, 0, 1, 0},
        {1, 0, 0, 2, 2, 0}
    };

    int answer = 0;
    answer = solution(m, n, city_map);

    printf("answer : %d\n", answer);

    return 0;
}
