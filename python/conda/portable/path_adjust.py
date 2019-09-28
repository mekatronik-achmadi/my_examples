import sys

filetxt = sys.argv[1]
oldtxt = 'C:/Users/stm32/Miniconda3'
newtxt = sys.argv[2]

newtxt = newtxt.replace('\\','/')

s = open(filetxt).read()
s = s.replace(oldtxt,newtxt)
if filetxt == 'etc\profile.d\conda.sh':
    f = open(filetxt,'w',newline='\n')
else:
    f = open(filetxt,'w')
f.write(s)
f.close()
