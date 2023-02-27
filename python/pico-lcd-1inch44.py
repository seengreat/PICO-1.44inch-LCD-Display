
from machine import Pin,SPI,PWM
import framebuf
import time
import os

# Pin definition
BL = 13
DC = 11
RST = 12
MOSI = 7
SCK = 6    
CS = 5
# color definition RBG
WHITE  =  0xFFFF
BLACK  =  0x0000
GREEN  =  0x001F
RED    =  0x07E0
BLUE   =  0xF800


class Lcd_1inch44():
    def __init__(self):
        self.w = 128
        self.h = 128
        
        self.cs = Pin(CS,Pin.OUT)
        self.rst = Pin(RST,Pin.OUT)
        self.dc = Pin(DC,Pin.OUT)
        self.cs(1)
        self.dc(1)        
        self.init_key()

        self.spi = SPI(0,8000_000,polarity=0, phase=0,sck=Pin(SCK),mosi=Pin(MOSI),miso=None)

        self.buff = bytearray(self.h * self.w * 2) # set the lcd buffer size
        self.draw = framebuf.FrameBuffer(self.buff, self.w, self.h, framebuf.RGB565)
        self.init_lcd()
        
        
    def init_key(self):
        self.k1 = Pin(8,Pin.IN,Pin.PULL_UP) 
        self.k2 = Pin(4,Pin.IN,Pin.PULL_UP)
        self.k3 = Pin(3,Pin.IN,Pin.PULL_UP)
        self.k4 = Pin(2,Pin.IN,Pin.PULL_UP)
        self.up = Pin(18,Pin.IN,Pin.PULL_UP) 
        self.left = Pin(16,Pin.IN,Pin.PULL_UP)
        self.right = Pin(19,Pin.IN,Pin.PULL_UP)
        self.down = Pin(20,Pin.IN,Pin.PULL_UP)
        self.center = Pin(17,Pin.IN,Pin.PULL_UP)
        
    def write_cmd(self, cmd):    
        self.dc(0)
        self.cs(0)
        self.spi.write(bytearray([cmd]))
        self.cs(1)

    def write_data(self, buf):
        self.dc(1)
        self.cs(0)
        self.spi.write(bytearray([buf]))
        self.cs(1)

    def init_lcd(self):
        """Initialize lcd dispaly"""  
        self.rst(1)
        time.sleep(0.01)
        self.rst(0)
        time.sleep(0.01)
        self.rst(1)
        time.sleep(0.01)
        
        self.write_cmd(0x01) #software reset
        time.sleep(0.02)
        
        self.write_cmd(0x11) #sleep out
        time.sleep(0.05)       
        # FRMCTR1:Frame Rate Control in normal mode
        self.write_cmd(0xB1)
        self.write_data(0x02)
        self.write_data(0x35)
        self.write_data(0x36)
        
        # FRMCTR2:Frame Rate Control in idle mode
        self.write_cmd(0xB2)
        self.write_data(0x02)
        self.write_data(0x35)
        self.write_data(0x36)
        
        # FRMCTR3:Frame Rate Control in Partial mode/full colors
        self.write_cmd(0xB3)
        self.write_data(0x02)
        self.write_data(0x35)
        self.write_data(0x36)
        self.write_data(0x02)
        self.write_data(0x35)
        self.write_data(0x36)
        
        # INVCTR:Displa INversion Control
        self.write_cmd(0xB4) 
        self.write_data(0x03)
        
        # PWCTR1:Power Control 1
        self.write_cmd(0xC0) 
        self.write_data(0xA2)
        self.write_data(0x02)
        self.write_data(0x84)
        
        self.write_cmd(0xC1) 
        self.write_data(0xC5)

        self.write_cmd(0xC2) 
        self.write_data(0x0D)
        self.write_data(0x00)

        self.write_cmd(0xC3) 
        self.write_data(0x8D)
        self.write_data(0x2A)
        
        self.write_cmd(0xC4) 
        self.write_data(0x8D)
        self.write_data(0xEE)

        self.write_cmd(0xC5) # VCOM
        self.write_data(0x0A)

        self.write_cmd(0x36) # MX,MY,RGB MODE
        self.write_data(0x68) #0xEC
        
        self.write_cmd(0xE0) 
        self.write_data(0x12)
        self.write_data(0x1C)
        self.write_data(0x10)
        self.write_data(0x18)
        self.write_data(0x33)
        self.write_data(0x2C)
        self.write_data(0x25)
        self.write_data(0x28)
        self.write_data(0x28)
        self.write_data(0x27)
        self.write_data(0x2F)
        self.write_data(0x3C)
        self.write_data(0x00)
        self.write_data(0x03)
        self.write_data(0x03)
        self.write_data(0x10)
        
        self.write_cmd(0xE1) 
        self.write_data(0x12)
        self.write_data(0x1C)
        self.write_data(0x10)
        self.write_data(0x18)
        self.write_data(0x2D)
        self.write_data(0x28)
        self.write_data(0x23)
        self.write_data(0x28)
        self.write_data(0x28)
        self.write_data(0x26)
        self.write_data(0x2F)
        self.write_data(0x3B)
        self.write_data(0x00)
        self.write_data(0x03)
        self.write_data(0x03)
        self.write_data(0x10)
        
        self.write_cmd(0xF0) 
        self.write_data(0x01)
        
        self.write_cmd(0xF6) 
        self.write_data(0x00)

        self.write_cmd(0x3A) 
        self.write_data(0x05)
        
        self.write_cmd(0x29)
        time.sleep(0.05)

    def set_windows(self, start_x, start_y, end_x, end_y):
        """display the windows of start point and end point"""
        # because register 36h = 0x68
        start_x += 1
        end_x += 1
        start_y += 2
        end_y += 2
        # set the start point and end point of x
        self.write_cmd(0x2A) 
        self.write_data(start_x >> 8)  # x address start
        self.write_data(start_x & 0xff)
        self.write_data(end_x >> 8)  # x address end
        self.write_data(end_x & 0xff)
        # set the start point and end point of y
        self.write_cmd(0x2B) 
        self.write_data(start_y >> 8)  # y address start
        self.write_data(start_y & 0xff)
        self.write_data(end_y >> 8)  # y address end
        self.write_data(end_y & 0xff)
        
        self.write_cmd(0x2C)

    def show(self,buff):
        self.set_windows(0, 0, 127, 127) # 36H=0XEC:2, 3, 129, 130; 36H=0X68:1, 2, 128, 129         
        self.write_cmd(0x2C)
        
        self.dc(1)
        self.cs(0)
        self.spi.write(buff)
        self.cs(1)
  
if __name__=='__main__':
    bl = PWM(Pin(BL))
    bl.freq(1000)
    bl.duty_u16(49152) #75%, max 65535, 65536*75%=49152

    lcd = Lcd_1inch44()
    lcd.draw.fill(WHITE)
    lcd.draw.text('SEENGREAT!', 2, 5, RED)
    lcd.draw.text('PICO-1.44in-LCD', 2, 20, GREEN)
    lcd.draw.text('ABC123456789!', 2, 35, BLUE)
    lcd.draw.hline(2,50,127,BLUE)
    lcd.draw.vline(2,50,127,BLUE)
    lcd.draw.fill_rect(20,80,20,20,RED)
    lcd.draw.fill_rect(50,80,20,20,GREEN)
    lcd.draw.fill_rect(80,80,20,20,BLUE)
    lcd.show(lcd.buff)
    time.sleep(5)
    lcd.draw.fill(WHITE)
    while(1):      
        if(lcd.k1.value() == 0):
            lcd.draw.fill_rect(95,16,20,15,GREEN)
        else :
            lcd.draw.fill_rect(95,16,20,15,BLACK)
            
        if(lcd.k2.value() == 0):
            lcd.draw.fill_rect(95,43,20,15,GREEN)
        else :
            lcd.draw.fill_rect(95,43,20,15,BLACK)
            
        if(lcd.k3.value() == 0):
            lcd.draw.fill_rect(95,70,20,15,GREEN)
        else :
            lcd.draw.fill_rect(95,70,20,15,BLACK)
            
        if(lcd.k4.value() == 0):  
            lcd.draw.fill_rect(95,97,20,15,GREEN)
        else :
            lcd.draw.fill_rect(95,97,20,15,BLACK)
            
        if(lcd.up.value() == 0):  
            lcd.draw.fill_rect(20,43,20,10,GREEN)
        else :
            lcd.draw.fill_rect(20,43,20,10,BLACK)
            
        if(lcd.left.value() == 0):  
            lcd.draw.fill_rect(5,58,10,20,GREEN)
        else :
            lcd.draw.fill_rect(5,58,10,20,BLACK)
            
        if(lcd.right.value() == 0):  
            lcd.draw.fill_rect(45,58,10,20,GREEN)
        else :
            lcd.draw.fill_rect(45,58,10,20,BLACK)
            
        if(lcd.down.value() == 0):  
            lcd.draw.fill_rect(20,83,20,10,GREEN)
        else :
            lcd.draw.fill_rect(20,83,20,10,BLACK)
            
        if(lcd.center.value() == 0):  
            lcd.draw.fill_rect(20,58,20,20,GREEN)
        else :
            lcd.draw.fill_rect(20,58,20,20,BLACK)                      
        lcd.show(lcd.buff)
    time.sleep(1)
    lcd.draw.fill(0xFFFF)






