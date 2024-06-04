#include <iostream>
using namespace std;
// Main program
main()
{
    char op;
    float num1, num2;
    // It allows user to enter operator i.e. +, -, *, /
    cout << "Masukkan Operasi Bilangan : ";
    cin >> op;
    // It allow user to enter the operands
    cout <<  "Masukkan Bilangan 1 : ";
    cin >> num1;
    cout << "Masukkan Bilangan 2 : ";
    cin >> num2;
    // Switch statement begins
    switch (op)
    {
    // If user enter +
    case '+':
        cout << "Hasil dari " << num1 << " + " << num2 << " = " << num1 + num2;
        break;
    // If user enter -
    case '-':
        cout << "Hasil dari " << num1 << " - " << num2 << " = " << num1 - num2;
        break;
    // If user enter *
    case '*':
        cout << "Hasil dari " << num1 << " * " << num2 << " = " << num1 * num2;
        break;
    // If user enter /
    case '/':
        cout << "Hasil dari " << num1 << " / " << num2 << " = " << num1 / num2;
        break;
    // If the operator is other than +, -, * or /,
    // error message will display
    default:
        cout << "Error!";
    } // switch statement ends
    return 0;
}
