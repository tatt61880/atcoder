use strict;
use warnings;
my $str = <>;
$str =~ s/\bnot\b/N/g;
while($str =~ s/N N ([^N])/$1/g){};
$str =~ s/N/not/g;
print $str;
