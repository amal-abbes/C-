#include <iostream>
#include<string>

using namespace std;

int main()
{
    cout << "Quel est votre nom ?" << endl;
    string nomutilisateur ("Sans nom");
    getline(cin,nomutilisateur);
    cout << "Combient vaut pi ?" << endl;
    double piutilisateur (-1.);
    cin >> piutilisateur;
    cout << "Vous vous appelez " << nomutilisateur << " et vous pensez que pi vaut " << piutilisateur << "." << endl;
    return 0;
}
