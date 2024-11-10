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
            for(auto it = Nvien.begin();it != Nvien.end();it++){
                if(it->lay_maNV() == nv){
                    Nvien.erase(it);
                    break;
                }
            }
        }
        void inDanhSach() const{
            for(auto NhanVien : Nvien){
                cout << NhanVien;
            }
        }
        void sapxeptheoTen() {
            Nvien.sort([](NhanVien a,NhanVien b) {
                return a.lay_ten() < b.lay_ten();
            });
        }
        void sapxeptheoTuoi(){
            Nvien.sort([](NhanVien a,NhanVien b){
                return a.lay_tuoi() < b.lay_tuoi();

            });
        }
        void sapxeptheoChucVu(){
            Nvien.sort([](NhanVien a,NhanVien b){
                return a.lay_chucvu() < b.lay_chucvu();

            });
        }
        NhanVien timNhanVien(const long long &maNV){
            NhanVien TimNhanVien = Nvien.front();
            for(auto it = Nvien.begin();it != Nvien.end();it++){
                if(it->lay_maNV() == maNV){
                    TimNhanVien = *it;
                    break;
                }
            }
            return TimNhanVien;
        }
        

        


};


#endif