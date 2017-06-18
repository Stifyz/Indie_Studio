/*
 * =====================================================================================
 *
 *       Filename:  CollisionComponent.hpp
 *
 *    Description:
 *
 *        Created:  20/04/2017 23:21:33
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef COLLISIONCOMPONENT_HPP_
#define COLLISIONCOMPONENT_HPP_

#include <functional>
#include <vector>

#include "SceneObject.hpp"

struct CollisionInfo {
	CollisionInfo(bool inCollision_, const std::string &entityName1_, const std::string &entityName2_)
		: inCollision(inCollision_), entityName1(entityName1_), entityName2(entityName2_) {}

	bool inCollision = false;

	std::string entityName1;
	std::string entityName2;
};

class CollisionComponent {
	using CollisionChecker = std::function<void(SceneObject&)>;
	using CollisionAction  = std::function<void(SceneObject&, SceneObject&, const CollisionInfo &)>;

	public:
		CollisionComponent(const std::vector<std::string> &entitiesToCheck = {"Body"})
			: m_entitiesToCheck(entitiesToCheck) {}

		void checkCollisions(SceneObject &object) {
			for(auto &checker : m_checkers) {
				checker(object);
			}
		}

		void collisionActions(SceneObject &object1, SceneObject &object2, const CollisionInfo &info) {
			for(auto &action : m_actions) {
				action(object1, object2, info);
			}
		}

		void addChecker(CollisionChecker checker) {
			m_checkers.push_back(checker);
		}

		void addAction(CollisionAction action) {
			m_actions.push_back(action);
		}

		const std::vector<std::string> &entitiesToCheck() const { return m_entitiesToCheck; }

	private:
		std::vector<std::string> m_entitiesToCheck;

		std::vector<CollisionChecker> m_checkers;
		std::vector<CollisionAction> m_actions;
};

#endif // COLLISIONCOMPONENT_HPP_
