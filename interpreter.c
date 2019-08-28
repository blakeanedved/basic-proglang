#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int data[1000] = { 0 };
char instructions[1000][11] = { "+0000000000" };
int input[1000] = { 0 };
int ci = 0; // current instruction
int ip = 0; // input pointer

void loadFile(const char *filename){
	FILE *f = fopen(filename, "r");
	if (f == NULL){
		printf("Fatal error: File \"%s\" does not exist\n", filename);
		exit(2);
	}

	char line[12];
	int index = 0;

	while (fscanf(f, "%s", line) != EOF){
		if (strcmp(line, "+9999999999") == 0){
			index = 0;
			break;
		}
		data[index++] = atoi(line);
	}
	
	while (fscanf(f, "%s", line) != EOF){
		if (strcmp(line, "+9999999999") == 0){
			index = 0;
			break;
		}
		strcpy(instructions[index], line);
		index++;
	}

	while (fscanf(f, "%s", line) != EOF){
		input[index++] = atoi(line);
	}

	fclose(f);
}

void p0(int adr1, int adr2, int adr3){
	exit(0);
}
void p1(int adr1, int adr2, int adr3){
	ci = adr3 - 1;
}
void p2(int adr1, int adr2, int adr3){
	data[adr3] = data[adr1] + data[adr2];
}
void p3(int adr1, int adr2, int adr3){
	data[adr3] = data[adr1] - data[adr2];
}
void p4(int adr1, int adr2, int adr3){
	data[adr3] = data[adr1] * data[adr2];
}
void p5(int adr1, int adr2, int adr3){
	if (data[adr2] != 0){
		data[adr3] = data[adr1] / data[adr2];
	} else {
		printf("Fatal Arithmetic Error\n");
		exit(2);
	}
}
void p6(int adr1, int adr2, int adr3){
	data[adr3] = data[adr1] % data[adr2];
}
void p7(int adr1, int adr2, int adr3){
	data[adr3] = data[adr2];
}
void p8(int adr1, int adr2, int adr3){
	data[adr3] = input[ip++];
}
void p9(int adr1, int adr2, int adr3){
	printf("%d\n", data[adr3]);
}

void n0(int adr1, int adr2, int adr3){
	if (data[adr1] == data[adr2]){
		ci = adr3 - 1;
	}
}
void n1(int adr1, int adr2, int adr3){
	if (data[adr1] < data[adr2]){
		ci = adr3 - 1;
	}
}
void n2(int adr1, int adr2, int adr3){
	if (data[adr1] > data[adr2]){
		ci = adr3 - 1;
	}
}
void n3(int adr1, int adr2, int adr3){
	if (data[adr1] <= data[adr2]){
		ci = adr3 - 1;
	}
}
void n4(int adr1, int adr2, int adr3){
	if (data[adr1] >= data[adr2]){
		ci = adr3 - 1;
	}
}
void n5(int adr1, int adr2, int adr3){
	if (data[adr1] != data[adr2]){
		ci = adr3 - 1;
	}
}
void n6(int adr1, int adr2, int adr3){
	printf("%c", (char)data[adr3]);
}
void n7(int adr1, int adr2, int adr3){
	data[adr3] = adr2;
}
void n8(int adr1, int adr2, int adr3){
	if (data[adr2] >= 0 && data[adr2] < 1000){
		data[adr3] = data[data[adr2]];
	} else {
		printf("Fatal SEGFAULT at instruction %d\n", ci);
		exit(1);
	}
}
void n9(int adr1, int adr2, int adr3){
	data[adr3] = rand() % data[adr2];
}

void parseInstruction(const char instruction[11], char *pn, int *op, int *adr1, int *adr2, int *adr3){
	(*pn) = instruction[0];
	(*op) = instruction[1] - '0';
	(*adr1) = ((instruction[2] - '0') * 100) + ((instruction[3] - '0') * 10) + (instruction[4] - '0');
	(*adr2) = ((instruction[5] - '0') * 100) + ((instruction[6] - '0') * 10) + (instruction[7] - '0');
	(*adr3) = ((instruction[8] - '0') * 100) + ((instruction[9] - '0') * 10) + (instruction[10] - '0');
}

int main(int argc, char *argv[]){

	if (argc == 1){
		printf("Fatal error: No file provided\n");
		return 1;
	}

	srand(time(NULL));

	loadFile(argv[1]);

	char pn;
	int op;
	int adr1, adr2, adr3;

	while (ci < 1000){
		
		parseInstruction(instructions[ci], &pn, &op, &adr1, &adr2, &adr3);

		switch (pn){
			case '+':
				switch(op){
					case 0: p0(adr1, adr2, adr3); break;
					case 1: p1(adr1, adr2, adr3); break;
					case 2: p2(adr1, adr2, adr3); break;
					case 3: p3(adr1, adr2, adr3); break;
					case 4: p4(adr1, adr2, adr3); break;
					case 5: p5(adr1, adr2, adr3); break;
					case 6: p6(adr1, adr2, adr3); break;
					case 7: p7(adr1, adr2, adr3); break;
					case 8: p8(adr1, adr2, adr3); break;
					case 9: p9(adr1, adr2, adr3); break;
				}
				break;
			case '-':
				switch(op){
					case 0: n0(adr1, adr2, adr3); break;
					case 1: n1(adr1, adr2, adr3); break;
					case 2: n2(adr1, adr2, adr3); break;
					case 3: n3(adr1, adr2, adr3); break;
					case 4: n4(adr1, adr2, adr3); break;
					case 5: n5(adr1, adr2, adr3); break;
					case 6: n6(adr1, adr2, adr3); break;
					case 7: n7(adr1, adr2, adr3); break;
					case 8: n8(adr1, adr2, adr3); break;
					case 9: n9(adr1, adr2, adr3); break;
				}
				break;
		}
		ci++;
	}

	return 0;
}
