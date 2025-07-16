#include <iostream>
#include "matriz.h"

using namespace std;

int main() {
    Matriz X(2,3);
    Matriz Y(2,3);
    Matriz Z(3,2);

    cin >> X;
    cin >> Y;
    cin >> Z;

    X += Y;

    cout << X << endl;
    cout << (Y == X) << endl << endl;
    cout << X * Z << endl;
    cout << Z * 3 << endl;
    cout << X.getTransposta();

    return 0;
}