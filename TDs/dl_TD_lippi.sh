echo -e "Recherche de fichiers dans http://users.polytech.unice.fr/~lippi/cpp/td/"
# source : https://stackoverflow.com/a/26269730
wget -q -r -np -nH --cut-dirs=3 -R *.html* http://users.polytech.unice.fr/~lippi/cpp/td/
# -q : silencieux
# -r : récursivement
# -np : ne pas aller dans les répertoires du dessus
# -nH : ne pas sauvegarder les fichiers dans le dossier "hostname".
# --cut-dirs=3 : sauvegarde en omettant les 3 premiers dossiers ~lippi, cpp, td
# -R *.html* : exclure les fichiers .html
echo -e "Terminé !"
