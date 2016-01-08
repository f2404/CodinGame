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
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    if (!n) {
        cout <<0 <<endl;
        return 0;
    }

    string delimiter = " ";
    const size_t delim_len = delimiter.length();
    size_t pos;
    string ress;
    int resi = INT_MAX;

    string temps; // the n temperatures expressed as integers ranging from -273 to 5526
    getline(cin, temps);
    temps += ' '; // parse last temp

    while ((pos = temps.find(delimiter)) != string::npos) {
        string ts = temps.substr(0, pos);
        int ti = stoi(ts);
        int ati = abs(ti);
        //cout <<ti <<" " <<ati <<endl;
        if (ati < resi || ati == resi && ti > 0) {
            resi = ati;
            ress = ts;
        }
        temps.erase(0, pos + delim_len);
    }
    cout <<ress <<endl;
}
