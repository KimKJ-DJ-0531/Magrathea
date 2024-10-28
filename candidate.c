#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(void)
{
    char* member_info[11] = {
        "성 명", "생 일", "성 별", "메 일", "국 적", "BMI", "주 스킬", "보조 스킬", "한국어 등급", "MBTI", "소개"
        };

    char candidate01[11][100];
    char candidate02[11][100];
    char candidate03[11][100];
    char candidate04[11][100];
    char candidate05[11][100];
    char candidate06[11][100];


    // 입력창 출력
    int idx_num = 1; 
    char* idx_char;

    int candidate_num = 6;
    int attribute_num = 11;

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
                char birthday[100];
                printf("%d. %s (YYYY/MM/DD 형식): ",i+1,birthday);
                // birthday format 변환해서 member_info[i]에 저장하기
                
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

        printf("=================================\n");
        
        idx_num ++;
        candidate_num --;
    }



    // 후보자 정보 출력
    candidate_num = 6;
    attribute_num = 11;

    for(int i = 0; i < candidate_num; i++)
    {
        printf("####################################\n");
        printf("     [%s] 오디션 후보자 데이터 조회\n",comp_name);
        printf("####################################\n");
        printf("=============================================================================================\n");
        printf("성   명 | 생   일 | 성별 | 메   일            | 국적 | BMI | 주스킬 | 보조스킬 | TOPIK | MBTI |       \n");
        printf("=============================================================================================\n");

        for(int j = 0; j < attribute_num; j++)
        {
            if(j < attribute_num - 1)
            {
                switch(i)
                {
                    case 0 : printf(" %s ", candidate01[j]); break;
                    case 1 : printf(" %s ", candidate02[j]); break;
                    case 2 : printf(" %s ", candidate03[j]); break;
                    case 3 : printf(" %s ", candidate04[j]); break;
                    case 4 : printf(" %s ", candidate05[j]); break;
                    case 5 : printf(" %s ", candidate06[j]); break;
                    default : break;
                }
            }
            else
            {
                printf("\n-------------------------------------------------------------------------------------\n");
                switch(i)
                {
                    case 0 : printf(" %s ", candidate01[j]); break;
                    case 1 : printf(" %s ", candidate02[j]); break;
                    case 2 : printf(" %s ", candidate03[j]); break;
                    case 3 : printf(" %s ", candidate04[j]); break;
                    case 4 : printf(" %s ", candidate05[j]); break;
                    case 5 : printf(" %s ", candidate06[j]); break;
                    default : break;
                }
                printf("\n-------------------------------------------------------------------------------------\n");
            }

            printf("|");
        }
 
        printf("\n---------------------------------------------------------------------------------------------\n");
        

    }


    return 0;
}