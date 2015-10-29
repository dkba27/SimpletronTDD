#include "simpletron.h"
#include "gtest/gtest.h"

namespace {

// The fixture for testing class Foo.
class simpleTest : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	simpleTest() {
		// You can do set-up work for each test here.
	}

	virtual ~simpleTest() {
		// You can do clean-up work that doesn't throw exceptions here.
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:

	virtual void SetUp() {
		s.loadmem(0, "+1007");
		s.loadmem(1, "+2007");
		s.loadmem(3, "5");
		s.loadmem(99,"99");
		s.setAccumulator(25);
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}
	simpletron s;
	// Objects declared here can be used by all tests in the test case for Foo.
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(simpleTest, simpletronLoadsMemory) {

	EXPECT_EQ("+1007", s.fetch(0));
	EXPECT_EQ("+2007", s.fetch(1));
}

TEST_F(simpleTest, simpletronItoR)
{
	EXPECT_EQ("5", s.itos(5));
}

// Tests that Foo does Xyz.
TEST_F(simpleTest, convertstring)
{
	EXPECT_EQ(10, s.getOpCode("0"));
	EXPECT_EQ(7, s.getOperand("0"));
	EXPECT_EQ(20, s.getOpCode("1"));
	EXPECT_EQ(07, s.getOperand("1"));
}


TEST_F(simpleTest, opcodes)
{
	EXPECT_EQ(1007, s.load(0));
	EXPECT_EQ("25", s.store(5));
	EXPECT_EQ(30, s.add(3));
	EXPECT_EQ(20, s.subtract(3));
	EXPECT_EQ(125, s.multiply(3));
	EXPECT_EQ(5, s.divide(3));


}

TEST_F(simpleTest, evalInstructionsInt)
{
	EXPECT_EQ(1007, s.evalInstruction(20,0));

	EXPECT_EQ(30, s.evalInstruction(30,3));
	EXPECT_EQ(20, s.evalInstruction(31,3));
	EXPECT_EQ(125, s.evalInstruction(33,3));
	EXPECT_EQ(5, s.evalInstruction(32,3));
}
TEST_F(simpleTest, evalInstructionsString)
{
	EXPECT_EQ("25", s.evalInstruction(21,5,'a'));
	EXPECT_EQ("0", s.evalInstruction(40,0,'a'));
	EXPECT_EQ("1", s.evalInstruction(41,1,'a'));
	EXPECT_EQ("3", s.evalInstruction(42,3,'a'));
}
}  // namespace


