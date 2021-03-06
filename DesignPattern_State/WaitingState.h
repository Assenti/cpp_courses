#pragma once
#include "IAutomatState.h"
class Automat;

class WaitingState : public IAutomatState
{
private:
	Automat * automat;
public:
	WaitingState(Automat *);
	std::string gotApplication() override final;
	std::string checkApplication() override final;
	std::string rentApartment() override final;
	std::string dispenseKeys() override final;
	~WaitingState();
};


