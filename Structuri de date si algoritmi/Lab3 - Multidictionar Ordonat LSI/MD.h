#pragma once
#include<vector>
#include<utility>

using namespace std;

typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;
class Node{
    friend class MD;
    friend class IteratorMD;

private:
    Node* urmator;
    TElem informatie;
};
class IteratorMD;

class MD
{
	friend class IteratorMD;

private:
    Node* head;
    int numar_perechi;
	/* aici e reprezentarea */

public:
	// constructorul implicit al MultiDictionarului
	MD();

	// adauga o pereche (cheie, valoare) in MD	
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MD 
	int dim() const;

	//verifica daca MultiDictionarul e vid 
	bool vid() const;

	// se returneaza iterator pe MD
	IteratorMD iterator() const;

	// destructorul MultiDictionarului	
	~MD();

    //returneaza diferenta dintre valoarea maxima si valoarea minima (pp valori intregi)
    //daca dictionarul este vid, se returneaza-1
    int diferentaValoareMaxMin()const;


};

