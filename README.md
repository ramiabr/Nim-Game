# Nim-Game

## Nim Game rules: 
• There are two players.
• The game starts out with pile of 𝑛 chips.
• The players alternate in removing chips from the pile.
• Neither player is allowed to remove 0 chips.
• The player who moves first can remove at most 𝑛−1 chips.
• After the first move, each player may remove, at most, twice the number of chips his opponent removed on the previous move.
• The player who removes the last chip wins.


## Solution using Fibonacci numbers:
• Let there be "n" chips in pile, the computer will decompose the number of chips in the pile Zeckendorf decomposition
• Computer will reduce the Length of Zeckendorf decomposition and also ensures that opponent cannot reduce the length of decomposition
• That will be winning move for each game play.  

For e.g. if the number of chips in pile is 54 then Zeckendorf form  = 34 + 13 + 3 + 1
• Computer can remove 34 + 13 + 3 + 1 = 54 Chips and reduce the Zeckendorf length to 0, that is sure a winning move.   
• if Computer removes 13 + 3 + 1 = 17 Chips, the length of Zeckendorf decomposition reduces to 1. But the opponent can remove 34 chips and win the game, so its not a winning move. 
• If computer removes 3 + 1 = 4 Chips, the Zeckendorff decomposition of remaining chips reduces to 2. The opponent can remove 8 chips But he will not be able to reduce the length of Zeckendorf decomposition.
• If computer removes 1 Chip, the Zeckendorff decomposition of remaining chips reduces to 53. The opponent can remove 2 chips But he will not be able to reduce the length of Zeckendorf decomposition.



## Running Time of the Algorithm: 
To Calculate Winning move in each Iteration = O(n^2)
