int lagDuration(int h1, int m1, int h2, int m2, int k) {
    // Return an integer denoting the duration of time in minutes by which the clock has been lagging.
    
    return std::abs((h2 - (h1 + k)) * 60 + (m2 - m1));
}

/*
Vernon is a working man. He needs to attend a conference, and so he has to leave his home at exactly , denoting the time in hours and minutes in a 24-hour clock. The moment he leaves, his home clock displays the correct time, .

image

He returns home after exactly  hours. It is guaranteed that he returns on the same day, hence . However, the home clock shows , which may or may not be the correct time. He suspects that the home clock is lagging, and he wishes to know the duration of time in minutes by which his home clock has been lagging.

It is guaranteed that the actual time is either the same as, or after the time displayed by the clock.

Complete the function lagDuration which takes in five integers  and returns an integer denoting the duration of time in minutes by which the clock has been lagging.

Input Format

The first line contains , the number of queries.

Each query is described by two lines. The first line contains four space-separated integers . The second line contains a single integer .

Constraints

It is guaranteed that  is strictly before 
Output Format

For each query, print a single line containing a single integer indicating the duration of time in minutes by which the clock has been lagging.

Sample Input 0

6
12 0 12 58
1
10 12 10 17
2
11 40 15 33
6
18 13 19 25
5
14 27 21 1
9
16 40 23 40
7
Sample Output 0

2
115
127
228
146
0
Explanation 0

In the first query, the home clock initially displays . He returns home at , exactly  hour after he leaves. But at this point, the clock displays . Hence, the clock must be lagging by  minutes.

In the second query, the home clock initially displays . He returns home at , exactly hours after he leaves. But at this point, the clock displays . Hence, the clock must be lagging by minutes.
*/
