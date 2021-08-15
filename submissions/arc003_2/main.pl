use strict;
use warnings;

my $n = <>;
chomp $n;
my @a;
for(1..$n){
	my $str = <>;
	chomp $str;
	$str = reverse $str;
	push @a, $str;
}

@a = sort @a;
foreach(@a) {
	my $str = reverse $_;
	print "$str\n";
}
