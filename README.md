# TP Bases du Génie Logiciel -- Makefile & Tests

Le but de ce TP est de mettre en pratique les notions sur les Makefile et les tests unitaires dans un projet logiciel simple.
En fin de TP si nous avons le temps nous pourrons utiliser des outils de couverture de code, et réaliser des mesures de performance.

## Prérequis

Pour faire ce TP vous aurez besoin d'installer

- La bibliothèque [cmocka](https://cmocka.org/)
- Le compilateur `gcc` ou `clang`
- (optionnel) L'outil `gcov`


repenses:
Question 2

La fonction testée est :static int parse_args(int argc, char * argv[])
Les entrées de tests ont été choisies en les divisant en classes d’équivalences:

-Testant le nombre d'arguments:
1/Aucun argument n
2/Deux arguments n1 n2

-Testant les cas invalides
1/n=different d'entier 
2/n=un entier négatif
3/n=0

-Testant les cas valides
1/Argument n=un entier positif


Oui il manque des tests comme :
Les tests au limites (donner un n=tres grand chiffre positif par exemple ) et et etudier le comportement de la fonction
