//Parser//

#include <stdio.h>
#include <ctype.h>

int charClass;
char lexeme [100];

char nextChar;
char nextChar1;
char nextChar2;

int lexLen;
int token;
int nextToken;
FILE *in_fp, *fopen();


void addChar();
void getChar();
void getNonBlank();
int lex();

#define LETTER 0
#define DIGIT 1
#define ADD 3
#define DIV 4
#define SUB 5
#define MUL 6
#define MOD 7
#define LEFT 8
#define RIGHT 9
#define UNKNOWN 99


#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define MOD_OP 25
#define LEFT_PAREN 26
#define RIGHT_PAREN 27

int count = 0;

int sub = 0;

int nextToken1;



main()
{



	printf("<assign>\n");
	printf("<id> = <expr>\n");


	if((in_fp = fopen("front.in", "r")) == NULL)
		printf("ERROR - cannot open front.in \n");
	else
	{
	getChar();
	do {
		lex();


	}while (nextToken != EOF);
}







}



void addChar()
{
	if(lexLen <=98)
	{
		lexeme[lexLen++] = nextChar;
	
		lexeme[lexLen] = 0;
	}
	else
		printf("ERROR - lexeme is too long \n");
}





void addChar1()
{
	if(lexLen <=98)
	{
		lexeme[lexLen++] = nextChar1;
	
		lexeme[lexLen] = 0;
	}
	else
		printf("ERROR - lexeme is too long \n");
}



void getChar() {

	if ((nextChar = getc(in_fp)) != EOF) 
	{

		nextChar1 = getc(in_fp);

		
		if(nextChar == '(')
		charClass = LEFT;

		else if(nextChar == ')')
		charClass = RIGHT;

		
		else if(nextChar == 'a')
		charClass = LETTER;

		else if(nextChar == 'b')
		charClass = LETTER;

		
		else if(nextChar == 'c')
		charClass = LETTER;

		else if(nextChar == 'd')
		charClass = LETTER;

		else if(nextChar == 'e')
		charClass = LETTER;

		else if(nextChar == 'f')
		charClass = LETTER;

		else if(nextChar == 'g')
		charClass = LETTER;

		
		else if(nextChar == 'h')
		charClass = LETTER;

		else if(nextChar == 'i')
		charClass = LETTER;

		else if(nextChar == 'j')
		charClass = LETTER;

		
		else if(nextChar == 'k')
		charClass = LETTER;

		
		else if(nextChar == 'l')
		charClass = LETTER;

		
		else if(nextChar == 'm')
		charClass = LETTER;

		
		else if(nextChar == 'n')
		charClass = LETTER;

		
		else if(nextChar == 'o')
		charClass = LETTER;

		
		else if(nextChar == 'p')
		charClass = LETTER;

		
		else if(nextChar == 'q')
		charClass = LETTER;

		
		else if(nextChar == 'r')
		charClass = LETTER;


		else if(nextChar == 's')
		charClass = LETTER;

		
		else if(nextChar == 't')
		charClass = LETTER;

		
		else if(nextChar == 'u')
		charClass = LETTER;

		
		else if(nextChar == 'v')
		charClass = LETTER;

		
		else if(nextChar == 'w')
		charClass = LETTER;

		
		else if(nextChar == 'x')
		charClass = LETTER;

		
		else if(nextChar == 'y')
		charClass = LETTER;

		
		else if(nextChar == 'z')
		charClass = LETTER;


		else if(nextChar == 'A' && nextChar1 == 'D' || nextChar == 'D' && nextChar1 == 'D')
		charClass = ADD;

		
		else if(nextChar == 'D' && nextChar1 == 'I' || nextChar == 'I' && nextChar1 == 'V')
		charClass = DIV;


		else if(nextChar == 'S' && nextChar1 == 'U' || nextChar == 'U' && nextChar1 == 'B' )
		charClass = SUB;

		else if(nextChar == 'M' && nextChar1 == 'U' || nextChar == 'U' && nextChar1 == 'L')
		charClass = MUL;

		else if(nextChar == 'M' && nextChar1 == 'O' || nextChar == 'O' && nextChar1 == 'D')
		charClass = MOD;


		else if(isdigit(nextChar))
			charClass  = DIGIT;

		else if(nextChar == ' ' || nextChar1 == ' ')
			getChar();

		


	}
	else
		charClass = EOF;
}



void getNonBlank()
{



	while (isspace(nextChar))
		getChar();
}


int lex() {
	lexLen = 0;
	getNonBlank();
	switch (charClass) {
	case LETTER:
		addChar();
		addChar1();
		getChar();
		while (charClass == LETTER){
		addChar();
		addChar1();
		getChar();
		}
		nextToken = IDENT;
		break;

	case ADD:
		addChar();
		addChar1();
		getChar();
		while (charClass == ADD){
		addChar();
		addChar1();
		getChar();
		}
		nextToken = ADD_OP;
		break;

		
	case DIV:
		addChar();
		addChar1();
		getChar();
		while (charClass == DIV){
		addChar();	
		addChar1();
		getChar();
		}
		nextToken = DIV_OP;
		break;

	case SUB:
		addChar();
		addChar1();
		getChar();
		while (charClass == SUB){
		addChar();
		addChar1();
		getChar();
		}
		nextToken = SUB_OP;
		break;

		
	case MOD:
		addChar();
		addChar1();
		getChar();
		while (charClass == MOD){
		addChar();
		addChar1();
		getChar();
		}
		nextToken = MOD_OP;
		break;

				
	case MUL:
		addChar();
		addChar1();
		getChar();
		while (charClass == MUL){
		addChar();	
		addChar1();
		getChar();
		}
		nextToken = MULT_OP;
		break;


	case DIGIT:
		addChar();
		getChar();
		while (charClass == DIGIT) {
			addChar();
			getChar();
		}
		nextToken = INT_LIT;
		break;

	
	case LEFT:
		addChar();
		getChar();
		while (charClass == LEFT) {
			addChar();
			getChar();
		}
		nextToken = LEFT_PAREN;
		break;

	case RIGHT:
		addChar();
		getChar();
		while (charClass == RIGHT) {
			addChar();
			getChar();
		}
		nextToken = RIGHT_PAREN;
		break;



	case EOF:
		nextToken = EOF;
		lexeme[0] = 'E';
		lexeme[1] = 'O';
		lexeme[2] = 'F';
		lexeme[3] = 0;
		break;


	}




////////////////////////////////////////////////////////////////////







	if(nextToken == 21)
	printf("ADD<term>\n");


	else if(nextToken == 22)
	printf("\n<expr>SUB<term>\n");

	
	else if(nextToken == 23)
	printf("MUL<factor>\n");
	
		
	
	else if(nextToken == 24)
	printf("DIV<factor>\n");



	else if(nextToken == 25)
	printf("MOD<factor>\n");


	else if(nextToken == 26)
	printf("\n( <expr> )\n");


	else if(nextToken == 27)
	{
	printf("\n");
	}
	
	

	else if(nextToken == EOF)
	printf("\n\n");

	else
		printf("<id>");





	return nextToken;


	
}








