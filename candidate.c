#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(void)
{
    typedef struct member_info
    {
        char name[86];
        char birthday[86];
        char gender[86];
        char mail_addr[86];
        char country[86];
        char BMI[86];
        char main_skill[86];
        char sub_skill[86];
        char korean_skill[86];
        char MBTI[86];
        char introduction[86];
    } member_info;

    char company_name[86];

    member_info candidate01;
    member_info candidate02;
    member_info candidate03;
    member_info candidate04;
    member_info candidate05;
    member_info candidate06;

    member_info members[6] = {candidate01, candidate02, candidate03, candidate04, candidate05, candidate06};

    printf("\n회사명을 입력하세요 : ");
    int t = 0;
    while(1)
    {
        char key = getchar();
        if(key == '\n') break;

        company_name[t++] = key;
    }
    company_name[t] = '\0';

    printf("####################################\n");
    printf("     [%s] 오디션 후보자 데이터 입력\n", company_name);
    printf("####################################\n");

    int candidate_count = 1;
    while(candidate_count < 7)
    {
        char* order;
        member_info cur_candidate;

        switch(candidate_count)
        {
            case 1: order = "첫"; break;
            case 2: order = "두"; break;
            case 3: order = "세"; break;
            case 4: order = "네"; break;
            case 5: order = "다섯"; break;
            case 6: order = "여섯"; break;
            default : break;
        }

        printf("%s 번째 후보자의 정보를 입력합니다.\n", order);
        printf("---------------------------------\n");
        printf("1. 성명: ");           scanf("%s", members[candidate_count-1].name);

        printf("2. 생일(YYYY/MM/DD 형식): ");
        char birthday_buffer[86];
        scanf("%s", birthday_buffer);
        int n = 0;
        for(int i = 0; i < 86; i++)
        {
            if(birthday_buffer[i] == '\0') break;
            if(birthday_buffer[i] != '/') members[candidate_count-1].birthday[n++] = birthday_buffer[i];
        }
        members[candidate_count-1].birthday[n] = '\0';

        printf("3. 성별(여성이면 F 또는 남성이면 M):"); scanf("%s",members[candidate_count-1].gender);
        printf("4. 메일 주소: ");       scanf("%s", members[candidate_count-1].mail_addr);
        printf("5. 국적: ");            scanf("%s", members[candidate_count-1].country);
        printf("6. BMI: ");             scanf("%s", members[candidate_count-1].BMI);
        printf("7. 주 스킬: ");         scanf("%s", members[candidate_count-1].main_skill);
        printf("8. 보조 스킬: ");       scanf("%s", members[candidate_count-1].sub_skill);
        printf("9. 한국어 등급: ");     scanf("%s", members[candidate_count-1].korean_skill);
        printf("10. MBTI: ");           scanf("%s", members[candidate_count-1].MBTI);
        printf("11. 소개: ");           scanf("%s", members[candidate_count-1].introduction);
        printf("=================================\n");

        candidate_count++;
    }


    printf("####################################\n");
    printf("    [%s] 오디션 후보자 데이터 조회\n",company_name);
    printf("####################################\n");


    for(int candidate_count = 1; candidate_count < 7; candidate_count++)
    {
        char* gender_buffer;
        if(members[candidate_count - 1].gender[0] == 'F') gender_buffer = "여"; 
        else if (members[candidate_count - 1].gender[0] == 'M') gender_buffer = "남";
        else gender_buffer = "알 수 없음";


        printf("=============================================================================================\n");
        printf("성   명 | 생   일 | 성별 | 메   일            | 국적 | BMI | 주스킬 | 보조스킬 | TOPIK | MBTI |  \n");
        printf("=============================================================================================\n");
        printf("%s | %s | %s | %s | %s | %s | %s | %s | %s | %s\n",
                members[candidate_count-1].name,members[candidate_count-1].birthday,
                gender_buffer, members[candidate_count-1].mail_addr,
                members[candidate_count-1].country, members[candidate_count-1].BMI,
                members[candidate_count-1].main_skill, members[candidate_count-1].sub_skill,
                members[candidate_count-1].korean_skill, members[candidate_count-1].MBTI                
        );
        printf("        -------------------------------------------------------------------------------------\n");
        printf("%s\n", members[candidate_count-1].introduction);
        printf("---------------------------------------------------------------------------------------------\n");
    }
    return 0;
}