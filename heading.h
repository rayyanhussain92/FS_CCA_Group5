//Header files used for input/output, formatting, file handling
//containers, and input validation
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;

//Creates a line using a specific character
string line(char c, int n) {
    return string(n, c);
}

//Displays formatted headings throughout the program
void heading(const string& t) {

    int w = 60;
    int p = (w - t.size()) / 2;

    cout << "\n" << line('=', w) << "\n";

    if (p > 0)
        cout << line(' ', p);

    cout << t << "\n";
    cout << line('=', w) << "\n";
}