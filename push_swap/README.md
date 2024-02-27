## MISTAKE NOTES (append_node())
- In append_node ahd incorrect if loop: `if (!(*stack))` instead of the correct way: `if (*stack == NULL)`, which lead to incorrect error handling in certain situations.
- Issues come as the expression if `(!(*stack))` is checking whether the value pointed to by `stack` is NULL, not whether stack itself is NULL.

## MAIN WALKTHROUGH

## MEMORY MANAGEMENT & ERROR HANDLING

## SORTING 
- Turk sort
- Tiny sort and bool checker for handling the last 5 or 3 values

## INSPIRATION AND KEY DIFFERENCES

## ERROR CHECKLIST

- Non integer args:
Expected Behavior: Display "Error" followed by a '\n' on the standard error and exit without performing any sorting operations.

- Integer overflow:
Expected Behavior: Display "Error" followed by a '\n' on the standard error and exit without performing any sorting operations.

- Duplicate args:
Expected Behavior: Display "Error" followed by a '\n' on the standard error and exit without performing any sorting operations.

- Empty input:
Expected Behavior: Display nothing and give the prompt back. It should exit gracefully without performing any sorting operations.

- General errors:
Expected Behavior: Any other errors encountered during the execution of the program should be handled gracefully. The program should display "Error" followed by a '\n' on the standard error and exit without performing any sorting operations.



