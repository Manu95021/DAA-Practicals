#include <iostream>
using namespace std;

int fact(int n)
{
    if(n == 0)
        return 1;
    return n * fact(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << fact(n);
}



#include <iostream>
using namespace std;

int main()
{
    int n, fact = 1;
    cin >> n;

    for(int i = 1; i <= n; i++)
        fact = fact * i;

    cout << fact;
}




Conclusion

Recursive Method: Solves the problem by calling the same function repeatedly.
Time complexity is O(n) and space complexity is O(n).

Iterative Method: Solves the problem using a loop. 
Time complexity is O(n) and space complexity is O(1).

Overall: Iteration uses less memory, while recursion can make some problems easier to solve.
