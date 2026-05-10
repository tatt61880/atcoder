use strict;
use warnings;

my $buf = <>;
chomp $buf;
if("aiueo" =~ m/$buf/){
	print "vowel\n";
}else{
	print "consonant\n";
}
