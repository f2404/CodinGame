#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int R;
    cin >> R; cin.ignore();
    int L;
    cin >> L; cin.ignore();

    string res = to_string(R);
    for (int i=1; i<L; ++i) {
        int cnt = 0;
        string rc, tok, n;
        vector<string> rps;
        stringstream ss(res);
        while(getline(ss, tok, ' ')) rps.push_back(tok);
        for (int j=0; j<rps.size(); ++j) {
            if (n.compare(rps[j]) != 0) {
                if (cnt) {
                    if (!rc.empty()) rc += " ";
                    rc += to_string(cnt);
                    rc += " ";
                    rc += n;
                }
                cnt = 1;
                n = rps[j];
            } else {
                cnt++;
            }
        }
        if (cnt) {
            if (!rc.empty()) rc += " ";
            rc += to_string(cnt);
            rc += " ";
            rc += n;
        }
        //cout <<rc <<endl;
        res = rc;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << res << endl;
}
