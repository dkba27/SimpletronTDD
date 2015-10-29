#include "simpletron.h"
#include <stdlib.h>
#include <string>
#include <sstream>

const int READ=10;
const int  WRITE =11;
const int  LOAD =20;
const int STORE =21;
const int ADD =30;
const int SUBTRACT =31;
const int DIVIDE =32;
const int MULTIPLY =33;
const int  BRANCH= 40;
const int  BRANCHNEG =41;
const int BRANCHZERO =42;
const int HALT= 43;

using namespace std;

simpletron::simpletron(){

	accumulator = 0;
	instructionCounter = 0;
	for (int i=0; i<100; i++)
		memory [i]="0000";
//	memory = {"0000"};
	opcode = 0;
	operand = 0;

}

string simpletron::itos(int num) const
{
	stringstream ss;
	ss << num;
	return ss.str();
}

int simpletron::getAccumulator()
{
	return accumulator;
}

void simpletron::setAccumulator(int a)
{
	accumulator = a;
}

void simpletron::loadmem(int location, string input){
	memory[location]= input;
}
string simpletron::fetch(int location){
	return memory[location];
}

void simpletron::inputprogram() {
	string userInput;
	int count = 0;
	cout << " Input your computer instruction. Type -99999 when you are completed " << endl;

	while (userInput != "-99999")
	{
		cout << count  << " ? ";
		cin >> userInput;
		if (userInput !="-99999")
		{
			loadmem(count, userInput);
			count ++;
		}

	}
}

int simpletron::getOperand(string userInput)
{
	int x, y;
	int index = atoi(userInput.c_str());
//	string foo;
//	foo = memory[index];  // 21
//	x = atoi(foo.c_str());
	y = index % 100;
	return  y;
}

int simpletron::getOpCode(string userInput)
{
	int x, y;
	int index = atoi(userInput.c_str());
//	string foo;
//	foo = memory[index];  // 21
//	x = atoi(foo.c_str());
	y = index / 100;
	return  y;
}


string simpletron::read(int operand)
{
	string input;
	cin >> input;
	memory[operand] = input;
	return input;
}

void simpletron::write(int operand)
{
	cout << memory[operand];
}
//20      00
int simpletron::load(int operand)  // return what is being loaded
{

	//accumulator = atoi(memory[operand].c_str());
	return atoi(memory[operand].c_str());;
}
string simpletron::store(int operand) // 20, 21 load/store accum
{
	memory[operand] = itos(accumulator);
	return memory[operand];
}
int simpletron::add(int operand)
{
	return accumulator + atoi(memory[operand].c_str());
}
int simpletron::subtract(int operand)
{
	return accumulator - atoi(memory[operand].c_str());
}
int simpletron::multiply(int operand)
{
	return accumulator * atoi(memory[operand].c_str());
}
float simpletron::divide(int operand)
{
	return accumulator / atoi(memory[operand].c_str());
}
string simpletron::branch(int operand) // 40 -- return value at memory[opcode] location
{
	instructionRegister = itos(operand);
	return instructionRegister;
}
string simpletron::branchNeg(int operand)
{
	instructionRegister = itos(operand);
	return instructionRegister;
}
string simpletron::branchZero(int operand)
{
	instructionRegister =itos(operand);
	return instructionRegister;
}

void simpletron::halt() // 43
{

}

string simpletron::evalInstruction (int opcode, int operand, char x)
{
	string retString;
	switch(opcode)
	{
	case READ:
			retString = read(operand);
			break;
	case STORE:
		retString = store(operand);
		//retCode = atoi(retString.c_str());
		break;
	case BRANCH:
		retString = branch(operand);
		break;
	case BRANCHNEG:
		retString = branchNeg(operand);
		break;
	case BRANCHZERO:
		retString = branchZero(operand);
		break;
	}
	return retString;

}

int simpletron::evalInstruction(int opcode, int operand)
{
	int retCode = 0;
	float retFloat = 0.0;
	string retString;
	switch(opcode)
	{
	case WRITE:
		write(operand);
		break;

	case LOAD:
		retCode = load(operand);
		break;


	case ADD:
		retCode = add(operand);
		break;
	case SUBTRACT:
		retCode = subtract(operand);
		break;
	case DIVIDE:
		retCode = divide (operand);
		break;
	case MULTIPLY:
		retCode = multiply(operand);
		break;

	case HALT:
		halt();
		break;
	}


	return retCode;
}


void simpletron::execute()
{
	do {

		instructionRegister = fetch(instructionCounter);
		//instructionRegister = memory[instructionCounter];
		opcode = getOpCode(instructionRegister);
		operand = getOperand(instructionRegister);

		//evalInstruction (int opcode, int operand);

		if (opcode == 10 || opcode == 21 || opcode == 40 || opcode == 41 || opcode == 42){
			evalInstruction(opcode, operand, 'a');
		}

		else {
			evalInstruction(opcode, operand);

		}

		instructionCounter ++;
	}	while(opcode != 43);


}

void simpletron::dump()
{
	cout << "REGISTERS:" << endl;

	cout << "accumulator: \t" << accumulator << endl;
	cout << "instructionCounter: \t" << instructionCounter << endl;
	cout << "instructionRegister: \t" << instructionRegister << endl;
	cout << "Opcode: \t\t\t" << opcode << endl;
	cout << "Operand: \t\t\t" << operand << endl << endl;

	cout << "MEMORY:" << endl << endl;

	cout << "\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9" << endl;

	for (int i = 0; i < 100; i+=10)
	{
		cout << i << ": ";
		for (int j = i; j<i+10; j++)
		{
			cout << memory[j]<< "\t";

		}
		cout << endl;
	}




}
