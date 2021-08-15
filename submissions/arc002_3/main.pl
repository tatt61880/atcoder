$N = <>;
$str = <>;
chomp $str;

$ans = 100000;
@cmd = qw/AA AB AX AY BA BB BX BY XA XB XX XY YA YB YX YY/;
foreach $L (@cmd){
	foreach $R (@cmd){
		$str2 = $str;
		$str2 =~ s/$L/L/g;
		$str2 =~ s/$R/R/g;
		if(length($str2) < $ans){
			$ans = length($str2);
		}
	}
}
printf "$ans\n";
