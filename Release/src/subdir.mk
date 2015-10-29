################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main.cpp \
../src/simpletron.cpp 

OBJS += \
./src/main.o \
./src/simpletron.o 

CPP_DEPS += \
./src/main.d \
./src/simpletron.d 


# Each subdirectory must supply rules for building sources it contributes
src/main.o: ../src/main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -I"/home/adminuser/workspace/Simpletron_mb/include" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/main.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/simpletron.o: ../src/simpletron.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -I"/home/adminuser/workspace/Simpletron_mb/include" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/simpletron.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


