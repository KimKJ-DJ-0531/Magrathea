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
        
        if(temp == NULL) 
        {
            printf("메모리 할당 실패");
            return 1;
        }

        printf("*심사자 %d: ", judges_num - judge_count + 1);
        scanf("%s",temp); 

        
        int confirm_count = 0;
        int temp_length = 0;

        while(temp[temp_length] != '\0')
        {
            if(temp[temp_length] == ',') confirm_count++;

            temp_length++;
        }

        if(confirm_count != 6) 
        {
            printf("입력 항목이 정확하지 않습니다. 다시 입력해주세요\n");
            free(temp);
            confirm_count = 0;
        }
        else
        {
            // judges_array 재할당 후 temp 데이터 추가

            judge_count--;
            free(temp);
        }
    }

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("심사자 풀 입력이 끝났습니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    char confirm;

    do
    {
        printf("[%s]심사자 풀을 확인할까요? (Y/N)",project_name);
        scanf(" %c",&confirm); // 개행 문자 방지용 공백

        switch(confirm)
        {
            case 'Y': 
                printf("####################################\n");
                printf("#       심사자 풀 데이터 출력       #\n");
                printf("####################################\n");
            
                for(int i = 0; i < judges_num; i++)
                {
                    printf("[심사자 %d]\n",i);
                    // json 데이터 파싱해서 출력
                    printf("-----------------------------------\n");
                }
            
            break;
            
            case 'N': printf("심사자 풀 확인을 취소했습니다."); break;

            default:
                confirm = '\0';
                printf("다시 입력해 주세요.\n");
        }
    }
    while(confirm != 'Y' && confirm != 'N');
    
    
    


    return 0;
}