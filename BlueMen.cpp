/**************************************************************************
** Program Name: BlueMen.hpp
** Name:         Story Caplain
** Date:         02/07/19
** Description:  This is the .cpp file for the BlueMen class.
**               It handles its specific attack and defend functions.
**************************************************************************/
#include <iostream>
#include <random>
#include "BlueMen.hpp"

BlueMen::BlueMen(int atk, int def, int arm, int str) : 
  Character(atk,def,arm,str) {}

//returns a value 2 to 20
int BlueMen::attacking() {

  int die1 = rand();
  int die2 = rand();

  //two ten-sided dice means range is 2-20
  die1 = (die1 % 10) + 1;
  die2 = (die2 % 10) + 1;

  int roll = die1 + die2;

  std::cout <<"\n"<<name<<" attacks with a roll of "<< roll << std::endl;

  return roll;

}

//returns a value 2 to 20
int BlueMen::defending() {

  int die1 = rand();
  int die2 = rand();
  int die3 = rand();

  //three six-sided dice means range is 3-18
  //However blue men lose one defense die
  //for every 4 points of strength lost
  if(strength > 8) {

    die1 = (die1 % 6) + 1;
    die2 = (die2 % 6) + 1;
    die3 = (die3 % 6) + 1;

    int roll = die1 + die2 + die3;

    std::cout <<"\n"<<name<<" defends with a roll of "<< roll << std::endl;

    return roll;
  
  }

  else if(strength > 4 && strength <= 8) {

    die1 = (die1 % 6) + 1;
    die2 = (die2 % 6) + 1;

    int roll = die1 + die2;
    
    std::cout <<"\n"<<name<<" defends with a roll of "<< roll << std::endl;

    return roll;
  
  }
  
  else {

    die1 = (die1 % 6) + 1;

    int roll = die1;

    std::cout <<"\n"<<name<<" defends with a roll of "<< roll << std::endl;

    return roll;
  
  }
}

//Updates strength value
void BlueMen::setStrength(int s) {

  strength -= s;

  if(strength <= 0 && strength > -100) {
    strength = 0;
    std::cout << "\n"<<name<<" screams out in tiny squeals of pain\n";
    std::cout << "They fall to the floor in a tiny blue pile...\n";
    std::cout << "never to battle again...\n";
  }
  else if(strength < -100) {
    strength = 0;
    std::cout << std::endl;
    std::cout <<name<<" shrieks as they make eye contact with\n";
    std::cout << "Medusa. They turn to run in different directions\n";
    std::cout << "But turn to stone before they can. Medusa laughs\n";
    std::cout << "and picks them up, thinking they'll make nice lawn\n";
    std::cout << "ornaments, next to those dwarves she froze last year\n";
  }
}

//Lets a winning vampire recover some health
void BlueMen::recover() {
  
  std::cout << std::endl;
  std::cout<<name<<" eats the remains of their victim, gaining strength!";

  int recovery = rand();

  int diff = 12 - getStrength();

  //if they took damage
  if(diff > 0) {

    recovery = (recovery % diff) + 1;

    strength += recovery;

    std::cout << std::endl;
    std::cout<<name<<" recovered "<<recovery<<" strength points!\n";
  }
  
  //if they took no damage
  else {
    std::cout << std::endl;
    std::cout<<name<<" is at full strength!\n";
  }
}
