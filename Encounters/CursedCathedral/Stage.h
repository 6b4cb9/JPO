#pragma once
#include "Character.h"
class Stage
{
protected:
	int lvl;
	Stage * nextStage;
	bool chestKey;
	bool wardrobeKey;
	bool book;
	bool child;	
	bool finishingStatus;

public:
	void setNextStage(Stage * stage);
	virtual bool proceed(Character * adventourer) = 0;
	void status(bool chest, bool wardrobe, bool book);
	void setChestKey(bool set);
	void setWardrobeKey(bool set);
	void setBook(bool set);
	bool getChest();
	bool getWadrobe();
	bool getBook();
	void status(bool child, bool book);

	bool getChild();

	void setChild(bool set);

	bool getFinishingstatus();

	void setFinishingstatus(bool status);

};

