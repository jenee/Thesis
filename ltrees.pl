#!/usr/bin/perl -w
#use strict;

# use "chmod u+x" to make this executable!
#http://www.comp.leeds.ac.uk/Perl/basic.html

print "Enter tree seed: ";
chomp( $treeString = <STDIN> );
print "Enter number of iterations: ";
chomp( $numIterations = <STDIN> );

print "Enter branch source string 1: ";
chomp( $source1 = <STDIN> );
print " branch string 1 branches to: ";
chomp( $replace1 = <STDIN> );

print "Enter branch source string 2: ";
chomp( $source2 = <STDIN> );
print " branch string 2 branches to: ";
chomp( $replace2 = <STDIN> );

print $treeString;
print $numIterations;
print $source1;
print $replace1;
print $source2;
print $replace2;

$i = 0;

for( $i = 0; $i < $numIterations; $i++) {
	$treeString =~ s/$source1/$replace1/g;
	$treeString =~ s/$source2/$replace2/g;
	print "Iteration $i:  $treeString \n";
}



