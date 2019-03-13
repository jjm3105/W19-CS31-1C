#include "Zoo.h"
#include <iostream>

Zoo::Zoo(int MAX) {
	Herbivores = new Animal*[MAX];
	Carnivores = new Animal*[MAX];
	m_capacity = MAX;
	m_numH = 0;
	m_numC = 0;
}

Zoo::~Zoo() {
	for (int i = 0; i < m_numH; i++)
		delete Herbivores[i];
	for (int i = 0; i < m_numC; i++)
		delete Carnivores[i];

	delete [] Herbivores;
	delete [] Carnivores;
}

bool Zoo::AddAnimal(std::string name, bool isHerbivore, Toy* favorite) {
	if (isHerbivore) {
		if (m_numH >= m_capacity)
			return false;
		Herbivores[m_numH] = new Animal(name, isHerbivore, favorite);
		m_numH++;
	}
	else {
		if (m_numC >= m_capacity)
			return false;
		Carnivores[m_numC] = new Animal(name, isHerbivore, favorite);
		m_numC++;
	}

	return true;
}

bool Zoo::LetPlay(std::string name) {
	for (int i = 0; i < m_numH; i++) {
		if (Herbivores[i]->Name() == name) {
			return Herbivores[i]->Play();
		}
	}
	for (int i = 0; i < m_numC; i++) {
		if (Carnivores[i]->Name() == name) {
			return Carnivores[i]->Play();
		}	
	}

	return false;
}

void Zoo::Play() {
	for (int i = 0; i < m_numH; i++) {
		Herbivores[i]->Play();
	}
	for (int i = 0; i < m_numC; i++) {
		Carnivores[i]->Play();
	}
}

void Zoo::Sleep() {
	for (int i = 0; i < m_capacity; i++) {
		Herbivores[i]->StopPlay();
		Carnivores[i]->StopPlay();	
	}
}

void Zoo::Status() {
	for (int i = 0; i < m_numH; i++) {
		if (Herbivores[i]->isPlaying())
			std::cout << Herbivores[i]->Name() << " is playing!" << std::endl;
		else
			std::cout << Herbivores[i]->Name() << " is not!" << std::endl;
	}
	for (int i = 0; i < m_numC; i++) {
		if (Carnivores[i]->isPlaying())
			std::cout << Carnivores[i]->Name() << " is playing!" << std::endl;
		else
			std::cout << Carnivores[i]->Name() << " is not!" << std::endl;
	}
}
