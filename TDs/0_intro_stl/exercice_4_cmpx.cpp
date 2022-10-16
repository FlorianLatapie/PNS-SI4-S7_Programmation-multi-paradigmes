/*
Ecrire une fonction cmpx qui prend en arguments deux entiers et les échange s'ils ne sont pas
dans l'ordre croissant.
- Utiliser cette fonction pour écrire une fonction insert qui prend en arguments un entier n
et un vecteur d'entiers triés vec et insère n dans vec au bon endroit.
- Utiliser cette fonction pour écrire un programme qui lit une liste d'entiers sur l'entrée standard
et la trie dans l'ordre croissant.
- Sauriez-vous modifier le programme précédent afin qu'il fonctionne non seulement pour les
entiers mais pour tous les types où une relation d'ordre est définie ?
*/

#include <iostream>
#include <vector>

using namespace std;

void cmpx(int &a, int &b){
    if (a > b){
        int tmp = a;
        a = b;
        b = tmp;
    }
}

void insert(int n, vector<int> &vec){
    vec.push_back(n);
    for (int i = vec.size() - 1; i > 0; i--){
        cmpx(vec[i-1], vec[i]);
    }
}

int main()
{
    vector<int> vec;
    int n;
    while (cin >> n){
        insert(n, vec);
    }
    cout << "vec = [";
    for (int i : vec){
        cout << i << ", ";
    }
    cout << "]" << endl;
}