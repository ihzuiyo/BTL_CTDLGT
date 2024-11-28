#include<bits/stdc++.h>
#include "classNhanVien.cpp"
#include "classnvList.cpp"


using namespace std;

class UngDung{
    nvList NV;
    public:
        void menu(){
            int luachon;
            do{
                cout << "1.Them nhan vien" << endl;
                cout << "2.Xoa nhan vien" << endl;
                cout << "3.In danh sach nhan vien" << endl;
                cout << "4.Sap xep nhan vien theo ten" << endl;
                cout << "5.Sap xep nhan vien theo tuoi" << endl;
                cout << "6.Sap xep nhan vien theo chuc vu" << endl;
                cout << "7.Tim nhan vien theo ma nhan vien" << endl;
                cout << "8.Thoat." << endl;
                cout << "Nhap lua chon: ";
                cin >> luachon;
                while(luachon < 0 || luachon > 8){
                    cout << "LUA CHON KHONG HOP LE! \n XIN VUI LONG NHAP LAI: ";
                    cin >> luachon;
                }
                switch (luachon){
                    case 1:{ 
                        NhanVien nv;
                        cin >> nv;
                        NV.themNhanVien(nv);
                        cout << "HOAN TAT THEM NHAN VIEN!" << endl;
                        break;
                    }
                    case 2:{
                        long long maNV;
                        cout << "Nhap ma nhan vien can xoa: "; cin >> maNV;
                        
                        if(NV.kiemtraMaNV(maNV)){
                            NV.xoaNhanVien(maNV);
                            cout << "XOA NHAN VIEN THANH CONG!" << endl;
                        }
                        else{
                            cout << "KHONG TIM THAY MA NHAN VIEN VUA NHAP!" << endl;
                        }
                        break;
                    }
                    case 3:{
                        if(!NV.empty()){
                            NhanVien::inBang();
                            NV.inDanhSach();
                        }
                        else{
                            cout << "DANH SACH TRONG!" << endl;
                        }
                        break;
                    }
                    case 4:{
                        NV.sapxeptheoTen();
                        cout << "DANH SACH NHAN VIEN DA DUOC SAP XEP THEO TEN!" << endl;
                        break;   
                    }
                    case 5:{
                        NV.sapxeptheoTuoi();
                        cout << "DANH SACH NHAN VIEN DA DUOC SAP XEP THEO TUOI!" << endl;
                        break;
                    }
                    case 6:{
                        NV.sapxeptheoChucVu();
                        cout << "DANH SACH NHAN VIEN DA DUOC SAP XEP THEO CHUC VU!" << endl;
                        break;
                    }
                    case 7:{
                        int maNV;
                        cout << "Nhap ma nhan vien de truy xuat thong tin nhan vien day: ";
                        cin >> maNV;
                        if(!NV.empty()){
                            NhanVien nv;
                            if(NV.timNhanVien(maNV,nv)){
                                cout << "Thong tin cua nhan vien co ma NV " << maNV << " " << "la: " << endl;
                                cout << nv << endl;
                            }
                            else{
                                cout << "Khong tim thay nhan vien co ma NV la " << maNV << endl;
                            }
                        }
                        else{
                            cout << "DANH SACH NHAN VIEN TRONG!" << endl;
                        }
                        break;
                    }
                    case 8:{
                        cout << "KET THUC UNG DUNG!" << endl;
                        break;
                    }
                    default:{
                        cout << "LUA CHON KHONG HOP LE!" << endl;
                        break;
                    }

                }
                
              

            }
            while(luachon >=0 && luachon < 8);
        }

};
main(){
    UngDung ud;
    ud.menu();
    return 0;    
}