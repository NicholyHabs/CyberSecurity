from random import randint
import crypt

#--- Main
f = open('pw-fake-unix')
 
out = open('pw-fake-unix-bare', 'w')
mangled = open('pw-fake-unix-mangled', 'w')
threenums = open('pw-fake-unix-threenumbers', 'w')
l33t = open('pw-fake-unix-l33t', 'w')

for line in f:
     
     line = line.strip();
     fields = line.split(':')
     
     if 'bf' in fields[0]:
        out.write(fields[0] + ':' + fields[1] + '\n')

     
     if 'des' not in fields[0]:
         continue
     
     out.write(fields[0] + ':' + fields[1] + '\n')
    
     old_pw = fields[-3]
     
     new_pw = old_pw + str(randint(0,9))
     hash = crypt.crypt(new_pw, '$1$')
     mangled.write(fields[0] + ':' + hash + '\n')
     
     new_pw = old_pw + str(randint(0,9)) * 3
     hash = crypt.crypt(new_pw, '$1$')
     threenums.write(fields[0] + ':' + hash + '\n')
     
     # l33t mangling
     new_pw = old_pw.replace('a', '@')
     new_pw = new_pw.replace('s', '5')
     new_pw = new_pw.replace('e', '3')
     new_pw = new_pw.replace('l', '1')
     new_pw = new_pw.replace('o', '0')
     hash = crypt.crypt(new_pw, '$1$')

     l33t.write(fields[0] + ':' + hash + '\n')

     