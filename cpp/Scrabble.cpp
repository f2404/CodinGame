#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int count_p(const string &s) {
    static vector<string> points;
    points.push_back("eaionrtlsu"); //1
    points.push_back("dg");
    points.push_back("bcmp");
    points.push_back("fhvwy");
    points.push_back("k");
    points.push_back("jx");
    points.push_back("qz"); //7
    int res = 0;
    for (size_t i=0; i<s.length(); ++i) {
        for (size_t j=0; j<7; ++j) {
            if (points[j].find(s[i]) != string::npos) {
                res += j+1;
                break;
            }
        }
    }
    return res;
}

int main()
{
    int N;
    cin >> N; cin.ignore();
    vector<string> words;
    words.reserve(N);
    string res;
    int max_p = 0;

    for (int i = 0; i < N; i++) {
        string W;
        getline(cin, W);
        words.push_back(W);
    }

    string LETTERS;
    getline(cin, LETTERS);

    for (int i=0; i<N; ++i) {
        string set = LETTERS;
        bool valid = true;
        for (size_t j=0; j<words[i].length(); ++j) {
            size_t pos = set.find(words[i][j]);
            if (pos == string::npos) {
                valid = false;
                break;
            } else {
                set.erase(pos, 1);
            }
        }
        if (valid) {
            int p = count_p(words[i]);
            if (p > max_p) {
                res = words[i];
                max_p = p;
            }
        }
    }

    cout << res << endl;
}
