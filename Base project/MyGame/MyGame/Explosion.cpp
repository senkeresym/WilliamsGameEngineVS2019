#include "Explosion.h"

Explosion::Explosion sf(sf::Vector2f pos)
: AnimatedSprite(pos);
{
	AnimatedSprite::setTexture(GAME.getTexture("Respurces/explosion-spritesheet.png"));
	SetIpExplosionAnimation();
	playAnimation();
	playAnimation("explosion", AnimationMode::OnceForwards);
	boom_.setBuffer(GAME.getSoundBuffer("Resources/boom.wav"));
	boom_.play();
}

void Explosion::SetUpExplosionAnimation()
{
	std::vector<sf::IntRect> frames;
	frames.push_back(sf::IntRect(0, 0, 64, 64));
	frames.push_back(sf::IntRect(64, 0, 64, 64));
	frames.push_back(sf::IntRect(128, 0, 64, 64));
	frames.push_back(sf::IntRect(192, 0, 64, 64));
	frames.push_back(sf::IntRect(256, 0, 64, 64));
	frames.push_back(sf::IntRect(320, 0, 64, 64));
	frames.push_back(sf::IntRect(384, 0, 64, 64));
	frames.push_back(sf::IntRect(448, 0, 64, 64));
	frames.push_back(sf::IntRect(512, 0, 64, 64));

	addAnimation("explosion", frames);
}

void Explosion::update(sf::Time& elasped)

{
	AnimatedSprite::update(elasped);

	if (!isPlaying())
	{
		makeDead();
	}
}