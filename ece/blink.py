import BlynkLib
import RPi.GPIO as GPIO
from BlynkTimer import BlynkTimer

#BLYNK_AUTH_TOKEN = 'yourapi'

device1 = 26
GPIO.setmode(GPIO.BCM)
GPIO.setup(device1, GPIO.OUT)
GPIO.output(device1, GPIO.LOW)

blynk = BlynkLib.Blynk('7abCByo-hXaYkjx2H8nvWssXCQVW3bXA')


@blynk.on("V0")
def v0_write_handler(value):
    if int(value[0]) is not 0:
        GPIO.output(device1, GPIO.HIGH)
        print('Device1 HIGH')
    else:
        GPIO.output(device1, GPIO.LOW)
        print('Device1 LOW')


@blynk.on("connected")
def blynk_connected():
    print("Alert: Hi! Raspberry Pi Connected to New Blynk2.0")

while True:
    blynk.run()