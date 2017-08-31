# Reviiyot
a C++ program that plays Reviiyot.
* 2 or more players, each plays according to a given strategy.

* an individual card consists of a VALUE and a SHAPE.The values are: 2,3,4,...,N, Jack, Queen, Kingand Ace. The shapes
are Spade(S), Diamond(D),Club(C)and Heart(H).
Each value has all 4 shapes.

## Game and program rules
1.Each player has a unique name and a position around the table.

2.Each player gets 7 cards from the shuffled deck of cards, starting with Player1. All 7 cards 
are distributed at once before moving to the next player. 

3.A player that received 4 cards of a single valued is cards the set from his hand before the first play of the first player.

4.Player1 plays first followed by Player2,Player3, ...

5.At his/her turn, theplayer, according to his/her strategy,asks another player for a card of a specific value.
The asking player can ask only for values that he/she holds at least one card of that same value.If the asked
player holds K(>0)cards of that value he/she has to give all of his/hercardsof that value to the asking
player and draw K(>0)new cards from the top of the deck.
If the asked player doesn't have any card of that value the asking player picks up one card from the top of the deck.

6.A player draws card(s) from the deck ONLY if his/her hand is not empty,regardless if he/she is the asking or the asked player.

7.Any player that has all 4 cards of a single valued is cards the set from his hand.

8.The turn moves on to the next player after each turn regardless ofthe outcome of the current player.

9.If the deck of cards is empty the game continues without drawing new cards.

10.Each turn is played to its completion, asking player and asked player get to Hand over cards, draw cards, discard sets.

11.The first player(s)that getsrid of his/her cardswins and the game ends.
Be aware that two players can win the game simultaneously.

## Player Strategies
* PlayerType1:Requests the value he has the most from the player with most cards at hand.
In case he has two or more values with the same highest amount,
choose the higher value.In case two players have the most amount of cards, choose the one with the higher position.

* PlayerType2: Requests the value he has the least from the player with most 
cards at hand.In case he has two or more values with the lowest amount,
choose the lower value.In case two players have the most amount of cards, choose the one with higher position. 

* PlayerType3: Start from the first player(except for oneself), 
move to the next one at each turn in a cyclic order.
The player requests for the highest value he/she has at hand.

* PlayerType4: Start from the first player (except for oneself), 
move to the next one at each turn in a cyclic order.
The player requests for the lowest value he/she has at hand.

## Configuration File
The configuration file contains the arguments each in a single line, by the following order:

Parameter1: Verbal:0 or 1

Parameter2: N–Highest numeric value.N=1 indicates only figures no numeric values,Ace is not numeric
in this game.

Parameter3: Initial deck ordered from top to bottom.

Parameter4 to the end: List of players and strategies.
The order of the players in the game is determined by the order they are listed in the file.

Example:
```
1
3
2H KD QS QC AS KC QH 2S 2D AH AD QD AC KH 2C KS JC JS JD JH 3C 3S 3D 3H 
Ami 1
Tami 3
```

## Output
Trace example:
```
Turn 1
Deck: 2C KS JC JS JD JH 3C 3S 3D 3H
Ami: 2H QC QH QS KC KD AS
Tami: 2D 2S QD KH AC AD AH
Ami asked Tami for the value Q

Turn 2
Deck: KS JC JS JD JH 3C 3S 3D 3H
Ami: 2H KC KD AS
Tami: 2C 2D
2S KH AC AD AH
Tami asked Ami for the value A

Turn 3
Deck: JC JS JD JH 3C 3S 3D 3H
Ami: 2H KC KD KS
Tami: 2C 2D 2S KH
Ami asked Tami for the value K
```

Summary example:
```
***** The Winner is: Ami *****
Number of turns: 7 
----------
Initial State:
Deck: 2C KS JC JS JD JH 3C 3S 3D 3H
Ami: 2H QC QH QS KC KD AS
Tami: 2D 2S QD KH AC AD AH
----------
Final State:
Deck: 3S 3D 3H
Ami:
```


