#include "GameScene.h"
#include "Ship.h"
#include "meteorspawnser.h"

GameScene::GameScene() 
{
	ShipPtr ship = std::make_shared<Ship>();
	addGameObject(ship);

	MeteorSpawnerPtr meteorspawner = std::make_shared<MeteorSpawner>();
	addGameObject(meteorspawner);
}
