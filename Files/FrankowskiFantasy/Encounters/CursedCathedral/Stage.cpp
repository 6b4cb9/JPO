#include "stdafx.h"
#include "Stage.h"

void Stage::setNextStage(Stage * stage){
	this->nextStage = stage;

}

void Stage::status(bool chest, bool wardrobe, bool boook){
	setBook(boook);
	setWardrobeKey(wardrobe);
	setChestKey(chest);
}

void Stage::setChestKey(bool set){
	this->chestKey = set;
}

void Stage::setWardrobeKey(bool set){
	this->wardrobeKey = set;
}

void Stage::setBook(bool set){
	this->book = set;
}

bool Stage::getChest()
{
	return this->chestKey;
}

bool Stage::getWadrobe()
{
	return this->wardrobeKey;
}

bool Stage::getBook()
{
	return this->book;
}

void Stage::status(bool child, bool book){
	setBook(book);
	setChild(child);
}

bool Stage::getChild()
{
	return this->child;
}

void Stage::setChild(bool set){

	this->child= set;
}

bool Stage::getFinishingstatus()
{
	return this->finishingStatus;
}

void Stage::setFinishingstatus(bool status) {

	this->finishingStatus = status;

}