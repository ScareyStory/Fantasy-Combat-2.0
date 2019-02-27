/**************************************************************************
** Program Name: Barbarian.hpp
** Name:         Story Caplain
** Date:         02/07/19
** Description:  This is the .cpp file for the Barbarian class.
**               It handles its specific attack and defend functions.
**************************************************************************/
#include <iostream>
#include <random>
#include "Barbarian.hpp"

Barbarian::Barbarian(int atk, int def, int arm, int str) : 
  Character(atk,def,arm,str) {}

//returns a value 2 to 12
int Barbarian::attacking() {

  int die1 = rand();
  int die2 = rand();

  //two six-sided dice means range is 2-12
  die1 = (die1 % 6) + 1;
  die2 = (die2 % 6) + 1;

  int roll = die1 + die2;

  std::cout <<"\n"<<name<<" attacks with a roll of "<< roll << std::endl;

  return roll;

}

//returns a value 2 to 12
int Barbarian::defending() {

  int die1 = rand();
  int die2 = rand();

  //two six-sided dice means range is 2-12
  die1 = (die1 % 6) + 1;
  die2 = (die2 % 6) + 1;

  int roll = die1 + die2;

  std::cout <<"\n"<<name<<" defends with a roll of "<< roll << std::endl;

  return roll;

}

//Updates strength value
void Barbarian::setStrength(int s) {

  strength -= s;

  if(strength <= 0 && strength > -100) {
    strength = 0;
    std::cout << "\n"<<name<<" falls and clutches his fatal wound...\n";
    std::cout << "He looks out to the horizon, where he knows his quest\n";
    std::cout << "now failed, would have taken him. He falls to his back\n";
    std::cout << "and looks up to the skies, content with a warrior's"
              << " death\n";
  }
  else if(strength <= -100) {
    strength = 0;
    std::cout << "\n"<<name<<" feels his body hardening to stone...\n";
    std::cout << "He yells and runs towards Medusa sword overhead!\n";
    std::cout << "But freezes to stone before taking but two steps...\n";
    std::cout << "Medusa laughs, and thinking it a nice statue, brings\n";
    std::cout << "her foe, now of stone, back to her lair...\n";
  }
}

//Lets a winning vampire recover some health
void Barbarian::recover() {
  
  std::cout << std::endl;
  std::cout<<name<<" feels the rush of victory in battle!\n";
  std::cout<<"...and recovers to full strength!\n\n";

  strength = 12;
}
