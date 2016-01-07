# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.
# ---
# Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.

# lightX: the X position of the light of power
# lightY: the Y position of the light of power
# initialTX: Thor's starting X position
# initialTY: Thor's starting Y position
read lightX lightY initialTX initialTY

# game loop
while true; do
    # remainingTurns: The remaining amount of turns Thor can move. Do not remove this line.
    read remainingTurns

    # Write an action using echo
    # To debug: echo "Debug messages..." >&2
    if [[ $lightX < $initialTX && $lightY == $initialTY ]]; then
        echo "W"
        let "initialTX++"
    elif [[ $lightX > $initialTX && $lightY == $initialTY ]]; then
        echo "E"
        let "initialTX--"
    elif [ $lightX == $initialTX ] && [ $lightY < $initialTY ]; then
        echo "N"
        let "initialTY--"
    elif [ $lightX == $initialTX ] && [ $lightY > $initialTY ]; then
        echo "S"
        let "initialTY++"
    elif [ $lightX < $initialTX ] && [ $lightY < $initialTY ]; then
        echo "NW"
        let "initialTX++"
        let "initialTY--"
    elif [ $lightX > $initialTX ] && [ $lightY < $initialTY ]; then
        echo "NE"
        let "initialTX--"
        let "initialTY--"
    elif [ $lightX < $initialTX ] && [ $lightY > $initialTY ]; then
        echo "SW"
        let "initialTX++"
        let "initialTY++"
    elif [ $lightX > $initialTX ] && [ $lightY > $initialTY ]; then
        echo "SE"
        let "initialTX--"
        let "initialTY++"
    fi

    #echo "SE" # A single line providing the move to be made: N NE E SE S SW W or NW
done
