#include <iostream>
#include <string>

using namespace std;

int main() {
    int num;

    cin >> num;

    string s[num];
    bool anw[num];

    for(int i = 0; i < num; i++) {
        cin >> s[i];
    }

    for(int j = 0; j < num; j++) {
        long unsigned int idx = 0;
        int back = 0;

        // (100+1+ | 01)+
        while(s[j].length() > idx) {
            if(s[j].length() >= idx + 1) {
                if(s[j][idx] == '0' && s[j][idx + 1] == '1') {
                    back = 0;
                    idx += 2;
                    if(s[j].length() == idx) {
                        anw[j] = true;
                        break;
                    }
                    continue;
                }
            }
            if(s[j].length() >= idx + 3) {
                if(s[j][idx] == '1' && s[j][idx + 1] == '0') {
                    idx += 2;
                }
                else if(back != 0) {
                    idx = back;
                    back = 0;
                    continue;
                }
                else {
                    break;
                }

                while(s[j].length() > idx && s[j][idx] == '0') {
                    idx += 1;
                }

                while(s[j].length() > idx && s[j][idx] == '1') {
                    idx += 1;
                    if(s[j].length() == idx) {
                        anw[j] = true;
                        break;
                    }
                }

                if(s[j][idx - 2] == '1') {
                    back = idx - 1;
                }
            }
            else {
                break;
            }
        }
    }
    
    for(int k = 0; k < num; k++) {
        if(anw[k] == true) { 
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}