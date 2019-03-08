#include <iostream>
using namespace std;

class Room {
public:
	Room(string s) {
		name = s;
	}
	void DecidePrice(int input) {
		price = input;
	}
	int GetPrice() {
		return price;
	}
	string GetName() {
		return name;
	}
private:
	int price;
	string name;
};


class House {
public:
	House();
	~House();
	void SetPrice(int room, int price);
	void ListPrice();
private:
	Room* list[3];
};


House::House() {
	list[0] = new Room("Living Room");
	list[1] = new Room("Bedroom");
	list[2] = new Room("Bathroom");
}

House::~House() {
	delete list[0];
	delete list[1];
	delete list[2];
}

void House::SetPrice(int room, int price) {
	list[room-1]->DecidePrice(price);
}

void House::ListPrice() {
	for (int i = 0; i < 3; i++)
		cout << "The " << list[i]->GetName() << " has price "
			 << list[i]->GetPrice() << endl;
}






int main() {
	House Sproul;

	Sproul.SetPrice(1, 1000);
	Sproul.SetPrice(2, 2000);
	Sproul.SetPrice(3, 3000);

	Sproul.ListPrice();
}