#pragma once
#ifndef LIVRE_H
#define LIVRE_H

#include <iostream>
#include "date.h"
#include "auteur.h"
#include <vector>

class Livre{
private:
	std::string _titre;
	Auteur _auteur;
	std::string _langue;
	std::string _genre;
	Date _date_publication;
	long int _ISBN;
	std::vector<std::string> _liste_emprunteur;
	bool _dispo;
public:
	Livre(std::string titre,Auteur auteur,std::string langue,std::string genre,Date date_publication,long int ISBN,std::vector<std::string> liste_emprunteur);
	std::string get_titre() const;
	Auteur get_auteur() const;
	std::string get_langue() const;
	std::string get_genre() const;
	Date get_date_publication() const;
	long int get_ISBN() const;
	std::vector<std::string> get_liste_emprunteur() const;
	bool get_dispo() const;
	void set_dispo(bool a);
	void add_emprunteur(std::string identifiant);
};

std::ostream& operator<<(std::ostream& os, const Livre& livre);

#endif