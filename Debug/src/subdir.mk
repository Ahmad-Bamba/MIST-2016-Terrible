################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Encrypt.cpp \
../src/MistOperate.cpp \
../src/Prime\ Checker.cpp \
../src/SysMist.cpp \
../src/Task.cpp 

OBJS += \
./src/Encrypt.o \
./src/MistOperate.o \
./src/Prime\ Checker.o \
./src/SysMist.o \
./src/Task.o 

CPP_DEPS += \
./src/Encrypt.d \
./src/MistOperate.d \
./src/Prime\ Checker.d \
./src/SysMist.d \
./src/Task.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Prime\ Checker.o: ../src/Prime\ Checker.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Prime Checker.d" -MT"src/Prime\ Checker.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


