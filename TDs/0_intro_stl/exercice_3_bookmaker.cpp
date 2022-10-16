/*
Un bookmaker enregistre dans un fichier chacune de ses transactions sous forme d'une ligne contenant le nom d'un client et une somme positive si le client lui doit de l'argent et négative sinon.
- Définir un nouveau type struct Bookrecord permettant de stocker une transaction ie un
nom de client et une somme d'argent.
- Ecrire un programme qui lit un fichier de transactions et les enregistre dans un vecteur où
chaque élément du vecteur contient une transaction.
- Afficher le contenu de ce vecteur sur la sortie standard.
- Entrer dans une boucle où l'on lit sur l'entrée standard un nom de client et l'on affiche la
somme algébrique correspondant aux montants concernant ce client. La boucle se termine sur
le caractère fin de fichier.
- Définir les opérateurs d'entrées/sorties pour un struct Bookrecord.
- Modifier le programme précédent afin d'utiliser ces nouveaux opérateurs.
*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Bookrecord
{
    string nom;
    double montant;
};

int main()
{
    ifstream is("transactions.txt");

    vector<Bookrecord> all_records;
    string nom; 
    double montant; 

    while (is >> nom >> montant)
    {
        Bookrecord book;
        book.nom = nom;
        book.montant = montant; 
        all_records.push_back(book);
    }

    for(Bookrecord book : all_records){
        cout << book.nom << ":" << book.montant << endl;
    }

    string recherche; 
    cin >> recherche; 
    int somme_recherche = 0;

    for(Bookrecord book : all_records){
        if (book.nom == recherche){
            somme_recherche += book.montant;
        }
    }

    cout << somme_recherche;

    return 0;
}
