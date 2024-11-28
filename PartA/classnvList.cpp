#include<bits/stdc++.h>
#include "classNhanVien.cpp"
#ifndef LIST_H
#define LIST_H

using namespace std;

class nvList{
    list<NhanVien> Nvien;
    public:
        void themNhanVien(const NhanVien &nv){
            Nvien.push_back(nv);
        }
        //Kiem tra danh sach co trong khong
        bool empty() const{
            return Nvien.empty();
        }
        bool kiemtraMaNV(const long long &nv){
            for(auto it = Nvien.begin();it != Nvien.end();it++){
                if(it->lay_maNV() == nv){
                    return true;
                }
            }
            return false;
        }

        void xoaNhanVien(const long long &nv){
            for(auto it = Nvien.begin();it != Nvien.end();){
                if(it->lay_maNV() == nv){
                    it = Nvien.erase(it);
                }
                else{
                    ++it;
                }
            }
        }
        void inDanhSach() const{
            for(auto NhanVien : Nvien){
                cout << NhanVien;
            }
        }
        void sapxeptheoTen() {
            Nvien.sort([](const NhanVien& a,const NhanVien& b) {
                return a.lay_ten() < b.lay_ten();
            });
        }
        void sapxeptheoTuoi(){
            Nvien.sort([](const NhanVien& a,const NhanVien& b){
                return a.lay_tuoi() < b.lay_tuoi();

            });
        }
        void sapxeptheoChucVu(){
            Nvien.sort([](const NhanVien& a,const NhanVien& b){
                return a.lay_chucvu() < b.lay_chucvu();

            });
        }
        

        bool timNhanVien(const long long &maNV, NhanVien &ketQua) {
            auto it = find_if(Nvien.begin(), Nvien.end(), [&](const NhanVien& nv) { //cu phap (iterator first,iterator last,unary predicate) - lambda function tra ve true hoac false
                return nv.lay_maNV() == maNV; 
                }
            ); 
            // lambda nam bat cac bien ben ngoai pham vi(gia tri va tham chieu)
            // ma NV duoc nam bat theo tham chieu
             if (it != Nvien.end()) {
                ketQua = *it;
                return true; 
            }
            return false;   
        }
        

        


};


#endif