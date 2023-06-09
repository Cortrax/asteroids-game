#include "bullet.hpp"
#include "player.hpp"

Bullet::Bullet(int width, int height)
{
	bullet.setSize(sf::Vector2f(width, height));
	bullet.setOrigin(width / 2, height / 2);
	bullet.setFillColor(sf::Color(220, 220, 220));
}

void Bullet::setPos(sf::Vector2f newPos)
{
	bullet.setPosition(newPos);
}

void Bullet::drawTo(sf::RenderWindow& window)
{
	window.draw(bullet);
}

void Bullet::fireBullet(int speed, Player& player, float& dt)
{
	auto playerDirX = player.returnAngle() * M_PI / 180;
	auto playerDirY = player.returnAngle() * M_PI / 180;
	velocity.x = speed * cos(playerDirX);
	velocity.y = speed * sin(playerDirY);

	bullet.move(velocity * dt);
}

void Bullet::moveBullet(float dt)
{
	bullet.move(velocity * dt);
}

int Bullet::returnPosX()
{
	return bullet.getPosition().x;
}

int Bullet::returnPosY()
{
	return bullet.getPosition().y;
}
