use strict;
use warnings;
my $c = <>;
chomp $c;
my $str = <>;
$str =~ s/$c//g;
print $str;
