#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <thread>
using namespace std;

class Tile
{
    char tile_prnt;
    Tile(char tile_prnt) {
        this->tile_prnt = tile_prnt;
    }
};

class Map : public Tile {
    char tile_prnt = '0';
};

class weapon {
    public:
        int weapon_durability, weapon_up_cost, weapon_damage;
        string weapon_name;

        void upgrade_weapon() {

        }
};

class player : public weapon
{
    public:
        int x_player, y_player, hp_player, gold_player;
        int player_attack = 1;

        int attack_monsters() {
            return 0;
         }


};

class gold {
    public:
        int rand_gold() {
            return 0;
        }

};

class monster : public Tile {
    public:
        int mon_x, mon_y, mon_hp, attack_val, mon_gold;

        void mon_fight() {

        }

};

int main() {
    srand(time(NULL));
    cout << "hello";
}   
