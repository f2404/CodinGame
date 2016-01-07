#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    vector<int> vs;
    int n, minv, minvi, maxv, maxvi, p = 0;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v; cin.ignore();
        //cout <<v <<endl;
        vs.push_back(v);
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    if (vs[0] > vs[1]) {
        maxv = vs[0]; maxvi = 0;
        minv = vs[1]; minvi = 1;
    } else {
        maxv = vs[1]; maxvi = 1;
        minv = vs[0]; minvi = 0;
    }
    p = (minvi > maxvi) ? minv - maxv : 0;
    if (n == 2) {
        cout <<p <<endl;
        return 0;
    }

    for (size_t i=2; i<vs.size(); ++i) {
        if (vs[i] > maxv) {
            maxv = vs[i];
            maxvi = i;
            minv = INT_MAX;
        } else if (vs[i] < minv) {
            minv = vs[i];
            minvi = i;
            if (minv - maxv < p && minvi > maxvi) {
                p = minv-maxv;
                //cerr <<"p" <<endl;
            }
        }
    }
    cout << p << endl;
}
