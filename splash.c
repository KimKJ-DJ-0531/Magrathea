#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 입력 변수
    char currentDate[32]; // 날짜 입력 변수
    char userName[32]; // 유저 이름 변수

    char DateFormat[32]; // 날짜 형식 저장할 변수

// ** Get Input ** //
    // 특수 문자 ""를 문자로 나타내기 위해 \"를 사용
    printf("[현재 날짜를 \"yyyy-mm-dd\" 형식으로 입력하세요]:");
    scanf("%s", &currentDate);

    printf("[당신의 이름을 입력하세요]:");    
    scanf("%s", &userName);

    printf("**입력이 정상적으로 처리되었습니다.**\n");

// ** Print Splash ** //
    // 예외처리
    if(currentDate == NULL || userName == NULL) return -1;

    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    printf("                         [마그라테아 ver 0.1]                              \n");
    printf("           풀 한 포기 없는 황무지에서 반짝이는 행성을 만들내는 곳 마그라테아,         \n");
    printf("         사람들이 보지 못하는 잠재력을 찾고 전문가의 손길을 더해 보석을 빗는 곳,    \n");
    printf("           마그라테아에 오신걸 환영합니다.\"   ");
    printf("\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ ");
    printf("[사용자]: %s                                   [실행 시간]:%s", userName, DateFormat);

    return 0;
}