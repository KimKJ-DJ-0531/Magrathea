#include <stdio.h>
#include <stdlib.h>

// 심사자 정보
// 이름 	성별	소속	직함	전문 분야	메일	전화

int main(void)
{
    char project_name[64];
    int judges_num;
    int selected_num;

    char* judges_array;    

    printf("###################################\n");
    printf("#       심사자 풀 데이터 입력       #\n");
    printf("####################################\n");
    
    printf("> 참여 프로젝트: ");      scanf("%s", project_name);
    printf("> 심사 풀 인원: ");       scanf("%d", &judges_num);
    printf("> 선발 멤버 수: ");       scanf("%d", &selected_num);

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d명의 심사자 정보를 입력합니다.\n", judges_num);
    printf("++++++++++++++++++++++++++++++++++++\n");
    
    int judge_count = judges_num;

    while(judge_count > 0)
    {
        char* temp = (char*)malloc(1024);
        
        printf("*심사자 %d: ", judges_num-judge_count+1);
        scanf("%s",temp); 

        int confirm_count = 0;
        
        if(temp != NULL)
        {
            for(int i = 0; i < sizeof(temp) * sizeof(char); i++)
            {
                if(temp[i] == ',') confirm_count++;
            }
        }
        
        if(confirm_count != 6) 
        {
            printf("정확한 데이터를 입력해 주세요.");
            free(temp);
            confirm_count = 0;
        }
        else
        {
            // judges_array 재할당 후 temp 데이터 추가
            judge_count--;
        }
        

    }

    return 0;
}