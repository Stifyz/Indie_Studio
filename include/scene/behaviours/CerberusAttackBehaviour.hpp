/************************************************************\
|*                                                          *|
|* Copyright (C) (2017) by zimmer_n
|*                                                          *|
|* CerberusAttackBehaviour.hpp for project :
|*                                                          *|
|* Created: 2017-06-21 13:54
|*                                                          *|
\************************************************************/

#ifndef CERBERUSATTACKBEHAVIOUR_HPP_
#define CERBERUSATTACKBEHAVIOUR_HPP_

#include "AnimationListComponent.hpp"
#include "AttackBehaviour.hpp"
#include "RadarComponent.hpp"
#include "HealthComponent.hpp"
#include "DamageComponent.hpp"

class CerberusAttackBehaviour : public AttackBehaviour {
	public:
		CerberusAttackBehaviour() : AttackBehaviour("Fight") {}

		void action(SceneObject &object) override {
			// AudioPlayer::playEffect("attack_monster1");
			auto &radarComponent = object.get<RadarComponent>();
			auto &object2 = radarComponent.neareastObject;
			if (object2 != nullptr && object2->has<HealthComponent>() && object.has<DamageComponent>()) {
				auto &healthComponent = object2->get<HealthComponent>();
				auto &damageComponent = object.get<DamageComponent>();
				healthComponent.removeLife(damageComponent.basicDamages);
			}
		}
};

#endif // !CERBERUSATTACKBEHAVIOUR_HPP_
