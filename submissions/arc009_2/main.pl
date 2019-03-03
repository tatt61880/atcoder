use strict;
use warnings;
my $buf = <>;
chomp $buf;
my $tr = $buf;
$tr =~ s/ //g;
<>;
my @A;
while(<>){
	chomp;
	eval("tr/$tr/0123456789/");
	push @A, $_;
}
foreach(sort {$a<=>$b} @A)
{
	eval("tr/0123456789/$tr/");
	print "$_\n";
}
