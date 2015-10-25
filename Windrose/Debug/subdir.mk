################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CopyOfParallel.cpp \
../Parallel01.cpp \
../Parallel02.cpp \
../Parallel03.cpp \
../Parallel04.cpp \
../Parallel05.cpp \
../Serial02.cpp \
../serial.cpp \
../test.cpp \
../test03.cpp \
../test04.cpp \
../test2.cpp \
../windorseAlgorithm04.cpp \
../windroseAlgorithm.cpp \
../windroseAlgorithm01.cpp \
../windroseAlgorithm02.cpp \
../windroseAlgorithm03.cpp \
../windroseAlgorithm05.cpp \
../windroseAlgorithm06.cpp \
../windroseAlgorithm07.cpp \
../windroseAlgorithm08.cpp \
../windroseAlgorithm09.cpp \
../windroseAlgorithm10.cpp \
../windroseAlgorithm11.cpp \
../windroseAlgorithm12.cpp 

OBJS += \
./CopyOfParallel.o \
./Parallel01.o \
./Parallel02.o \
./Parallel03.o \
./Parallel04.o \
./Parallel05.o \
./Serial02.o \
./serial.o \
./test.o \
./test03.o \
./test04.o \
./test2.o \
./windorseAlgorithm04.o \
./windroseAlgorithm.o \
./windroseAlgorithm01.o \
./windroseAlgorithm02.o \
./windroseAlgorithm03.o \
./windroseAlgorithm05.o \
./windroseAlgorithm06.o \
./windroseAlgorithm07.o \
./windroseAlgorithm08.o \
./windroseAlgorithm09.o \
./windroseAlgorithm10.o \
./windroseAlgorithm11.o \
./windroseAlgorithm12.o 

CPP_DEPS += \
./CopyOfParallel.d \
./Parallel01.d \
./Parallel02.d \
./Parallel03.d \
./Parallel04.d \
./Parallel05.d \
./Serial02.d \
./serial.d \
./test.d \
./test03.d \
./test04.d \
./test2.d \
./windorseAlgorithm04.d \
./windroseAlgorithm.d \
./windroseAlgorithm01.d \
./windroseAlgorithm02.d \
./windroseAlgorithm03.d \
./windroseAlgorithm05.d \
./windroseAlgorithm06.d \
./windroseAlgorithm07.d \
./windroseAlgorithm08.d \
./windroseAlgorithm09.d \
./windroseAlgorithm10.d \
./windroseAlgorithm11.d \
./windroseAlgorithm12.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -fopenmp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


