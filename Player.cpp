#include "Player.h"

Player::Player(float startPos_x, float startPos_y)
{
	shape.setSize(begginingSize);
	shape.setFillColor(sf::Color::Blue);
	shape.setOutlineThickness(1.0);
	shape.setOutlineColor(sf::Color::Black);
	shape.setPosition(startPos_x, startPos_y);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->shape, state);
}

void Player::update()
{
	shape.move(this->velocity);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && this->velocity.y == 0)
	{
		this->velocity.x = 0.0f;
		this->velocity.y = -this->speed;
		this->horizontalMove = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && this->velocity.y == 0)
	{
		this->velocity.x = 0.0f;
		this->velocity.y = this->speed;
		this->horizontalMove = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && this->velocity.x == 0)
	{
		this->velocity.x = this->speed;
		this->velocity.y = 0.0f;
		this->horizontalMove = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && this->velocity.x == 0)
	{
		this->velocity.x = -this->speed;
		this->velocity.y = 0.0f;
		this->horizontalMove = true;
	}
}

float Player::top()
{
	return shape.getPosition().y;
}

float Player::bottom()
{
	return shape.getPosition().y + shape.getSize().y;
}

float Player::left()
{
	return shape.getPosition().x;
}

float Player::right()
{
	return shape.getPosition().x + shape.getSize().x;
}

float Player::horizDir()
{
	return this->velocity.x;
}

float Player::verticDir()
{
	return this->velocity.y;
}

float Player::blockSize()
{
	return shape.getSize().x;
}

sf::Vector2f Player::getVelocity()
{
	return this->velocity;
}

void Player::setVelocity(sf::Vector2f vel)
{
	this->velocity = vel;
}

void Player::tailUpdate(Player &block)
{
	shape.move(this->velocity);

	if (this->velocity != block.getVelocity())
	{
		if (block.getVelocity().x == 0)
		{
			if (this->left() <= block.left() + 0.1 && this->left() >= block.left() - 0.1 || this->right() <= block.right() + 0.1 && this->right() >= block.right() - 0.1)
			{
				if (block.getVelocity().y < 0)
				{
					shape.setPosition(sf::Vector2f(block.left(), block.bottom()));
				}

				if (block.getVelocity().y > 0)
				{
					shape.setPosition(sf::Vector2f(block.left(), block.top()-shape.getSize().x));
				}
				
				this->velocity = block.getVelocity();
			}
		}

		if (block.getVelocity().x != 0)
		{
			if (this->top() <= block.top() + 0.1 && this->top() >= block.top() - 0.1 || this->bottom() <= block.bottom() + 0.1 && this->bottom() >= block.bottom() - 0.1)
			{
				if (block.getVelocity().x < 0)
				{
					shape.setPosition(sf::Vector2f(block.right(), block.top()));
				}

				if (block.getVelocity().x > 0)
				{
					shape.setPosition(sf::Vector2f(block.left() - shape.getSize().x, block.top()));
				}

				this->velocity = block.getVelocity();
			}
		}
	}
}
