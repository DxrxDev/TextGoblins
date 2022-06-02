/* Headers */
#include"mhandler.hpp"
#include"weapon.hpp"

/* STD Headers */
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

/* Helpful definitions */
const char *TEXTG_ASCII_ART =
"/=====/ /#====/ \\=\\ /=/ /=====/     /=====/ \n"
"  |#|   |#==>     >#<     |#|       |#| \\=\\ \n"
"  |#|   |#====\\ /=/ \\#\\   |#|       \\=====/ \n"
;

struct SaveData{
	const char *pname;
	int maxHP, hp, armour, stamina, money, level;
	std::vector<Weapon> weapons;
};

/* MainHandler method definitions */
MainHandler::MainHandler(){
	std::cout << "Setting things up...\n";
}
MainHandler::~MainHandler(){
	delete sd;
}
MainHandler *
MainHandler::CreateInstance(){
	return new MainHandler;
}
void
MainHandler::DeleteInstance(MainHandler *_mh){
	delete _mh;
}
void
MainHandler::Run(){
	std::cout << TEXTG_ASCII_ART;


	if(ReadSave() == 0){
		CreateSave();
		std::cout << "Hello, Let's beguin your adventure!!!\n";
	}else
		std::cout << "Let your jurney continue!!\n";


	std::string userInput;
	bool shouldQuit = false;

	while(!shouldQuit){
		std::cout << "What do you want to do?\n(n)ext battle, (c)haracter info, (s)ave, (q)uit\n: ";
		std::getline(std::cin, userInput);
		std::cout << '\n';

		if(userInput[0] == 'n'){
			DoBattle();
		}
		if(userInput[0] == 'c'){
			std::cout <<
				"Name: " << sd->pname << '\n' <<
				"Health: (" << sd->hp << " / " << sd->maxHP << ")\n" <<
				"Armour: " << sd->armour << '\n' <<
				"Stamina: " << sd->stamina << "\n\n"
			;
		}
		if(userInput[0] == 's'){
			UpdateSave();
		}
		if(userInput[0] == 'q'){
			shouldQuit = true;
			continue;
		}
	}
}

int
MainHandler::ReadSave(){
	return 0;
}

void
MainHandler::CreateSave(){
	std::cout << "So farm this only sets player name lol\n";
	sd = new SaveData{"player", 3, 2, 0, 2, 0, 0, {}};
}

void
MainHandler::UpdateSave(){
	std::cout << "Saved..?\n";
}

void
MainHandler::DoBattle(){
	std::cout << "On level " << sd->level << '\n';
	sd->level++;
}