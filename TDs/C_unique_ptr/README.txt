1. Implémenter la classe Copiable qui :
- Possède un compteur statique initialisé à 1
- Possède un id en attribut
- A chaque nouvelle construction et/ou copie, attribue la valeur du compteur à l'id de la nouvelle instance, puis incrémente le compteur
- Affiche dans chacune de ses 4 opérations spéciales (Default constructor, Destructor, Copy constructor, Copy assignment) le nom de l'opération ainsi que l'id de l'instance


2. Implémenter la classe Movable qui :
- Possède toutes les caractéristiques de la classe Copiable
- Ajoute et affiche les 2 opérations spéciales de déplacement (Move constructor, Move assignment)

Note 1 : Contrairement aux copies, lors des déplacements on n'incrémente pas le compteur, à la place on "vole" l'id de l'ancienne instance, puis on réinitialise ce dernier à 0 (afin d'indiquer que l'ancienne instance n'est plus valide)
Note 2 : Le destructeur ne doit rien afficher si l'id est 0


3. Comparer 2_main_movable.out :
- avec 1_main_copiable.out, que constate-t-on ?
- avec 3_main_ptr.out, que constate-t-on ?


4. Implémenter la classe UniquePtr qui :
- Possède un pointeur vers un type template T en attribut
- Alloue la mémoire associée au pointeur dans ses constructeurs
- Désalloue la mémoire dans son destructeur
- Supprime les opérations de copie
- Implémente correctement les opérations de déplacement de sorte à éviter toute nouvelle allocation, ainsi que toute double désallocation


5. Comparer 3_main_ptr.out avec 4_main_uniqueptr.out
