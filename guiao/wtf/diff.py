#! /usr/bin/python3

import subprocess

p = subprocess.Popen(['ls','code/'],stdout=subprocess.PIPE)

files = p.communicate()[0].decode().split("\n")

for file in files:
	p = subprocess.Popen(['diff',f'code/{file}',f'../code/{file}'],stdout=subprocess.PIPE)
	diff = p.communicate()[0].decode()
	if len(diff) > 0:
		print(f'\x1b[1;31m {file} diff :\n\x1b[0m{diff}')
	else:
		print(f'\x1b[1;38;2;0;255;0m {file}\x1b[0m')
	print("\n\n\n\n")
