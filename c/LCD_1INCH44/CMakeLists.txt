cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(LCD_INCH44_project)

# Initialize the SDK
pico_sdk_init()

add_executable(LCD_1INCH44
        main.c
        lcd_1inch44.c
        lcd_gui.c
        font16.c
        font24.c
        key.c
)
            
# pull in common dependencies
target_link_libraries(LCD_1INCH44 hardware_spi hardware_pwm pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(LCD_1INCH44 1)
pico_enable_stdio_uart(LCD_1INCH44 0)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(LCD_1INCH44)

