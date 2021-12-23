#include <iostream>
#include <string>

using namespace std;

int main() {
    int num;

    cin >> num;

    string s[num];

    for(int i = 0; i < num; i++) {
        cin >> s[i];
    }

    for(int j = 0; j < num; j++) {
        cout << s[j] << endl;
    }

    return 0;
}