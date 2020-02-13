#include "Zombie.h"
#include "Framework/Animation.h"

Zombie::Zombie() {
	// Setup walk animation
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(1.f / 13.f);
}

Zombie::~Zombie() {

}

void Zombie::update(float dt) {
	walk.animate(dt);
	setTextureRect(walk.getCurrentFrame());
}

void Zombie::handleInput(float dt) {
	if (input->isKeyDown(sf::Keyboard::D)) {
		move(75 * dt, 0);
		walk.setFlipped(false);
	}
	else if (input->isKeyDown(sf::Keyboard::A)) {
		move(-75 * dt, 0);
		walk.setFlipped(true);
	}

	if (input->isKeyDown(sf::Keyboard::S)) {
		move(0, 45 * dt);
	}
	else if (input->isKeyDown(sf::Keyboard::W)) {
		move(0, -45 * dt);
	}
}