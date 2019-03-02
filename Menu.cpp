/***************************************************************************
** Program name: Menu.cpp
** Name:         Story Caplain
** Date:         02/21/19
** Description:  This cpp file is an easily modifiable menu function.
***************************************************************************/
#include "Menu.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int Menu(std::string name) {

  int choice = 0;

  cout << "\n" <<  name << " choose a character!" << endl;

  cout << "\nOption 1: The Vampire" << endl;
  cout << "\tThe vampure is suave, debonair, but vicious"   << endl;
  cout << "\tand surprsingly resilient. Vampires have a "   << endl;
  cout << "\tgood chance in each round to charm their   "   << endl;
  cout << "\topponent into not attacking.\n\n";

  cout << "Option 2: The Barbarian" << endl;
  cout << "\tThe Barbarian is herculean and carries with"   << endl;
  cout << "\thim a large sword. He wears only shoes, a  "   << endl;
  cout << "\tleather skirt, and a bandolier.\n\n";

  cout << "Option 3: The Blue Men" << endl;
  cout << "\tA group of tough quick 6 inch tall men. They"  << endl;
  cout << "\tcan crawl inside enemy clothing and inflict"   << endl;
  cout << "\tlots of damage. They are also hard to hit.\n\n";

  cout << "Option 4: Medusa" << endl;
  cout << "\tScrawny, but with hair made of snakes. These " << endl;
  cout << "\tsnakes assist her. If she makes eye contact"   << endl;
  cout << "\twith her opponent she kills them on the spot.\n\n";

  cout << "Option 5: Harry Potter" << endl;
  cout << "\tHarry Potter is a wizard. However, he has a "  << endl;
  cout << "\tunique ability. If Harry Potter's health "     << endl;
  cout << "\treaches zero he is revived, as long as he"     << endl;
  cout << "\thasn't been revived once already.\n\n";

  cout << "\nChoice (enter a number): ";
  int val = 1;
  cin  >> choice;
  while(val==1) {
    if(cin.fail() || choice < 1 || choice > 5) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "\nOops! Invalid input." << endl;
      cout << "Enter a 1, 2, 3, 4 or 5: ";
      cin  >> choice;
    }
    else if(!cin.fail()) {
      val = 0;
    }
  }
  cin.clear();
  cin.ignore(256, '\n');

  return choice;

}
