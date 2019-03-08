#ifndef ZOO
#define ZOO

#include "Animal.h"

class Zoo
{
public:
	Zoo(int MAX);
	~Zoo();
	bool AddAnimal(std::string name, bool isHerbivore, Toy* favorite);
	bool LetPlay(std::string name);
	void Play();
	void Sleep();
	void Status();
private:
	// ???
};

#endif