#include "lexer.h"


void Lexer::Advance(){
	if (*textptr != '\0' || *textptr == ' ') // increment pointer until pass a null or increment pointer if pass a space.
		textptr++;
}
void Lexer::Check(){
	if (*textptr == '\0')
	{
		tokens.emplace_back(token);
	}
	switch (*textptr)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		token = *textptr;
		tokens.emplace_back(token);
		token.clear();
	break;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		token += *textptr;
		if (*(textptr + 1) == '+' || *(textptr + 1) == '-' || *(textptr + 1) == '*' || *(textptr + 1) == '/')
		{
			tokens.emplace_back(token);
		}
	break;


	}
}
void Lexer::setCode(std::string m_code)
{
	code = m_code;
	textptr = &code[0];
}

void Lexer::Tokenize(){
	if (code.empty()) {
		std::cout << "CANNOT TOKENIZE EMPTY STRING!" << '\n';
		return;
	}

	tokens.clear();
	token.clear();
	while (true) {
		if (*textptr == '\0') //check dupy
		{
			Check();
			break;
		}
		Check();
		Advance();
	}
}

void Lexer::Display(){
	for (const auto& val : tokens)
		std::cout << val;
	std::cout << '\n';
}