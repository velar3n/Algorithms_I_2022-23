#include <iostream>
#include <stack>
#include <vector>

bool is_operand(std::string operand){														// funkcja sprawdzająca, czy string jest jednym ze znaków działań matematycznych
	return operand == "+" || operand == "-" || operand == "*" || operand == "/";
}

int rpn(std::vector<std::string> input){

	std::stack<int> temp_stack;																// tworzenie stosu
	int i = 0;

	for(std::string element : input){														// przeiterowanie przez wektor 'input'
		std::string character = input[i];
		i++;

		if(is_operand(character)){															// jeśli string jest operandem dokonujenie działanie + usuwamy 2 ostatnie liczby ze stosu
			int a = temp_stack.top();
			temp_stack.pop();
			int b = temp_stack.top();
			temp_stack.pop();

			if(character == "+"){
				temp_stack.push(b + a);
			} else if(character == "-"){
				temp_stack.push(b - a);
			} else if(character == "*"){
				temp_stack.push(b * a);
			} else{
				temp_stack.push(b / a);
			}
		} else {																			// jeśli nie, to string jest liczbą - dodajemy ją na stos
			int number = stoi(character);
			temp_stack.push(number);
		}
	}
	return temp_stack.top();																// zwracamy ostatnią pozostałą na stosie liczbę - czyli wynik
}