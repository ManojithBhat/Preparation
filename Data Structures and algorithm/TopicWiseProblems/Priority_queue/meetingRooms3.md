#  Meeting Rooms III
[Problem Link](https://leetcode.com/problems/meeting-rooms-iii/description/)

## Problem desciption 
You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.

### Example 1:
 
> **Input**: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]] <br>
> **Output**: 0 <br>
> **Explanation**: <br>
> - At time 0, both rooms are not being used. The first meeting starts in room 0. <br>
> - At time 1, only room 1 is not being used. The second meeting starts in room 1. <br>
> - At time 2, both rooms are being used. The third meeting is delayed. <br>
> - At time 3, both rooms are being used. The fourth meeting is delayed. <br>
> - At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10). <br>
> - At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11). <br>
> Both rooms 0 and 1 held 2 meetings, so we return 0. 


### Example 2:

> **Input**: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]<br>
> **Output**: 1<br>
> **Explanation**:<br>
> - At time 1, all three rooms are not being used. The first meeting starts in room 0.<br>
> - At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.<br>
> - At time 3, only room 2 is not being used. The third meeting starts in room 2.<br>
> - At time 4, all three rooms are being used. The fourth meeting is delayed.<br>
> - At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).<br>
> - At time 6, all three rooms are being used. The fifth meeting is delayed.<br>
> - At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).<br>
> Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1. 

## constraints
* 1 <= n <= 100
* 1 <= meetings.length <= 105
* meetings[i].length == 2
* 0 <= starti < endi <= 5 * 105
* All the values of starti are unique.

## Code
```cpp

class Solution {
public:
/*
    1. we keep two min-heaps -> one keep track of the end time of the meeting and the room allocated to it, and the second available rooms in the decreasing order.
    2. when the next meeting start time is greater than the min-heap top, which means that the meeting have been concluded long back, and has to be put in the available meeting rooms list. so that smallest one could be taken.
    3. then we select from the minimum available meeting room.
    4. If there is no room in the available set, then we wait till the meeting in the alloted list and add the duration to it.
    5. Then we iterate through the count array to get the minimum one. 

*/
    typedef pair<long long,int> P;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        sort(meetings.begin(),meetings.end());
        vector<int> count(n,0);

        priority_queue<P,vector<P>,greater<P>> allotedRooms;
        priority_queue<int,vector<int>,greater<int>> availableRooms;

        for(int i = 0;i<n;i++) availableRooms.push(i);

        for(auto &it: meetings){
            int start = it[0];
            int end = it[1];
            int duration = end - start;

            while(!allotedRooms.empty() && allotedRooms.top().first <= start){
                int roomNumber = allotedRooms.top().second;
                allotedRooms.pop();
                availableRooms.push(roomNumber);
            }

            if(availableRooms.size()){
                int room = availableRooms.top();
                availableRooms.pop();
                allotedRooms.push({end,room});
                count[room]++;
            }else{
                int room = allotedRooms.top().second;
                long long endTime = allotedRooms.top().first;
                allotedRooms.pop();

                allotedRooms.push({endTime + duration,room});
                count[room]++;
            }
        }

        int maxVal = INT_MIN;
        int room = -1;

        for(int i = 0;i<n;i++){
            if(maxVal < count[i]){
                maxVal = count[i];
                room = i;
            }
        }

        return room;
    }
};
```

## Intuition


## Approach


## Complexity
- Time complexity: O(m log n)

- Space complexity: 