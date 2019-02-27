#include <iostream>
#include <string>
using namespace std;

class Nation
{
	public:
		Nation(int size, int b, int d) {
			m_population = size;
			m_year = 0;
			m_birth = b;
			m_death = d;
		}
		int population() {
			return m_population;
		}
		int year() {
			return m_year;
		}
		void pass_year() {
			m_population = m_population + m_birth - m_death;
			m_birth *= 3;
			m_death += 2;
		}

	private:
		int m_population;
		int m_year;
		int m_birth;
		int m_death;
};

int main()
{
	Nation	France(2000, 100, 75),
			USA(5000, 500, 475),
			Japan(3000, 100, 200),
			Brazil(4000, 375, 100);

	for (int i = 0; i < 5; i++) {
		France.pass_year();
		USA.pass_year();
		Japan.pass_year();
		Brazil.pass_year();
	}

	cout << "France: " << France.population() << endl;
	cout << "USA: " << USA.population() << endl;
	cout << "Japan: " << Japan.population() << endl;
	cout << "Brazil: " << Brazil.population() << endl;
}
