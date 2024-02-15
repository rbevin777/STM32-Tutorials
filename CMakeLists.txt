cmake_minimum_required(VERSION 3.20) # this is required in every cmakelists file.
project(STM32NucleoTutorials) # this is required in every cmakelists file. This is just the project name.

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER /usr/bin/arm-none-eabi-gcc) # build on linux

string(APPEND compiler_opts
        "-Wall;"
        "-Wextra;"
        "-Wfatal-errors;"
        "-lm;"
        "-lc;"
        "-lgcc;"
        "-std=c99;"
)

string(  
    APPEND link_opts 
    "-fdiagnostics-color=always;"
    "-fno-diagnostics-show-caret;"
    "-fno-diagnostics-show-line-numbers;"
    "-fdiagnostics-urls=always;"
    "-fdiagnostics-path-format=separate-events;"
    )

    
add_link_options("${link_opts}")


add_compile_options("${compiler_opts}")
set(top_dir I2C)


set(CORE_DIR
    # Src 
    ${top_dir}/Core/Src/main.c
    ${top_dir}/Core/Src/stm32f3xx_hal_msp.c
    ${top_dir}/Core/Src/stm32f3xx_it.c
    ${top_dir}/Core/Src/syscalls.c
    ${top_dir}/Core/Src/sysmem.c
    ${top_dir}/Core/Src/system_stm32f3xx.c

    # Inc
    ${top_dir}/Core/Inc/main.h
    ${top_dir}/Core/Inc/stm32f3xx_hal_conf.h
    ${top_dir}/Core/Inc/stm32f3xx_it.h

    # Peripherals
    ${top_dir}/Core/Peripherals/periph_i2c.c
    ${top_dir}/Core/Peripherals/periph_i2c.h
    ${top_dir}/Core/Peripherals/periph_uart.c
    ${top_dir}/Core/Peripherals/periph_uart.h

    # UserDrivers
    ${top_dir}/Core/UserDrivers/mpu6050_reg_map.h
    ${top_dir}/Core/UserDrivers/mpu6050.h
    ${top_dir}/Core/UserDrivers/mpu6050.c
)

set(CMSIS_DIR
    ${top_dir}/Drivers/CMSIS/Device/ST/STM32F3xx/Include/stm32f3xx.h
    ${top_dir}/Drivers/CMSIS/Device/ST/STM32F3xx/Include/stm32f334x8.h
    ${top_dir}/Drivers/CMSIS/Device/ST/STM32F3xx/Include/system_stm32f3xx.h
    ${top_dir}/Drivers/CMSIS/Include/cmsis_armcc.h
    ${top_dir}/Drivers/CMSIS/Include/cmsis_armclang.h
    ${top_dir}/Drivers/CMSIS/Include/cmsis_compiler.h
    ${top_dir}/Drivers/CMSIS/Include/cmsis_gcc.h
    ${top_dir}/Drivers/CMSIS/Include/cmsis_iccarm.h
    ${top_dir}/Drivers/CMSIS/Include/cmsis_version.h
    ${top_dir}/Drivers/CMSIS/Include/core_armv8mbl.h
    ${top_dir}/Drivers/CMSIS/Include/core_armv8mml.h
    ${top_dir}/Drivers/CMSIS/Include/core_cm0.h
    ${top_dir}/Drivers/CMSIS/Include/core_cm0plus.h
    ${top_dir}/Drivers/CMSIS/Include/core_cm1.h
    ${top_dir}/Drivers/CMSIS/Include/core_cm3.h
    ${top_dir}/Drivers/CMSIS/Include/core_cm4.h
    ${top_dir}/Drivers/CMSIS/Include/core_cm7.h
    ${top_dir}/Drivers/CMSIS/Include/core_cm23.h
    ${top_dir}/Drivers/CMSIS/Include/core_cm33.h
    ${top_dir}/Drivers/CMSIS/Include/core_sc000.h
    ${top_dir}/Drivers/CMSIS/Include/core_sc300.h
    ${top_dir}/Drivers/CMSIS/Include/mpu_armv7.h
    ${top_dir}/Drivers/CMSIS/Include/mpu_armv8.h
    ${top_dir}/Drivers/CMSIS/Include/tz_context.h
)

set(HAL_DRIVERS_INC_DIR
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_cortex.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_def.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_dma_ex.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_dma.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_exti.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_flash_ex.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_flash.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_gpio_ex.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_gpio.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_i2c_ex.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_i2c.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_pwr_ex.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_pwr.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_rcc_ex.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_rcc.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_tim_ex.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_tim.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_uart_ex.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_uart.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_ll_bus.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_ll_cortex.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_ll_dma.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_ll_exti.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_ll_gpio.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_ll_i2c.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_ll_pwr.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_ll_rcc.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_ll_system.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_ll_usart.h
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_ll_utils.h
)

set(HAL_DRIVERS_SRC_DIR
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_cortex.c 
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_dma.c 
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_exti.c 
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_flash_ex.c 
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_flash.c 
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_gpio.c 
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_i2c_ex.c 
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_i2c.c 
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_pwr_ex.c 
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_pwr.c 
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_rcc_ex.c 
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_rcc.c 
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_tim_ex.c 
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_tim.c 
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_uart_ex.c 
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_uart.c 
    ${top_dir}/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal.c
)

# Compile
add_executable(output.elf ${CORE_DIR} ${CMSIS_DIR} ${HAL_DRIVERS_SRC_DIR})
target_include_directories(output.elf ${CORE_DIR} ${HAL_DRIVERS_INC_DIR})
# target_link_libraries(output.elf ${CORE_DIR} ${CMSIS_DIR} ${HAL_DRIVERS_INC_DIR} ${HAL_DRIVERS_SRC_DIR})