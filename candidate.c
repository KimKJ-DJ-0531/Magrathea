#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(void)
{
    char* member_info[10] = {
        "성 명", "생 일", "성 별", "메 일", "국 적", "BMI", "주 스킬", "보조 스킬", "한국어 등급", "MBTI"
        };

    char candidate01[10][100];
    char candidate02[10][100];
    char candidate03[10][100];
    char candidate04[10][100];
    char candidate05[10][100];
    char candidate06[10][100];


    // 입력창 출력
    int idx_num = 1; 
    char* idx_char;

    int candidate_num = 6;
    int attribute_num = 10;

    // 회사명 입력 //
    char comp_name[1024];
    char comp_ch_temp;
    int comp_ch_count = 0;

    printf("회사명을 입력하세요 : ");
    while(1)
    {
        comp_ch_temp = getchar();
        if(comp_ch_temp == '\n') break;

        comp_name[comp_ch_count++] = comp_ch_temp;
    }

    comp_name[comp_ch_count] = '\0';

    printf("####################################\n");
    printf("     [%s] 오디션 후보자 데이터 입력\n",comp_name);
    printf("####################################\n");



    while(candidate_num > 0)
    {
        switch(idx_num)
        {
            case 1 : {idx_char = "첫"; break;}
            case 2 : {idx_char = "두"; break;}
            case 3 : {idx_char = "세"; break;}
            case 4 : {idx_char = "네"; break;}
            case 5 : {idx_char = "다섯"; break;}
            case 6 : {idx_char = "여섯"; break;}
            default : break;
        }

        printf("%s 번째 후보자의 정보를 입력합니다.\n", idx_char);
        printf("---------------------------------\n");
        
        for(int i = 0; i < attribute_num; i++)
        {
            if (i == 1)
            {
                printf("%d. %s (YYYY/MM/DD 형식): ",i+1,member_info[i]);
            }
            else if (i == 2)
            {
                printf("%d. %s (여성이면 F 또는 남성이면 M): ",i+1,member_info[i]);
            }
            else if (i == 8)
            {
                printf("%d. %s (TOPIK): ",i+1,member_info[i]);
            }
            else
            {
                printf("%d. %s : ",i+1,member_info[i]);
            }
            
            switch(idx_num)
            {
                case 1 : {scanf("%s", candidate01[i]); break;}
                case 2 : {scanf("%s", candidate02[i]); break;}
                case 3 : {scanf("%s", candidate03[i]); break;}
                case 4 : {scanf("%s", candidate04[i]); break;}
                case 5 : {scanf("%s", candidate05[i]); break;}
                case 6 : {scanf("%s", candidate06[i]); break;}
                default : break;
            }
                
        }

        printf("=================================");
        
        idx_num ++;
        candidate_num --;
    }



    // 후보자 정보 출력

    


    return 0;
}