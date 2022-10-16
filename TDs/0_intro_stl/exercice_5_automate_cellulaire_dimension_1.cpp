/*
Ecrire un programme qui affiche l'évolution d'un automate cellulaire booléen de dimension 1 : chaque cellule contient un état booléen et à chaque transition son nouvel état dépend de l'état des cellules voisines. Toutes les cellules changent d'état en même temps. L'état initial sera tiré au hasard. Le nouvel état d'une cellure est calculé en faisant le ET logique entre ces deux voisines.
*/

#include <iostream>
#include <vector>

using namespace std;

// https://stackoverflow.com/questions/43329352/generating-random-boolean
bool randomBool()
{
    return 0 + (rand() % (1 - 0 + 1)) == 1;
}

void printBoolVec(vector<bool> vec)
{
    cout << "vec = [";
    for (int i : vec)
    {
        cout << i;
    }
    cout << "]" << endl;
}

int main()
{
    int nb_of_cells;
    cin >> nb_of_cells;

    vector<bool> cells(nb_of_cells);
    vector<bool> cells2(nb_of_cells);

    for (int i = 0; i < nb_of_cells; i++)
    {
        bool val = randomBool();
        cells[i] = val;
        cells2[i] = val;
    }

    printBoolVec(cells);

    // cout << "running sim" << endl;

    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 1)
        {
            for (int i = 1; i < nb_of_cells - 1; i++)
            {
                cells[i] = cells2[i - 1] && cells2[i + 1];
            }
            for (int i = 0; i<nb_of_cells ; i++){
                cells2[i] = cells[i];
            }
        }
        else
        {
            for (int i = 1; i < nb_of_cells - 1; i++)
            {
                cells2[i] = cells[i - 1] && cells[i + 1];
            }
            for (int i = 0; i<nb_of_cells ; i++){
                cells[i] = cells2[i];
            }
        }
        printBoolVec(cells);
    }

    return 0;
}