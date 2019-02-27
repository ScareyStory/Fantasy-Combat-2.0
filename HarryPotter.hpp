/**************************************************************************
** Program Name: HarryPotter.hpp
** Name:         Story Caplain
** Date:         02/07/19
** Description:  This is the implemntation file for the HarryPotter class.
**************************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include <iostream>
#include "Character.hpp"

class HarryPotter : public Character {

private:

  int theBoyWhoLived = 1;

protected:

public:

  HarryPotter(int, int, int, int);
  
  int attacking();

  int defending();

  void setStrength(int);

  void recover();
};
#endif
