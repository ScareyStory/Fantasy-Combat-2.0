/**************************************************************************
** Program Name: Main.cpp
** Name:         Story Caplain
** Date:         02/21/19
** Description:  Plays a turn based combat game where die rolls determine
**               defense and offense. There are two teams represented by
**               queues. The first player in the queue of one team fights
**               the first player in the queue of the other team. The player
**               who wins goes to the back of their queue. The player who
**               lost goes to a loser queue. An empty team loses.
***************************************************************************/
#include <iostream>
#include <string>
#include <random>
#include <thread>
#include <chrono>
#include "Menu.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {

  cout<<endl;
  cout<<"Hello! And welcome to the fantasy combat team battle!\n";
  cout<<"In this game two players make teams that go head to head\n";
  cout<<"in a battle to the death. Players get to form their team from\n";
  cout<<"5 character types, each with unique traits and attributes.\n";
  cout<<"A character is defeated if its strength reaches zero,\n";
  cout<<"and a team is defeated if all its characters have been defeated.";
  cout<<endl;
  cout<<"Attack values and defend values are determined by dice rolls, and";
  cout<<endl;
  cout<<"each character type has unique dice roll characteristics\n\n";

  cout<<"Prepare for battle! But who is battling...\n";

  std::string name1;
  std::string name2;

  int val = 1;
  cout << "\nPlayer 1, what is your name: ";
  getline(cin,name1);
  while(val==1) {
    if(cin.fail() || name1.length() > 15) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "\nOops! Invalid input." << endl;
      cout << "Enter a name 15 characters or less: ";
      cin  >> name1;
    }   
    else if(!cin.fail()) {
      val = 0;
    }   
  }
  
  val = 1;
  cout << "\nPlayer 2, what is your name: ";
  getline(cin,name2);
  while(val==1) {
    if(cin.fail() || name2.length() > 15) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "\nOops! Invalid input." << endl;
      cout << "Enter a name 15 characters or less: ";
      cin  >> name2;
    }   
    else if(!cin.fail()) {
      val = 0;
    }   
  }

  //while loop
  bool playing = true;

  while(playing==true) { 

    //Team 1
    Queue Team1;

    //Team 2
    Queue Team2;

    //Losers queue
    Queue losers;

    Queue *l = &losers;

    cout << "\n\nIt is now time for "<<name1<<" to build their team\n";
    int choice1 = 0;
    bool creating = true;
    char more;

    int teammax = 0;

    //Loop until team 1 is created
    while(creating==true && teammax < 5) { 
    
      choice1 = Menu(name1);
    
      Team1.addBack(choice1);

      teammax++;

      cout << endl;
      if(teammax > 1 && teammax < 5) {
        cout << name1 << " you now have "<<teammax<<" characters!";
        cout << endl;

        //MAX size of 5 chosen is arbitrary, keeps game from being too long

        cout << "\nThe max size for a team is 5 characters";
        cout << "\nYou may add "<<(5-teammax)<<" more character(s)";
        cout << endl;
      }

      if(teammax < 5) {
        cout<<"\n"<<name1<<", would you like to add another character?";
        cout<<"\nEnter the letter c for another character";
        cout<<"\nPress any other key to stop adding characters to team: ";
        cin >> more;
      
      
        if(cin.fail() || (more != 'c' && more != 'C')) {
          cout << "\n\n" <<name1<<" has built their team!\n\n";
          creating = false;
        }
        else {
          creating = true;
        }
      }
    }

    for(int i=0; i<50; i++) {
      cout << "\n";
    }
    
    cout << "\n\nIt is now time for "<<name2<<" to build their team\n";
    int choice2 = 0;
    creating = true;
    teammax = 0;

    //Loop until team 2 is created
    while(creating==true && teammax < 5) { 
    
      choice2 = Menu(name2);
    
      Team2.addBack(choice2);

      teammax++;

      cout << endl;

      if(teammax > 1 && teammax < 5) {
        cout << name2 << " you now have "<<teammax<<" characters!";
        cout << endl;
        cout << "\nThe max size for a team is 5 characters";
        cout << "\nYou may add "<<(5-teammax)<<" more character(s)";
        cout << endl;
      }

      if(teammax < 5) {
        cout<<"\n"<<name2<<", would you like to add another character?";
        cout<<"\nEnter the letter c for another character";
        cout<<"\nPress any other key to stop adding characters to team: ";
        cin >> more;
      
      
        if(cin.fail() || (more != 'c' && more != 'C')) {
          cout << "\n\n" <<name2<<" has built their team!\n\n";
          creating = false;
        }
        else {
          creating = true;
        }
      }
    }

    for(int i=0; i<50; i++) {
      cout << "\n";
    }

    cout << "\nA coin is flipped to determine who goes first!\n";
    cout << "A heads means "<<name1<<" goes first\n";
    cout << "and a tails means "<<name2<<" goes first\n\n";

    int coin = rand();
    coin = coin % 2;

    //delay before showing coin toss result
    //simulates it flipping in air
    std::this_thread::sleep_for(std::chrono::seconds(2));

    if(coin==0) {
      cout << "It's a heads! "<<name1<<" goes first!\n";
    }
  
    else if(coin==1) {
      cout << "It's a tails! "<<name2<<" goes first!\n";
    }
    //delay again
    std::this_thread::sleep_for(std::chrono::seconds(1));
 
    //for keeping track of round and loop 
    int round = 0;
    bool battling = true;
    
    //to display damages
    int damage1 = 0;
    int damage2 = 0;

    //check if killed
    int killed = 0;
    int lost = 0;

    cin.clear();
    cin.ignore(256, '\n');
   
    while(battling==true) {
      if(coin==0) {
        round++;

        cout << "\nHit enter to begin round...\n";
        cin.clear();
        cin.ignore(256, '\n');

        cout << "\n\nIt is round "<<round<<"... Fight!\n\n";
        
        //attack1 holds the return value of Team1's attacking function
        int attack1 = Team1.head->attacking();
        Team1.head->setAttack(attack1);

        //defend2 holds the return value of Team2's defending function
        int defend2 = Team2.head->defending();
        Team2.head->setDefense(defend2);

        //damage holds the diff between Team1's attack and Team2's defend
        int damage1 = attack1 - defend2;

        //If attack exceeds defense
        if(damage1 > 0) {

          //excess holds the amount of damage not caught by armor
          int excess = Team2.head->setArmor(damage1);
          
          //if damage exceeds armor, reduce strength by excess
          Team2.head->setStrength(excess);
          
          //if Player 2's character is killed
          if(Team2.head->getStrength() <= 0) {
            cout << "\n\n";
            cout << Team2.head->getName() <<" is defeatad!\n";
            
            //Add losing character to losing queue
            Team2.removeLoser(l);

            lost = 2;
            killed=1;

            //Restore winning character some health
            Team1.head->recover();
          }
        }
        //else if defense exceeds attack
        else{
          
          //If Medusa locked eyes with a charming vampire
          if(attack1==1000 && defend2==1000) {
            cout << "\n"<<Team2.head->getName() 
                 << "'s charming eyes are unaffected by"
                 << Team2.head->getName() << "'s glare!" 
                 << endl;
          }
          //If defense exceeds or equals attack
          else {
            cout << "\n\n";
            cout << Team2.head->getName() 
                 << " took no damage!\n";
          }
        }

        //Now Player 2 attacks
        cout << endl;
        if(killed == 0) {

          //attack2 holds the return value of Team2's attacking function
          int attack2 = Team2.head->attacking();
          Team2.head->setAttack(attack2);

          //defend1 holds the return value of Team1's defending function
          int defend1 = Team1.head->defending();
          Team1.head->setDefense(defend1);

          //damage holds the diff between Team2's attack and Team1's defend
          int damage2 = attack2 - defend1;

          //If attack exceeds defense
          if(damage2 > 0) {

            //excess holds the amount of damage not caught by armor
            int excess = Team1.head->setArmor(damage2);
            
            //if damage exceeds armor, reduce strength by excess
            Team1.head->setStrength(excess);
            
            //if Player 1's character is killed
            if(Team1.head->getStrength() <= 0) {
              cout << "\n\n";
              cout << Team1.head->getName() <<" is defeatad!\n";
            
              //Add losing character to losing queue
              Team1.removeLoser(l);

              lost = 1;
              
              //Restore winning character some health
              Team2.head->recover();
            }
          }
          //else if defense exceeds attck
          else{
            
            //If Medusa locked eyes with a charming vampire
            if(attack2==1000 && defend1==1000) {
              cout << "\n"
                   << Team1.head->getName()
                   << "'s charming eyes are unaffected by"
                   << Team2.head->getName() 
                   << "'s glare!" 
                   << endl;
            }
            //If defense exceeds or equals attack
            else {
              cout << "\n\n";
              cout << Team1.head->getName() 
                   << " took no damage!\n";
            }
          }
        }
        //reset killed
        else {killed=0;} 
      }//coin == 0

      if(coin==1) {
        round++;

        cout << "\nHit enter to begin round...\n";
        cin.clear();
        cin.ignore(256, '\n');

        cout << "\n\nIt is round "<<round<<"... Fight!\n\n";
        
        //attack2 holds the return value of Team2's attacking function
        int attack2 = Team2.head->attacking();
        Team2.head->setAttack(attack2);

        //defend1 holds the return value of Team1's defending function
        int defend1 = Team1.head->defending();
        Team1.head->setDefense(defend1);

        //damage holds the diff between Team2's attack and Team1's defend
        int damage2 = attack2 - defend1;

        //If attack exceeds defense
        if(damage2 > 0) {

          //excess holds the amount of damage not caught by armor
          int excess = Team1.head->setArmor(damage2);
          
          //if damage exceeds armor, reduce strength by excess
          Team1.head->setStrength(excess);
          
          //if Player 1's character is killed
          if(Team1.head->getStrength() <= 0) {
            cout << "\n\n";
            cout << Team1.head->getName() <<" is defeatad!\n";
          
            //Add losing character to losing queue
            Team1.removeLoser(l);

            lost = 1;

            killed=1;

            //Restore winning character some health
            Team2.head->recover();
          }
        }
        //else if defense exceeds attck
        else{
          
          //If Medusa locked eyes with a charming vampire
          if(attack2==1000 && defend1==1000) {
            cout << "\n"
                 << Team1.head->getName()
                 <<"'s charming eyes are unaffected by"
                 << Team2.head->getName()
                 << "'s glare!" 
                 << endl;
          }
          //If defense exceeds or equals attack
          else {
            cout << "\n\n";
            cout << Team1.head->getName()
                 << " took no damage!\n";
          }
        }

        //Now Player 1 attacks
        cout << endl;
        if(killed==0) {

          //attack1 holds the return value of Team1's attacking function
          int attack1 = Team1.head->attacking();
          Team1.head->setAttack(attack1);

          //defend2 holds the return value of Team2's defending function
          int defend2 = Team2.head->defending();
          Team2.head->setDefense(defend2);

          //damage holds the diff between Team1's attack and Team2's defend
          int damage1 = attack1 - defend2;

          //If attack exceeds defense
          if(damage1 > 0) {

            //excess holds the amount of damage not caught by armor
            int excess = Team2.head->setArmor(damage1);
            
            //if damage exceeds armor, reduce strength by excess
            Team2.head->setStrength(excess);
            
            //if Player 2's character is killed
            if(Team2.head->getStrength() <= 0) {
              cout << "\n\n";
              cout << Team2.head->getName() <<" is defeatad!\n";
          
              //Add losing character to losing queue
              Team2.removeLoser(l);

              lost = 2;

              //Restore winning character some health
              Team1.head->recover();
            }
          }
          //else if defense exceeds attck
          else{
            
            //If Medusa locked eyes with a charming vampire
            if(attack1==1000 && defend2==1000) {
              cout << endl;
              cout << Team2.head->getName()
                   << "'s charming eyes are unaffected by"
                   << Team1.head->getName()
                   << "'s glare!" 
                   << endl;
            }
            //If defense exceeds or equals attack
            else {
              cout << "\n\n";
              cout << Team2.head->getName()
                   << " took no damage!\n";
            }
          }
        }
        else {killed=0;} 
      }//coin==1

      cout << "\n\nHit enter for detailed round statistics...";
      cin.clear();
      cin.ignore(256, '\n');

      //Make space
      for(int i=0; i<50; i++) { cout << "\n"; }

      //Print out detailed round statistics
      cout << "\n\n";
      
      //makes proper amount of space
      if(lost==0) {
        cout << "Name:\t\t" << Team1.head->getName();
        for(int i=((Team1.head->getName()).length());i<16;i++) {cout<<" ";}
           
        cout << (Team2.head->getName());
        cout << endl;
      }
      else if(lost==1) {
        cout << "Name:\t\t" << losers.head->getName();
        for(int i=((losers.head->getName()).length());i<16;i++) {cout<<" ";}
           
        cout << (Team2.head->getName());
        cout << endl;
      }
      else if(lost==2) {
        cout << "Name:\t\t" << Team1.head->getName();
        for(int i=((Team1.head->getName()).length());i<16;i++) {cout<<" ";}
           
        cout << (losers.head->getName());
        cout << endl;
      }
    
      //Output attack based on how much attack
      if(lost==0) {
        if(Team1.head->getAttack() > 100) {
          cout << "Attack:\t\t" << "Glare!" << "\t\t" 
               << Team2.head->getAttack();
          cout << endl;
        } 
        else if(Team2.head->getAttack() > 100) {
          cout << "Attack:\t\t" << Team1.head->getAttack() << "\t\t" 
               << "Glare!";
          cout << endl;
        }
        else { 
          cout << "Attack:\t\t" << Team1.head->getAttack() 
               << "\t\t" << Team2.head->getAttack();
          cout << endl;
        }
      }
      //Output attack based on how much attack
      if(lost==1) {
        if(losers.head->getAttack() > 100) {
          cout << "Attack:\t\t" << "Glare!" << "\t\t" 
               << Team2.head->getAttack();
          cout << endl;
        } 
        else if(Team2.head->getAttack() > 100) {
          cout << "Attack:\t\t" << losers.head->getAttack() << "\t\t" 
               << "Glare!";
          cout << endl;
        }
        else { 
          cout << "Attack:\t\t" << losers.head->getAttack() 
               << "\t\t" << Team2.head->getAttack();
          cout << endl;
        }
      }
      //Output attack based on how much attack
      if(lost==2) {
        if(Team1.head->getAttack() > 100) {
          cout << "Attack:\t\t" << "Glare!" << "\t\t" 
               << losers.head->getAttack();
          cout << endl;
        } 
        else if(losers.head->getAttack() > 100) {
          cout << "Attack:\t\t" << Team1.head->getAttack() << "\t\t" 
               << "Glare!";
          cout << endl;
        }
        else { 
          cout << "Attack:\t\t" << Team1.head->getAttack() 
               << "\t\t" << losers.head->getAttack();
          cout << endl;
        }
      }
      //Output defense based on how much defense
      if(lost==0) {
        if(Team1.head->getDefense() > 100) {
          cout << "Defense:\t" << "Charm!" << "\t\t" 
               << Team2.head->getDefense();
          cout << endl;
        } 
        else if(Team2.head->getDefense() > 100) {
          cout << "Defense:\t" << Team1.head->getDefense() 
               << "\t\t" << "Charm!";
          cout << endl;
        }
        else { 
          cout << "Defense:\t" << Team1.head->getDefense() 
               << "\t\t" << Team2.head->getDefense();
          cout << endl;
        }
      }
      else if(lost==1) {
        if(losers.head->getDefense() > 100) {
          cout << "Defense:\t" << "Charm!" << "\t\t" 
               << Team2.head->getDefense();
          cout << endl;
        } 
        else if(Team2.head->getDefense() > 100) {
          cout << "Defense:\t" << losers.head->getDefense() 
               << "\t\t" << "Charm!";
          cout << endl;
        }
        else { 
          cout << "Defense:\t" << losers.head->getDefense() 
               << "\t\t" << Team2.head->getDefense();
          cout << endl;
        }
      }
      else if(lost==2) {
        if(Team1.head->getDefense() > 100) {
          cout << "Defense:\t" << "Charm!" << "\t\t" 
               << losers.head->getDefense();
          cout << endl;
        } 
        else if(losers.head->getDefense() > 100) {
          cout << "Defense:\t" << Team1.head->getDefense() 
               << "\t\t" << "Charm!";
          cout << endl;
        }
        else { 
          cout << "Defense:\t" << Team1.head->getDefense() 
               << "\t\t" << losers.head->getDefense();
          cout << endl;
        }
      }
      //make sure damage taken isn't printed as a negative number 
      if(lost==0) {
        if(Team2.head->getAttack() - Team1.head->getDefense() < 0) {
          damage1 = 0;
        }
        else {
          damage1 = Team2.head->getAttack() - Team1.head->getDefense();
        }
      
        //make sure damage taken isn't printed as a negative number 
        if(Team1.head->getAttack() - Team2.head->getDefense() < 0) {
          damage2 = 0;
        }
        else {
          damage2 = Team1.head->getAttack() - Team2.head->getDefense();
        }
      }
      else if(lost==1) {
        if(Team2.head->getAttack() - losers.head->getDefense() < 0) {
          damage1 = 0;
        }
        else {
          damage1 = Team2.head->getAttack() - losers.head->getDefense();
        }
      
        //make sure damage taken isn't printed as a negative number 
        if(losers.head->getAttack() - Team2.head->getDefense() < 0) {
          damage2 = 0;
        }
        else {
          damage2 = losers.head->getAttack() - Team2.head->getDefense();
        }
      }
      else if(lost==2) {
        if(losers.head->getAttack() - Team1.head->getDefense() < 0) {
          damage1 = 0;
        }
        else {
          damage1 = losers.head->getAttack() - Team1.head->getDefense();
        }
      
        //make sure damage taken isn't printed as a negative number 
        if(Team1.head->getAttack() - losers.head->getDefense() < 0) {
          damage2 = 0;
        }
        else {
          damage2 = Team1.head->getAttack() - losers.head->getDefense();
        }
      }
      //Output rest of statistics
      if(damage1 > 100) {
        cout << "Damage Taken:\t" << "Glared!" << "\t\t" << damage2;
        cout << endl;
      }
      else if(damage2 > 100) {
        cout << "Damage Taken:\t" << damage1 << "\t\t" << "Glared!";
        cout << endl;
      }
      else {
        cout << "Damage Taken:\t" << damage1 << "\t\t" << damage2;
        cout << endl;
      }  

      if(lost==0) {
        cout << "Armor:\t\t" << Team1.head->getArmor() <<"\t\t"
             << Team2.head->getArmor();
        cout << endl;
      
        cout << "Strength:\t" << Team1.head->getStrength() <<"\t\t"
             << Team2.head->getStrength();
        cout << endl;
      }
      else if(lost==1) {
        cout << "Armor:\t\t" << losers.head->getArmor() <<"\t\t"
             << Team2.head->getArmor();
        cout << endl;
      
        cout << "Strength:\t" << losers.head->getStrength() <<"\t\t"
             << Team2.head->getStrength();
        cout << endl;
      }
      else if(lost==2) {
        cout << "Armor:\t\t" << Team1.head->getArmor() <<"\t\t"
             << losers.head->getArmor();
        cout << endl;
      
        cout << "Strength:\t" << Team1.head->getStrength() <<"\t\t"
             << losers.head->getStrength();
        cout << endl;
      }

      if(lost==1) {
        cout << "\n";
        cout << Team2.head->getName() << " won this round!\n";
        //Rotate winning team
        Team2.head = Team2.head->next;
      }
      else if(lost==2) {
        cout << "\n";
        cout << Team1.head->getName() << " won this round!\n";
        //Rotate winning team
        Team1.head = Team1.head->next;
      }

      //If Team 1 is out of characters
      if(Team1.isEmpty() == true) {
        cout << endl;

        cout << "\n\n\n";
        cout << name2 << "'s team is victorious!\n";
        cout << endl;
        cout << name1 << "'s team is defeated!\n\n";

        cout << "\n\n";
        cout << name2 << "'s team after the battle\n";
        cout << "_________________________________\n";
        Team2.printQueue();    

        cout << "\n\n\n\n\n";

        cout << endl;
        cout << "The characters who didn't make it...\n";
        cout << "____________________________________\n";
        losers.printQueue();

        battling = false;
      }

      //If team 2 is out of characters
      else if(Team2.isEmpty() == true) {
        cout << endl;
        
        cout << name1 << "'s team is victorious!\n";

        cout << name2 << "'s team is defeated!\n\n";

        cout << name1 << "'s team after the battle\n";
        cout << "_________________________________\n";
        Team1.printQueue();    

        cout << "\n\n\n\n\n";

        cout << endl;
        cout << "The characters who didn't make it...\n";
        cout << "____________________________________\n";
        losers.printQueue();

        battling = false;
      }
     
      //Else both teams still have characters
      else if(lost!=0) { 
        //tell user who is up next
        cout <<"\nNow it is time for "<<Team1.head->getName()
             <<" and "<<Team2.head->getName()<<" to battle!\n";
        //reset lost
        lost = 0;
        battling = true;
      }

      else {
        cout << endl;
        cout << Team1.head->getName() <<" and "<<Team2.head->getName()
             << " both survive and continue their battle!\n";
        lost = 0;
        battling = true;
      }

    }//battling loop

    char again;

    cout << "\n\n\n";

    cout << "\nWould you like to play another match?\n";
    cout << "\nEnter a y to play again, anything else to quit: ";
    cin  >> again;

    if(cin.fail() || (again != 'y' && again != 'Y')) {
      for(int i=0; i<100; i++) {cout << "\n";}
      cout << "\n\nThank you for playing fantasy combat!\n";
      cout << "I hope you enjoyed it\n\n";
      playing = false;
    }
    else {
      for(int i=0;i<100;i++) {cout<<"\n";}
      playing = true;
    }

  }//playing loop
  return 0;
}
