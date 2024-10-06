#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <thread>
using namespace std;


// initialising variables
bool Kill_knight = true;
bool Kill_dragon = true;
bool dodge_hit = true;
int damage_to_knight;
int damage_to_dragon;
bool crit_TF = false;
int randomm;
int *p; // pointer

void random_num() { // random num function., seeding is not done here or else the number wouldnt be random
  randomm = rand() % 100 + 1;
  p = &randomm;
};


class Characters {
  public: // initialise public variables
    int hp;
    int attack_damage;
    int defense_damage;
    int chance_dodge;

};

class Knight : public Characters { // Knight is a child class of characters

  public:
    int crit_chance;

    Knight(int hp, int attack_damage, int defense_damage, double chance_dodge, int crit_chance) // knight constructer
    {
      this->hp = hp;
      this->attack_damage = attack_damage;
      this->defense_damage = defense_damage;
      this->chance_dodge = chance_dodge;
      this->crit_chance = crit_chance;
    }

    void dodge() // dodge function, sets its T/F for the main while loop
    {
      random_num();
      cout << *p << endl;
      if (*p <= chance_dodge) 
      {
        cout << "The knight dodged the attack!" << endl;
        dodge_hit = true;
      }
      else
      {
        cout << "The knight failed to dodge the attack!" << endl;
        dodge_hit = false;
      }
    }

    void critical_hit(){ //crit function, sets its T/F for the main while loop
      random_num();
      cout << *p << endl;
      if (*p <= crit_chance){
        cout << "The knight landed a critical hit!" << endl;
        crit_TF = true;
      }
      else {
        cout << "The knight missed their critical hit!" << endl;
        crit_TF = false;
      }
    }
};

class Dragon :public Characters // dragon child class inherits from characters
{
  public:
    int death_hit;
  Dragon(int hp, int attack_damage, int defense_damage, int chance_dodge, int death_hit) { // constructer
    this->hp = hp;
    this->attack_damage = attack_damage;
    this->defense_damage = defense_damage;
    this->chance_dodge = chance_dodge;
    this->death_hit = death_hit;
  }
  void instant_kill() // instant kill function, sets its T/F for the main while loop
  {
    random_num();
    cout << *p << endl;
    if (*p <= death_hit)
    {
      cout << "The dragon did a normal attack!" << endl;
      Kill_knight = false;
    }
    else
    {
      cout << "The dragon did an instant kill attack" << endl;
      Kill_knight = true;
    }
  }
};

int main() 
{
  srand(time(NULL)); // seeding the random number generator, so that the random number is different every time
  
  Knight knight(300,80,30,90,33);
  Dragon dragon(1500,120,60,0,25);
  
  cout << "KNIGHT VS DRAGON\n" << endl;
  
  while (knight.hp > 0 && dragon.hp > 0) // main game loop
  {
    cout << "\nKnight HP: " << knight.hp << endl;
    cout << "Dragon HP: " << dragon.hp << "\n" << endl;
    
    knight.dodge();
    if (dodge_hit == true) {
      damage_to_knight = 0;
    }
    else
    {
      damage_to_knight = dragon.attack_damage;
    }
    
    knight.critical_hit();
    if (crit_TF == true) {
      damage_to_dragon = knight.attack_damage * 3;
    }
    else
    {
      damage_to_dragon = knight.attack_damage;
    }

    dragon.instant_kill();
    if (Kill_knight == true && dodge_hit == false){
      knight.hp = 0;
    }
    else if (Kill_knight == false && dodge_hit ==false){
      damage_to_knight = dragon.attack_damage;
    }
    else {
      damage_to_knight = 0;
      cout << "but it did not hit!!" << endl;
    }

    knight.hp -= damage_to_knight;
    dragon.hp -= damage_to_dragon;


    this_thread::sleep_for(chrono::seconds(2));
  };

  if (knight.hp <= 0){
    cout << "\nThe knight has died!" << endl;
  }
  else if (dragon.hp <=0){
    cout << "\nThe dragon has died!" << endl;
  }
}

 