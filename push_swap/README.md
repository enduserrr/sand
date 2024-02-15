## MISTAKE NOTES (append_node())
- In append_node ahd incorrect if loop: `if (!(*stack))` instead of the correct way: `if (*stack == NULL)`, which lead to incorrect error handling in certain situations.
- Issues come as the expression if `(!(*stack))` is checking whether the value pointed to by `stack` is NULL, not whether stack itself is NULL.