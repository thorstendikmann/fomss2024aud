#include <stdio.h>

/**
 * Function will ask for user input and count characters.
 */
void countChars()
{
	long nc;

	printf("Gebe Zeichen ein und drücker [Enter]. Beende mit \'c\' + [Enter]\n");
	nc = 0;
	while (getchar() != 'c')
	{
		++nc;
	}
	printf("%ld Zeichen\n", nc);
}

/**
 * Demo of using scanf for reading int and char from user input.
 */
void scanfInt()
{
	int myNum;
	char myChar;
	printf("Gebe nummer UND ein Zeichen ein, z.B.  '9 c', '18 e': \n");
	scanf("%d %c", &myNum, &myChar);

	printf("Eingabe: num %d und char %c\n", myNum, myChar);
}

/**
 * Demo of using scanf for reading single word from user input.
 */
void scanfString()
{
	char name[20];
	printf("Gebe Name ein (max 20 Zeichen!!): \n");
	scanf("%s", name);

	printf("Eingabe: %s\n", name);
}

/**
 * Demo of using fgets for reading multiple words from user input.
 */
void fgetsString()
{
	char fullName[30];
	printf("Gebe Vorname und Nachname ein (max 30 Zeichen!!): \n");
	fgets(fullName, sizeof(fullName), stdin);

	printf("Eingabe: %s\n", fullName);
}

int main()
{
	// // Uncomment
	// countChars();
	// scanfInt();
	// scanfString();
	// fgetsString();
	return 0;
}