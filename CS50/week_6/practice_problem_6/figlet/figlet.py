from sys import argv, exit
import random
from pyfiglet import Figlet

randomfont = False

if(len(argv) == 1):
    randomfont = True
elif(len(argv) == 3):
    randomfont = False
else:
    exit("Invalid usage")

figlet = Figlet()

fontlist = figlet.getFonts()

if randomfont == False:
    if(argv[1] not in ["-f", "--font"]):
        exit("Invalid usage")
    try:
        font = figlet.setFont(font = argv[2])
    except:
        exit("Invalid usage")
else:
    font = random.choice(fontlist)

txt = input("Input: ")

print(figlet.renderText(txt))









