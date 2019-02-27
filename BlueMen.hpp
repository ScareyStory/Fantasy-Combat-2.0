/**************************************************************************
** Program Name: BlueMen.hpp
** Name:         Story Caplain
** Date:         02/07/19
** Description:  This is the implemntation file for the BlueMen class.
**************************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include <iostream>
#include "Character.hpp"

class BlueMen : public Character {

private:

protected:

public:

  BlueMen(int, int, int, int);
  
  int attacking();

  int defending();

  void setStrength(int);

  void recover();
};
#endif
