cp  ../../FreeRTOSDemo_s/Debug/FreeRTOSDemo_s.axf .
arm-none-eabi-objcopy -v -O ihex FreeRTOSDemo_s.axf FreeRTOSdemo_s.hex
arm-none-eabi-objcopy -v -O ihex FreeRTOSDemo_ns.axf FreeRTOSdemo_ns.hex
mergehex --merge FreeRTOSDemo_ns.hex FreeRTOSDemo_s.hex -o FreeRTOSDemo_combined.hex
nrfjprog -e
nrfjprog --program ./FreeRTOSDemo_combined.hex
 