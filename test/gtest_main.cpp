/*
 * gtest_main.cpp
 *
 *  Created on: Oct 8, 2015
 *      Author: adminuser
 */
#include <stdio.h>
#include "gtest/gtest.h"

GTEST_API_ int main(int argc, char **argv) {
	printf("Running main() from gtest_main.cc\n");
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}



