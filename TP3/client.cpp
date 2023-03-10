
#include "client.h"

Client::Client(std::string identifiant, std::string nom, std::string prenom, std::vector<Produit> panier_achat) : _identifiant(identifiant), _nom(nom), _prenom(prenom), _panier_achat(panier_achat) {
}
std::string Client::get_identifiant() const{
	return _identifiant;
}
std::string Client::get_nom() const{
	return _nom;
}
std::string Client::get_prenom() const{
	return _prenom;
}
std::vector<Produit> Client::get_panier_achat() const{
	return _panier_achat;
}
void Client::ajouter_au_panier(Produit produit){
	produit.quantite_produit(1);
	_panier_achat.push_back(produit);
}
void Client::vider_panier(){
	_panier_achat = {};
}
void Client::quantite_produit_panier(Produit produit,int quantite){
	for(Produit& p : _panier_achat){
		if(p.get_titre()==produit.get_titre()){
			p.quantite_produit(quantite);
		}
	}
}
void Client::supprimer_produit_panier(Produit produit){
	int j=0;
	int k=-1;
	for(Produit& p : _panier_achat){
		if(p.get_titre()==produit.get_titre()){
			k=j;
		}
		j++;
	}
	if(k==-1){
		std::cout << "Le produit n'est pas dans le panier." << std::endl;
	}
	else{
		_panier_achat.erase(_panier_achat.begin()+k);
	}
}

void Client::afficher_panier_achat(){
	std::string ligne =
      "--------------------------------------------------------------------------";
    std::cout << ligne << std::endl;
    std::cout << "| Panier : " << _nom;
	std::cout << " ";
	std::cout << _prenom;
    std::cout << " |" << std::endl;
    std::cout << "--------------------------------------------------------------------------"
            << std::endl;
    for(Produit p : _panier_achat){
		std::cout << "| " << p << "  |" << std::endl;
	}
	std::cout << ligne << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Client& client){
	os << "| Nom du client : " << client.get_nom();
	for(int k=client.get_nom().size();k<55;k++){
		os << " ";
	}
	os << "|" << std::endl;
	os << "| Prénom de client : " << client.get_prenom();
	for(int k=client.get_prenom().size();k<52;k++){
		os << " ";
	}
	os << "|" << std::endl;

	return os;
}

