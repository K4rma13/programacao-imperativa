#! /usr/bin/python3

import subprocess

p = subprocess.Popen(['ls', 'code/'], stdout=subprocess.PIPE)
files = p.communicate()[0].split(b'\n')

cc = 0
loc = 0

for file in files:
	p = subprocess.Popen(['pmccabe', f'code/{file.decode()}'], stdout=subprocess.PIPE)
	out = p.communicate()[0].split(b'\n')
	for x in out:
		try:
			x = x.decode().split("\t")
			if(int(x[0])>cc):
				cc = int(x[0])
				functioncc = x[5]

			if(int(x[4])>loc):
				loc = int(x[4])
				functionloc = x[5]

		except:
			pass


if cc >= 10:
	print(f'[\x1b[1;5;31m!\x1b[0m] Max CC: \x1b[1;31m{cc}\x1b[0m na função: \x1b[1;3m{functioncc}\x1b[0m')
else:
	print(f'[\x1b[1;32m*\x1b[0m] Max CC: \x1b[1;38;2;0;255;150m{cc}\x1b[0m na função: \x1b[1;3m{functioncc}\x1b[0m')

if loc >= 50:
	print(f'[\x1b[1;5;31m!\x1b[0m] Max LoC: \x1b[1;31m{loc}\x1b[0m na função: \x1b[1;3m{functionloc}\x1b[0m')
else:
	print(f'[\x1b[1;32m*\x1b[0m] Max LoC: \x1b[1;38;2;0;255;150m{loc}\x1b[0m na função: \x1b[1;3m{functionloc}\x1b[0m')
if loc < 50 and cc < 10:
	print("[\x1b[1;38;2;0;255;0mO\x1b[0m] Legibilidade maxima")