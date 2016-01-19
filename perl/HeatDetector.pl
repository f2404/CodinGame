use strict;
use warnings;
#use diagnostics;
use 5.20.1;

select(STDOUT); $| = 1; # DO NOT REMOVE

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

my $tokens;

# w: width of the building.
# h: height of the building.
chomp($tokens=<STDIN>);
my ($w, $h) = split(/ /,$tokens);
chomp(my $n = <STDIN>); # maximum number of turns before game over.
chomp($tokens=<STDIN>);
my ($x0, $y0) = split(/ /,$tokens);

my $maxH = $h-1, my $minH = 0, my $maxW = $w-1, my $minW = 0;

# game loop
while (1) {
    chomp(my $bomb_dir = <STDIN>); # the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
    
    # Write an action using print
    # To debug: print STDERR "Debug messages...\n";
    if ($bomb_dir =~ /L/) {
        $maxW = $x0 - 1;
    } elsif ($bomb_dir =~ /R/) {
        $minW = $x0 + 1;
    }
    if ($bomb_dir =~ /U/) {
        $maxH = $y0 - 1;
    } elsif ($bomb_dir =~ /D/) {
        $minH = $y0 + 1;
    }
    $x0 = int(($maxW + $minW)/2);
    $y0 = int(($maxH + $minH)/2);

    print "$x0 $y0\n"; # the location of the next window Batman should jump to.
}
