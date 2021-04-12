#include <iostream>

using namespace std;
int counter;
class Proces{
protected:
    int nrProces;
    string reclamant;
    string reclamat;

public:
    Proces(int,string,string);
    Proces();
    Proces(const Proces&);
    ~Proces();

    Proces& operator=(const Proces&);

	friend istream& operator>>(istream& , Proces&);
	friend ostream& operator<<(ostream& , Proces&);
    virtual void afisare();
};


Proces::Proces()
{   this-> nrProces = ++counter;
    this-> reclamant = "nedefinit";
    this-> reclamat  = "nedefinit";
}

Proces::Proces(int a,string b,string c)
{   this-> nrProces = ++counter;
    this-> reclamant = b;
    this-> reclamat  = c;
}

Proces::Proces(const Proces& old)
{
    this-> nrProces = ++counter;
    this-> reclamant = old.reclamant;
    this-> reclamat  = old.reclamat;
}


Proces& Proces::operator=(const Proces& a)
{
    if (this != &a)
    {
        this-> nrProces  = a.nrProces;
        this-> reclamant = a.reclamant;
        this-> reclamat  = a.reclamat;
    }
    return *this;
}

istream& operator>>(istream& in, Proces& a)
{

	cout << "Nume Reclamant: " << endl;
	in   >> a.reclamant;
	cout << "Nume Reclamat:" << endl;
	in   >> a.reclamat;
	return in;
}

ostream& operator<<(ostream& out, Proces& a)
{
	cout<<"Numar Proces: ";
	out << a.nrProces << endl;
	cout<<"Nume Reclamant: ";
	out << a.reclamant << endl;
	cout<<"Nume Reclamat: ";
	out << a.reclamat << endl;
	return out;
}

void Proces::afisare()
{
    cout<<"Numar Proces: "<<nrProces<<endl;
    cout<<"Nume Reclamant: "<<reclamant<<endl;
    cout<<"Nume Reclamat: "<<reclamat<<endl;
}

class Proces_civil : public Proces{
protected:
    double dauneMorale;
    double dauneMateriale;
    int nrMartori;
    bool stadiu;
public:
    Proces_civil()
    {
        this->dauneMorale=0;
        this->dauneMateriale=0;
        this->nrMartori=0;
        this->stadiu=0;
    }
    Proces_civil(int nP, string r1, string r2):Proces(nP,r1,r2)
    {
        this->dauneMorale=0;
        this->dauneMateriale=0;
        this->nrMartori=0;
        this->stadiu=0;
    }
    Proces_civil(int nP,string r1,string r2,double a, double b, int c):Proces(nP,r1,r2)
    {
        this->dauneMorale=a;
        this->dauneMateriale=b;
        this->nrMartori=c;
        if (nrMartori>5)
            this->stadiu=1;
        else this->stadiu=0;
    }
    Proces_civil(const Proces_civil& old): Proces(old)
    {
        this->dauneMorale=old.dauneMorale;
        this->dauneMateriale=old.dauneMateriale;
        this->nrMartori=old.nrMartori;
        this->stadiu=old.stadiu;
    }
    ~Proces_civil();

    Proces_civil& operator=(const Proces_civil&);

	friend istream& operator>>(istream& , Proces_civil& );
	friend ostream& operator<<(ostream& , Proces_civil& );
    void afisare();
    friend double Taxa_timbru(const Proces_civil&);
};

Proces_civil& Proces_civil::operator=(const Proces_civil& a)
{
    if (this != &a)
    {
        Proces:operator=(a);
        this->dauneMorale=a.dauneMorale;
        this->dauneMateriale=a.dauneMateriale;
        this->nrMartori=a.nrMartori;
        this->stadiu=a.stadiu;
    }
    return *this;
}

istream& operator>>(istream& in, Proces_civil& a)
{
    in   >>(Proces&)a;
	cout << "Daune Morale: " << endl;
	in   >> a.dauneMorale;
	cout << "Daune Materiale: " << endl;
	in   >> a.dauneMateriale;
	cout << "Numar de martori: " << endl;
	in   >> a.nrMartori;
	if (a.nrMartori>5) a.stadiu=1;
	else a.stadiu=0;
	return in;
}
double Taxa_timbru(const Proces_civil& a)
{
    return (a.dauneMorale/10+a.dauneMateriale/10);
}

ostream& operator<<(ostream& out, Proces_civil& a)
{
    cout<<endl;
    out  << (Proces&)a;
	cout << "Daune Morale: " << endl;
	out  << a.dauneMorale << endl;
	cout << "Daune Materiale: " << endl;
	out  << a.dauneMateriale << endl;
	cout << "Numar de martori: " << endl;
	out  << a.nrMartori << endl;
    cout << "Stadiu: " << endl;
    out  << a.stadiu << endl;
	return out;
}

void Proces_civil::afisare()
{
    Proces::afisare();
    cout<<endl;
	cout << "Daune Morale: " << dauneMorale << endl;
	cout << "Daune Materiale: " << dauneMateriale << endl;
	cout << "Numar de martori: " << nrMartori << endl;
    cout << "Stadiu: " << stadiu << endl;
}




class Proces_penal : public Proces{
private:
    int dovezi;
    bool stadiu;
public:
    Proces_penal()
    {
        this->dovezi=0;
        this->stadiu=0;
    }
    Proces_penal(int nP, string r1, string r2):Proces(nP,r1,r2)
    {
        this->dovezi=0;
        this->stadiu=0;
    }
    Proces_penal(int nP,string r1,string r2,int a):Proces(nP,r1,r2)
    {
        this->dovezi=a;
        if (dovezi>25)
            this->stadiu=1;
        else this->stadiu=0;
    }
    Proces_penal(const Proces_penal& old): Proces(old)
    {
        this->dovezi=old.dovezi;
        this->stadiu=old.stadiu;
    }
    ~Proces_penal();

    Proces_penal& operator=(const Proces_penal&);

	friend istream& operator>>(istream& , Proces_penal& );
	friend ostream& operator<<(ostream& , Proces_penal& );
    void afisare();
};

Proces_penal& Proces_penal::operator=(const Proces_penal& a)
{
    if (this != &a)
    {
        Proces:operator=(a);
        this->dovezi=a.dovezi;
        this->stadiu=a.stadiu;
    }
    return *this;
}

istream& operator>>(istream& in, Proces_penal& a)
{
    in   >>(Proces&)a;
	cout << "Dovezi: " << endl;
	in   >> a.dovezi;
	if (a.dovezi>25) a.stadiu=1;
	else a.stadiu=0;
	return in;
}

ostream& operator<<(ostream& out, Proces_penal& a)
{
    cout<<endl;
    out  << (Proces&)a;
	cout << "Dovezi: " << endl;
	out  << a.dovezi << endl;
    cout << "Stadiu: " << endl;
    out  << a.stadiu << endl;
	return out;
}

void Proces_penal::afisare()
{
    Proces::afisare();
    cout<<endl;
    cout << "Dovezi: " << dovezi << endl;
    cout << "Stadiu: " << stadiu << endl;
}

int main()
{
    Proces **p;
    int n;
    cout<<"Introduceti numarul de procese: "<<endl;
    cin>>n;
    p= new Proces* [n];
    int a[100];
    for(int i=0;i<n;i++)
    {
        int optiune;
        cout<<"Alegeti tipul de proces: 1 - civil; 2 - penal. "<<endl;
        cin>>optiune;
        switch(optiune){
            case 1 :
            {
                p[i] = new Proces_civil();
                cin>>*dynamic_cast<Proces_civil*>(p[i]);
                a[i]=1;

            }
                break;
            case 2 :
            {
                p[i] = new Proces_penal();
                cin>>*dynamic_cast<Proces_penal*>(p[i]);
                a[i]=2;
            }
                break;
            default :
            {
                cout<<" Introduceti un tip de proces valabil."<<endl;
                cout<<endl;
                i--;
            }
        }
    }
    double maxim=0;
    for(int i=0;i<n;i++)
    {
        switch(a[i]){
            case 1 :
                {
                cout<<*dynamic_cast<Proces_civil*>(p[i]);
                cout<<" Taxa de timbru: ";
                cout<<Taxa_timbru(*dynamic_cast<Proces_civil*>(p[i]));
                cout<<endl;
                if (Taxa_timbru(*dynamic_cast<Proces_civil*>(p[i]))>maxim)
                    maxim=Taxa_timbru(*dynamic_cast<Proces_civil*>(p[i]));
                }
                break;
            case 2 :
                cout<<*dynamic_cast<Proces_penal*>(p[i]);
                break;
        }
    }
    cout<<endl;
    cout<<" Taxa de timbru maxima este: "<<maxim;


    delete [] p;

    return 0;
}
