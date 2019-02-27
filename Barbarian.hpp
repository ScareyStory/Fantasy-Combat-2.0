/**************************************************************************
** Program Name: Barbarian.hpp
** Name:         Story Caplain
** Date:         02/07/19
** Description:  This is the implemntation file for the Barbarian class.
**************************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include <iostream>
#include "Character.hpp"

class Barbarian : public Character {

private:

protected:

public:

  Barbarian(int, int, int, int);
  
  int attacking();

  int defending();

  void setStrength(int);

  void recover();
};
#endif
