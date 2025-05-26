#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
  sf::SoundBuffer buffer;
  if (!buffer.loadFromFile("background_music.mp3")) {
    std::cout << "Error loading background music" << std::endl;
    return -1;
  }

  sf::Sound sound;
  sound.setBuffer(buffer);
  sound.play();

  while (sound.getStatus() == sf::Sound::Playing) {
    sf::sleep(sf::milliseconds(100));
  }

  return 0;
}
