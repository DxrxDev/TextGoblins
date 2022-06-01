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
	std::vector<Weapon> weapons;
	int hp, ar, st;
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
		std::cout << "What do you want to do? (n)ext battle, (m)enu, (q)uit\n: ";
		std::getline(std::cin, userInput);

		if(userInput == "q"){
			shouldQuit = true;
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
	sd = new SaveData{"player", {}, 3, 0, 2};
}

void
MainHandler::UpdateSave(){
	std::cout << "Saved..?\n";
}
