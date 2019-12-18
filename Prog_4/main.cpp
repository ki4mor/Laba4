#include "stdlib.h"
#include "Landscape.h"
#include "menu.h"


using namespace std;
using namespace laba4;
using namespace menu;

int main(int argc, const char* argv[]) {
	Landscape L;
	L.read_school();
	vector<pair<string, unsigned int> > p;
	L.set_user_summoner(L.create_summoner("User", p, "C:\\txt_files\\User_Summoner.txt"));
	L.set_enemy_summoner(L.create_summoner("Enemy", p, "C:\\txt_files\\Enemy_Summoners.txt"));
	L.input_map();
	Immoral_Troop tr;
	for (int i=0; i < 5; i++) {
	cout << L.get_School(i) << endl;
}
	cout << L;
	int  fl = 1;
	do {
		char  d = dialog();
		if (menu_t(d,L)) {
			system("pause");
			return 1;
		}
		system("pause");
		system("cls");
		

	} while (fl);


	std::cin.get();
	return 0;
	}
