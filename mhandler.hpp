#pragma once

/* Headers */

/* STD Headers */

/* Type definitions */
struct SaveData;

class MainHandler{
private:
	MainHandler();
	~MainHandler();
public:
	static MainHandler *CreateInstance();
	static void DeleteInstance(MainHandler *);

	void Run();

private:
	int ReadSave();
	void CreateSave();
	void UpdateSave();

	void DoBattle();

	SaveData *sd;
};
