#include <iostream>
#include <vector>
#include <cstdlib> // Needed for rand() and srand()
#include "Weapon.h"
#include "SuperWeapon.h"

using namespace std;

int health  = 100;

int random1or2(){
       // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number in the range 1-2
    int random_num = rand() % 2 + 1;

    return random_num;
}

Weapon* search(){

    cout << "You found a sword!\n";
    
    int rand = random1or2();
    Weapon* weapon;

    if(rand == 1){
       weapon = new Weapon("sword",10);
    }
    else{
       weapon = new SuperWeapon("sword",1);
    }
    
    return weapon;
}

void goIntoTheForest(Weapon* weapon){

    cout << "You encounter a goblin in the forest!\n";
    int goblinHealth = 120;

    if (weapon == nullptr){
        cout << "The goblin attacks you\n";
        health = 0;
    }
    else {

       string selection = "";

       while (selection != "2" && goblinHealth >0){

            cout << "[1] attack\n";
            cout << "[2] run away\n";

            cin >> selection;

            if ("1" == selection){
                goblinHealth = goblinHealth - (weapon->attack());
                cout << "you attack the goblin. The goblin is at " <<  goblinHealth <<  " health.\n";
            }

       }
    }

}

int main() {

    vector <Weapon*> inventory;
    string selection;
    

    while ("x" != selection){

        cout << "Select an action!\n";
        cout << "[1] to search around you\n";
        cout << "[2] to view inventory\n";
        cout << "[3] go into the forest\n";
        cout << "[x] to exit\n";

        cin >> selection;

        if ("1" == selection){
            inventory.push_back(search());
        }
        else if("2" == selection){
            cout << "Your inventory contains:\n";
            for(int i=0; i < inventory.size() ; i++){
                cout << inventory[i]->getDescription() << "\n";
            }
        }
        else if("3" == selection){
            
            Weapon *weapon = nullptr;

            if (inventory.size() > 0){
                weapon = inventory[0];
            }
            goIntoTheForest(weapon);
        }

        
        if(health <= 0){
            cout << "you died!\n";
            break;
        }
    }

    cout << "goodbye\n";
    return 0;
}

