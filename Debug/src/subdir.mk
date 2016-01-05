################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Encrypt.cpp \
../src/MistOperate.cpp \
../src/Prime\ Checker.cpp \
../src/Program.cpp \
../src/SysMist.cpp \
../src/Task.cpp 

OBJS += \
./src/Encrypt.o \
./src/MistOperate.o \
./src/Prime\ Checker.o \
./src/Program.o \
./src/SysMist.o \
./src/Task.o 

CPP_DEPS += \
./src/Encrypt.d \
./src/MistOperate.d \
./src/Prime\ Checker.d \
./src/Program.d \
./src/SysMist.d \
./src/Task.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -D__GXX_EXPERIMENTAL_CXX0X__ -O2 -g -Wall -c -fmessage-length=0 -std=c++11  -pthread -Wl,--whole-archive -lpthread -Wl,--no-whole-archive -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Prime\ Checker.o: ../src/Prime\ Checker.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -D__GXX_EXPERIMENTAL_CXX0X__ -O2 -g -Wall -c -fmessage-length=0 -std=c++11  -pthread -Wl,--whole-archive -lpthread -Wl,--no-whole-archive -fPIC -MMD -MP -MF"src/Prime Checker.d" -MT"src/Prime\ Checker.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


