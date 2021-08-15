use strict;
use warnings;

my $S = <>;
chomp $S;
$S =~ s/ //;
$S *= 2;
print "$S\n";
