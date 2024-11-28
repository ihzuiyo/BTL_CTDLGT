#include<bits/stdc++.h>

#ifndef __List__
#define __List__
using namespace std;


class Node{
    public:
        int data; // chua value
        Node* next; // chua vi tri cua node tiep theo
        Node (int value) : data(value),next(nullptr){} //Ham tao Node
};

class Dayso{
    private:
        Node* head;
    public:
        Dayso() : head(nullptr) {}

        void add(int value){
            Node* newNode = new Node(value);
            if(!head){ 
                head = newNode; // list rong thi head se tro thanh node dau tien trong list
            }
            else{
                Node* temp = head;
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void print() const{
            if(!head){
                cout << "Danh sach hien tai khong co phan tu nao." << endl;
                return;
            }

            cout << "DAY SO DA NHAP: ";
            Node* temp = head;
            while(temp){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        ~Dayso(){
            while(head){
                Node* temp = head;
                head = head->next;
                delete temp;
            } 
        }
        

//a) Tao danh sach so,qua trinh nhap se dung lai khi nhap dau "#"
        void createList(){
            cout << "Nhap cac so vao danh sach (nhap # de dung qua trinh nhap cac so): ";
            while(true){
                string input; //Chuoi kiem tra dau #
                cin >> input;
                if(input == "#"){
                    break;
                }
                try{
                    int value = stoi(input);
                    add(value);
                }
                catch(exception& e){
                    cout << "Gia tri nhap khong hop le,nhap # de dung qua trinh nhap cac so." << endl;
                }
            }

        }


//b) Them mot phan tu vao danh sach,vi tri them do nguoi dung chon
        void insertAt(int pos,int value){
            Node* newNode = new Node(value);
            if(pos == 1){ // neu chen vao vi tri dau tien danh sach
                newNode->next = head;
                head = newNode;
                cout << "THONG BAO - Them gia tri thanh cong!" << endl;
                return;
            }
            Node* temp = head;
            for(int i=1;i < pos-1 && temp; i++){
                temp = temp->next;
            }
            if(!temp){
                cout << "Vi tri chen khong hop le" << endl;
                delete newNode;
            }
            else{
                newNode->next = temp->next;
                temp->next = newNode;
                cout << "THONG BAO - Them gia tri thanh cong!" << endl;
            }
        }
//c) Nhap vao mot so k ,dem xem co bao nhieu phan tu trong day so bang k
        int countEqualK(int k){
            int count = 0;
            Node* temp = head;
            while(temp){
                if(temp->data == k){
                    count++;
                }
                temp = temp->next;
            }
            return count;
        }

//d) Kiem tra xem trong danh sach co 3 so chan duong dung canh nhau hay khong?
        void checkThreeValueEqual(){
            if(!head || !head->next || !head->next->next){
                cout << "CAN PHAI CO IT NHAT 3 PHAN TU DE TIEN HANH KIEM TRA." << endl;
                return;
            }
            Node* first = head;
            Node* second = head->next;
            Node* third = head->next->next;
            int index = 1;
            bool found = false;
            while(third){
                if(isEvenPositive(first->data) && isEvenPositive(second->data) && isEvenPositive(third->data)){
                    found = true;
                    cout << "THONG BAO - Co 3 so chan dung canh nhau" << endl;
                    cout << "THONG BAO - Vi tri cua 3 so chan la: " << index << ", " << index + 1 << ", " << index + 2 << endl;    
                }
                first = second;
                second = third;
                third = third->next;
                index++;
            }
            if(!found){
                cout << "KHONG CO 3 SO CHAN DUONG DUNG CANH NHAU!" << endl;
                return;
            }

        }
        bool isEvenPositive(int value){
            return value > 0 && value % 2 == 0;
        }

//e) Sap xep danh sach theo thu tu tang dan
        void sortList(){
            if(!head || !head->next){
                cout << "THONG BAO - Trong danh sach can it nhat 2 so de tien hanh sap xep." << endl;
                return;
            }
            for(Node* i = head;i->next != NULL;i = i->next){
                for(Node* j = i->next;j != NULL;j = j->next){
                    if(i->data > j->data){
                        swap(i->data,j->data);
                    }
                }
            }
        }
//f) Xoa tat ca cac so nguyen to trong danh sach
        bool isPrime(int n){
            if(n <= 1){
                return false;
            }
            for(int i = 2;i*i <= n;i++){
                if(n % i == 0){
                    return false;
                }
            }
            return true;
        }
        void removePrime(){
            while(head && isPrime(head->data)){
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        
            Node* temp = head;
            while(temp && temp->next){
                if(isPrime(temp->next->data)){
                    Node* goDelete = temp->next;
                    temp->next = temp->next->next;
                    delete goDelete;
                }
                else{
                    temp = temp->next;
                }
            }
        }
 
//g) Xoa tat ca cac phan tu co gia tri trung nhau trong danh sach,chi giu lai 1 so
        void remoteDuplicates(){
            Node* temp = head;
            while(temp){
                Node* runner = temp;
                while(runner->next){
                    if(runner->next->data == temp->data){
                        Node* goDelete = runner->next;
                        runner->next = runner->next->next;
                        delete goDelete;
                    }
                    else{
                        runner = runner->next;
                    }
                
                }
                temp = temp->next;
            }
        }

};






#endif
