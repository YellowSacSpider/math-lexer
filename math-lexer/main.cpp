#include "lexer.h"



int main() {

	Lexer lexer("25+2/4/2+1*8-2");
	lexer.Tokenize();
	lexer.Display();
	lexer.setCode("2+2");
	lexer.Tokenize();
	lexer.Display();
	return 0;
}