#include <stdio.h>

//input in succession two times
/*void main() {
	int input_data = getchar();
	rewind(stdin);//�ʱ�ȭ
	printf("first_input_data : %c\n", input_data);

	input_data = getchar();
	printf("second_input_data : %c\n", input_data);
	//�ʱ�ȭ
	rewind(stdin);
}*/


//cancle input to use ctrl+c
/*
void main() {
	//������ 0�� �����ؾ� �ϹǷ� 9���� ���� ���� ����(���ڿ��� Ư¡)
	char input_string[10];
	if (NULL != gets(input_string)) {
		printf("input_value : %s\n", input_string);
	}
	else {
		printf("\ninput_value : input is canceled(ctrl + c)\n");
	}

}*/

//���� �Է� ���� �����ϴ� ����
//���ڸ� �ϳ��ϳ� ����� �ϱ� ������ �ϳ��� �Է� �޴� getchar()���
//���� �Է¹޴� GetString �Լ�, �������� �Է��̸� 1�� �ƴϸ� 0�� ��ȯ
int GetString(char buffer[], int limit) {
	int i;
	for (i = 0; i < limit; i++) {
		//i��° ������ getchar�� �ϳ��� �Է�
		buffer[i] = getchar();
		//���� EnterŰ�� �ƴٸ� \n�� ���Ƿ� ���ڿ��� ���� �˸��� \n���� �ٲپ �Է�
		if (buffer[i] == "\n") {
			buffer[i] = 0;
			//���������� �Լ� ����
			return 1;
		}
	}
	//�ݸ��� ���� ���Դٴ� ���� ������ �ʰ��ؼ� �Է��ߴٴ� ���̹Ƿ� return 0;
	buffer[i] = 0;//�Է��� Enter�� ���� ���̹Ƿ� ������ i�� ���� ��°�� ���� 0�� ����, ���� �ʰ��ص� ���� ������ ��½�Ű�� ��� ������ ���ڸ� ��µ�
	rewind(stdin);
	return 0;
}

void main() {
	char temp[2];
	int state;

	//�ڿ� 0�� �����Ƿ� ���� �Է��Ҽ� �ִ� ũ��� �迭�� ũ�� -1
	state = GetString(temp, 1);

	if (state == 1) printf("input : %s\n", temp);
	else printf("ERROR Out of Range");
}