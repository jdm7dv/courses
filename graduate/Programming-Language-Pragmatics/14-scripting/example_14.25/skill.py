#! /usr/bin/python
# Example 14.25 (Figure 14.6)

# This assumes that your /usr/bin/python is Python 3.
# To use, start a bunch of process you don't care about (loop.c in this
# directory makes a good candidate) then run: ./skill.py <pattern>

import os, re, subprocess, sys, time
if len(sys.argv) != 2:
    sys.stderr.write('usage: ' + sys.argv[0] + ' pattern\n')
    sys.exit(1)
ps = subprocess.Popen(['/bin/ps', '-w', '-w', '-x',
                       '-o', 'pid,command'], stdout=subprocess.PIPE)
toss = ps.stdout.readline()         # discard header line
for line in ps.stdout:
    line = line.decode().rstrip()
    proc = int(re.search('\S+', line).group())
    if re.search(sys.argv[1], line) and proc != os.getpid():
        print(line + '? ', flush=True, end='')
        answer = sys.stdin.readline()
        while not re.search('^[yn]', answer, re.I):
            print('? ', flush=True, end='')
            answer = sys.stdin.readline()
        if re.search('^y', answer, re.I):
            os.kill(proc, 9)
            time.sleep(1)
            try:                    # expect exception if process
                os.kill(proc, 0)    # no longer exists
                sys.stderr.write('unsuccessful; sorry\n');
                sys.exit(1)
            except: pass            # do nothing on expected exception
