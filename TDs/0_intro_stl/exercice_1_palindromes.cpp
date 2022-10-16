/*
Un palindrome est une chaîne de caractères qui se lit de la même manière de gauche à droite et de
droite à gauche : otto, madam... Ecrire un programme qui lit une chaîne de caractères sur l'entrée
standard, vérifie s'il s'agit d'un palindrome et affiche le résultat.
*/
#include <iostream>

using namespace std;

int main() {
    cout << "Entrez un mot : ";
    
    string mot;
    cin >> mot;
    
    bool palindrome = false;

    for (int i = 0; i < (int) mot.length() / 2; i++) {
        if (mot[i] == mot[mot.length() - i - 1]) {
            palindrome = true;
        } else {
            palindrome = false;
            break;
        }
    }

    cout << "Ce mot est un palindrome : " << (palindrome?"oui":"non") << endl;
    
    return 0;
}