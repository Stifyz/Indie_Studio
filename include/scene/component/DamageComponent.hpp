/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* DamageComponent.hpp for project :
|*                                                          *|
|* Created: 2017-06-21 12:48
|*                                                          *|
\************************************************************/

#ifndef DAMAGECOMPONENT_HPP_
#define DAMAGECOMPONENT_HPP_

#include "IntTypes.hpp"

class DamageComponent {
	public:
		DamageComponent(u16 bDamages = 0, u16 sDamages = 0) : basicDamages(bDamages), secondaryDamages(sDamages) {}

		const u16 basicDamages = 0;
		const u16 secondaryDamages = 0;
};

#endif // !DAMAGECOMPONENT_HPP_
