#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Node {
    map<char, Node*> children;
};

void addTelephone(string &telephone, int &counter, Node *head) {
    Node *node = head;
    for (size_t i = 0; i < telephone.length(); ++i) {
        char number = telephone.at(i);
        if (node->children[number] == NULL) {
            node->children[number] = new Node{};
            counter++;
        }
        node = node->children[number];
    }
}

int main()
{
    int counter = 0;
    Node *head = new Node{};
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        string telephone;
        cin >> telephone; cin.ignore();
        addTelephone(telephone, counter, head);
    }
    cout << counter << endl; // The number of elements (referencing a number) stored in the structure.

    return 0;
}
