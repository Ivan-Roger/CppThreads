#ifndef TABLEAU_HPP_
#define TABLEAU_HPP_

#include <vector>
#include <random>

class Tableau
{
friend class CalculateurMonoVecteur;
friend class CalculateurBiVecteur;

public :
  Tableau();
  virtual ~Tableau();     // nécessaire avec méthode virtuelle

  virtual void reserver(const unsigned long numero, const unsigned long iter,
                        int& poids_somme, int& poids_multiplication) = 0;
  virtual void liberer(const unsigned long numero) = 0;

  // Pour chaque vecteur du tableau, l'uniformité des entrées est testée et la valeur commune affichée.
  void afficher_etat_final(void);

  static const unsigned long NB_VALEURS=40;

protected :
  std::vector<std::vector<int>> vecteurs; // bandes constituant le tableau
  std::default_random_engine gen;

  // pour vérifier la contrainte 1 réservation par itération
  std::vector<int> tickets;
  void verifier_une_reservation_par_iteration(const unsigned long numero, const unsigned long iter);

  // récupération des poids pour l'itération
  void recuperer_poids(const unsigned long iter, int& poids_somme, int& poids_multiplication);

  // Le tableau est cylindrique : la suite des bandes est circulaire.
  unsigned long gauche(const unsigned long numero);
  unsigned long droite(const unsigned long numero);
};

#endif // TABLEAU_HPP_
