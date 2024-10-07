#include <stdio.h>
#include <stdlib.h>


void ConvertFormat(char* array, int firstIdx, int lastIdx, int* var)
{
    char temp[16] = {'\0',};
    int idx = 0;

    for(int i = firstIdx; i < lastIdx + 1; i++)
    {
        temp[idx] = array[i];
        idx++;
    }
    
    *var = atoi(temp);
}



int main()
{
// ** 변수 ** //
    const char *splashText[] = {
        "                         [마그라테아 ver 0.1]                                    ",
        "   풀 한 포기 없는 황무지에서 반짝이는 행성을 만들내는 곳 마그라테아,            ",
        "   사람들이 보지 못하는 잠재력을 찾고 전문가의 손길을 더해 보석을 빗는 곳,       ",
        "    마그라테아에 오신걸 환영합니다.\"                                             ",
        "                                                                                 "
        }; //출력할 문장을 저장하는 변수

    char currentDate[32]; // 날짜 입력 변수
    char userName[128];    // 유저 이름 변수


    int textCount = (sizeof(splashText) / sizeof(splashText[0])); // 출력할 문장의 개수

    int year, month, date; // 날짜 저장 변수

// ** Get Input ** //
    // 특수 문자 ""를 문자로 나타내기 위해 \"를 사용
    printf("[현재 날짜를 \"yyyy-mm-dd\" 형식으로 입력하세요]:");
    scanf("%s", &currentDate);

    printf("[당신의 이름을 입력하세요]:");
    scanf("%s", &userName);

    printf("**입력이 정상적으로 처리되었습니다.**\n");

    // ** Print Splash ** //
    // 예외처리
    if (currentDate == NULL || userName == NULL) return -1;

    ConvertFormat(currentDate,0,3, &year);
    ConvertFormat(currentDate,5,6, &month);
    ConvertFormat(currentDate,8,9, &date);

    _sleep(3000);
    // system("cls");
    // 이스케이프 문자를 이용하여 콘솔 지우기
    // \e[1;1H] : 커서를 1행 1열로 이동
    // \e[2J : 터미널의 모든 텍스트를 스크롤백 버퍼로 이동
    // \e[3J : 스크롤백 버퍼를 지움
    printf("\e[1;1H\e[2J\e[3J");
    

    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    // *    *****
    // **    ****
    // ***    ***
    // ****    **
    // *****    *
    for(int i = 0; i < textCount; i++)
    {
        int frontStarCount = i + 1;                         // 앞에 오는 별은 처음에 1개부터 늘어남
        int backStartCount = textCount + 1 - frontStarCount;  // 뒤에 오는 별은 처음에 문장 수 개수부터 줄어듬

        // 출력

        for(int j = 0; j < frontStarCount; j++)     // 앞쪽 출력
        {
            printf("*");
        }

        printf("%s", splashText[i]);    // 문장 출력

        for(int j = 0; j < backStartCount; j++)     // 뒤쪽 출력
        {
            printf("*");
        }

        printf("\n");
    }

    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("[사용자]: %s                                   [실행 시간]: %d년 %d월 %d일\n", userName, year, month, date);
    printf("================================================================================\n");

    return 0;
}