/*
 * =====================================================================================
 *
 *       Filename:  DiabolousAttackBehaviour.hpp
 *
 *    Description:
 *
 *        Created:  21/06/2017 06:45:28
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef DIABOLOUSATTACKBEHAVIOUR_HPP_
#define DIABOLOUSATTACKBEHAVIOUR_HPP_

#include "AnimationListComponent.hpp"
#include "AttackBehaviour.hpp"
#include "RadarComponent.hpp"
#include "HealthComponent.hpp"
#include "DamageComponent.hpp"

class DiabolousAttackBehaviour : public AttackBehaviour {
	public:
		DiabolousAttackBehaviour() : AttackBehaviour("Attack") {}

		void action(SceneObject &object) override {
			AudioPlayer::playEffect("attack_monster1");
			auto &radarComponent = object.get<RadarComponent>();
			auto &object2 = radarComponent.neareastObject;
			if (object2 != nullptr && object2->has<HealthComponent>() && object.has<DamageComponent>()) {
				auto &healthComponent = object2->get<HealthComponent>();
				auto &damageComponent = object.get<DamageComponent>();
				healthComponent.removeLife(damageComponent.basicDamages);
			}
		}
};

#endif // DIABOLOUSATTACKBEHAVIOUR_HPP_
