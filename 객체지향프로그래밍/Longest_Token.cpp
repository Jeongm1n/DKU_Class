#include<iostream>
#define MAXSIZE 200
using namespace std;

class stringclass {
private:
    char astring[MAXSIZE];
    int itslength;
public:
    int token_length();
};
int stringclass::token_length() {
    gets_s(astring);
    int count = 0;
    int itslength = 0;
    int max = 0;
    for (itslength = 0; astring[itslength]; itslength++);
    for (int i = 0; i <= itslength; i++) {
        if (astring[i] != ' ' && astring[i] != NULL)
            count++;
        if (astring[i] == ' ' || astring[i] == NULL) {
            if (count > max)
                max = count;
            count = 0;
        }
    }
    return max;
}

int main() {
    stringclass C;
    cout << C.token_length() << endl;

    return 0;
}