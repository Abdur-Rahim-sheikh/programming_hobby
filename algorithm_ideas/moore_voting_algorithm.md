# we can know if in N number there is a number which occurance is more then N/2 time in O(n) time complexity and O(1) space complexity

```
public int majorityElement(int[] nums) {  //T.C:0(n)  A.S:0(1)
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if(num==candidate)
            count += 1; 
            else count -= 1; 
        }

        return candidate;
    }
}
<!-- credit: (aaisha-afreen)[https://leetcode.com/aaisha-aafreen] -->
```