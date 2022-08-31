#include<SFML\Graphics.hpp>
#include<random>
#include<ctime>

sf::Vector2f transform(sf::Image& image, sf::Vector2f pos) {
	int r = rand() % 100;
	if (r == 0) {
		image.setPixel(int(1080), int((108 * (0.16 * pos.y)) + 1080), sf::Color::Red);
		return sf::Vector2f(0, 0.16 * pos.y);
	}
	else if (r < 8) {
		image.setPixel(int(108 * (0.85 * pos.x + 0.04 * pos.y) + 1080), int(108 * (-0.04 * pos.x + 0.85 * pos.y - 1.60) + 1080), sf::Color::Blue);
		return sf::Vector2f(0.85 * pos.x + 0.04 * pos.y, -0.04 * pos.x + 0.85 * pos.y - 1.60);
	}
	else if (r < 15) {
		image.setPixel(int(108 * (0.20 * pos.x - 0.26 * pos.y) + 1080), int(108 * (0.23 * pos.x + 0.22 * pos.y - 1.60) + 1080), sf::Color::Cyan);
		return sf::Vector2f(0.20 * pos.x - 0.26 * pos.y, 0.23 * pos.x + 0.22 * pos.y - 1.60);
	}
	else {
		image.setPixel(int(108 * (-0.15 * pos.x + 0.28 * pos.y) + 1080), int(108 * (0.26 * pos.x + 0.24 * pos.y - 0.44) + 1080), sf::Color::Yellow);
		return sf::Vector2f(-0.15 * pos.x + 0.28 * pos.y, 0.26 * pos.x + 0.24 * pos.y - 0.44);
	}
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

		for (int i = 0; i < 100; i++) {
			pos = transform(image, pos);
		}

		texture.loadFromImage(image);
		window.draw(fern);

        window.display();
    }
}
