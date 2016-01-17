#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <climits>

using namespace std;

# define M_PI           3.14159265358979323846

void dd(string &s) {
    for (size_t i=0; i<s.length(); ++i) {
        if (s[i] == ',') {
            s[i] = '.';
            break;
        }
    }
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string LON;
    cin >> LON; cin.ignore();
    dd(LON);
    double LONR = stod(LON) * M_PI / 180;

    string LAT;
    cin >> LAT; cin.ignore();
    dd(LAT);
    double LATR = stod(LAT) * M_PI / 180;

    double dist = INT_MAX;
    string res;

    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);

        regex e("([[:digit:]]+);(.*);(.*);(.*);(.*);(.*)");
        smatch sm;
        regex_match(DEFIB.cbegin(), DEFIB.cend(), sm, e);
        //name - sm[2], lon - sm[5], lat - sm6
        string lon = sm[5];
        dd(lon);
        string lat = sm[6];
        dd(lat);

        double lonr = stod(lon) * M_PI / 180;
        double latr = stod(lat) * M_PI / 180;
        //cout <<lonr <<" " <<latr <<endl;
        double x = (lonr - LONR) * cos((latr + LATR) / 2);
        double y = latr - LATR;
        double d = sqrt(x*x + y*y) * 6371;
        if (d < dist) {
            dist = d;
            res = sm[2];
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << res << endl;
}
