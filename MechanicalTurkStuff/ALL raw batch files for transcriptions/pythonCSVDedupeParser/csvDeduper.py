import sys
import csv
import time

#convert date format strings to python dates
# http://docs.python.org/library/time.html#time.strptime
def toPyDate(dateStr):
   #takes dates of this format: 'Fri Jun 08 09:21:50 PDT 2012'
   # format % explanations at: http://www.geezer.org/sw/mvform/doc/strftime.txt
   print "dateStr: " + dateStr
   timeStruct = time.strptime( dateStr, "%a %b %d %H:%M:%S %Z %Y" )
   
   ''' this version looks for the current time zone
   timeStruct = time.strptime( dateStr, "%a %b %d %I:%M:%S %Z %Y" )
   '''
   epochTime = time.mktime(timeStruct) - time.timezone

   print epochTime
   return epochTime




if len(sys.argv) < 2:
   sys.stderr.write('Usage: sys.argv[0] ')
   sys.exit(1)

filename = sys.argv[1]

print filename
# got this from here: http://stackoverflow.com/questions/1532810/how-to-read-lines-from-a-file-into-a-multidimensional-array-or-an-array-of-list
array = list( csv.reader( open( filename ) ) );
'''
data = csv.reader(open(filename))
# Read the column names from the first line of the file
fields = data.next()

for s in fields  :
   print s
'''
#print array[0]
#print array[1]

workerIdIndex = 15 #WorkerID, column P
taskIdIndex = 0 #hitID, column A
submitDateIndex = 18 #submitTime column S

HIT = 1
workerArg = array[HIT][workerIdIndex]
taskArg = array[HIT][taskIdIndex]
submitDate = array[HIT][submitDateIndex]

print "worker: " +workerArg
print "task : " +taskArg

epochTest = toPyDate(submitDate)
print epochTest
print


print


