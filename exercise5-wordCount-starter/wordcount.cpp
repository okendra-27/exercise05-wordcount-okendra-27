#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;


int main() {
    string filename = "mobydick.txt";
    ifstream inFile;
    inFile.open(filename);

    if (!inFile) {
        cerr << "Could not open file.\n";
        return 1;
    }

    unordered_map<string, int> times;
    string word;

    while (inFile >> word) {
        for (char &c : word) {
            c = tolower(static_cast<unsigned char>(c));
        }

        times[word]++;
    }

    vector<pair<string, int>> items(times.begin(), times.end());

    sort(items.begin(), items.end(),
         [](const auto &a, const auto &b) {
             return a.second > b.second;   // sort by timesuency descending
         });

    for (int i = 0; i < 10 && i < items.size(); i++) {
        cout << (i + 1) << ". "
             << items[i].first << ": "
             << items[i].second << " times\n";
    }

    return 0;
}
