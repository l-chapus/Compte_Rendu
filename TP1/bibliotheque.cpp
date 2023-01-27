#include "bibliotheque.h"
#include "livre.h"
#include "auteur.h"
#include "lecteur.h"
#include <vector>
#include <iostream>

Bibliotheque::Bibliotheque(std::vector<Livre> livres, std::vector<Auteur> auteurs, std::vector<Lecteur> lecteurs): _livres(livres), _auteurs(auteurs), _lecteurs(lecteurs){

}
std::vector<Livre> Bibliotheque::get_livre() const {
	return _livres;
}
std::vector<Auteur> Bibliotheque::get_auteur() const {
	return _auteurs;
}
std::vector<Lecteur> Bibliotheque::get_lecteur() const {
	return _lecteurs;
}
void Bibliotheque::add_lecteur(Lecteur L1){
	_lecteurs.push_back(L1);
}
void Bibliotheque::add_auteur(Auteur A){
	_auteurs.push_back(A);
}
void Bibliotheque::add_livre(Livre L2){
	_livres.push_back(L2);
}

void Bibliotheque::emprunter(Date date_emprunt,Livre& livre_emprunter,Lecteur& lecteur){
	if(livre_emprunter.get_dispo()){
		lecteur.add_ISBN(livre_emprunter.get_ISBN());
		livre_emprunter.add_emprunteur(lecteur.get_identifiant());
	}
	else{
		std::cout << "Le livre demandé n'est pas disponible (" << livre_emprunter.get_titre() << ").\n";
	}
}
void Bibliotheque::restituer(Date date_restitution,Livre& livre_restituer,Lecteur& lecteur){
	for(long int k : lecteur.get_liste_ISBN()){
		if(k == livre_restituer.get_ISBN()){
			livre_restituer.set_dispo(true);
			lecteur.remove_ISBN(livre_restituer.get_ISBN());
		}
	}
}
void Bibliotheque::chercherLivresAvecAuteur(Auteur auteur) const {
	std::cout << "Les livres de " << auteur.get_nom() << " que la bibliothèque possède sont : \n";
	for(Livre k:_livres){
		if(k.get_auteur().get_nom()==auteur.get_nom()){
			std::cout << "   " << k.get_titre() << std::endl;
		}
	}
}