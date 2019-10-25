import wave
import contextlib
import csv
from pydub import AudioSegment

fname = ''
cnt = 0
with open('part3.csv') as csvfile:
    readCSV = csv.reader(csvfile, delimiter=',')
    for row in readCSV:
        fname = row[0]
        
        with contextlib.closing(wave.open(fname,'r')) as f:
            sound = AudioSegment.from_wav(fname)
            sound = sound.set_channels(1)
            sound.export(fname, format="wav")
            cnt += 1

print(cnt)