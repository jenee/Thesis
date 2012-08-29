import sys
import csv

if len(sys.argv) < 2:
   sys.stderr.write('Usage: sys.argv[0] ')
   sys.exit(1)

filename = sys.argv[1]

print filename

array = list( csv.reader( open( filename ) ) );
'''
data = csv.reader(open(filename))
# Read the column names from the first line of the file
fields = data.next()

for s in fields  :
   print s
'''
print array[0]
print array[1]


print


