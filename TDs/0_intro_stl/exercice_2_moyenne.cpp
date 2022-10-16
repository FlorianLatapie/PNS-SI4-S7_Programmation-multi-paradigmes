/*
-  Ecrire un programme qui lit une liste de notes sur l'entrée standard et afiche leurs somme
et leurs moyenne.
-  Sauriez-vous modifier le programme précédent afin que la liste de notes soit lues dans un
fichier ?
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "Entrez les notes : " << endl;

    double somme = 0;
    int nb_notes = 0;
    
    double notes; 
    while(cin>>notes){
        somme += notes;
        nb_notes ++; 
    }
    
    cout << (somme/nb_notes) << endl;
    return 0;
}