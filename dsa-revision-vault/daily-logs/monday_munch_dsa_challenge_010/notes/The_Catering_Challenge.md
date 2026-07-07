# The Catering Challenge

Brute force:
Try every possible order schedule for D days. This is exponential because each day can choose many orders.

Intuition:
If no work is done, penalty is sum(Ti * Si).
One day of work on order i saves Si penalty.
Therefore, every day Chef should work on the available order with maximum Si.

Optimal:
Group orders by arrival day. Use max heap ordered by Si.
Each day add newly arrived orders, pop highest Si, work one day, reduce penalty, and push back if unfinished.

Complexity:
O((N + D) log N)
