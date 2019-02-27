#include <iostream>
using namespace std;

class Nation {
	public:
		Nation(int size, string capital) {
			m_population = size;
			m_capital = capital;
		}
		int population() {
			return m_population;
		}
		string capital() {
			return m_capital;
		}
		void increase() {
			m_population++;
		}
	private:
		int m_population;
		string m_capital;
};

int pivot(Nation array[], int size, Nation Cmp)
{
	int ind = 0;
	int cur = 0;
	int count = 0;

	while (ind < size)
	{
		if (array[ind].population() < Cmp.population())
		{
			Nation temp = array[cur];
			array[cur] = array[ind];
			array[ind] = temp;

			count++;
			cur++;
		}

		ind++;
	}

	return count;
}

int main()
{
	Nation 	France(67, "Paris"), 			Italy(60, "Rome"),
			USA(325, "Washington D.C."), 	Japan(128, "Tokyo"),
			Thailand(69, "Bangkok"), 		Brazil(209, "Brasilia");

	Nation States[5] = { France, Italy, USA, Thailand, Brazil };

	cout << pivot(States, 5, Japan) << endl;

	for (int i = 0; i < 5; i++)
		cout << States[i].capital() << endl;
}