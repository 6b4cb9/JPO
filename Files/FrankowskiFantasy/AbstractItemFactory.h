#ifndef ABSTRACTITEMFACTORY_H
#define ABSTRACTITEMFACTORY_H
#pragma once
#include"stdafx.h"
class AbstractItemFactory;
#include "Item.h"
class AbstractItemFactory
{
public:
	AbstractItemFactory();
	~AbstractItemFactory();
	virtual Item* CreateItem() = 0;
};

#endif