#include "funkcje.h"
#include "figura.h"
#include "pionek.h"
#include "wieza.h"
#include "szachownica.h"


int main()
{
	JakGrac();

	szachownica* _szachownica = new szachownica();

	koordynaty zpoz;
	koordynaty dopoz;

	bool czyjRuch = 1;
	bool koniecgry = 0;

	while (!koniecgry)
	{
		cout << "\x1B[2J\x1B[H";

		int ileruchow = _szachownica->IleMozliwychRuchow(czyjRuch);


		if (ileruchow == 0)
		{
			koniecgry = 1;

			if (_szachownica->CzyJestSzach(czyjRuch))
			{
				if (czyjRuch)
				{
					cout << "SZACH MAT! czarny wygral";
				}
				else 
					cout << "SZACH MAT! bialy wygral";
			}
			else
			{
				cout << "Remis PRZEZ PATA";
			}
			break;
		}
		if (_szachownica->Czyremis(czyjRuch)) 
		{
			cout << "REMIS";
			break;
		}


		_szachownica->Rysuj();

		//cout << ileruchow;

		if (czyjRuch)
		{
			cout << "ruch bialego "<<endl;
		}
		else
			cout << "ruch czarnego "<<endl;

		cout << pionek::ilepionkow;

		string ruch;
		cin >> ruch;
		
		if (ruch == "wyjdz")
		{
			koniecgry = 1;
			break;
		}
		else if (ruch == "O-O-O")
		{
			_szachownica->Roszdl(czyjRuch);
		}
		else if (ruch == "O-O")
		{
			_szachownica->Roszkr(czyjRuch);
		}
		else if(ruch.length() == 5 and ruch[2] == '-')
		{
		string skad = ruch.substr(0, 2);
		string dokad = ruch.substr(3, 5);

		zpoz = WpisaneNaPoz(skad);
		dopoz = WpisaneNaPoz(dokad);

		_szachownica->PrubujRusz(zpoz, dopoz, czyjRuch);
		}
		else
		{
			cout << "zle wpisany ruch"<<endl;
			system("pause");
		}
		
	
		
	}
	return 0;
}