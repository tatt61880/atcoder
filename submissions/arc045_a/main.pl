use strict;
use warnings;

my $S = <>;
$S =~ s/Left/</g;
$S =~ s/Right/>/g;
$S =~ s/AtCoder/A/g;
print $S;
