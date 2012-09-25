import sys
import csv
import time
from collections import defaultdict

workerIdIndex = 15 		#WorkerID, column P
urlIndex = 27 			#input.audioURL, column AB
taskIdIndex = 0 		#hitID, column A
submitDateIndex = 18 	#submitTime column S
statusIndex = 16		#AssignmentStatus, column Q
answerIndex = 28 		#Answer.answer, column AC
countryIndex = 29 		#Answer.country, column AD
markDuplicateIndex = 31  # NEW COLUMN, column AG, 

def debugPrint(item):
   dummyVar = "" 
   #print >> sys.stderr, str(item)

def buildUniqueURLlist():
	uniqueURLlist = []
	uniqueURLlist.append(" http://ani.pe/jenee/A.20.163.wav")
	uniqueURLlist.append(" http://ani.pe/jenee/A.19.49.wav")
	uniqueURLlist.append(" http://ani.pe/jenee/A.19.283.wav")
	uniqueURLlist.append(" http://ani.pe/jenee/A.19.139.wav")
	uniqueURLlist.append(" http://ani.pe/jenee/A.19.137.wav")
	uniqueURLlist.append(" http://ani.pe/jenee/A.19.133.wav")
	uniqueURLlist.append(" http://ani.pe/jenee/A.19.116.wav")
	uniqueURLlist.append(" http://ani.pe/jenee/A.18.68.wav")
	uniqueURLlist.append(" http://ani.pe/jenee/A.18.65.wav")
	uniqueURLlist.append(" http://ani.pe/jenee/A.18.284.mp3")
	uniqueURLlist.append(" http://ani.pe/jenee/A.18.140.wav")
	uniqueURLlist.append(" http://ani.pe/jenee/A.18.140.mp3")
	uniqueURLlist.append(" http://ani.pe/jenee/A.18.125.wav")
	uniqueURLlist.append(" http://ani.pe/jenee/A.17.69.wav")
	uniqueURLlist.append(" http://ani.pe/jenee/A.17.51.wav")
	uniqueURLlist.append(" http://ani.pe/jenee/A.17.141.wav")
	uniqueURLlist.append(" http://ani.pe/jenee/A.17.135.wav")
	return uniqueURLlist

def allTasksWithURL(origHitList, urlString):
	global urlIndex
	urlList = []
	for HIT in origHitList:
		if HIT[urlIndex] == urlString:
			urlList.append( HIT )
	return urlList

def getEarliestHit( workerHitList ):
	global submitDateIndex
	#import pdb;pdb.set_trace()
	#print >> sys.stderr, "*****************************************************"	
	#print >> sys.stderr, "*****************************************************"	
	#print >> sys.stderr,  workerHitList	
	#sortedHitList = sorted( workerHitList, key=lambda task: task[ submitDateIndex ] )
	#return sortedHitList[0]
	firstHit=workerHitList[0]
	earliestDate = firstHit[submitDateIndex]#time.time() #Today
	
	for HIT in workerHitList:
		if int(earliestDate) > int(HIT[submitDateIndex]):
			firstHit = HIT
			earliestDate = firstHit[submitDateIndex] 
		
	return firstHit

def printCSVRow(rowList):
   rowStr = ""
   for item in rowList:
      rowStr +=  item 
      rowStr += ", "
   print rowStr


def markDuplicateHITs(workerHitList):
   global markDuplicateIndex
   for HIT in workerHitList:
      HIT[markDuplicateIndex] = "DUPLICATE"
   return workerHitList
   #return getEarliestHit(PP workerHitList )

# BEGIN MAIN PROGRAM

if len(sys.argv) < 2:
   sys.stderr.write('Usage: sys.argv[0] ')
   sys.exit(1)

filename = sys.argv[1]

# got this from here: http://stackoverflow.com/questions/1532810/how-to-read-lines-from-a-file-into-a-multidimensional-array-or-an-array-of-list
origHitList = list( csv.reader( open( filename, "rU") ) )
#debugPrint(origHitList[0])
dedupedTaskList = []

uniqueURLlist = buildUniqueURLlist()
#debugPrint(uniqueURLlist)



for urlString in uniqueURLlist:

	urlTaskList = allTasksWithURL(origHitList, urlString)
	#debugPrint(urlTaskList)
   #set default hash entry to a blank list 
	workerCountDict = defaultdict(list)

	for HIT in urlTaskList:
		workerCountDict[ HIT[workerIdIndex] ].append(HIT) 

	#print >> sys.stderr,  workerCountDict[" A3HBWVAVKRASDF"]	
	#print >> sys.stderr,  getEarliestHit( workerCountDict[" A3HBWVAVKRASDF"])	

	for curWorkerID, workerHITList in workerCountDict.iteritems():
		####APPROACH 1: Mark duplicates for manual review
		if len(workerHITList) > 1:
			#mark duplicates
			markDuplicateHITs( workerHITList )
		#add all HITs to the new csv
		dedupedTaskList.extend( workerHITList)

		#### APPROACH 2: auto-delete newer duplicates
		#The line below appends only the earliest Hit to the new csv 
		#dedupedTaskList.append( getEarliestHit (workerHITList) )

#print Header
printCSVRow(origHitList[0])

for HIT in dedupedTaskList:
	if( HIT[statusIndex] != "Rejected" and
		HIT[answerIndex].strip() != "" and
		HIT[countryIndex].strip() != "" ): 
		dummyVarTwo = ""
		printCSVRow(HIT)
