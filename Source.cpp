#include<SFML\Graphics.hpp>
#include<random>
#include<ctime>

sf::Vector2f transform(sf::Image& image, sf::Vector2f pos) {
    sf::Vector2f temp;
	float r = (rand() % 100);
    if (r < 1)
        temp = sf::Vector2f(0, 0.16 * pos.y);
    else if (r < 89)
        temp = sf::Vector2f(0.85 * pos.x + 0.04 * pos.y, -0.04 * pos.x + 0.85 * pos.y - 1.60);
    else if (r < 94)
        temp = sf::Vector2f(0.20 * pos.x - 0.26 * pos.y, 0.23 * pos.x + 0.22 * pos.y - 1.60);
    else
        temp = sf::Vector2f(-0.15 * pos.x + 0.28 * pos.y, 0.26 * pos.x + 0.24 * pos.y - 0.44);
    image.setPixel(int((temp.x * 108) + 1080), int((temp.y * 108) + 1080), sf::Color::Green);
    return temp;
}

int main() {
	srand(time(NULL));
	
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Fern", sf::Style::Fullscreen);
	sf::Event event;
	sf::Color bgColor = sf::Color(8, 6, 12);

	sf::Image image;
	image.create(window.getSize().x, window.getSize().y, bgColor);
	sf::Texture texture;
	texture.loadFromImage(image);
	sf::Sprite fern(texture);

	sf::Vector2f pos(0, 0);
    sf::Vector2f scaled;

    while (window.isOpen()) {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                window.close();
            }

        }

        window.clear(bgColor);

		for (int i = 0; i < 100000; i++) {
			pos = transform(image, pos);
		}

		texture.loadFromImage(image);
		window.draw(fern);

        window.display();
    }
}
