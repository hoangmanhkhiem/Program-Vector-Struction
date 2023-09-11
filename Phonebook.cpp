//Xây dựng một ứng dụng quản lý danh bạ điện thoại, email.
//Yêu cầu:
//1. Xây dựng lớp Contact
//+ Các thuộc tính: Họ và tên, Số điện thoại, Địa chỉ email;
//+ Các phương thức: tạo mới một liên hệ với thông tin tương ứng, hiển thị thông tin liên hệ.
//2. Xây dựng lớp AddressBook
//+ Các thuộc tính: Một danh sách (vector) chứa các đối tượng Contact;
//+ Các phương thức:
//	Thêm một liên hệ mới vào danh bạ
//	Xóa một liên hệ khỏi danh bạ dựa trê số điện thoại
//	Tìm kiếm liên hệ dựa trên số điện thoại và hiển thị thông tin liên hệ tìm thấy
//	Hiển thị tất cả các liên hệ trong danh bạ.
//3. Xây dựng ứng dụng chính:
//+ Tạo một giao diện người dùng đơn giản để tương tác với danh bạ.
//+ Cho phép người dùng thực hiện các thao tác sau:
//+ Thêm liên hệ mới.
//+ Xóa liên hệ.
//+ Tìm kiếm liên hệ.
//+ Hiển thị danh sách tất cả các liên hệ.



#include <iostream>
#include <utility>
#include <vector>

class Contact{
private:
    std::string FullName;
    std::string phone;
    std::string email;
public:
    Contact(std::string FullName, std::string phone, std::string email) : FullName(std::move(FullName)) , phone(phone) , email(std::move(email)){};
    std::string getName(){ return FullName;}
    std::string getPhone() const{ return phone;}
    std::string getEmail(){return email;}
    friend std::ostream& operator << (std::ostream& os,Contact &contact){
        os << "\nHo va ten: " << contact.FullName;
        os << "\nSo dien thoai: " << contact.phone;
        os << "\nHo va ten: " << contact.email;
        return os;
    }
};

class AddressBook{
private:
    std::vector<Contact> List;
public:
    void addContact(Contact &newContact){
        List.push_back(newContact);
    }
    void deleteContactWithphone(std::string &numberphone){
        int i;
        for (i = 0; i < List.size(); ++i) {
            if(List[i].getPhone()==numberphone){
                List.erase(List.begin()+i);
                return;
            }
        }
        std::cout << "Thong tin khong ton tai de xoa\n";
    }
    void searchInfomationWithPhone(std::string &numberphone){
        std::cout << "Thong tin dang duoc tim kiem\n";
        for(auto x:List){
            if(x.getPhone()==numberphone){
                std::cout << x;
                return;
            }
        }
        std::cout << "Khong tim thay thong tin";
    }
    void Display(){
        std::cout << "Danh sach thong tin lien he\n";
        for(auto x:List) std::cout << x;
    }

};

class Home{
private:
    AddressBook listInfo;
    std::string fname,numphone,mail;
public:
    void addInfo(){
        std::cout << "---THEM LIEN HE MOI---\n";
        std::cout << "Nhap thong tin lien he: \n";
        std::cout << "Ho va ten: ";
        std::cin.ignore();
        getline(std::cin,fname);
        std::cout << "So dien thoai: ";
        std::cin >> numphone;
        std::cout << "Email: ";
        std::cin >> mail;
        Contact NewContact(fname,numphone,mail);
        listInfo.addContact(NewContact);
        std::cout << "Thong tin da duoc them\n";
//        listInfo.Display();
    }
    void deleteInfo(){
        std::cout << "---XOA LIEN HE---\n";
        std::cout << "Nhap thong tin lien he: \n";
        std::cout << "So dien thoai: ";
        std::cin >> numphone;
        listInfo.deleteContactWithphone(numphone);
        std::cout << "Thong tin da duoc xoa\n";
    }
    void findInfo(){
        std::cout << "---TIM LIEN HE---\n";
        std::cout << "Nhap thong tin lien he: \n";
        std::cout << "So dien thoai: ";
        std::cin >> numphone;
        listInfo.searchInfomationWithPhone(numphone);
    }
    void selectOption(int click){
        std::string fname,numphone,mail;
        switch (click) {
            case 1:
                addInfo();
                break;
            case 2:
                deleteInfo();
                break;
            case 3:
                findInfo();
                break;
            case 4:
                listInfo.Display();
        }
    }
    void menu(){
        while(true){
            std::cout << "\n\n";
            std::cout << "Hello 500 anh em\n";
            std::cout << "1. Them lien he moi\n";
            std::cout << "2. Xoa lien he\n";
            std::cout << "3. Tim kiem lien he\n";
            std::cout << "4. Hien thi danh sach lien he\n";
            std::cout << "5. Exit\n";
            int click;
            std::cout << "\n\n";
            std::cout << "\nNhap lua chon cua ban: ";
            std::cin >> click;
            if(click >5 || click < 0){
                std::cout << "Nhap sai\n";
                continue;
            }
            if(click ==5 ){
                std::cout << "Thank you for used !";
                return;
            }
            selectOption(click);
        }
    }
};
int main() {
    Home Ui;
    Ui.menu();
}
