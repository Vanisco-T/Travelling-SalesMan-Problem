# Travelling-SalesMan-Problem
Implementation du problem de voyageur de commerce en c
# Description,formalisation 
La description du probleme et formalisation sont disponible<br>
dans le rapport du projet
# Methode de resolution
 Nous avons representer le graph du voyageur de commerce par une matrice d'adjacence,<br> donc l'element  à  l'indice i,j est le coût  pour quitter du sommet i au sommet j.
# Methode sequentielle
1.On commence par générer la matrice d'adjacence ou bien de lire depuis un fichier.<br>
2.Ensuite par stocker tous les sommet dans un tableau en eliminant la sommet de depart<br>
3.Puis on calcule le coût initiale en utilisant l'ordre du tableau initiale.La mis à jour du coût se fait en permutant le tableau initiale pour trouver toutes les permutation possible <br>
4.Enfin, on retourne le coût trouver et le meilleur chemin
# Methode Multithreadee


# Compilation
  1.Pour la compilation vous devez avoir gcc deja installer <br>
  2.Taper la commande suivant pour compile
  # 3. make  ou make tsp

# Execution 
1 Si le graph doit etre generer lors de execution
# ./tsp g nombre_de_ville ville_depart nombre_thread
exx: ./tsp 6 1 3 
# un voyageur de commerce de 6 commencant a la ville 1 et utilise 3 thread
2 Si le graph est deja generer et present dans le fichier graph.txt
# ./tsp u nombre_de_ville ville_depart nombre_thread
exx: ./tsp 6 1 3 
# un voyageur de commerce de 6 commencant a la ville 1 et utilise 3 thread

# Resultat et courbe 
Le resultat et les different courbes sont present dans le rapport
 






