#include "manage.h"
#include<iostream>
#include"mammal.h"
#include"bird.h"
#include"reptile.h"
#include <algorithm>
#include <fstream>
#include <sstream>
class enclosure;

using namespace std;
void swap(animal* a, animal* b)
{
	animal* temp;
	temp = a;
	a = b;
	b = temp;
}
void manage::LoadDataFromFile(const string& filename)
{
	ifstream file(filename);
	if (!file.is_open())
	{
		cout << "Khong mo duoc file!" << endl;
		return;
	}

	string line;
	while (getline(file, line))
	{
		if (line.empty()) continue;

		stringstream ss(line);
		string type;
		ss >> type;

		
		// Đọc ENLOSURE
		
		if (type == "ENCLOSURE")
		{
			string id, name;
			ss >> id;
			getline(ss, name);
			if (!name.empty() && name[0] == ' ') name.erase(0, 1);

			enclosure* e = new enclosure(id, name);
			ec.push_back(e);
		}

		// --------------------
		// Đọc CARETAKER
		// --------------------
		else if (type == "CARETAKER")
		{
			string id, name;
			ss >> id;
			getline(ss, name);
			if (!name.empty() && name[0] == ' ') name.erase(0, 1);

			caretaker* c = new caretaker(id, name);
			ct.push_back(c);
		}

		// --------------------
		// Đọc ANIMAL
		// --------------------
		else if (type == "ANIMAL")
		{
			string loai;
			ss >> loai;

			animal* an = nullptr;

			if (loai == "MAMMAL") an = new mammal();
			else if (loai == "BIRD") an = new bird();
			else if (loai == "REPTILE") an = new reptile();

			if (an)
			{
				// Tự tạo hàm đọc từ string
				an->nhapFromStream(ss);

				enclosure* e = FindEnclosureByID(an->hienthienclosureid());
				if (e)
					e->them(an);
			}
		}

		// --------------------
		// Gán caretaker vào enclosure
		// --------------------
		else if (type == "ASSIGN_CARETAKER")
		{
			string cid, eid;
			ss >> cid >> eid;

			addcaretakertoenclosure(cid, eid);
		}
	}

	file.close();
	cout << "Da nap du lieu tu file thanh cong!" << endl;
}
void manage::themmoi()
{
	int choice;
	cout << "\n--- Nhap Thong Tin Dong Vat Moi ---" << endl;
	cout << "1. Bird" << endl;
	cout << "2. Mammal" << endl;
	cout << "3. Reptile" << endl;
	cout << "Chon loai dong vat: ";
	cin >> choice;
	cin.ignore();

	animal* newAnimal = nullptr;

	switch (choice) {
	case 1:
		newAnimal = new bird();
		cout << "\n- Nhap thong tin Bird -" << endl;
		break;
	case 2:
		newAnimal = new mammal();
		cout << "\n- Nhap thong tin Mammal -" << endl;
		break;
	case 3:
		newAnimal = new reptile();
		cout << "\n- Nhap thong tin Reptile -" << endl;
		break;
	default:
		cout << "LOI: Lua chon khong hop le." << endl;
		return;
	}

	if (newAnimal) {
		newAnimal->nhap();
		string encID;
		cout << "Nhap ID chuong muon chuyen den (bo qua neu chua muon chuyen): ";
		getline(cin, encID);

		if (!encID.empty()) {
			enclosure* enc = FindEnclosureByID(encID);
			if (enc) {
				
				enc->them(newAnimal);
			}
			else {
				cout << "Canh bao: Khong tim thay chuong ID " << encID << ". Dong vat hien tai khong co chuong." << endl;
			}
		}
	}
}

void manage:: sapxep() {
	
		char choice;
		do {
			cout << "Sap xep tat ca dong vat theo (tuoi/can)(1/2): ";
			cin >> choice;
			cin.ignore();

			vector<animal*> allAnimals;
			for (auto& e : ec) {
				auto& v = e->getAnimals(); 
				allAnimals.insert(allAnimals.end(), v.begin(), v.end());
			}

		
			for (size_t i = 0; i < allAnimals.size() - 1; i++) {
				for (size_t j = 0; j < allAnimals.size() - i - 1; j++) {
					if ((choice == '1' && allAnimals[j]->hienthituoi() < allAnimals[j + 1]->hienthituoi()) ||
						(choice == '2' && allAnimals[j]->hienthican() < allAnimals[j + 1]->hienthican())) {
						swap(allAnimals[j], allAnimals[j + 1]); 
					}
				}
			}

			
			cout << "=== Danh sach dong vat sau khi sap xep ===\n";
			for (auto& a : allAnimals) a->hienthi();

			cout << "Tiep tuc hay khong (y/n)? ";
			cin >> choice;
		} while (choice == 'y');
	}
void manage::hienthi() {
	vector<animal*> allAnimals;
	for (auto& e : ec) {
		auto& v = e->getAnimals();
		allAnimals.insert(allAnimals.end(), v.begin(), v.end());
	}
	int i = 1;
	cout << "=== Danh sach tat ca dong vat trong so thu ===\n";
	for (auto& e : allAnimals) {
		cout << i++ << ". " << e->hienthiten() << " (ID: " << e->hienthiid() << ", Loai: " << e->hienthitype() << ")" << endl;
		cout << "----------------------\n";
	}
}
void manage::AddEnclosure(enclosure* e)
{
	ec.push_back(e);
		cout << "Them chuong thanh cong: ID " << e->getEnclosureID() << endl;
	
}
void manage::AddCaretaker(caretaker* c)
{
	
	ct.push_back(c);
			cout << "Them nhan vien thanh cong: " << c->getName() << " (ID: " << c->getId() << ")" << endl;
	
	}
void manage::addcaretakertoenclosure(const string& cid, const string& eid)
{
	caretaker* c = FindCaretakerByID(cid);
	enclosure* e = FindEnclosureByID(eid);

	if (!c || !e) {
		cout << "khong tim thay chuong hoac nhan vien phu hop\n";
		return;
	}

	e->addcaretaker(c);
	
}
void manage::DisplayAllCaretakers() {
	cout << "\n========== DANH SACH NHAN VIEN  ==========" << endl;
	if (ct.size() == 0) {
		cout << "Chua co nhan vien nao trong he thong." << endl;
		return;
	}
	for (auto c:ct) {
		c->hienthi();
		cout << "---" << endl;
	}
	cout << "==========================================================\n" << endl;
}
void manage::DisplayAllEnclosures() {
	cout << "\n========== DANH SACH CHUONG  ==========" << endl;
	if (ec.size() == 0) {
		cout << "Chua co chuong nao trong he thong." << endl;
		return;
	}
	for (auto* e:ec) {
		e->DisplayOccupants();
	}
	cout << "=======================================================\n" << endl;
}
animal* manage::FindAnimalByID(const string& ID)
{
	for (auto& chuong : ec)
	{
		vector<animal*>& ds = chuong->getAnimals();
		for (auto* a : ds)
		{
			if (a->hienthiid() == ID)
				return a;
			}
	}
	return nullptr;
}
void manage::FindAnimalsByName(const string& name) {
	cout << "\n========== KET QUA TIM KIEM THEO TEN (" << name << ") ==========" << endl;
	bool found = false;
	for (auto& chuong : ec)
	{
		vector<animal*>& ds = chuong->getAnimals();
		for (auto* a : ds)
		{
			if (a->hienthiten() == name)
			{
				cout << "ID: " <<a->hienthiid() << " | Ten: " << a->hienthiten() << " | Chuong: " << a->hienthienclosureid() << endl;
				found = true;
			}
		}
	}
	if (!found) {
		cout << "Khong tim thay dong vat nao voi ten  '" << name << "'." << endl;
	}
	cout << "===============================================================\n" << endl;
}
void manage::RemoveAnimalByID(const string& ID) {
	bool found = false;

	for (auto& enclosure : ec)                   
	{
		auto& animals = enclosure->getAnimals();   

		for (auto it = animals.begin(); it != animals.end(); ++it)
		{
			if ((*it)->hienthiid() == ID)            
			{
				delete* it;                       // giải phóng bộ nhớ động
				animals.erase(it);                // xóa khỏi vector
				cout << "Da xoa dong vat co ID: " << ID << endl;
				found = true;
				return;                           
			}
		}
	}

	if (!found)
		cout << "Khong tim thay dong vat co ID: " << ID << endl;
}
enclosure* manage::FindEnclosureByID(const string& ID)
{
	for (auto e:ec) {
		if (e->getEnclosureID() == ID) {
			return e;
		}
	}
	return nullptr;
}
caretaker* manage::FindCaretakerByID(const string& ID) {
	for (auto c : ct) {
		if (c->getId() == ID) {
			return c;
		}
	}
	return nullptr;
}
animal* manage::RemoveAnimalWithoutDelete(const string& ID)
{
	for (auto& enclosure : ec)
	{
		auto& animals = enclosure->getAnimals();
		for (auto it = animals.begin(); it != animals.end(); ++it)
		{
			if ((*it)->hienthiid() == ID)
			{
				animal* temp = *it;
				animals.erase(it);
				return temp;     
			}
		}
	}
	return nullptr;
}
void manage::runManager()
{
	int choice;
	string id1, id2, animalID, enclosureID, caretakerID;

	do {
		cout << "                              =========== MENU HE THONG QUAN LY VUON THU ============" << endl;
		cout << "                              |                                                     |"<<endl;
		cout << "                              |             --- QUAN LY DOI TUONG ---               |" << endl;
		cout << "                              |                                                     |" << endl;
		cout << "                              | 1. Nhap thong tin Chuong moi                        |" << endl;
		cout << "                              | 2. Nhap thong tin Nhan vien moi                     |" << endl;
		cout << "                              | 3. Nhap thong tin Dong vat moi                      |" << endl;
		cout << "                              | 4. Xoa Dong vat theo ID                             |" << endl;
		cout << "                              | 5. Chuyen Dong vat den Chuong                       |" << endl;
		cout << "                              |                                                     |" << endl;
		cout << "                              |            --- BAO CAO & HIEN THI ---               |" << endl;
		cout << "                              |                                                     |" << endl;
		cout << "                              | 6. Hien thi tat ca Chuong va Dong vat trong do      |" << endl;
		cout << "                              | 7. Hien thi tat ca Nhan vien                        |" << endl;
		cout << "                              | 8. Hien thi chi tiet tat ca Dong vat                |" << endl;
		cout << "                              |                                                     |" << endl;
		cout << "                              |               --- TIM KIEM ---                      |" << endl;
		cout << "                              |                                                     |" << endl;
		cout << "                              | 9. Tim kiem Dong vat theo Ten                       |" << endl;
		cout << "                              | 10. Tim kiem Dong vat theo ID                       |" << endl;
		cout << "                              | 11.Sap xep                                          |" << endl;
		cout << "                              | 0. Thoat chuong trinh & luu thong tin               |" << endl;
		cout << "                              -------------------------------------------------------" << endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1: { // Nhap Chuong
			enclosure* e = new enclosure();
			e->nhap();
			AddEnclosure(e);
			break;
		}
		case 2: { // Nhap Nhan vien
			system("cls");//xoa man hinh
			string enid;
			cout << "---THEM NHAN VIEN MOI---" << endl;
			caretaker* c = new caretaker();
			c->nhap();
			AddCaretaker(c);
			cout << "ban co muon them chuong cho nhan vien nay khong(y/n)";
			char choice2;
			cin >> choice2;
			cin.ignore();
			while (choice2 == 'y')
			{
				cout << "nhap id chuong";
				getline(cin, enid);
				cin.ignore();
				addcaretakertoenclosure(c->getId(), enid);
				cout << "ban co muon them chuong cho nhan vien nay khong(y/n)";
				cin >> choice2;

			}

			break;
		}
		case 3: // Nhap Dong vat
			themmoi();
			break;
		case 4: { // Xoa Dong vat
			cout << "Nhap ID dong vat can xoa: ";
			getline(cin, animalID);
			RemoveAnimalByID(animalID);
			break;
		}
		case 5: { // Chuyen Dong vat den Chuong
			cout << "Nhap ID dong vat can chuyen: ";
			getline(cin, animalID);
			cout << "Nhap ID chuong moi: ";
			getline(cin, enclosureID);

			animal* a = RemoveAnimalWithoutDelete(animalID);
			enclosure* e = FindEnclosureByID(enclosureID);

			if (a && e) {
				
				e->them(a);
			}
			else {
				cout << "LOI: Khong tim thay dong vat hoac chuong." << endl;
			}
			break;
		}
		
		
		case 6: // Hien thi Chuong
			DisplayAllEnclosures();
			break;
		case 7: // Hien thi Nhan vien
			DisplayAllCaretakers();
			break;
		case 8: // Hien thi Dong vat
			hienthi();
			break;
		
		case 9: { // Tim theo Ten
			string searchName;
			cout << "Nhap ten hoac mot phan ten dong vat: ";
			getline(cin, searchName);
			FindAnimalsByName(searchName);
			break;
		}
		
		case 10: {
			string animalID;
			cout << "\n--- TIM KIEM DONG VAT THEO ID ---" << endl;
			cout << "Nhap ID dong vat (vi du: m001, b002): ";
			getline(cin, animalID); // Bước 1: Nhập ID từ người dùng
			// Bước 2: Gọi hàm FindAnimalByID()
			animal* result = FindAnimalByID(animalID);
			// Bước 3: Tự xử lý kết quả và hiển thị cho người dùng
			if (result) {
				cout << "\nTIM THAY DONG VAT:" << endl;
				result->hienthi(); // Hiển thị chi tiết
				cout << "-------------------------------------\n" << endl;
			}
			else {
				cout << "\n LOI: Khong tim thay dong vat nao voi ID: " << animalID << endl;
			}
			break;
		}
		case 11:
			sapxep();
		case 0:
			cout << "Dang thoat chuong trinh..." << endl;
			break;
		default:
			cout << "Lua chon khong hop le. Vui long thu lai." << endl;
		}
	} while (choice != 0);
}
void manage::ExportToFile(const string& filename)
{
	ofstream out(filename);
	if (!out.is_open()) {
		cout << "Khong mo duoc file de ghi!\n";
		return;
	}

	out << "===== DANH SACH CHUONG =====\n\n";

	for (auto e : ec)
	{
		out << "----------------------------------------\n";
		out << "Ma chuong   : " << e->getEnclosureID() << "\n";
		out << "Ten chuong  : " << e->getName() << "\n";
		out << "So dong vat : " << e->hienthisoluong() << "\n\n";

		out << "---- Danh sach dong vat ----\n";
		for (auto a : e->getAnimals())
		{
			out << "ID      : " << a->hienthiid() << "\n";
			out << "Ten     : " << a->hienthiten() << "\n";
			out << "Can nang: " << a->hienthican() << "\n";
			out << "Tuoi    : " << a->hienthituoi() << "\n";
			out << "Loai    : " << a->hienthitype() << "\n";
			out << "Tinh trang suc khoe: " << a->hienthiHealthStatus() << "\n";
			out << "----------------------------------------\n";
		}

		out << "\n---- Nhan vien phu trach ----\n";
		for (auto c : e->getCaretakers())
		{
			out << "Nhan vien ID  : " << c->getId() << "\n";
			out << "Ten nhan vien : " << c->getName() << "\n";
		}

		out << "\n========================================\n\n";
	}

	out.close();
	cout << "Da xuat du lieu ra file thanh cong!\n";
}
