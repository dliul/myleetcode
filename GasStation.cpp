/*
 * Two properties:
 *  (1) if the total cost is great than the total gas, no valid start station
 *  (2) if the total cost of the first n stations is great than the total gas of 
 *  the first n stations, none of the first n stations can be the start point.
 *
 *
 *  Reference:
 *  http://blog.csdn.net/kenden23/article/details/14106137 (Chinese)
 *
 */


#include <iostream>
#include <vector>
using std::cout;
using std::vector;

class Solution {
public:
	int can CompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int tank = 0;
		int total = 0;
		int start = -1; 
		// the start point should be initialized by -1 
		// in order to avoid the corner case when there is only one station
		for ( int i = 0; i < gas.size(); ++i ) {
			tank += gas[i] - cost[i];
			total += gas[i] - cost[i];
			if ( tank < 0 ) {
				start = i; tank = 0;
			}
		}
		if ( total < 0 ) return -1;
		else return start + 1;
	}
};
