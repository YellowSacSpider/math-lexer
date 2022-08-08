#include "lexer.h"

int main() {

	Lexer lexer("10*2");
	lexer.Tokenize();
	lexer.Display();
	return 0;
}