#pragma once

#include <set>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>


class GameObject
{
public:
	
	void assignTag(std::string tag);
	bool hasTag(std::string tag);
	
	
	bool isDead();
	void makeDead();

	
	virtual void update(sf::Time& elapsed) {}

	
	virtual void draw() {}

	
	bool isCollisionCheckEnabled();
	void setCollisionCheckEnabled(bool isCollisionCheckEnabled);

	
	virtual sf::FloatRect getCollisionRect() { return sf::FloatRect(); }

	virtual void handleCollision(GameObject& otherGameObject) {}

	virtual void handleEvent(sf::Event& event) {}

private:

	std::set<std::string> tags_;

	bool isDead_ = false;
	bool isCollisionCheckEnabled_ = false;
};

typedef std::shared_ptr<GameObject> GameObjectPtr;