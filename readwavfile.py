import wave
import contextlib
import csv
fname = ''
total = 0
cnt = 0
with open('part4A.csv') as csvfile:
    readCSV = csv.reader(csvfile, delimiter=',')
    for row in readCSV:
        fname = row[0]
        
        with contextlib.closing(wave.open(fname,'r')) as f:
            frames = f.getnframes()
            rate = f.getframerate()
            duration = frames / float(rate)
            total = total + duration
            cnt += 1

print(total,' ',cnt)