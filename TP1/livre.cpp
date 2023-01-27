#include "livre.h"
#include "auteur.h"
#include <vector>

Livre::Livre(std::string titre,Auteur auteur,std::string langue,std::string genre,Date date_publication,long int ISBN,std::vector<std::string> liste_emprunteur) : _titre(titre), _auteur(auteur), _langue(langue), _genre(genre), _date_publication(date_publication), _ISBN(ISBN), _liste_emprunteur(liste_emprunteur){
_dispo = true;
}

std::string Livre::get_titre() const {
	return _titre;
}
Auteur Livre::get_auteur() const {
	return _auteur;
}
std::string Livre::get_langue() const {
	return _langue;
}
std::string Livre::get_genre() const {
	return _genre;
}
Date Livre::get_date_publication() const {
	return _date_publication;
}
long int Livre::get_ISBN() const {
	return _ISBN;
}
std::vector<std::string> Livre::get_liste_emprunteur() const {
	return _liste_emprunteur;
}
bool Livre::get_dispo() const {
	return _dispo;
}
void Livre::set_dispo(bool a){
	_dispo = a;
}
void Livre::add_emprunteur(std::string identifiant){
	_liste_emprunteur.push_back(identifiant);
	_dispo=false;
}

std::ostream& operator<<(std::ostream& os, const Livre& livre){
	os << std::endl;
	os << "Titre du livre : " << livre.get_titre() << std::endl;
	os << "Auteur : " << livre.get_auteur();
	os << "Date de publication : " << livre.get_date_publication().to_text() << std::endl;
	os << "Genre : " << livre.get_genre() << std::endl;
	os << "Langue originale : " << livre.get_langue() << std::endl;
	os << "Identifiant des anciens emprunteurs : ";
	for(std::string k : livre.get_liste_emprunteur()){
		os << k << " ,";
	}
	os << std::endl;
	return os;
}