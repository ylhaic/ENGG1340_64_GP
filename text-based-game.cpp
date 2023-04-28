#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <memory>
#include <string>
#include "introduction.h"
#include "game1.h"
#include "game2.h"
#include "game4.h"
#include "game5.h"
#include "room1.h"
#define WIN_MSG "Congratulations! You've collected all the required items and won the game!\n"
#define LOSS_MSG "You didn't collect all the required items. Game over!\n"
#define DEAD_MSG "You lose all healthpoint, you dead!\n"


using namespace std;
class Room {
public:
    Room(){
        pNorthRoom = NULL;
        pSouthRoom = NULL;
        pEastRoom = NULL;
        pWestRoom = NULL;
        passable = false;//player can pass flag
        win = false;//room game win flag
        hasTreasure = false;//room has treasure
        hasGame = false;//room has game
        hasItem = false;//room has item
        play_game = NULL;//room game
        healthLoss = 0;//game fail health loss
        treasure = 0;//room treasure number
    }
    int get_id(){
        return id;
    }
    string descript(){
		return description+guide();
    }
    string guide(){
		string g;
		if(pNorthRoom){
			g += "there is a room to your north,";
		}
		if(pSouthRoom){
			g += "there is a room to your south,";
		}
		if(pWestRoom){
			g += "there is a room to your west,";
		}
		if(pEastRoom){
			g += "there is a room to your east";
		}
		return g;
	}
    int id;
    string description;
    string monster;
    int treasure;
    bool (*play_game)();
    string item;
    bool passable;
    bool win;
    bool hasTreasure;
    bool hasGame;
    bool hasItem;
    Room *pNorthRoom;
    Room *pSouthRoom;
    Room *pEastRoom;
    Room *pWestRoom;
    int healthLoss;
};

class Player {
public:

    Player() : healthPoints(100), cash(0) {}
    void set_name(string name){
        this->name = name;
    }

    void is_dead(){
		if(healthPoints <= 0){
			cout<<DEAD_MSG<<endl;
			exit(0);
		}
	}
    // ... Methods for interacting with monsters, picking up items, etc.
    void play(){
		if(!currentRoom->win){
			if(!currentRoom->hasGame){
				return;
			}
			if(currentRoom->play_game()){
				currentRoom->win = true;
				cout<<"you win\n";
				if(currentRoom->hasItem){
					bag.push_back(currentRoom->item);
					currentRoom->hasItem = false;
					cout<<"you get "<<currentRoom->item<<endl;
				}
				currentRoom->passable = true;
			}else{
				healthPoints -= currentRoom->healthLoss;
				cout<<"you loss\n";
				is_dead();
			}
		}
	}
	int pick(){
		if(currentRoom->hasTreasure){
			cash += currentRoom->treasure;
			currentRoom->hasTreasure = false;
		}
		return cash;
	}
	void move(char arg0){
		switch(arg0){
			case 'n':
			case 'N':
			if(currentRoom->pNorthRoom){
				if(currentRoom->passable || currentRoom->pNorthRoom->passable){
					
					currentRoom = currentRoom->pNorthRoom;
					if(!currentRoom->hasGame){
						currentRoom->passable = true;
					}
				}
			}
			break;
			
			case 's':
			case 'S':
			if(currentRoom->pSouthRoom){
				if(currentRoom->passable || currentRoom->pSouthRoom->passable){
					
					currentRoom = currentRoom->pSouthRoom;
					if(!currentRoom->hasGame){
						currentRoom->passable = true;
					}
				}
			}
			break;
			
			case 'w':
			case 'W':
			if(currentRoom->pWestRoom){
				if(currentRoom->passable || currentRoom->pWestRoom->passable){
					
					currentRoom = currentRoom->pWestRoom;
					if(!currentRoom->hasGame){
						currentRoom->passable = true;
					}
				}
			}
			break;
			
			case 'e':
			case 'E':
			if(currentRoom->pEastRoom){
				if(currentRoom->passable || currentRoom->pEastRoom->passable){
					
					currentRoom = currentRoom->pEastRoom;
					if(!currentRoom->hasGame){
						currentRoom->passable = true;
					}
				}
			}
			break;
		}
	}

    string name;
    int healthPoints;
    Room* currentRoom;
    vector<string> bag;
    int cash;
};

class Game {
public:
    Game() {
        init_rooms();
    }
    void connect_rooms(){
		rooms[0].pNorthRoom = NULL;
		rooms[0].pSouthRoom = &rooms[3];
		rooms[0].pWestRoom = NULL;
		rooms[0].pEastRoom = &rooms[1];
		
		rooms[1].pNorthRoom = NULL;
		rooms[1].pSouthRoom = &rooms[4];
		rooms[1].pWestRoom = &rooms[0];
		rooms[1].pEastRoom = &rooms[2];
		
		rooms[2].pNorthRoom = NULL;
		rooms[2].pSouthRoom = NULL;
		rooms[2].pWestRoom = &rooms[1];
		rooms[2].pEastRoom = NULL;
		
		rooms[3].pNorthRoom = &rooms[0];
		rooms[3].pSouthRoom = NULL;
		rooms[3].pWestRoom = NULL;
		rooms[3].pEastRoom = NULL;
		
		rooms[4].pNorthRoom = &rooms[1];
		rooms[4].pSouthRoom = &rooms[7];
		rooms[4].pWestRoom = NULL;
		rooms[4].pEastRoom = &rooms[5];
		
		rooms[5].pNorthRoom = NULL;
		rooms[5].pSouthRoom = &rooms[8];
		rooms[5].pWestRoom = &rooms[4];
		rooms[5].pEastRoom = NULL;
		
		rooms[6].pNorthRoom = NULL;
		rooms[6].pSouthRoom = NULL;
		rooms[6].pWestRoom = NULL;
		rooms[6].pEastRoom = &rooms[7];
		
		rooms[7].pNorthRoom = &rooms[4];
		rooms[7].pSouthRoom = NULL;
		rooms[7].pWestRoom = &rooms[6];
		rooms[7].pEastRoom = NULL;
		
		rooms[8].pNorthRoom = &rooms[5];
		rooms[8].pSouthRoom = NULL;
		rooms[8].pWestRoom = NULL;
		rooms[8].pEastRoom = NULL;
		
    }
    void init_rooms() {
        rooms[0].id = 1;
        rooms[0].description = "";
        rooms[0].passable = true;

        rooms[1].id = 2;
        rooms[1].description = "rooms 2 description,pick treasure\n";
        rooms[1].hasTreasure = true;
        rooms[1].treasure = 10;

        rooms[2].id = 3;
        rooms[2].description = "rooms 3 description,play game\n";
        rooms[2].hasItem = true;
        rooms[2].item = "item3";
        rooms[2].hasGame = true;
        rooms[2].play_game = playgame1;
        rooms[2].healthLoss = 40;

        rooms[3].id = 4;
        rooms[3].description = "rooms 4 description,pick treasure\n";
        rooms[3].treasure = 10;
        rooms[3].hasTreasure = true;

        rooms[4].id = 5;
        rooms[4].description = "rooms 5 description,play game\n";
        rooms[4].hasItem = true;
        rooms[4].item = "item5";
        rooms[4].hasGame = true;
        rooms[4].play_game = playgame2;
        rooms[4].healthLoss = 10;

        rooms[5].id = 6;
        rooms[5].description = "rooms 6 description,attack\n";
        rooms[5].hasItem = true;
        rooms[5].item = "item6";

        rooms[6].id = 7;
        rooms[6].description = "rooms 7 description,play game\n";
        rooms[6].hasItem = true;
        rooms[6].item = "item7";
        rooms[6].hasGame = true;
        rooms[6].play_game = playgame4;
        rooms[6].healthLoss = 20;

        rooms[7].id = 8;
        rooms[7].description = "rooms 8 description,play game\n";
        rooms[7].hasItem = true;
        rooms[7].item = "item8";
        rooms[7].hasGame = true;
        rooms[7].play_game = playgame5;
        rooms[7].healthLoss = 30;

        rooms[8].id = 9;
        rooms[8].description = "rooms 9 description\n";

        connect_rooms();
    }
    void play() {
        string playerName;
		display_introduction(playerName);
        cin >> playerName;
        player.set_name(playerName);
        player.currentRoom = &rooms[0];

		cout << "\nWelcome, " << playerName << "! Let the adventure begin!\n";
		cout << "#########################################\n";
		cout << "#                                       #\n";
		cout << "#         Text Based Game               #\n";
		cout << "#                                       #\n";
		cout << "#########################################\n\n";
        displayCurrentRoomInfo();
        // ... Main game loop ...
			string interact;
		while(true){
			interact.clear();
			cin>>interact;
			if(interact.find("north") != string::npos){
				player.move('n');
			}else if(interact.find("south") != string::npos){
				if(player.currentRoom->pSouthRoom == &rooms[8]){
					if(rooms[5].win){
						player.move('s');
					}
				}else{
						player.move('s');
				}
			}else if(interact.find("west") != string::npos){
				player.move('w');
			}else if(interact.find("east") != string::npos){
				player.move('e');
			}else if(interact.find("play") != string::npos){
				player.play();
			}else if(interact.find("pick") != string::npos){
				player.pick();
			}else if(interact.find("attack") != string::npos){
				if(player.currentRoom == &rooms[5]){
					for(vector<string>::iterator iter = player.bag.begin(); iter != player.bag.end(); iter++){
						if(iter->find("item3") != string::npos || iter->find("item7") != string::npos){
							rooms[5].win = true;
							break;
						}
					}
					if(rooms[5].win){
						
							player.bag.push_back(rooms[5].item);
							rooms[5].hasItem = false;
							cout<<"you get "<<rooms[5].item<<endl;
							cout<<"you win\n";
					}else{
						cout<<"you losss\n";
					}
							
				}
			}else{
				puts("error input");
			}
			if(player.currentRoom == &rooms[8]){
				if(checkWinCondition()){
					cout<<WIN_MSG;
				}else{
					cout<<LOSS_MSG;
				}
				break;
			}
			displayCurrentRoomInfo();
		}
    }

    bool checkWinCondition() {
		        int items = 0;
				vector<string>::iterator iter = player.bag.begin();
		        for (; iter != player.bag.end(); iter++) {
		            if (iter->find("item") != string::npos) {
		                items++;
		            }
		        }
		        return player.cash >= 20 && items >= 3;
    }

    void displayCurrentRoomInfo() {

            cout << "Currently you are in Room " << player.currentRoom->get_id() << ". " << player.currentRoom->descript() << endl;
			if (player.currentRoom->get_id() == 1) {
				print_and_get_room1_description();
            } else {
				cout << player.currentRoom->descript() << endl;
            }

		    if (player.currentRoom->hasItem) {
		        cout << "The room contains the following items:";
		        cout << player.currentRoom->item;
		        
		    }
		    cout << "\nyour bag contains the following items:";
		    for(int i=0; i< player.bag.size(); i++){
				cout<<player.bag.at(i)<<" ";
			}

		    cout << "\nCurrent Cash is: " << player.cash <<"\nCurrent health is:"<<player.healthPoints<< std::endl;
		    cout << "What do you want to do: ";
    }
    
private:
    Room rooms[9];
    Player player;
};

int main() {
			Game game;
			game.play();
		    return 0;
}

