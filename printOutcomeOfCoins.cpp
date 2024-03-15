#include <bits/stdc++.h>
using namespace std;

void printAllSubstring(string given, string str, int idx) {
    if (idx == given.size()) {
        cout << str << endl;
        return;
    }
    // Base condition
    printAllSubstring(given, str + given[idx], idx + 1);
    printAllSubstring(given, str, idx + 1);
    // Append ASCII value in the third recursive call
    int ascii = static_cast<int>(given[idx]); // Convert character to ASCII
    printAllSubstring(given, str + to_string(ascii), idx + 1);
}

int main() {
    string str = "HELLOHARSH";
    printAllSubstring(str, "", 0);
    return 0;
}
