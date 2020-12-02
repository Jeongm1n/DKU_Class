"""
Problem #5
"""

class Message:
    def __init__(self, sender, recipient):
        self.sender = sender
        self.recipient = recipient
        self.body = ""

    def append(self, line):
         self.body += line + "\n"
    
    def __str__(self):
         messageString = "\n\nFrom : {}\nTo: {}\n{}\n".format(self.sender, self.recipient, self.body)
         return messageString

sender = input('Who is sending this message? ')
recipient = input('Who is receiving this message? ')
body = input('What would you like to send? ')
email = Message(sender, recipient)
email.append(body)

print(email.__str__())


