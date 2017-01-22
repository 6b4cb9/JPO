#ifndef AETHERARMORFACTORY_H
#define AETHERARMORFACTORY_H
#pragma once
class AetherArmorFactory;
#include "AbstractItemFactory.h"
#include"stdafx.h"
class AetherArmorFactory : public AbstractItemFactory
{
public:
	AetherArmorFactory();
	~AetherArmorFactory();
	Item* CreateItem();
};
#include "AetherArmor.h"
#endif