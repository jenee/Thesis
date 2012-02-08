#!/usr/bin/perl

$unisynSrc = $ARGV[0];
$csvOutput = $ARGV[1];

$slippedPhone = ""; #this will hold the value of any phones that "slipped" from a coda into the next Syllable's onset

open(OUTFILE, ">$csvOutput");
open(INFILE, $unisynSrc);

while(<INFILE>) {
	chomp;
	($ortho,$src_uniqueID,$partOfSpeech,$src_SAMPA,$extOrtho,$freq) = split(":");

#ORTHO	
	print OUTFILE "$ortho\t:\t";

#UNIQUE ID
	if(length($src_uniqueID) == 0) {
		print OUTFILE "0\t\t:\t";
	} elsif ( length($src_uniqueID) == 1 ) {
		print OUTFILE "$src_uniqueID\t\t:\t";
	} elsif ( substr($src_uniqueID,1,1) eq ',' ) {
		($out_IDnum, $out_IDstr) = split(",", $src_uniqueID);
		print OUTFILE "$out_IDnum\t$out_IDstr\t:\t";
	}	elsif (substr($src_uniqueID,0,1) =~ m/\D/) {
		print STDERR "NO NUMBER IN UNIQUEID! $ortho $src_uniqueID";
		print OUTFILE "0\t$src_uniqueID\t:\t";
	}	else {
		print "WTF!  AHHH!!src_uniqueID= $src_uniqueID!\n";
		exit;
	}
#PART OF SPEECH
	print OUTFILE "$partOfSpeech\t:\t";
	
#EXTENDED ORTHOGRAPHIC BREAKDOWN	
	print OUTFILE "$extOrtho\t";
	print OUTFILE ":\t";
	
#UNISYN FREQ COUNT
	print OUTFILE "$freq\t";
	print OUTFILE ":\t";

	
#SAMPA AND SYLLABLE BREAKDOWN	
	$src_SAMPA =~ s/\s$//; #remove trailing whitespace;
	$src_SAMPA =~ s/^\s*//; # remove leading whitespace.
	
	print OUTFILE "$src_SAMPA\t";
	print OUTFILE ":\t";
	print "$src_SAMPA\t";

	@array_src_SAMPA = split (/[\$|%|\"]/, $src_SAMPA);
	$length = @array_src_SAMPA;
	print "size of array is $length\n";
	$curDelimPos = 0; 
	
	for($i = 0; $i < $length; $i++) {
		if($i == 0 ) {
			$curDelimPos = 0; 
		}
		#get the length of this syllable string
		$sublen = length($array_src_SAMPA[$i]);
	
		#since the separator is not in the array, we find it in the orig string
		$sep = substr( $src_SAMPA, $curDelimPos, 1);	

		if( $sep =~ m/(\$|\"|%)/) {
			if($sublen == 0) {
			} else {
#print "\tSAMPA-for-if-if-else:DEBUG!\n\t***curDelimPos = $curDelimPos, sep =|$sep|\n\t*** srcSampaFull =|$src_SAMPA|, curSyll =|$array_src_SAMPA[$i]|, i = $i\n";
				print $sep;
				print "1.\t2.";
				print $array_src_SAMPA[$i];
				print "3.\t4.";
				print OUTFILE $sep;
				print OUTFILE "\t";
				print OUTFILE $array_src_SAMPA[$i];
				print OUTFILE "\t";
				$curDelimPos += 1;
			}
		} elsif ($sublen == 0) {
			#do nothing. NOTHING.	
		} elsif ( $sep =~ m/\S/) {
			if($i == 0) {
				print "\$1>\t2>";
				print $array_src_SAMPA[$i];
				print "3>\t4>";
				print OUTFILE "\$\t";
				print OUTFILE $array_src_SAMPA[$i];
				print OUTFILE "\t";
			} else {
				print "\tSAMPA-for-elsif-else:SOMETHINE WENT WRONG!\n\t***curDelimPos = $curDelimPos, sep =|$sep|\n\t*** srcSampaFull =|$src_SAMPA|, curSyll =|$array_src_SAMPA[$i]|, i = $i\n";
					
			}
		} else {
			print "\tSAMPA-for-else:SOMETHINE WENT WRONG!\n\t***curDelimPos = $curDelimPos, sep =|$sep|\n\t*** srcSampaFull =|$src_SAMPA|, curSyll =|$array_src_SAMPA[$i]|, i = $i\n";
		}

		$curDelimPos += $sublen;
		print "\n";
	}

	print OUTFILE "\n";
}

close(INFILE);
close(OUTFILE);
exit;


#param is a sampaString
sub breakDownSyllableParts {
	#TODO
	print "FINISH WRITING BREAK DOWN SYLLABLE PARTS!\n";
}

sub isAPhone {
	@myArray = @_;
	$ph = $myArray[0];

	if (ph eq '@`') { return 1; }
	if (ph eq '`r') { return 1; }
	if (ph eq '3`') { return 1; }
	if (ph eq 'A`') { return 1; }
	if (ph eq 'aI') { return 1; }
	if (ph eq 'aU') { return 1; }
	if (ph eq 'b') { return 1; }
	if (ph eq 'dZ') { return 1; }
	if (ph eq 'E`') { return 1; }
	if (ph eq 'I`') { return 1; }
	if (ph eq 'jU') { return 1; }
	if (ph eq 'ju') { return 1; }
	if (ph eq 'l=') { return 1; }
	if (ph eq 'm=') { return 1; }
	if (ph eq 'n=') { return 1; }
	if (ph eq 'O`') { return 1; }
	if (ph eq 'OI') { return 1; }
	if (ph eq 'oU') { return 1; }
	if (ph eq 'ou') { return 1; }
	if (ph eq 'tS') { return 1; }
	if (ph eq 'U`') { return 1; }
	if (ph eq '3') { return 1; }
	if (ph eq '@') { return 1; }
	if (ph eq 'A') { return 1; }
	if (ph eq 'a') { return 1; }
	if (ph eq 'd') { return 1; }
	if (ph eq 'D') { return 1; }
	if (ph eq 'E') { return 1; }
	if (ph eq 'I') { return 1; }
	if (ph eq 'j') { return 1; }
	if (ph eq 'l') { return 1; }
	if (ph eq 'm') { return 1; }
	if (ph eq 'n') { return 1; }
	if (ph eq 'N') { return 1; }
	if (ph eq 'O') { return 1; }
	if (ph eq 't') { return 1; }
	if (ph eq 'U') { return 1; }
	if (ph eq '{') { return 1; }
	if (ph eq 'e') { return 1; }
	if (ph eq 'f') { return 1; }
	if (ph eq 'g') { return 1; }
	if (ph eq 'h') { return 1; }
	if (ph eq 'i') { return 1; }
	if (ph eq 'k') { return 1; }
	if (ph eq 'p') { return 1; }
	if (ph eq 'r') { return 1; }
	if (ph eq 's') { return 1; }
	if (ph eq 'S') { return 1; }
	if (ph eq 'T') { return 1; }
	if (ph eq 'u') { return 1; }
	if (ph eq 'v') { return 1; }
	if (ph eq 'V') { return 1; }
	if (ph eq 'w') { return 1; }
	if (ph eq 'W') { return 1; }
	if (ph eq 'x') { return 1; }
	if (ph eq 'z') { return 1; }
	if (ph eq 'Z') { return 1; }

	
	return 0;
}

sub isSlippery {
	#TODO
	@myArray = @_;
	$ph = $myArray[0];
	print "\t\t ph ='$ph', FINISH WRITING ISSLIPPERY!\n";
	if (ph eq '@`') { return 0; }
	if (ph eq '`r') { return 0; }
	if (ph eq '3`') { return 0; }
	if (ph eq 'A`') { return 0; }
	if (ph eq 'aI') { return 0; }
	if (ph eq 'aU') { return 0; }
	if (ph eq 'b') { return 1; }
	if (ph eq 'dZ') { return 1; }
	if (ph eq 'E`') { return 0; }
	if (ph eq 'I`') { return 0; }
	if (ph eq 'jU') { return 0; }
	if (ph eq 'ju') { return 0; }
	if (ph eq 'l=') { return 0; }
	if (ph eq 'm=') { return 0; }
	if (ph eq 'n=') { return 0; }
	if (ph eq 'O`') { return 0; }
	if (ph eq 'OI') { return 0; }
	if (ph eq 'oU') { return 0; }
	if (ph eq 'ou') { return 0; }
	if (ph eq 'tS') { return 1; }
	if (ph eq 'U`') { return 0; }
	if (ph eq '3') { return 0; }
	if (ph eq '@') { return 0; }
	if (ph eq 'A') { return 0; }
	if (ph eq 'a') { return 0; }
	if (ph eq 'd') { return 1; }
	if (ph eq 'D') { return 0; }
	if (ph eq 'E') { return 0; }
	if (ph eq 'I') { return 0; }
	if (ph eq 'j') { return 0; }
	if (ph eq 'l') { return 0; }
	if (ph eq 'm') { return 0; }
	if (ph eq 'n') { return 0; }
	if (ph eq 'N') { return 0; }
	if (ph eq 'O') { return 0; }
	if (ph eq 't') { return 1; }
	if (ph eq 'U') { return 0; }
	if (ph eq '{') { return 0; }
	if (ph eq 'e') { return 0; }
	if (ph eq 'f') { return 1; }
	if (ph eq 'g') { return 1; }
	if (ph eq 'h') { return 1; }
	if (ph eq 'i') { return 0; }
	if (ph eq 'k') { return 1; }
	if (ph eq 'p') { return 1; }
	if (ph eq 'r') { return 0; }
	if (ph eq 's') { return 1; }
	if (ph eq 'S') { return 1; }
	if (ph eq 'T') { return 1; }
	if (ph eq 'u') { return 0; }
	if (ph eq 'v') { return 0; }
	if (ph eq 'V') { return 0; }
	if (ph eq 'w') { return 0; }
	if (ph eq 'W') { return 0; }
	if (ph eq 'x') { return 1; }
	if (ph eq 'z') { return 0; }
	if (ph eq 'Z') { return 0; }
	
	return false;
}
