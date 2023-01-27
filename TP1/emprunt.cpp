#include <iostream>
#include "emprunt.h"
#include "date.h"

Emprunt::Emprunt(Date date_emprunt, int ISBN, std::string identifiant) : _date_emprunt(date_emprunt), _ISBN(ISBN), _identifiant(identifiant){
}
Date Emprunt::get_date_emprunt() const{
	return _date_emprunt;
}
int Emprunt::get_ISBN() const{
	return _ISBN;
}
std::string Emprunt::get_identifiant() const{
	return _identifiant;
}