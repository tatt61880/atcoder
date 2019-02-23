use strict;
use warnings;

$_ = <>;
chomp;
if(m/^.*keyence$/){
  print "YES\n";
  exit(0);
}
if(m/^k.*eyence$/){
  print "YES\n";
  exit(0);
}
if(m/^ke.*yence$/){
  print "YES\n";
  exit(0);
}
if(m/^key.*ence$/){
  print "YES\n";
  exit(0);
}
if(m/^keye.*nce$/){
  print "YES\n";
  exit(0);
}
if(m/^keyen.*ce$/){
  print "YES\n";
  exit(0);
}
if(m/^keyenc.*e$/){
  print "Y
ES\n";
  exit(0);
}
if(m/^keyence.*$/){
  print "YES\n";
  exit(0);
}
print "NO\n";
exit(0);
