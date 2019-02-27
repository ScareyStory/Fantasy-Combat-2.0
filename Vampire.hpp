/**************************************************************************
** Program Name: Vampire.hpp
** Name:         Story Caplain
** Date:         02/06/19
** Description:  This is the implemntation file for the Vampire class.
**************************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include <iostream>
#include "Character.hpp"

class Vampire : public Character {

private:

protected:

public:

  Vampire(int, int, int, int);
  
  int attacking();

  int defending();

  void setStrength(int);

  void recover();

};
#endif
