#include "GameScene.h"
#include "Ship.h"
#include "meteorspawnser.h"
#include "Score.h"

GameScene::GameScene() 
{
	ShipPtr ship = std::make_shared<Ship>();
	addGameObject(ship);

	MeteorSpawnerPtr meteorspawner = std::make_shared<MeteorSpawner>();
	addGameObject(meteorspawner);

	ScorePtr score = std::make_shared<Score>(sf::Vector2f(10.0f, 10.0f));
	addGameObject(score);
}

int GameScene::getScore()
{
	return score_;
}

void GameScene::increaseScore()
{
	++score_;
}

int GameScene::getLives()
{
	return lives_;
}

void GameScene::decreaseLives()
{
	--lives_;

	if (lives_ == 0)
	{
		GameObjectPtr gameOverScene = std::make_shared<GameOverScene>(score_);
		GAME.setScene(gameOverScene);
	}
}