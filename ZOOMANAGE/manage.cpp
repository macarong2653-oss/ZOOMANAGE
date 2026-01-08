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