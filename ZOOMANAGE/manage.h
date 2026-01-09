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
	void ThemChuong(enclosure* enclosure);
	void themnhanvien(caretaker* caretaker);
	void ThenNhanVienVaoChuong(const string& caretakerID, const string& enclosureID);
	void HienThiToanBoNhanVien();
	void HienThiToanBoChuong();
	animal* TimKiemDongVatBangID(const string& ID);
	void TimKiemDongVatBangTen(const string& name);
	void XoaDongVatByID(const string& ID);
	enclosure* TimKiemChuongBangID(const string& ID);
	caretaker* TimKiemNhanVienBangID(const string& ID);
	void MENUQuanLy();
	animal* ChuyenDongVat(const string& ID);
	void TaiDuLieuTuFile(const string& filename);
	void XuatRaFile(const string& filename);
	void TimKiemBangThuocTinhDacBiet();
};

