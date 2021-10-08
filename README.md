# Push Swap ~

### ~ a 42 School algorythmic project. Grade : 125/100.
## Goal	
#### Solving a "Tower of Hanoi like" puzzle using sequential access sorting algorithms.
## Usage
- make (compiles push_swap executable)
- ./push_swap [m] INT LIST
	- Optional "m" flag toggles step by step monitoring.

## Constraints ~
### ~ the catch
Starting with randomly ordered integers on one stack, we must order these by means of a second empty stack and a limited movements set :

- Pushing the topmost value of a stack to the next stack ( pa, pb )
- Swapping both topmost values of stack a, stack b or both ( sa, sb, ss )
- Rotating the topmost value of stack a, stack b or both under their bottom ( ra, rb, rr )
- Rotating the bottommost value of stack a, stack b or both over their top ( rra, rrb, rrr )

## Interest ~
### ~ now what ?
- Our algorithm performance is solely judged against its frugality of moves. Thus, it doesn't need to be shy about checks.  
- While this makes it a poor candidate for unbridled digital sorting on random access memory, it may shine when physical hindrances get in the way of quick random access to whatever needs sorting.
	- Tape storage or actual logistics challenges come to mind as potentially relevant for a sequential access sorting algorithm that checks twice and sorts once.
- From a pedagogic standpoint, this hurdle is obviously a way to get us to apply algorithmic beyond a stale copy-pasting of ubiquitous algorithms.

## Performance ~
### ~ not too shabby
Measured over 600+ random sets with the "complexity" tester thoughtfully arranged by scros https://github.com/SimonCROS/push_swap/blob/master/complexity
### 100 values sets :
- Worst : 651 moves
- Average :	599 moves
- Best : 548 moves

### 500 values sets :
- Worst : 4828 moves
- Average :	4671 moves
- Best : 4550 moves

## Technique ~
### ~ the nitty gritty
- I devised a recursive sequential access quicksort algorithm, taylored to the game constraints.
- This algorythm breaks our set into ever smaller sorted subsets until those hold less than 15 elements.
- An insertion sort subsequently orders the values inside these subsets.

## Implementation ~
### ~ under the hood
- Parsing uses a merge sort to check for doubles and attribute keys to each our values.
- Said keys correspond to the position of our ordered elements. Facilitating sorting, checking and optimisation down the line.
- Stack structure is achieved thanks to arrays.  
	- This data structure was favored over linked lists since we know the maximum size of our stacks from the get go, making memory reallocations unnecessary and taking advantage of cache processor optimisation for shifting/rotation of values.

## Optimization ~
### ~ the bag of tricks
- The subsets are pushed upside down on our second stack. Limiting the need for rotations when we put them back in order on our initial stack.
- The first quicksort pass cuts our initial set in half, as well as the subset pushed to our second stack (by rotating the smaller half of that subset under itself)
	- Therefore, two quartiles are defined early on the bigger quicksort subset.  
	- The ( up to n/4 ) added rotations save pushes between both stacks and further rotations.
- My insertion sort compensates its bruteforce sequential fetching by pushing neighbouring elements encountered while drawing from a stack.  
	- A single swap of their destination stack is then needed to order this "doubled draw".
- Joint instructions ( ss, rr, rrr ) are never called during actual solving of the puzzle.  
	- "Raw" instructions are instead stored in a buffer. Upon completion, this buffer is read by a function which prints the function calls and joins consecutive "joinable" calls.

## Bonuses ~
### ~ going further ?
- Thanks to a reversible array of function pointers pointing to our instruction set, and the use of keys instead of actual values, checker implementation was ridiculously breezy and largely reused the solver's code, parsing and data structures in particular.
- A monitoring feature was implemented ( even if it isn't a considered bonus anymore ) as it proved crucial to debug this project.
- Monitoring works with the checker as well, making it legible and playable ( if you ever fancy solving push swap manually ! ).

## Checker usage
- make bonus (compiles checker executable)
- ./checker [m] INT LIST
- Checker waits instruction input on stdin until shutdown is triggered by CTRL + D.
	- Optional "m" flag toggles step by step monitoring.
