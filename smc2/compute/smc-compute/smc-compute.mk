#ADD inputs and output to the build variables
CPP_SRCS += \
../smc-compute/NodeConfiguration.cpp \
../smc-compute/NodeNetwork.cpp \
../smc-compute/SecretShare.cpp \
../smc-compute/SMC_Utils.cpp \
../smc-compute/LocationTracking.cpp

OBJS += \
./smc-compute/NodeConfiguration.o \
./smc-compute/NodeNetwork.o \
./smc-compute/SecretShare.o \
./smc-compute/SMC_Utils.o \
./smc-compute/LocationTracking.o

CPP_DEPS += \
./smc-compute/NodeConfiguration.d \
./smc-compute/NodeNetwork.d \
./smc-compute/SecretShare.d \
./smc-compute/SMC_Utils.d \
./smc-compute/LocationTracking.d

#Supply the rules for building the source
smc-compute/%.o: ../smc-compute/%.cpp
	@echo 'Building file:'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
                    

