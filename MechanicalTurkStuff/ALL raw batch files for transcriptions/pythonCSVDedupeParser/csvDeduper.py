import sys
import csv

if len(sys.argv) < 2:
   sys.stderr.write('Usage: sys.argv[0] ')
   sys.exit(1)

filename = sys.argv[1]

# got this from here: http://stackoverflow.com/questions/1532810/how-to-read-lines-from-a-file-into-a-multidimensional-array-or-an-array-of-list
origHitList = list( csv.reader( open( filename, "rU") ) )

dedupedTaskList = []

uniqueURLlist = buildUniqueURLlist()

workerIdIndex = 15 		#WorkerID, column P
urlIndex = 27 			#input.audioURL, column AB
taskIdIndex = 0 		#hitID, column A
submitDateIndex = 18 	#submitTime column S
statusIndex = 16		#AssignmentStatus, column Q
answerIndex = 28 		#Answer.answer, column AC
countryIndex = 29 		#Answer.country, column AD


for urlString in uniqueURLlist

	urlTaskList = allTasksWithURL(origHitList, urlString)
	
	#set default hash entry to a blank list 
	workerCountDict = defaultdict(list)

	for HIT in urlTaskList
		workerCountDict[ HIT[workerIDIndex] ].append(HIT) 

	for workerHITList in workerCountDict
		dedupedTaskList.add( getEarliestHit (workerHITList) )

for HIT in dedupedTaskList:
	if HIT[statusIndex] != "Rejected" and
		HIT[answerIndex].strip() != "" and
		HIT[countryIndex].strip() != "" : 
		print HIT

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
	urlList = []
	for HIT in origHitList:
		if HIT[urlIndex] == urlString:
			urlList.append( HIT )
	return urlList
			

def getEarliestHit( workerHitList ):
	sortedHitList = sorted( workerHitList, key=lamba HIT: HIT[ submitDateIndex ] ) 
	return sortedHitList[0]
		

