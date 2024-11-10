#include<bits/stdc++.h>
#ifndef __NhanVien__
#define __NhanVien__

using namespace std;

class NhanVien{
    private:
        string ten,chucvu;
        long long maNV,tuoi;
    public:
        NhanVien(){
            maNV = 0;
            ten = "";
            tuoi = 0;
            chucvu = "";
        }
    friend istream& operator >> (istream &is,NhanVien &nv){
        cout << "Nhap ma nhan vien: ";
        is >> nv.maNV;
        cout << "Nhap ten nhan vien: ";
        is.ignore();
        getline(is,nv.ten);
        cout << "Nhap tuoi nhan vien: ";
        while(!(is >> nv.tuoi) || nv.tuoi <= 0){
            cout << "TUOI PHAI LA SO DUONG! XIN VUI LONG NHAP LAI: "; 
        }
        cout << "Nhap chuc vu: ";
        is.ignore();
        getline(is,nv.chucvu);
        
        return is;

    }
    friend ostream& operator << (ostream &os,NhanVien &nv){
        os << setw(30) << nv.maNV << setw(30) << nv.ten << setw(30) << nv.tuoi << setw(30) << nv.chucvu << endl;
        return os;
    }
    long long lay_maNV(){ 
        return maNV;
    }
    string lay_ten(){
        return ten;
    }
    long long lay_tuoi(){
        return tuoi;
    }
    string lay_chucvu(){
        return chucvu;
    }
    static void inBang(){
        for(int i=0;i<150;i++){
            cout << "#";
        }
        cout << endl;
        cout << setw(30) << "Ma Nhan Vien" << setw(30) << "Ten Nhan Vien" << setw(30) << "Tuoi" << setw(30) << "Chuc Vu" << endl;
        for(int i=0;i<150;i++){
            cout << "#";
        }
        cout << endl;
    }
};



#endif