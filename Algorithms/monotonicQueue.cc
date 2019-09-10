#include <bits/stdc++.h>
using namespace std; //(If we use this, then we don't need to use std::<> everywhere.)

// The idea is to store only elements which can be the answer, and store till when will they
// remain an answer.
// So if a smaller element comes, then it can't be the answer till the larger element before it is
// out of the window. If a larger element comes after a smaller element, then the smaller
// element can no longer be our answer ever, so we can safely remove it right then, but it can be
// popped later (reduce count) as the window slides.
class Monoqueue
{
    deque<pair<int, int>> m_deque; //pair.first: the actual value,
                                   //pair.second: how many elements were deleted between it and the one before it.
    public:
        void push(int val)
        {
            int count = 0;
            while(m_deque.empty()==false && m_deque.back().first < val)
            {
                count += m_deque.back().second + 1;
                m_deque.pop_back();
            }
            m_deque.emplace_back(val, count);
        };
        int max()
        {
          //This is suitable for only sliding window, in which case m_queue will never be empty,
          //but in a general case, it should check if m_queue is empty or not, if empty, return -1.
            return m_deque.front().first;
        }
        void pop ()
        {
            if (m_deque.front().second > 0)
            {
                m_deque.front().second --;
                return;
            }
            //If m_deque.front().second <= 0, there are zero or 1 elements in the underlying DQ, so pop_front();
            m_deque.pop_front();
        }
};
struct Solution {
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> results;
        Monoqueue mq;
        k = min(k, (int)nums.size());
        int i = 0;
        for (;i < k - 1; ++i) //push first k - 1 numbers;
        {
            mq.push(nums[i]);
        }
        for (; i < nums.size(); ++i)
        {
            mq.push(nums[i]);            // push a new element to queue;
            results.push_back(mq.max()); // report the current max in queue;
            mq.pop();                    // pop first element in queue;
        }
        return results;
    }
};
