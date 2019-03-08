#ifndef TOY
#define TOY

#include <string>

class Toy
{
public:
	Toy() {
		isPlayed = false;
		m_player = "";
	}
	bool Play(std::string name) {
		if (isPlayed)
			return false;

		isPlayed = true;
		m_player = name;

		return true;
	}
	bool Finish(std::string name) {
		if (!isPlayed)
			return false;

		if (name == m_player) {
			isPlayed = false;
			m_player = "";
			return true;
		}

		return false;
	}
	bool isBeingPlayed() { return isPlayed; }
	std::string whoIsPlaying() { return m_player; }
private:
	bool isPlayed;
	std::string m_player;
};

#endif