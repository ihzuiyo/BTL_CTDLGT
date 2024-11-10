#include<bits/stdc++.h>
#include "Bai6_.cpp"

using namespace std;



main(){
    Dayso Ds;
    while(1){
        cout << endl;
        cout << " --------Menu--------" << endl;
        cout << "1.Nhap vao danh sach day so" << endl;
        cout << "2.Them mot phan tu vao danh sach" << endl;
        cout << "3.Kiem tra xem trong day so co bao nhieu gia tri k duoc nhap vao" << endl;
        cout << "4.Kiem tra co 3 so chan duong dung canh nhau khong" << endl;
        cout << "5.Sap xep danh sach theo thu tu tang dan" << endl;
        cout << "6.Xoa tat ca cac so nguyen to trong danh sach" << endl;
        cout << "7.Xoa cac gia tri trung nhau cua so" << endl;
        cout << "8.Xoa danh sach day so" << endl;
        cout << "9.In danh sach." << endl;
        cout << "0.Thoat." << endl;
        cout << "Nhap lua chon: ";
        int luachon; cin >> luachon;
        if(luachon == 1){
            Ds.createList();
            cout << "THONG BAO - Hoan tat nhap danh sach!" << endl;
        }

        else if(luachon == 2){
            int pos;
            int value;
            cout << "THONG BAO - Nhap gia tri can chen: "; cin >> value;
            cout << "THONG BAO - Nhap vi tri can chen: "; cin >> pos;
            Ds.insertAt(pos,value);
            cout << "THONG BAO - Them gia tri thanh cong!" << endl;
        }

        else if(luachon == 3){
            int k;
            cout << "THONG BAO - Nhap gia tri k: "; cin >> k;
            cout << "THONG BAO - Co " << Ds.countEqualK(k) << " gia tri trung voi k" << endl;
        }

        else if(luachon == 4){
            Ds.checkThreeValueEqual();
        }

        else if(luachon == 5){
            cout << "THONG BAO - Da sap xep day so theo gia tri tang dan" << endl;
            Ds.sortList();
        }
        else if(luachon == 6){
            cout << "THONG BAO - Da xoa tat ca cac so nguyen to" << endl;
            Ds.removePrime();
        }

        else if(luachon == 7){
            cout << "THONG BAO - Da xoa cac gia tri trung nhau" << endl;
            Ds.remoteDuplicates();
        }

        else if(luachon == 8){
            Ds.~Dayso();
            cout << "THONG BAO - DA XOA DAY SO!" << endl;
        }
        else if(luachon == 9){
            for(int i=0;i<50;i++){ cout << "-";}
            cout << endl;
            Ds.print();
            for(int i=0;i<50;i++){ cout << "-";}
        }
        else{
            cout << "THONG BAO - Ket thuc chuong trinh." << endl;
            return 0;
        }
                
        
    }        
}
