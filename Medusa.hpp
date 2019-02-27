/**************************************************************************
** Program Name: Medusa.hpp
** Name:         Story Caplain
** Date:         02/07/19
** Description:  This is the implemntation file for the Medusa class.
**************************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include <iostream>
#include "Character.hpp"

class Medusa : public Character {

private:

protected:

public:

  Medusa(int, int, int, int);
  
  int attacking();

  int defending();

  void setStrength(int);

  void recover();
};
#endif
