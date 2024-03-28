#include <stdio.h>

/**
 * Function will ask for user input and count characters.
 */
void countChars(void)
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
void scanfInt(void)
{
	int myNum;
	char myChar;
	printf("Gebe nummer UND ein Zeichen ein, z.B.  '9 c', '18 e': \n");
	if (scanf("%d %c", &myNum, &myChar) != 2)
	{
		printf("Error!\n");
		return;
	}

	printf("Eingabe: num %d und char %c\n", myNum, myChar);
}

/**
 * Demo of using scanf for reading single word from user input.
 */
void scanfString(void)
{
	char name[21]; // max 20 + '\0'
	printf("Gebe Name ein (max 20 Zeichen!!): \n");
	if (scanf("%20s", name) != 1)
	{
		printf("Error!\n");
		return;
	}

	printf("Eingabe: %s\n", name);
}

/**
 * Demo of using fgets for reading multiple words from user input.
 */
void fgetsString(void)
{
	char fullName[30];
	printf("Gebe Vorname und Nachname ein (max 30 Zeichen!!): \n");
	if (!fgets(fullName, sizeof(fullName), stdin))
	{
		printf("Error!\n");
		return;
	}

	printf("Eingabe: %s\n", fullName);
}

int main(void)
{
	printf("Uncomment parts in source code.\n");
	// // Uncomment
	// countChars();
	// scanfInt();
	// scanfString();
	// fgetsString();
	return 0;
}
