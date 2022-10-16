/*
Ecrire un programme qui affiche l'évolution d'un automate cellulaire booléen de dimension 1 : chaque cellule contient un état booléen et à chaque transition son nouvel état dépend de l'état des cellules voisines. Toutes les cellules changent d'état en même temps. L'état initial sera tiré au hasard. Le nouvel état d'une cellure est calculé en faisant le ET logique entre ces deux voisines.
*/

#include <iostream>
#include <vector>
#include <random>

using namespace std;

void printBoolVec(vector<bool> vec)
{
    for (int i : vec)
    {
        cout << i;
    }
    cout << endl;
}

// https://stackoverflow.com/questions/43329352/generating-random-boolean
bool randomBool()
{
    return 0 + (rand() % (1 - 0 + 1)) == 1;
}

int main()
{
    int nb_of_cells;
    cin >> nb_of_cells;

    vector<bool> vec(nb_of_cells);

    for (int i = 0; i < nb_of_cells; i++){
        vec[i] = randomBool();
    }

    printBoolVec(vec);

    for(int i =0 ; i < 10; i++){
        vector<bool> vec2(nb_of_cells);
        for (int i = 0; i < nb_of_cells; i++){
            vec2[i] = vec[(i-1+nb_of_cells)%nb_of_cells] && vec[(i+1)%nb_of_cells];
        }
        vec = vec2;
        printBoolVec(vec2);
    }
}