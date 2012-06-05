/* http://www.kryogenix.org/code/browser/searchhi/ */
/* Modified 20021006 to fix query string parsing and add case insensitivity */
/* Modified 20070316 to stop highlighting inside nosearchhi nodes */
function highlightWord(node,word) {
	// Iterate into this nodes childNodes
	if (node.hasChildNodes) {
		var hi_cn;
		for (hi_cn=0;hi_cn<node.childNodes.length;hi_cn++) {
			highlightWord(node.childNodes[hi_cn],word);
		}
	}
	
	// And do this node itself
	if (node.nodeType == 3) { // text node
		tempNodeVal = node.nodeValue.toLowerCase();
		tempWordVal = word.toLowerCase();
        
        
        
		if (tempNodeVal.indexOf(tempWordVal) != -1){	
			pn = node.parentNode;
			// check if we're inside a "nosearchhi" zone
			checkn = pn;
			while (checkn.nodeType != 9 && 
			checkn.nodeName.toLowerCase() != 'body') { 
			// 9 = top of doc
				if (checkn.className.match(/\bnosearchhi\b/)) { return; }
				checkn = checkn.parentNode;
			}
			if (pn.className != "searchword") {
				// word has not already been highlighted!
				nv = node.nodeValue;
				ni = tempNodeVal.indexOf(tempWordVal);
				// Create a load of replacement nodes
				
				//search only complete word
				b=false;
				
				if (ni !=0){
					if ((tempNodeVal.indexOf(tempWordVal) + word.length) <= nv.length){
						if ((tempNodeVal.charAt(ni-1)==" " || tempNodeVal.charAt(ni-1)=="," ) && 
						(tempNodeVal.charAt(tempNodeVal.indexOf(tempWordVal) + word.length) ==" " ||
						 tempNodeVal.charAt(tempNodeVal.indexOf(tempWordVal) + word.length) ==",")){
							b=true;
						}
					}else {
						if (tempNodeVal.charAt(ni-1)==" " || tempNodeVal.charAt(ni-1)==","){
							b=true;
						}
					}
				}else {
					if ((tempNodeVal.indexOf(tempWordVal) + word.length) <= nv.length){
						if (tempNodeVal.charAt(tempNodeVal.indexOf(tempWordVal) + word.length) ==" " ||
						    tempNodeVal.charAt(tempNodeVal.indexOf(tempWordVal) + word.length) ==","){
							b=true;
						}
					}else {
						b= true;
					}
				}// end search only complete word
				
				if (b == true){ // "if" search only complete word
				before = document.createTextNode(nv.substr(0,ni));
				docWordVal = nv.substr(ni,word.length);
				after = document.createTextNode(nv.substr(ni+word.length));
				hiwordtext = document.createTextNode(docWordVal);
				hiword = document.createElement("span");
				hiword.className = "searchword";
				hiword.appendChild(hiwordtext);
				pn.insertBefore(before,node);
				pn.insertBefore(hiword,node);
				pn.insertBefore(after,node);
				pn.removeChild(node);
				}// end "if" search only complete word
			}
		}
	}
}

function googleSearchHighlight()  {
	if (!document.createElement) return;
	ref = document.referrer;
	if (ref.indexOf('?') == -1) return;
	qs = ref.substr(ref.indexOf('?')+1);
	qsa = qs.split('&');
	for (i=0;i<qsa.length;i++) {
		qsip = qsa[i].split('=');
	        if (qsip.length == 1) continue;
        	if (qsip[0] == 'q' || qsip[0] == 'p') { // q= for Google, p= for Yahoo
			words = unescape(qsip[1].replace(/\+/g,' ')).split(/\s+/);
	                for (w=0;w<words.length;w++) {
	                	if (words[w].length > 0) {
				      highlightWord(document.getElementsByTagName("body")[0],onlyOneSpace(words[w]));
				}
                	}
	        }
	}
}
function testHi(){
	highlightWord(document.getElementsByTagName("body")[0],onlyOneSpace("  ssrn     "));
	highlightWord(document.getElementsByTagName("body")[0],onlyOneSpace("Carl"));
	highlightWord(document.getElementsByTagName("body")[0],onlyOneSpace("Good Capitalism, Bad Capitalism, and"));
	highlightWord(document.getElementsByTagName("body")[0],onlyOneSpace(" Schramm ")); 
	//SSRN Michael Jensen
}

function onlyOneSpace(words){
	words = words.replace(/\s+/gi, ' '); //sacar espacios repetidos dejando solo uno
	words = words.replace(/^\s+|\s+$/gi, ''); //sacar espacios blanco principio y final
	//alert ('/' +words+ '/');
	return words;
}
window.onload = googleSearchHighlight;
//window.onload = testHi; // use this function to test in dev, 