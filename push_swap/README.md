## MISTAKE NOTES (append_node())
- `if (!(*stack))`: This expression checks whether the value pointed to by `stack` (i.e., the pointer to the first node in the stack) is `NULL`. If the value pointed to by `stack` is `NULL`, the condition evaluates to true, indicating that the stack is empty.

- `if (*stack == NULL)`: This expression also checks whether the value pointed to by `stack` (i.e., the pointer to the first node in the stack) is `NULL`. If the value pointed to by `stack` is `NULL`, the condition evaluates to true, indicating that the stack is empty.

Both expressions essentially serve the same purpose in this context, as they are checking whether the stack is empty by examining the pointer to the first node (`*stack`). 