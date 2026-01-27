𝑇ℎ𝑖𝑠 𝑝𝑟𝑜𝑗𝑒𝑐𝑡 ℎ𝑎𝑠 𝑏𝑒𝑒𝑛 𝑐𝑟𝑒𝑎𝑡𝑒𝑑 𝑎𝑠 𝑝𝑎𝑟𝑡 𝑜𝑓 𝑡ℎ𝑒 42 𝑐𝑢𝑟𝑟𝑖𝑐𝑢𝑙𝑢𝑚 𝑏𝑦 <𝑟𝑎𝑟𝑟𝑖𝑜𝑙𝑎>
# Description
- Goal: The learning objectives of this project are rigor, proficiency in C, and the application of
basic algorithms, with a particular focus on their complexity.
- Brief overview: Push_swap is an algorithmic challenge where you must sort a stack of random integers using only two stacks (A and B) and a specific set of operations. The goal is to sort stack A in ascending order with the smallest number of operations possible.
# Instructions
## Compilation
- make        # Compile the project
- make clean  # Remove object files
- make fclean # Remove object files and executable
- make re     # Recompile from scratch
##  Usage
- ./push_swap [list of integers]
## Examples
- ./push_swap 3 2 1
- ./push_swap "3 2 1"
- ./push_swap 5 "3 2" 1 4
## Testing
- ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
## Benchmark with random numbers
- *100 numbers*
- ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

- *500 numbers*
- ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l
# Resources
- https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
- Used AI to help me with the logic of the starting process. Claude.
