#pragma once
#ifndef AUTEUR_H
#define AUTEUR_H


#include <iostream>
#include "date.h"

class Auteur{
private:
	std::string _identifiant_auteur;
	std::string _nom;
	std::string _prenom;
	Date _date_naissance;
public:
	Auteur(std::string identifiant_auteur, std::string nom, std::string prenom, Date date_naissance);
	std::string get_identifiant_auteur() const;
	std::string get_nom() const;
	std::string get_prenom() const;
	Date get_date_naissance() const;
};
std::ostream& operator<<(std::ostream& os, const Auteur& auteur);

#endif