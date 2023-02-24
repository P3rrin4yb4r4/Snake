#include<SFML/Graphics.hpp>

class Player : public sf::Drawable
{
public:
	Player(float startPos_x, float startPos_y);
	~Player() = default;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
	void update();
	float top();
	float bottom();
	float left();
	float right();
	float horizDir();
	float verticDir();
	float blockSize();
	sf::Vector2f getVelocity();
	void setVelocity(sf::Vector2f vel);
	void tailUpdate(Player &block);

private:
	bool horizontalMove;
	sf::RectangleShape shape;
	sf::Vector2f velocity{ 0.0f, 0.0f };
	sf::Vector2f begginingSize{ 20.0, 20.0 };
	float speed{ 0.05f };
};

