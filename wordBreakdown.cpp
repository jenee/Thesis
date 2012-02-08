
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <assert.h>

#include <sqlite3.h>

using namespace std;

typedef string phone ;


vector<string> findAllPermutations(string orthoPhrase);
void DDDDDDDDDDDEBUG(string s);
vector<string> strTokOnWhitespace(string phrase);
vector<string> interpretPhrase( vector<phone> sampaPhrase );
vector<phone> getSampa( string orthoWord );
string queryDBforSAMPA( string orthoWord );
vector<phone> parseSAMPAintoPhonemes( string sampaString );
vector<string> dictLookup( string sampaStr ); 
vector<string> splitSampaIntoLetters( string phrase );


int main() {
   cout << "HTTP/1.1 200 OK\n";
   cout << "Cache-Control: private\n";
   cout << "Content-Type: text/plain\n";
   cout << "Server: bash/2.0\n";
   cout << "Connection: Close\n";

   string output = "";
   vector<string> sampaPhrase = splitSampaIntoLetters("{bdZEkt");
   for (int i=0; i < sampaPhrase.size(); i++) {
      output.append(sampaPhrase.at(i) + " ");
   }
   output.append("\n");

   cout << "Content-Length: " << output.size() << "\n";
   cout << "\n";

   cout << output;
   return 0;
}


vector<string> findAllPermutations(string orthoPhrase) {
	vector<string> permutedPhrases;	
	
	vector<string> orthoWords = strTokOnWhitespace( orthoPhrase );
	vector<phone> sampaPhrase;

   for (int i = 0; i < orthoWords.size(); i++) {
      string orthoWord = orthoWords[i];
		vector<phone> sampaWord = getSampa( orthoWord );
		sampaPhrase.insert( sampaPhrase.end(), sampaWord.begin(), sampaWord.end() );
	}	

	vector<string> misheard = interpretPhrase( sampaPhrase );
	
	for (int i = 0; i < misheard.size(); i++) {
      string s = misheard[i];
      DDDDDDDDDDDEBUG(s);
	}	


	return misheard;

}
	
void DDDDDDDDDDDEBUG(string s) {
	cout << s << endl;	
}

//http://www.daniweb.com/software-development/cpp/threads/27905
vector<string> strTokOnWhitespace(string phrase) {
   string temp;
   stringstream ss(phrase);
   vector<string> tokens;
   
   //while (phrase >> temp) {
   while ( getline(ss, temp, ' ') ) {
      tokens.push_back(temp);
   }
   return tokens;
}

vector<phone> getSampa( string orthoWord ) {
   string sampaString = queryDBforSAMPA( orthoWord );
   vector<phone> sampaWord = parseSAMPAintoPhonemes( sampaString );
   return sampaWord;
}

vector<string> dictLookup( string sampaStr ) {
   vector<string> orthoMatches;
   vector<phone> sampaSylls = parseSAMPAintoPhonemes(sampaString);
   assert(0); // PUT SQL QUERY HERE
   
   return orthoMatches;
}

string queryDBforSAMPA( string orthoWord ) {
   assert(0); // PUT SQL QUERY HERE
   return "";
}

vector<phone> parseSAMPAintoPhonemes( string sampaString ) {
   vector<phone> sampaSylls = splitSampaIntoLetters(sampaString);
   return sampaSylls;
}

vector<string> interpretPhrase( vector<phone> sampaPhrase ) {
	vector<string> misheardOrthoPhrases;
   
	if( sampaPhrase.size() == 0 ) {
		misheardOrthoPhrases.push_back("");
		return misheardOrthoPhrases;
	}
	
   string sampaStr = "";
	vector <phone> usedPhones;
   
   for (int i = 0; i < sampaPhrase.size(); i++) {
      phone p = sampaPhrase[i];
		sampaStr += p;
		usedPhones.push_back(p);
		vector<string> orthoMatches = dictLookup( sampaStr );
		if ( orthoMatches.size() == 0 ) {
			misheardOrthoPhrases.push_back("DEADBEEF");
			return misheardOrthoPhrases;
		}

      for (int i = 0; i < orthoMatches.size(); i++) {
         string orthoWord = orthoMatches[i];
			vector<phone> sampaPhraseTail( sampaPhrase.begin(), sampaPhrase.begin() + i );
			vector<string> orthoLeaves = interpretPhrase ( sampaPhraseTail );
			if ( orthoLeaves.size() == 0 ) {
				misheardOrthoPhrases.push_back( orthoWord.append( "DEADBEEF" ) );
				return misheardOrthoPhrases;
			} else {
                        
            for (int i = 0; i < orthoLeaves.size(); i++) {
               string orthoLeaf = orthoLeaves[i];
					misheardOrthoPhrases.push_back( orthoWord + orthoLeaf );
				}
            
			}
		}
	}
	return misheardOrthoPhrases;
}

vector<string> splitSampaIntoLetters(string phrase) {
   vector<string> tokens;
   string sampaCharacter;
   
   for (size_t i=0; i < phrase.length(); i++) {
      // We're not at the last character
      if (i+1 < phrase.length()) {
         // Get a two-character set.
         sampaCharacter = phrase.substr(i, 2);
	 if (sampaCharacter == "@`"
          || sampaCharacter == "`r"
          || sampaCharacter == "3`"
          || sampaCharacter == "A`"
          || sampaCharacter == "aI"
          || sampaCharacter == "aU"
          || sampaCharacter == "dZ"
          || sampaCharacter == "E`"
          || sampaCharacter == "I`"
          || sampaCharacter == "jU"
          || sampaCharacter == "ju"
          || sampaCharacter == "l="
          || sampaCharacter == "m="
          || sampaCharacter == "n="
          || sampaCharacter == "O`"
          || sampaCharacter == "OI"
          || sampaCharacter == "oU"
          || sampaCharacter == "ou"
          || sampaCharacter == "tS"
          || sampaCharacter == "U`") {
	    // We're good.  Skip the second character for purpose of the loop.
	    i++;
         } else {
            sampaCharacter = phrase.at(i);
         }
      } else {
         sampaCharacter = phrase.at(i);
      }
      tokens.push_back(sampaCharacter);
   }
   return tokens;
}


/*
vector<string>  getPhrasePhonemes(string phrase) {
	vector<string> phrasePhones;;
	vector<string> words = split(/\s/); //split on any whitespace character

	for ( string s : words) {
		vector<string> sampleSylls = getSAMPAForPhrase(s);
		//append to end
		phrasePhones.insert( phrasePhones.end(), 
			sampaSylls.begin(), sampaSylls.end() );			
	}
	return phrasePhones;
}
string[] getSAMPAForPhrase(string orthoWord) {
	//lookup in dictionary
	split sampa phrase
	$src_SAMPA =~ s/\s$//; #remove trailing whitespace;
	$src_SAMPA =~ s#^\s*##; # remove leading whitespace.
	
	print OUTFILE "$src_SAMPA\t";
	print OUTFILE ":\t";
	print "$src_SAMPA\t";

	@array_src_SAMPA = split (/[\$|%|\"]/, $src_SAMPA);
	
	//return split sampa phrase
}


vector<PhoneWithIndex> embedPhoneOrder(vector<string> phones) {
	vector<PhoneWithIndex> toRet;
	int i = 0;
	for( string s : phones) {
		toRet.add( LocPhone(i++, s) );  
	}
	return toRet;
}
*/

