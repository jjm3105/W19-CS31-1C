#ifndef ANIMAL
#define ANIMAL

#include "Toy.h"
#include <string>


class Animal
{
public:
	Animal(std::string name, bool isHerbivore, Toy* favorite) {
		m_name = name;
		m_herbivore = isHerbivore;
		m_favorite = favorite;
	}
	bool Play() { 
		if (!m_favorite->isBeingPlayed())
			return m_favorite->Play(m_name);

		return false;
	}
	bool StopPlay() {
		return m_favorite->Finish(m_name);
	}
	bool isPlaying() {
		return m_name == m_favorite->whoIsPlaying();
	}
	std::string Name() {
		return m_name;
	}
	bool isHerbivore() {
		return m_herbivore;
	}
private:
	std::string m_name;
	bool m_herbivore;
	Toy* m_favorite;
};

#endif