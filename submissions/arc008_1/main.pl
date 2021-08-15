use strict;
use warnings;

my $num = <>;
if($num % 10 >= 7){
	print (100 + 100 * int($num / 10));
}else{
	print (($num % 10) * 15 + 100 * int($num / 10));
}
print "\n";
