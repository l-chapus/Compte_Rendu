#pragma once
#ifndef EMPRUNT_H
#define EMPRUNT_H

#include <iostream>
#include "date.h"

class Emprunt{
private:
	Date _date_emprunt;
	int _ISBN;
	std::string _identifiant;
public:
	Emprunt(Date date_emprunt, int _ISBN, std::string identifiant);
	Date get_date_emprunt() const;
	int get_ISBN() const;
	std::string get_identifiant() const;
};

#endif