#include <iostream>
#include <string>
using namespace std;

void generate(int openings, int closings, string str) {
    if (openings == 0 && closings == 0) {
        cout << str << endl;
    }
    else if (openings > closings) {
        return;
    }
    else if(openings <0) return;
    
    generate(openings, closings - 1, str + ")");
    generate(openings - 1, closings, str + "(");
    
}

int main() {
    generate(3, 3, "");
    return 0;
}
