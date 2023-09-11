//Xây dựng một ứng dụng quản lý tài liệu học tập:
//Yêu cầu:
//1. Xây dựng lớp Document có:
//+ Thuộc tính: Tên tài liệu, mô tả tài liệu, tên tác giả, định dạng tài liệu (ví dụ: PDF, Word), và năm xuất bản.
//+ Phương thức: Tạo mới một tài liệu với thông tin tương ứng, hiển thị thông tin tài liệu.
//2. Xây dựng lớp Folder:
//+ Thuộc tính: Tên thư mục, một danh sách (vector) chứa các đối tượng Document.
//+ Phương thức:
//	Thêm một tài liệu vào thư mục.
//	Xóa một tài liệu khỏi thư mục dựa trên tên tài liệu.
//	Hiển thị tất cả các tài liệu trong thư mục.
//3. Xây dựng Lớp User:
//+ Thuộc tính: Tên người dùng và một danh sách chứa các đối tượng Folder.
//+ Phương thức:
//	Thêm một thư mục mới vào danh sách thư mục của người dùng.
//	Xóa một thư mục khỏi danh sách thư mục của người dùng dựa trên tên thư mục.
//	Hiển thị danh sách thư mục của người dùng.
//4. Xây dựng ứng dụng chính:
//+	Tạo một giao diện người dùng để tương tác với tài liệu học tập (menu).
//+	Cho phép người dùng thực hiện các thao tác sau:
//+	Thêm tài liệu mới vào một thư mục của người dùng.
//+	Xóa tài liệu khỏi thư mục của người dùng.
//+	Hiển thị danh sách tài liệu trong thư mục của người dùng.
//+	Thêm thư mục mới vào danh sách thư mục của người dùng.
//+	Xóa thư mục khỏi danh sách thư mục của người dùng.
//+	Hiển thị danh sách thư mục của người dùng.


#include<iostream>
#include<vector>

class Document{
private:
    std::string nameDocument;
    std::string descriptionDocument;
    std::string Author;
    std::string documentType;
    int year;
public:
    Document(std::string nameDocument, std::string descriptionDocument,
             std::string Author, std::string documentType, int year) : nameDocument(nameDocument),
             descriptionDocument(descriptionDocument), Author(Author), documentType(documentType), year(year){};
    std::string get_nameDocument(){ return nameDocument;}
    std::string get_descriptionDocument(){ return descriptionDocument;}
    std::string get_Author(){return Author;}
    std::string get_documentType(){return documentType;}
    int get_year(){return year;}
    friend std::ostream& operator << (std::ostream& os,Document &document){
        os << "\nTen tai lieu: " << document.nameDocument;
        os << "\nMo ta: " << document.descriptionDocument;
        os << "\nTac gia: " << document.Author;
        os << "\nLoai tai lieu: " << document.documentType;
        os << "\nNam xuat ban: " << document.year;
        return os;
    }
};

class Folder{
private:
    std::string nameFolder;
    std::vector<Document> List;
public:
    Folder(std::string nameFolder, std::vector<Document> List) :nameFolder(std::move(nameFolder)), List(std::move(List)){};
    std::string get_nameFolder(){return nameFolder;}
    void add_newDocuments(Document &new_Document){
        List.push_back(new_Document);
    }
    void deleteDocumentwithnameDocument(std::string &name_deleteDocument){
        int i;
        for (i = 0; i < List.size(); ++i) {
            if(List[i].get_nameDocument()==name_deleteDocument){
                List.erase(List.begin()+i);
                return;
            }
        }
        std::cout << "Tai lieu khong ton tai de xoa\n";
    }
    void Display(){
        std::cout << "Danh sach thong tin tai lieu\n";
        for(auto x:List) std::cout << x;
    }
};

class User{
private:
    std::string username;
    std::vector<Folder> listFolder;
public:
    void add_newFolder(Folder &new_Folder){
        listFolder.push_back(new_Folder);
    }
    void deleteFolderwithnameFolder(const std::basic_string<char>& name_deleteFolder){
        int i;
        for (i = 0; i < listFolder.size(); ++i) {
            if(listFolder[i].get_nameFolder()==name_deleteFolder){
                listFolder.erase(listFolder.begin()+i);
                return;
            }
        }
        std::cout << "Thu muc khong ton tai de xoa\n";
    }
    void Display(){
        std::cout << "Danh sach thong tin thu muc\n";
        for(auto x:listFolder) std::cout << x.get_nameFolder() << std::endl;
    }
};
class HomeUi{
private:
        Document info_Document;
        std::vector<Folder> info_Folder;
        User member;
        std::string name_Document;
        std::string description_Document;
        std::string Au_thor;
        std::string document_Type;
        std::string name_Folder;
        int year_dcm;
public:
    int insert_Folder_avaible(){
        member.Display();
        std::cout << "\nNhap ten folder can truy cap";
        std::string name_Folder_insert;
        std::getline(std::cin,name_Folder_insert);
        int i;
        for(i =0 ;i<info_Folder.size();i++){
            if(info_Folder[i].get_nameFolder()==name_Folder_insert){
                return i;
            }
        }
    }
    void add_newDocuments(){
        std::cout << "---THEM MOI DOCUMENT---\n";
        int Name_folder = insert_Folder_avaible();
        std::cout << "Nhap thong tin lien he: \n";
        std::cout << "Ten Tai Lieu: ";
        std::cin.ignore();
        getline(std::cin,name_Document);
        std::cout << "Mo ta: ";
        getline(std::cin,description_Document);
        std::cout << "Tac Gia: ";
        getline(std::cin,Au_thor);
        std::cout << "Loai tai lieu: ";
        getline(std::cin,document_Type);
        std::cout << "Nam xuat ban: ";
        std::cin >> year_dcm;
        Document newDocument(name_Document,description_Document,Au_thor,document_Type,year_dcm);
        info_Folder[Name_folder].add_newDocuments(newDocument);
        std::cout << "Da tao xong tep moi\n";
    }
    void delete_documentwithnameinonefolder(){
        std::cout << "---XOA TEP---\n";
        int Name_folder = insert_Folder_avaible();
        std::cout << "Nhap ten tep can xoa: \n";
        std::getline(std::cin,name_Document);
        info_Folder[Name_folder].deleteDocumentwithnameDocument(name_Document);
        std::cout << "Thong tin da duoc xoa\n";
    }
    void DisplayAllDocument_inFolder(){
        int Name_folder = insert_Folder_avaible();
        info_Folder[Name_folder].Display();
    }
    void deleteFolderinUser(){
        member.Display();
        int Name_folder = insert_Folder_avaible();
        member.deleteFolderwithnameFolder(info_Folder[Name_folder].get_nameFolder());
        std::cout << "\nDa xoa Thu muc thanh cong\n";
    }
    void DisplayAllFolder_inUser(){
        member.Display();
    }
    void addnewFolder(){
        std::cout << "TAO THU MUC MOI\n";
        std::cout << "Nhap ten thu muc: ";
        std::string name_new_Folder;
        std::vector<Document> Listnew;
        std::cin >> name_new_Folder;
        Folder New_Folder(name_new_Folder,Listnew);
        member.add_newFolder(New_Folder);
    }
    void selectOption(int click){
        std::string fname,numphone,mail;
        switch (click) {
            case 1:
                add_newDocuments();
                break;
            case 2:
                delete_documentwithnameinonefolder();
                break;
            case 3:
                DisplayAllDocument_inFolder();
                break;
            case 4:
                DisplayAllFolder_inUser();
            case 5:
                addnewFolder();
            case 6:
                deleteFolderinUser();
        }
    }
    void menu(){
        while(true){
            std::cout << "\n\n";
            std::cout << "Hello 500 anh em\n";
            std::cout << "1. Tao tai lieu moi\n";
            std::cout << "2. Xoa tai lieu theo ten\n";
            std::cout << "3. Hien thi danh sach tai lieu trong thu muc n";
            std::cout << "4. Hien thi tat ca thu muc\n";
            std::cout << "5. Them thu muc moi\n";
            std::cout << "6. Xoa thu muc\n";
            std::cout << "7. Exit\n";
            int click;
            std::cout << "\n\n";
            std::cout << "\nNhap lua chon cua ban: ";
            std::cin >> click;
            if(click >7 || click < 0){
                std::cout << "Nhap sai\n";
                continue;
            }
            if(click ==7 ){
                std::cout << "Thank you for used !";
                return;
            }
            selectOption(click);
        }
    }
};
signed main(){

}