"""
Problem #7
"""

class Letter:
    def __init__(self, letterfrom, letterto):
        self.letterfrom = letterfrom
        self.letterto = letterto
        self.text = ""
        
    def addLine(self, line):
        self.text += line + "\n"
        
    def get_text(self):
        print("---------------------------------------------------")
        return "Dear {}: \n\n{}\nSincerely,\n\n- {} -".format(self.letterto, self.text, self.letterfrom)
    
        
if __name__=='__main__':
    letterfrom = input("From : ")
    letterto = input("To : ")
    letter = Letter(letterfrom, letterto)
    start = input('Text (Enter key is Exit) : ')
    letter.addLine(start)
    
    while True:
        text = input()
        letter.addLine(text)
        
        if text == '':
            break
        
    print(letter.get_text())
    
    
    