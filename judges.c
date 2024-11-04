#include <stdio.h>
#include <stdlib.h>

#define MAX_JUDGE_INFO_LEN 1024  // 각 심사자 정보의 최대 길이

int main(void) {
    char project_name[64];
    int judges_num;
    int selected_num;

// 심사자 풀 입력
    printf("###################################\n");
    printf("#       심사자 풀 데이터 입력       #\n");
    printf("####################################\n");
    
    // 각 항목 별 입력을 받음
    printf("> 참여 프로젝트: ");    scanf("%s", project_name);
    printf("> 심사 풀 인원: ");    scanf("%d", &judges_num);
    printf("> 선발 멤버 수: ");    scanf("%d", &selected_num);

    // 총 인원 수 만큼 정보를 입력 받음
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d명의 심사자 정보를 입력합니다.\n", judges_num);
    printf("++++++++++++++++++++++++++++++++++++\n");

    // 심사자 정보를 저장할 1차원 배열 할당
    char* judges_array = (char*)malloc(judges_num * MAX_JUDGE_INFO_LEN);
    if (judges_array == NULL) { printf("메모리 할당 실패\n");  return 1;}

    int input_count = 0;
    while(input_count < judges_num)
    {
        char temp[MAX_JUDGE_INFO_LEN]; // 입력받은 정보를 임시로 저장할 배열
        printf("* 심사자 %d (이름,성별,소속,직함,전문분야,메일,전화): ", input_count + 1);
        scanf(" %[^\n]", temp); // 띄어쓰기 포함 입력

        // 입력된 항목 개수 확인
        int confirm_count = 0;
        for (int j = 0; temp[j] != '\0'; j++) 
        {
            if (temp[j] == ',') confirm_count++;
        }

        if (confirm_count != 6) 
        {
            printf("입력 항목이 정확하지 않습니다. 다시 입력해주세요.\n");
            input_count--; // 다시 입력하도록 인덱스를 감소시킴
        } 
        else
        {
            // 문자열 복사
            for (int j = 0; j < MAX_JUDGE_INFO_LEN - 1 && temp[j] != '\0'; j++) 
            {
                judges_array[input_count * MAX_JUDGE_INFO_LEN + j] = temp[j];
            }
            judges_array[(input_count + 1) * MAX_JUDGE_INFO_LEN - 1] = '\0'; // 문자열 종료
        }
        input_count++;
    }

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("심사자 풀 입력이 끝났습니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    char confirm;
    do {
        printf("[%s] 심사자 풀을 확인할까요? (Y/N): ", project_name);
        scanf(" %c", &confirm); // 개행 문자 방지용 공백 추가

        switch (confirm) 
        {
            case 'Y': case 'y' :
                printf("####################################\n");
                printf("#       심사자 풀 데이터 출력       #\n");
                printf("####################################\n");

                for (int i = 0; i < judges_num; i++) {
                    printf("[심사자 %d]\n", i + 1);
                    printf("\n");

                    // 필드명 배열
                    const char* fields[] = { "이름", "성별", "소속", "직함", "전문 분야", "메일", "전화" };
                    int field_index = 0;

                    // 쉼표 기준으로 파싱하여 출력
                    int start = 0;
                    // 0부터 j7번째 필드까지 char 요소 하나 하나 확인
                    for (int j = 0; judges_array[i * MAX_JUDGE_INFO_LEN + j] != '\0' && field_index < 7; j++) 
                    {
                        if (judges_array[i * MAX_JUDGE_INFO_LEN + j] == ',' || judges_array[i * MAX_JUDGE_INFO_LEN + j + 1] == '\0') 
                        {
                            // 현재 이름 출력이면 
                            // 이름 : 
                            // 까지 출력
                            printf("  %s  \t: ", fields[field_index]);

                            // 필드 값 출력
                            // judges_array : "1_이름,1_성별,1_소속,...","2_이름,2_성별,..."
                            // 예) 김철수,남자,우송대학교...
                            int end = (judges_array[i * MAX_JUDGE_INFO_LEN + j] == ',') ? j : j + 1;
                            for (int k = start; k < end; k++) 
                            {
                                // 1_이름 출력 순서면 김 철 수 순으로 출력
                                putchar(judges_array[i * MAX_JUDGE_INFO_LEN + k]);
                            }
                            printf("\n");

                            // 다음 필드 시작 위치와 필드 인덱스 갱신
                            start = j + 1;
                            field_index++;
                        }
                    }

                    printf("\n");
                    printf("-----------------------------------\n");
                }
                break;

            case 'N': case 'n' :
                printf("심사자 풀 확인을 취소했습니다.\n");
                break;

            default:
                confirm = '\0';
                printf("다시 입력해 주세요.\n");
        }
    } while (confirm != 'Y' && confirm != 'N' && confirm != 'y' && confirm != 'n');

    // 메모리 해제
    free(judges_array);

    return 0;
}
