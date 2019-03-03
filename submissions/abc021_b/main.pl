use strict;
use warnings;
<>;
my ($a, $b) = split / /, <>;
chomp $a;
chomp $b;
my %A;
$A{$a} = 1;
$A{$b} = 1;
<>;
foreach (split / /, <>){
	chomp;
	if(defined $A{$_}){
		print "NO\n";
		exit 0;
	}else{
		$A{$_} = 1;
	}
}
print "YES\n";
