#include <iostream>
#include "Zoo.h"
using namespace std;

int main()
{
	Toy Ball;
	Toy Trampoline;
	Toy Pickaxe;

	Zoo Steve(5);

	Steve.AddAnimal("Mr. Pickles", false, &Ball);
	Steve.AddAnimal("Rudolph", true, &Trampoline);
	Steve.AddAnimal("Carlos", true, &Pickaxe);

	Steve.AddAnimal("Stinger", false, &Ball);
	Steve.AddAnimal("Secretariat", true, &Pickaxe);

	Steve.Play();
	Steve.Status();
}