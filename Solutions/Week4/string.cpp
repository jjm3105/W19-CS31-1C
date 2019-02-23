#include <iostream>
using namespace std;


bool syntax(string train) {
    int end = 0;
    int start = end;

    while (start < train.size()) {
        string car = "";

        while (end < train.size()) {
            if (train[end] == '-')
                break;
            car += train[end];
            end++;
        }

        if (car.size() != 4)
            return false;
        if (!isalpha(car[0]))
            return false;
        if (!isdigit(car[1]) || !isdigit(car[2]))
            return false;
        if (!isalpha(car[3]))
            return false;

        while (end < train.size()) {
            if (train[end] != '-')
                break;
            end++;
        }

        start = end;
    }

    return true;
}

void tally(string train, string color, int& seats) {
    
    seats = 0;

    for (int i = 0; i < train.size(); i++) {
        if (train[i] == color[0]) {
            if (i != 0) {
                if (train[i-1] != '-')
                    continue;
            }

            if (train[i+3] != 'P')
                continue;

            int one = train[i+2] - '0';
            int ten = train[i+1] - '0';
            ten *= 10;

            seats += ten;
            seats += one;
        }
    }
}

int main()
{
    string train = "G37C--B15P----Y39P-B18C---B23P";
    string color = "B";
    int seats;

    if(syntax(train))
        tally(train, color, seats);

    cout << seats << endl;
}