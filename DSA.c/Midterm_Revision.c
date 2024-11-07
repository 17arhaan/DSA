https://chat.openai.com/share/1a03bb4f-5198-4b26-b164-7a848246489e
//______LAB 1______

- Data structures are essential for organizing and storing data in programs.
- Common data structures include arrays, stacks, queues, linked lists, and trees.
- Arrays allocate contiguous memory, with static arrays allocated at compile time and dynamic arrays at runtime.
- Stacks operate on a Last In First Out (LIFO) basis, with push and pop operations.
- Queues operate on a First In First Out (FIFO) basis, with enqueue and dequeue operations.
- Linked lists store data non-linearly, with nodes created at runtime and pointers linking them.
- Singly linked lists have one pointer to the next node, while doubly linked lists have two pointers.
- Trees, such as binary trees, are useful for specialized storage requirements like graphs and dictionaries, with nodes potentially having two children.

//______LAB 2______

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
//“opcount” means counting how many basic steps or actions an algorithm performs to solve a problem.

/*The “middle school method” refers to a basic technique often taught in middle school for finding the greatest common divisor (GCD) of two numbers. It involves listing the factors of each number and finding the greatest number that divides both numbers evenly.

Here’s a simplified version of the middle school method:

	1.	List all the factors of each number.
	2.	Find the common factors shared by both numbers.
	3.	The greatest common factor (GCF) is the largest number that appears in both lists.

For example, let’s find the GCD of 24 and 36 using the middle school method:

Factors of 24: 1, 2, 3, 4, 6, 8, 12, 24
Factors of 36: 1, 2, 3, 4, 6, 9, 12, 18, 36

Common factors: 1, 2, 3, 4, 6, 12

The greatest common factor (GCD) is 12.

1. Time-Consuming: Listing all factors for large numbers is inefficient, leading to longer computation times.
2. Memory Intensive: Requires significant memory to store factors, becoming impractical for large inputs.
3. Lack of Algorithmic Complexity Analysis: Difficulty in determining exact number of operations makes it unsuitable for understanding algorithm efficiency.

While the middle school method is straightforward, it becomes impractical for large numbers because listing all the factors can be time-consuming. That’s why more efficient algorithms. */

//______LAB 3______
/*
Brute Force Technique:
A straightforward approach that exhaustively tries all possible solutions without employing any optimizations or heuristics. It typically involves systematically checking every option in a problem space until the correct solution is found, making it less efficient for complex problems but easier to implement and understand.
	
Disadvantages :-
    3.	Lack of Scalability: Time and resources required grow exponentially with problem size, limiting its applicability.
	4.	Suboptimal Solutions: Does not leverage problem-specific insights, often resulting in less efficient solutions.
	5.	Feasibility Constraints: Impractical for problems with vast solution spaces due to time and resource constraints.

Selection Sort :-
*/
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

//______LAB 4______
/*
A bipartite graph is a type of graph where you can split the vertices into two groups so that no two vertices in the same group are connected by an edge. It's like having two separate groups of friends where everyone knows someone from the other group, but not within their own group.

Travelling Salesman's Problem:-
*/
int tsp(int cities, int mask, int current) {
    if (mask == (1 << cities) - 1) {
        return graph[current][0];
    }
    int min_cost = 999999;
    for (int i = 0; i < cities; i++) {
        if (!(mask & (1 << i))) {
            int cost = graph[current][i] + tsp(cities, mask | (1 << i), i);
            min_cost = min(min_cost, cost);
        }
    }
    return min_cost;
}

//______LAB 5______
/*
Decrease and Conquer Method:
A problem-solving strategy where the problem is gradually reduced or simplified into smaller instances until reaching a base case that can be directly solved. It differs from divide and conquer in that the problem is not divided into equal parts but is instead simplified in each iteration until it becomes solvable. This approach typically involves reducing the problem size by a constant factor with each iteration until reaching a base case.

Disadvantages:-
	1.	Overhead: Involves additional computational overhead due to repeated reduction of problem size until it becomes solvable.
	2.	Difficulty in Identifying Base Cases: Challenging to determine appropriate stopping points or base cases for problem reduction, leading to potential implementation errors.
	3.	Limited Applicability: Not suitable for all types of problems, making it less versatile in problem-solving contexts.
	4.	Not Universally Effective: May not be the most efficient or effective approach for all problem-solving scenarios, limiting its overall utility.

*/

__________________

Method,Approach,Advantages,Disadvantages
Brute Force,Tries every possible solution without optimization or heuristics,Simple to implement,Inefficient for large problems; Requires significant time and resources
Middle School Method,Lists all factors of each number and finds common factors,Easy to understand; Suitable for small inputs,Time-consuming for large numbers; Memory-intensive
Decrease and Conquer,Reduces problem size until directly solvable,Simple to understand; Versatile,Additional overhead in problem reduction; Limited applicability
