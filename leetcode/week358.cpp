class Solution {
public:
    int findMaxBit(int num) {
        int maxbit = 0;
        int currbit = 0;
        while (currbit = num % 10) {  // 此处写法有问题
            if (currbit > maxbit)
                maxbit = currbit;
            num /= 10;
        }
        return maxbit;
    }
    int maxSum(vector<int>& nums) {
        map<int, priority_queue<int>> buckets;
        // buckets.reserve(10);
        for(auto n : nums) {
            int index = findMaxBit(n);
            // cout << "index: " << index << endl;
            buckets[index].push(n);
        }
        int result = -1;
        for(auto bucket : buckets) {
            auto b = bucket.second;
            if (b.size() < 2)
                continue;
            int max1 = b.top();
            b.pop();
            int max2 = b.top();
            int max = max1 + max2;
            if (max > result)
                result = max;
        }
        return result;
    }
};

class Solution {
public:
    int findMaxBit(int num) {
        int maxbit = 0;
        int currbit = 0;
        while (num) {
            currbit = num % 10;
            if (currbit > maxbit)
                maxbit = currbit;
            num /= 10;
        }
        return maxbit;
    }
    int maxSum(vector<int>& nums) {
        map<int, priority_queue<int>> buckets;
        // buckets.reserve(10);
        for(auto n : nums) {
            int index = findMaxBit(n);
            cout << "index: " << index << endl;
            buckets[index].push(n);
        }
        int result = -1;
        for(auto bucket : buckets) {
            auto b = bucket.second;
            if (b.size() < 2)
                continue;
            int max1 = b.top();
            b.pop();
            int max2 = b.top();
            int max = max1 + max2;
            cout << max1 << " " << max2<<endl;
            if (max > result)
                result = max;
        }
        return result;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void printLinkList(ListNode* head) {
      if (!head) {
        cout << "empty list" << endl;
        return;
      }
      auto p = head;
      while(p) {
        std::cout << p->val << " ";
        p = p->next;
      }
      std::cout << std::endl;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode * prev = nullptr, * curr = head, * tmp = nullptr;
        while(curr) {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        head = prev;
        return head;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode * rhead = reverseList(head);
        ListNode * p = rhead;
        int carry = 0;
        while (p) {
            int mul = p->val * 2 + carry;
            p->val = mul % 10;
            carry = mul / 10;
            // cout << "val: " << p->val << " " << carry << endl;
            if (p->next == nullptr && carry != 0) {
                p->next = new ListNode(carry);
                p->next->next = nullptr;
                break;
            }
            p = p->next;
        }
        head = reverseList(rhead);
        return head;
    }
};

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int min = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j <= i - x; ++j) {
                int curr = abs(nums[i] - nums[j]);
                if (curr < min)
                    min = curr;
            }
            for (int j = i + x; j < nums.size(); ++j) {
                int curr = abs(nums[i] - nums[j]);
                if (curr < min)
                    min = curr;
            }
        }
        return min;
    }
};