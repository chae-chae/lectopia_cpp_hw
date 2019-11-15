#include <iostream>
using namespace std;
#include <string>
#define MAX 100

class Fitness
{
    private :
    int num; // 회원번호
    string name; // 성명
    double weight; // 몸무게(kg단위)
    double height; // 신장(키-cm단위)
    public :
    // 생성자 함수, 소멸자 함수
    Fitness();//회원번호 0, 성명 null string, 몸무게 0kg, 신장 0cm로 초기화
    Fitness(int num, char *name, double weight, double height);
    //Fitness(Fitness &r);
    //~Fitness(); // 동적 할당된 메모리 해제
    // 연산자 함수
    //Fitness & operator=(Fitness &r);
    bool operator==(Fitness &r);
    // setter, getter 함수
    void setNum(int num); // num 멤버 초기화 함수
    int getNum(); // num 멤버값 리턴 하는 함수
    void setName(char *name); // name 멤버 초기화 함수
    string getName(); // name 멤버값 리턴 하는 함수
    void setWeight(double weight); // weight 멤버 초기화 함수
    double getWeight(); // weight 멤버값 리턴 하는 함수
    void setHeight(double height); // height 멤버 초기화 함수
    double getHeight(); // height 멤버값 리턴 하는 함수
    // 기타멤버함수
    double bmi(); // 해당 회원의 bmi를 계산하여 리턴 하는 함수
};

Fitness::Fitness(){
    this->num = 0;
    this->name = "";
    this->weight = 0;
    this->height = 0;
}
Fitness::Fitness(int num, char *name, double weight, double height){
    this->num = num;
    this->name = name;
    this->weight = weight;
    this->height = height;
}
bool Fitness::operator==(Fitness &r){
    if (this->name == r.name) {
        return true;
    } else {
        return false;
    }
}
void Fitness::setNum(int num){
    this->num = num;
}

int Fitness::getNum(){
    return this->num;
}
void Fitness::setName(char *name){
    this->name = name;
}
string Fitness::getName(){
    return this->name;
}
void Fitness::setWeight(double weight){
    this->weight = weight;
}
double Fitness::getWeight(){
    return this->weight;
}
void Fitness::setHeight(double height){
    this->height = height;
}
double Fitness::getHeight(){
    return this->height;
}
double Fitness::bmi(){
    double dbmi;
    double meterh;
    meterh = this->height/100;
    dbmi = this->weight/(meterh*meterh);
    return dbmi;
}


int menu();
int userInput(Fitness *ap[], int size, int &memberCnt);
void userDisplay(Fitness *ap[], int cnt);
void userSearch(Fitness *ap[], int cnt);
int userOut(Fitness *ap[], int cnt);
void userManage(Fitness *ap[], int cnt);

int main(){
    int size = MAX;
    Fitness *fary[MAX];
    
    int memberCnt = 0;
    int menusel;
    
    while (1) {
        menusel = menu();
        if (menusel == 6){ //6종료
            break;
        }
        switch (menusel) {
            case 1:
                memberCnt = userInput(fary, size, memberCnt);
                break;
            case 2:
                userDisplay(fary, memberCnt);
                break;
            case 3:
                userSearch(fary, memberCnt);
                break;
            case 4:
                memberCnt = userOut(fary, memberCnt);
                break;
            case 5:
                userManage(fary, memberCnt);
                break;
            default:
                break;
        }
    }
    for (int i = 0; i<memberCnt; i++) {
        delete fary[i];
    }
//    delete [] *fary;
    return 0;
}

int menu(){
    
    int n = 0, i;
    char menulist[6][20] = { "회원등록", "회원전체보기", "회원정보검색", "회원탈퇴", "특별관리회원", "종료" };
    
    for (i = 0; i<6; i++) {
        cout << i+1 << ". " << menulist[i] << endl;
    }
    while (n<1 || n> 6) {
        cout << "* 메뉴를 선택하세요 : ";
        cin >> n;
    }
    return n;
}

int userInput(Fitness *ap[], int size, int &memberCnt){
    char name[50];
    double weight;
    double height;
//    static int cnt = 0;
//    int num = memberCnt+1;
    
    while (1) {
        if (memberCnt == size) {
            cout << "최대 회원수는 " << size << "명입니다. " << endl;
            return memberCnt;
//            break;
        }
        cout << "이름 입력(end 입력시 종료) : ";
        cin >> name;
        if (strcmp(name, "end") == 0) {
            break;
        }
        cout << "몸무게 입력 : ";
        cin >> weight;
        cout << "신장 입력 : ";
        cin >> height;
    
        ap[memberCnt] = new Fitness;
        *ap[memberCnt] = Fitness(memberCnt+1, name, weight, height);
        memberCnt++;
    }
    
    return memberCnt;
}
void userDisplay(Fitness *ap[], int cnt){
    int i;
    for (i = 0; i < cnt; i++)
    {
        cout << "회원번호 : " << ap[i]->getNum();
        cout << " 성명 : " << ap[i]->getName();
        cout << " 몸무게 : " << ap[i]->getWeight() << "kg";
        cout << " 신장 : " << ap[i]->getHeight() << "cm" << endl;
    }
    cout << endl;
}
void userSearch(Fitness *ap[], int cnt){
    string temp;
    cout << "찾을 회원을 입력하세요 : ";
    cin >> temp;
    
    for (int i = 0; i<cnt; i++) {
        if (temp == ap[i]->getName()) {
            cout << "회원번호 : " << ap[i]->getNum();
            cout << " 성명 : " << ap[i]->getName();
            cout << " 몸무게 : " << ap[i]->getWeight() << "kg";
            cout << " 신장 : " << ap[i]->getHeight() << "cm" << endl;
            return;
//        } else {
//            cout << "일치하는 회원이 없습니다." << endl;
//            break;
        }
    }
    cout << "일치하는 회원이 없습니다." << endl;
    return;
}
int userOut(Fitness *ap[], int cnt){
    int outnum;
    //Fitness *newp;
    cout << "탈퇴할 회원의 회원번호를 입력하세요 : ";
    cin >> outnum;
    int outnump = outnum-1;
    if(outnump < cnt){//탈퇴할 회원의 번호가 존재
        delete ap[outnump];
        for (int i = outnump; i<cnt-1; i++) {
            ap[i] = ap[i+1];
            ap[i]->setNum(i+1);
        }
        return cnt-1;
    } else {
        cout << "일치하는 번호가 없습니다, " << endl;
        return cnt;
    }
}
void userManage(Fitness *ap[], int cnt){
    cout << "===특별 관리 회원 목록===" << endl;
    for (int i = 0; i<cnt; i++) {
        if (25.0 <= ap[i]->bmi() && ap[i]->bmi() < 30.0) {
            cout << "회원번호 : " << ap[i]->getNum() << "(과체중)" << endl;
            cout << "성명 : " << ap[i]->getName() << endl;
            cout << "몸무게 : " << ap[i]->getWeight() << "kg" << endl;
            cout << "신장 : " << ap[i]->getHeight() << "cm" << endl;
        } else if (30.0 <= ap[i]->bmi() && ap[i]->bmi() < 40.0){
            cout << "회원번호 : " << ap[i]->getNum() << "(비만)" << endl;
            cout << "성명 : " << ap[i]->getName() << endl;
            cout << "몸무게 : " << ap[i]->getWeight() << "kg" << endl;
            cout << "신장 : " << ap[i]->getHeight() << "cm" << endl;
        } else if (40.0 <= ap[i]->bmi()){
            cout << "회원번호 : " << ap[i]->getNum() << "(고도비만)" << endl;
            cout << "성명 : " << ap[i]->getName() << endl;
            cout << "몸무게 : " << ap[i]->getWeight() << "kg" << endl;
            cout << "신장 : " << ap[i]->getHeight() << "cm" << endl;
        }
    }
}
