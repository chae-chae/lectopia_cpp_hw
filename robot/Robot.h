#pragma once
class Robot
{
private:
    char *name;
    int energy;
    void errPrn(); // 에너지 부족- 에러메시지 출력
public:
    Robot();  // name은 Null string("") 생성자에서 1바이트만 t할당해주고, energy는 0으로 초기화
    ~Robot(); // delete해주기
    Robot(const char *name, int energy = 0); //name받아야함
    Robot(const Robot& r); //복사생성자에도 const해주기 원본인 애가 바뀌지않게, Deep Copy 필요
    void go();              // 전진 메시지 출력 후 에너지 10 감소 // 에너지가 10만큼 있는지 검사하고 움직여야함
    void back();            // 후진 메시지 출력 후 에너지 20 감소 // 에너지 양이 20 이상입니까? 20미만이면 errPrn()호출해주기, 20이상이면 후진메시지 나오게
    void turn();             // 턴 메시지 출력 후 에너지 30 감소
    void jump();            // 점프 메시지 출력 후 에너지 40 감소
    void charge(int e);      // e값 만큼 충전 // 현재 에너지 양이 50이 있는데 100을 충전하면 150 됨. 에너지 충전할 양이 음수일수는 없으니까 e값이 음수인지 체크필요
    char *getName() const;       // name멤버의 값 리턴 // name이라는 멤버의 주소만 리턴해주면 된다. return name; 간단한 코드
    void setName(const char *);   // name멤버의 값을 전달된 문자열로 재 초기화 // 똘똘이->신사임당 // 기존메모리 해제하고 신사임당들어갈 만큼 다시 할당하고 거기에 복사해주기
    int getEnergy() const;         // energy멤버의 값 리턴  // 그냥 return energy하면 끝
    void setEnergy(int);     // energy멤버의 값을 전달된 숫자로 재 초기화 //charge랑은 다름 원래 100에너지있었는데 50이 들어오면 50으로 바뀜, 여기도 음수체크
};

