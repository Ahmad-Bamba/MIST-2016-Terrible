################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MistInit.cpp \
../src/MistOperate.cpp \
../src/SysMist.cpp \
../src/Task.cpp 

OBJS += \
./src/MistInit.o \
./src/MistOperate.o \
./src/SysMist.o \
./src/Task.o 

CPP_DEPS += \
./src/MistInit.d \
./src/MistOperate.d \
./src/SysMist.d \
./src/Task.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


