#include <iostream>
#include <vector>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

class Apartament {
	const int anConstructie;
	const string adresa;
	bool esteDecomandat;
	float pret;
	int nrCamere;
	float * suprafeteCamere = nullptr;
	static bool esteMobilat;
	
public:
	Apartament(): anConstructie(1997), adresa("ewe") {
		pret = 30000.0;
		nrCamere = 1;
		suprafeteCamere = nullptr;
		esteDecomandat = false;
	}

	Apartament(float pret, int nrCamere) : anConstructie(1997), adresa("ewewewewewe") {
		if (pret >= 30000 && pret <= 200000) {
			this->pret = pret;
		}
		else {
			throw "Pretul este incorect.(trebuie sa apartina intervalului [30.000, 200.000])";
		}

		if (nrCamere >= 1 && nrCamere <= 4) {
			this->nrCamere = nrCamere;
			this->suprafeteCamere = new float[nrCamere];
			for (int i = 0; i < nrCamere; i++) {
				this->suprafeteCamere[i] = 5.0;
			}
		}
		else {
			this->nrCamere = 0;
			this->suprafeteCamere = nullptr;
			//throw "Numar de camere incorect.(numarul de camere trebuie sa apartina intervalului [1,4]";
		}
		esteDecomandat = false;
	}

	Apartament(bool esteDecomandat, float pret, 
		int nrCamere, float * suprafeteCamere,
		bool esteMobilat) : anConstructie(1997), adresa("weweew") {

		this->esteDecomandat = esteDecomandat;

		if (pret >= 30000 && pret <= 200000) {
			this->pret = pret;
		}
		else {
			this->pret = 0;
			throw "Pretul este incorect.(trebuie sa apartina intervalului [30.000, 200.000])";
		}

		if (nrCamere >= 1 && nrCamere <= 4) {
			this->nrCamere = nrCamere;
			this->suprafeteCamere = new float[nrCamere];
			for (int i = 0; i < nrCamere; i++) {
				this->suprafeteCamere[i] = suprafeteCamere[i];
			}
		}
		else {
			this->nrCamere = 0;
			this->suprafeteCamere = nullptr;
			throw "Numar de camere incorect.(numarul de camere trebuie sa apartina intervalului [1,4]";
		}
		this->esteMobilat = esteMobilat;
	}

	~Apartament() {

		if(suprafeteCamere != nullptr)
		delete[] suprafeteCamere;
	}


	void setPret(float pret) {
		if (pret >= 30000 && pret <= 200000) {
			this->pret = pret;
		}
		else {
			this->pret = 0;
			throw "Pretul este incorect.(trebuie sa apartina intervalului [30.000, 200.000])";
		}
	}

	float getPret() {
		return this->pret;
	}

	void setSuprafeteCamere(float* suprafeteCamere) {
		if (nrCamere != 0 && suprafeteCamere != nullptr) {
			for (int i = 0; i < nrCamere; i++) {
				this->suprafeteCamere[i] = suprafeteCamere[i];
			}
		}
		else {
			this->nrCamere = 0;
			this->suprafeteCamere = nullptr;
		}
	}

	float* getSuprafeteCamere() {
		float* sup = this->suprafeteCamere;
		return sup;
	}

	void setNrCamere(int nrCamere) {
		if (nrCamere >= 1 && nrCamere <= 4) {
			this->nrCamere = nrCamere;
		}
		else {
			throw("Numar de camere incorect.(numarul de camere trebuie sa apartina intervalului [1,4]");
		}
	}

	int getNrCamere() {
		return this->nrCamere;
	}

	Apartament(Apartament& a) : anConstructie(a.anConstructie), adresa(a.adresa) {
		esteDecomandat = a.esteDecomandat;
		pret = a.pret;
		nrCamere = a.nrCamere;
		suprafeteCamere = new float[nrCamere];
		if(a.suprafeteCamere!=nullptr)
		for (int i = 0; i < nrCamere; ++i) {
			suprafeteCamere[i] = a.suprafeteCamere[i];
		}
		else {
			suprafeteCamere = nullptr;
		}
		esteMobilat = a.esteMobilat;
	}

	Apartament operator=(Apartament a) {
		esteDecomandat = a.esteDecomandat;
		pret = a.pret;
		nrCamere = a.nrCamere;
		if (suprafeteCamere != nullptr)
			delete[] suprafeteCamere;
		suprafeteCamere = new float[nrCamere];
		for (int i = 0; i < nrCamere; i++) {
			suprafeteCamere[i] = a.suprafeteCamere[i];
		}
		esteMobilat = a.esteMobilat;

		return *this;
	}

	friend istream& operator>>(istream& in, Apartament& a);
	friend ostream& operator<<(ostream& out, Apartament a);
	friend bool operator>(Apartament a1, Apartament a2);

	Apartament& operator+=(float suprafataCamera) {
		float* aux = new float[nrCamere];
		if (nrCamere + 1 <= 4) {
			for (int i = 0; i < nrCamere; i++) {
				aux[i] = this->suprafeteCamere[i];
			}
			delete[] suprafeteCamere;
			this->suprafeteCamere = new float[nrCamere + 1];
			for (int i = 0; i < nrCamere; i++) {
				this->suprafeteCamere[i] = aux[i];
			}
			this->suprafeteCamere[nrCamere] = suprafataCamera;
			nrCamere++;
			return *this;
		}
		else {
			throw("Prea multe camere.");
		}
	}

	float operator[](int index) {
		if (index <= nrCamere) {
			return suprafeteCamere[index];
		}
		else {
			throw("OOB");
		}
	}

	static float mediaPreturilor(vector<Apartament> &preturi, int nrApartamente) {
		float totalPret = 0;
		float media;
		for (Apartament a : preturi) {
			totalPret += a.pret;
		}
		media = totalPret / nrApartamente;
		return media;
	}

	float calculSuprafataTotala() {
		float suprafata = 0;
		for (int i = 0; i < nrCamere; i++) {
			suprafata += suprafeteCamere[i];
		}
		return suprafata;
	}

	float calculPretPeMetruPatrat() {
		float suprafata = calculSuprafataTotala();
		float pretPeMetruPatrat = this->pret/suprafata;
		return pretPeMetruPatrat;
	}
};

bool operator>(Apartament a1, Apartament a2) {
	if (a1.pret > a2.pret) {
		return true;
	}
	else {
		return false;
	}
}

istream& operator>>(istream& in, Apartament& a) {
	cout << "Este decomandat: ";
	in >> a.esteDecomandat;
	while (a.esteDecomandat != 0 && a.esteDecomandat != 1) {
		cout << "0=nu, 1=da" << endl;
		in >> a.esteDecomandat;
	}
	cout << endl;
	cout << "Pret: ";
	in >> a.pret;
	while (a.pret < 30000 && a.pret >200000) {
		cout << "Pretul trebuie sa apartina intervalului [30.000, 200.000]" << endl;
		in >> a.pret;
	}
	cout << "Nr Camere: ";
	in >> a.nrCamere;
	while(a.nrCamere<1 || a.nrCamere>4) {
		cout << "Prea multe camere" << endl;
		in >> a.nrCamere;
		
	}
	cout << endl;
	cout << "Suprafete camere: ";
	if (a.suprafeteCamere != nullptr)
		delete[] a.suprafeteCamere;
	a.suprafeteCamere = new float[a.nrCamere];
	for (int i = 0; i < a.nrCamere; i++)
		in >> a.suprafeteCamere[i];
	cout << endl;
	cout << "Este mobilat: ";
	in >> a.esteMobilat;
	while (a.esteMobilat != 0 && a.esteMobilat != 1) {
		cout << "0=nu, 1=da" << endl;
		in >> a.esteMobilat;
	}
	cout << endl;

	return in;
}

ostream& operator<<(ostream& out, Apartament a) {
	out << "Este decomandat(0=nu;1=da): " << a.esteDecomandat << ", Pret: " << a.pret << ", Nr camere: " << a.nrCamere << ", Este mobilat(0=nu;1=da): " << a.esteMobilat <<
		", Adresa: " << a.adresa << ", An constructie: " << a.anConstructie << ", Suprafete camere: ";
	if(a.suprafeteCamere !=nullptr)
	for (int i = 0; i < a.nrCamere; i++) {
		out << a.suprafeteCamere[i] << " ";
	}
	else {
		out << "Suprafetele camerelor nu au fost specificate" << endl;
	}
	cout << endl;
	return out;
}



bool Apartament::esteMobilat = false;

int main() {
	Apartament a;
	cout << a;

	Apartament a1(40000, 1);
	cout << a1;

	float v[] = { 4.0f,5.0f, 6.0f, 7.0f };
	Apartament a2(true, 50000.0f, 4, v, true);
	cout << a2;

	cout << "Pret initial a2: " << a2.getPret() << endl;
	a2.setPret(200000);
	cout << "Pret schimbat a2: " << a2.getPret() << endl;

	float* sup = a2.getSuprafeteCamere();
	cout << "Suprafetele initiale ale camerelor a2: " <<  endl;
	for (int i = 0; i < a2.getNrCamere(); i++) {
		cout << sup[i] << " " ;
	}
	cout << endl;
	float v2[] = { 10.0f, 11.0f, 12.0f, 13.0f };
	a2.setSuprafeteCamere(v2);

	float* sup2 = a2.getSuprafeteCamere();
	cout << "Suprafetele camerelor a2 dupa ce au fost schimbate: " << endl;
	for (int i = 0; i < a2.getNrCamere(); i++) {
		cout << sup2[i] << " ";
	}
	cout << endl;

	cout << "Nr camere a2: " << a2.getNrCamere() << endl;
	a2.setNrCamere(1);
	cout << "Nr camere a2(schimbat): " << a2.getNrCamere() << endl;

	Apartament a3(a2);
	cout << a3;

	a3 = a1;
	cout << a3;

	/*Apartament a4;
	cin >> a4;
	cout << a4;*/

	cout << a1;
	a1 += 5.0f;
	cout << a1;
	
	cout << "Suprafata camera 2 a apartamentului a1: " << a1[1] << endl;

	cout << "Pretul lui a1: " << a1.getPret() << endl;
	cout << "Pretul lui a2: " << a2.getPret() << endl;
	if (a1 > a2) {
		cout << "Pretul lui a1 este mai mare decat pretul lui a2" << endl;
	}
	else {
		cout << "Pretul lui a2 este mai mare decat pretul lui a1" << endl;
	}

	//vector<Apartament> va{ {111111.0f,2}, {121212.0f, 3} };
	//sau
	//va.push_back(a1);
	//va.push_back(a2);
	//cout << "Media preturilor apartamentelor a1, a2, a3: " << Apartament::mediaPreturilor(va, 3) << endl;
	//Ma scuzati, nu am reusit sa implementez aceasta metoda cat sa o si pot folosi pentru ca nu stiu cum sa 
	//pasez acel vector de obiecte fara sa am erori(trebuie sa fac un alt copy constructor ca sa functioneze--cred)

	cout << "Suprafata totala a1: " << a1.calculSuprafataTotala() << endl;
	cout << "Pret pe metru patrat a1: " << a1.calculPretPeMetruPatrat() << endl;
	

}