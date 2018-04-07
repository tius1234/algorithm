// https://www.acmicpc.net/problem/1149


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solve(int n, int vIdx, int hIdx, vector< vector<int> > &house_map, vector< vector<int> > &dp_map) {

    if (n == vIdx) {
        return 0;
    }

    int &ret = dp_map[vIdx][hIdx];
    if (ret != -1) {
        return ret;
    }

    ret = pow(2, 31) - 1;
    if (vIdx == 0) {
        ret = min(ret, solve(n, vIdx+1, hIdx, house_map, dp_map) + house_map[vIdx][hIdx]);
    }
    ret = min(ret, solve(n, vIdx+1, (hIdx+1)%3, house_map, dp_map) + house_map[vIdx][(hIdx+1)%3]);
    ret = min(ret, solve(n, vIdx+1, (hIdx+2)%3, house_map, dp_map) + house_map[vIdx][(hIdx+2)%3]);

    return ret;
}

int main(){

    int n = 0;
    cin >> n;
    vector< vector<int> > dp_map (n, vector<int>(3, -1));
    vector< vector<int> > house_map (n, vector<int>(3, -1));

    for(int ii=0; ii<n; ii++)
        scanf("%d %d %d", &house_map[ii][0], &house_map[ii][1], &house_map[ii][2]);

    cout << solve(n, 0, 0, house_map, dp_map);

    return 0;
}