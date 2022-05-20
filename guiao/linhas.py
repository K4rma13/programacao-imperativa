#! /usr/bin/python3

import subprocess

p = subprocess.Popen(['ls', 'code/'], stdout=subprocess.PIPE)
files = p.communicate()[0].split(b'\n')
count = 0
tabsize = [len(name) for name in files]
tabsize = max(tabsize) 
for file in files:
	if file:
		with open(f'code/{file.decode()}',"r") as f:
			data = f.read()
		lines = len([line for line in data.split("\n") if line])
		count+=lines
		print(f'{file.decode():<{tabsize+3}} {lines}')
print(f'{"Total":<{tabsize+3}} {count}')