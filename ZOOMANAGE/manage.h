#pragma once
#include "enclosure.h"
#include "caretaker.h"
#include "animal.h"
#include<vector>
class manage
{
	
	vector <enclosure*> ec;
	vector <caretaker*> ct;
	
public:
	
	void themmoi();
	void timkiem();
	void sapxep();
	void hienthi();
	void AddEnclosure(enclosure* enclosure);
	void AddCaretaker(caretaker* caretaker);
	void addcaretakertoenclosure(const string& caretakerID, const string& enclosureID);
	void DisplayAllCaretakers();
	void DisplayAllEnclosures();
	animal* FindAnimalByID(const string& ID);
	void FindAnimalsByName(const string& name);
	void RemoveAnimalByID(const string& ID);
	enclosure* FindEnclosureByID(const string& ID);
	caretaker* FindCaretakerByID(const string& ID);
	void runManager();
	animal* RemoveAnimalWithoutDelete(const string& ID);
	void LoadDataFromFile(const string& filename);
	void ExportToFile(const string& filename);
};

// Nguyen Minh Hieu