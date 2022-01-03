#include <iostream>
#include <vector>

using namespace std;

int check_vow_con(char c) {
    switch(c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        return 1;
        default:
        return 0;
    }
}

void check_print(vector<char> comb) {
    int vow = 0;
    int con = 0;
    for(int i = 0; i < comb.size(); i++) {
        if(check_vow_con(comb[i])) {
            vow += 1;
        }
        else {
            con += 1;
        }
    }
    if(vow >= 1 && con >= 2) {
        for (int j = 0; j < comb.size(); j++) {
            cout << comb[j];
        }
        cout << endl;
    }
    return;
}

void combination(vector<char> cha, vector<char> comb, int length, int idx, int num) {
    if(length == 0) {
        check_print(comb);
    }
    else if(num == cha.size()) {
        return;
    }
    else {
        comb[idx] = cha[num];
        combination(cha, comb, length - 1, idx + 1, num + 1);

        combination(cha, comb, length, idx, num + 1);
    }
}

int main() {
    int length, num;

    cin >> length >> num;
    
    vector<char> cha(num);
    vector<char> comb(length);

    for(int i = 0; i < num; i++) {
        cin >> cha[i];
    }

    for(int i = 0; i < cha.size() - 1; i++) {
        for(int j = 0; j < cha.size() - 1 - i; j++) {
            if(cha[j] > cha[j + 1]) {
                char tmp = cha[j];
                cha[j] = cha[j + 1];
                cha[j + 1] = tmp;
            }
        }
    }

    combination(cha, comb, length, 0, 0);

    return 0;
}