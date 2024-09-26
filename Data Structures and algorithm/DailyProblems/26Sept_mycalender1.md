# My Calender I
[Problem Link](https://leetcode.com/problems/my-calendar-i/description/?envType=daily-question&envId=2024-09-26)

## Problem desciption 

You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.

A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).

The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end], the range of real numbers x such that start <= x < end.

Implement the MyCalendar class:

MyCalendar() Initializes the calendar object.
boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.
 

### Example 1:

**Input**
["MyCalendar", "book", "book", "book"]<BR>
[[], [10, 20], [15, 25], [20, 30]]<BR>
**Output**
[null, true, false, true]<BR>

**Explanation**
MyCalendar myCalendar = new MyCalendar();<BR>
myCalendar.book(10, 20); // return True<BR>
myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by another event.<BR>
myCalendar.book(20, 30); // return True, The event can be booked, as the first event takes every time less than 20, but not including 20.<BR>

## constraints
* 0 <= start < end <= 109
* At most 1000 calls will be made to book.

## Code
```cpp
class MyCalendar {
public:
    vector<pair<int, int>> ranges;
    MyCalendar() {}
    bool book(int start, int end) {
        for (auto const& pair : ranges) {
            int r_start = pair.first;
            int r_end = pair.second;
            if (start < r_end && end > r_start)
                return false;
        }
        ranges.push_back(make_pair(start, end));
        return true;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
```
Overlapping problems 
## Intuition


## Approach


## Complexity
- Time complexity:


- Space complexity:
