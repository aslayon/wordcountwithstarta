#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS 
#define max 3000
char data[max];




void read() {
	FILE* fp;
	
	if (fopen_s(&fp, "d.txt", "r") != 0) { printf("���� �б� ����"); }

	fread(data,sizeof(char),sizeof(data),fp);
	fclose(fp);
	//printf("%s",data);
}

int charc() {
	int count = 0;
	for (int i = 0; data[i] !='\0'; i++) {
		if (data[i] != ' ' && data[i] != '\n' && data[i] != '\t' && data[i] != '\r') {
			count++;
		}
	}
	return count;
}

int wordc() {
	int count = 0;
	int flag = 0;
	for (int i = 0; data[i] != '\0'; i++) {
		if (data[i] != ' ' && data[i] != '\n' && data[i] != '\t' && data[i] != '\r' && flag!=1) {
			count++;
			flag = 1;
		}
		if (data[i] == ' ' || data[i] == '\n' || data[i] == '\t' || data[i] == '\r' || flag != 1) {
			flag = 0;
		}
	}
	return count;
}

int wordac() {
	int count = 0;
	int flag = 0;
	for (int i = 0; data[i] != '\0'; i++) {
		if (data[i] != ' ' && data[i] != '\n' && data[i] != '\t' && data[i] != '\r' && flag!=1) {
			if (data[i] == 'a' || data[i] == 'A') {
				count++;
				flag = 1;
			}
			else flag = 1;
		}
		if (data[i] == ' ' || data[i] == '\n' || data[i] == '\t' || data[i] == '\r' || flag != 1) {
			flag = 0;
		}
	}
	return count;
}


int numc() {
	int count = 0;
	for (int i = 0; data[i] != '\0'; i++) {
		if (data[i]>='0' && data[i]<='9') {
			count++;
		}
	}
	return count;
}

int main() {
	read();
	printf("\n���� �� :%d\n�ܾ� �� :%d\n���� ��:%d\na �� �����ϴ� �ܾ� ��:%d", charc(), wordc(),numc(),wordac());
}