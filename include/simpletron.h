#ifndef INCLUDE_SIMPLETRON_H_
#define INCLUDE_SIMPLETRON_H_
#include <string>
#include <iostream>



using namespace std;

class simpletron{
public:
	simpletron();
	void loadmem(int, string);
	string fetch(int);
	void inputprogram();
	int getOpCode(string);
	int getOperand(string);
	void execute();
	// opcodes
	string read(int operand) ; // opcode 10 -- read from keyboard
	void write(int operand); // opcode 11 -- output to screen
	int load(int operand);  // return what is being loaded
	string store(int operand); // 20, 21 load/store accum
	int add(int operand);
	int subtract(int operand);
	int multiply(int operand);
	float divide(int operand);
	string branch(int operand); // 40 -- return value at memory[opcode] location
	string branchNeg(int operand);
	string branchZero(int operand);
	void halt(); // 43

	int evalInstruction(int opcode, int operand);
	string evalInstruction(int opcode, int operand, char x);
	string itos(int) const;

	int getAccumulator();
	void setAccumulator(int);

	void dump();
private:
	string memory[100];
	int accumulator;
	int opcode;
	int operand;
	string instructionRegister;
	int instructionCounter;


};




#endif /* INCLUDE_SIMPLETRON_H_ */
