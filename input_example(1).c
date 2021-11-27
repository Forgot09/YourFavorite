#include <stdio.h>

//input in succession two times
/*void main() {
	int input_data = getchar();
	rewind(stdin);//초기화
	printf("first_input_data : %c\n", input_data);

	input_data = getchar();
	printf("second_input_data : %c\n", input_data);
	//초기화
	rewind(stdin);
}*/


//cancle input to use ctrl+c
/*
void main() {
	//마지막 0도 저장해야 하므로 9개의 문자 저장 가능(문자열의 특징)
	char input_string[10];
	if (NULL != gets(input_string)) {
		printf("input_value : %s\n", input_string);
	}
	else {
		printf("\ninput_value : input is canceled(ctrl + c)\n");
	}

}*/

//문자 입력 개수 제한하는 예제
//문자를 하나하나 살펴야 하기 때문에 하나씩 입력 받는 getchar()사용
//문자 입력받는 GetString 함수, 정상적인 입력이면 1을 아니면 0을 반환
int GetString(char buffer[], int limit) {
	int i;
	for (i = 0; i < limit; i++) {
		//i번째 변수에 getchar로 하나씩 입력
		buffer[i] = getchar();
		//만약 Enter키를 쳤다면 \n이 들어가므로 문자열의 끝을 알리는 \n으로 바꾸어서 입력
		if (buffer[i] == "\n") {
			buffer[i] = 0;
			//정상적으로 함수 종료
			return 1;
		}
	}
	//반목문을 빠져 나왔다는 것은 개수를 초과해서 입력했다는 뜻이므로 return 0;
	buffer[i] = 0;//입력후 Enter를 받은 것이므로 마지막 i의 값인 번째에 가서 0을 대입, 따라서 초과해도 만약 억지로 출력시키면 출력 가능한 글자만 출력됨
	rewind(stdin);
	return 0;
}

void main() {
	char temp[2];
	int state;

	//뒤에 0이 붙으므로 실제 입력할수 있는 크기는 배열의 크기 -1
	state = GetString(temp, 1);

	if (state == 1) printf("input : %s\n", temp);
	else printf("ERROR Out of Range");
}