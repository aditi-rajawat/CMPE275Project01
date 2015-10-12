################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test.cpp \
../windorseAlgorithm04.cpp \
../windroseAlgorithm.cpp \
../windroseAlgorithm01.cpp \
../windroseAlgorithm02.cpp \
../windroseAlgorithm03.cpp 

OBJS += \
./test.o \
./windorseAlgorithm04.o \
./windroseAlgorithm.o \
./windroseAlgorithm01.o \
./windroseAlgorithm02.o \
./windroseAlgorithm03.o 

CPP_DEPS += \
./test.d \
./windorseAlgorithm04.d \
./windroseAlgorithm.d \
./windroseAlgorithm01.d \
./windroseAlgorithm02.d \
./windroseAlgorithm03.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -fopenmp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


