use strict;
use warnings;
my $buf = <>;
$buf =~ s/[a-zA-Z]//g;
print $buf;
