#include<SFML/Graphics.hpp>
#include<Windows.h>
#include<ctime>

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
	bool delayStatus();
	void delayActivation();
	time_t startDelayStatus(float seconds);

private:
	sf::RectangleShape shape;
	sf::Vector2f velocity{ 0.0f, 0.0f };
	sf::Vector2f begginingSize{ 10.0, 10.0 };
	float speed{ 0.05f };
	bool delay = false;
	bool stop = false;
	time_t startDelay;
};

