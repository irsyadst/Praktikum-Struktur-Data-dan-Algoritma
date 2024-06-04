#include<iostream>

using namespace std;

main()
{
    char op;
    float num1, num2;

    cout<<"Masukan operasi bilangan : ";
    cin>>op;
    cout<<"Masukan bilangan 1 :";
    cin>>num1;
    cout<<"Masukan bilangan 2 : ";
    cin>>num2;

    switch (op)
    {
    case '+':
        cout<<num1+num2;
        break;

    case '/':
        cout<<num1/num2;
    break;

    case '-':
    cout<<num1-num2;
    break;

    case '*':
        cout<<num1*num2;
        break;
    
    default:
    cout<<"Error!";
        break;
    }
    return 0;
}