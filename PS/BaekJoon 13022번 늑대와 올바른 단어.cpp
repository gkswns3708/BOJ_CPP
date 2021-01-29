#include <iostream>
using namespace std;
int main()
{
    char input = ' ';
    int count[4] = { 0 };

    while (input != '\n')
    {
        cin.get(input);
        if (input == 'w') count[0]++;
        else if (input == '\n') {
            if (count[0] == 0) {
                cout << 1;
                return 0;
            }
            else {
                cout << 0;
                return 0;
            }
        }
        else {
            if (input == 'o') {
                count[1]++;
                while (count[1] != count[0]) {
                    cin.get(input);
                    if (input != 'o') {
                        cout << 0;
                        return 0;
                    }
                    count[1]++;
                }
                while (count[2] != count[0]) {
                    cin.get(input);
                    if (input != 'l') {
                        cout << 0;
                        return 0;
                    }
                    count[2]++;
                }
                while (count[3] != count[0]) {
                    cin.get(input);
                    if (input != 'f') {
                        cout << 0;
                        return 0;
                    }
                    count[3]++;
                }
                for (int i = 0; i < 4; i++) count[i] = 0;
            }
            else{
                cout << 0;
                return 0;
            }
        }
    }
    return 0;
}