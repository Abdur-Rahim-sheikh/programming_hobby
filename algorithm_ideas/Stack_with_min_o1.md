## Implement a stack Which extra feature is get min value in O(1) time complexity and min_value should only consume O(1) space complexity

**Idea from geeks for geeks
An approach that uses O(1) time and O(n) extra space is discussed here.
In this article, a new approach is discussed that supports minimum with O(1) extra space. We define a variable minEle that stores the current minimum element in the stack. Now the interesting part is, how to handle the case when minimum element is removed. To handle this, we push “2x – minEle” into the stack instead of x so that the previous minimum element can be retrieved using the current minEle and its value stored in the stack. Below are detailed steps and an explanation of work.

Push(x) : Inserts x at the top of stack. 

If the stack is empty, insert x into the stack and make minEle equal to x.
If the stack is not empty, compare x with minEle. Two cases arise:
If x is greater than or equal to minEle, simply insert x.
If x is less than minEle, insert (2*x – minEle) into the stack and make minEle equal to x. For example, let previous minEle was 3. Now we want to insert 2. We update minEle as 2 and insert 2*2 – 3 = 1 into the stack.
Pop() : Removes an element from top of stack. 

Remove element from top. Let the removed element be y. Two cases arise:
If y is greater than or equal to minEle, the minimum element in the stack is still minEle.
If y is less than minEle, the minimum element now becomes (2*minEle – y), so update (minEle = 2*minEle – y). This is where we retrieve previous minimum from current minimum and its value in stack. For example, let the element to be removed be 1 and minEle be 2. We remove 1 and update minEle as 2*2 – 1 = 3.
Important Points: 

Stack doesn’t hold actual value of an element if it is minimum so far.
Actual minimum element is always stored in minEle

My Code
```
class MinStack {
    long array[3*10000];
    long idx, minValue;
public:
    MinStack() {
        idx = -1;
    }
    
    void push(int val) {
        idx++;
        if(idx==0) minValue = val;
        
        
        if(val<minValue){
            array[idx] = 2*(long)val - minValue;
            minValue = val;
        }
        else array[idx] = val;
    }
    
    void pop() {
        if(idx>=0){
            if(array[idx]<minValue)
                minValue = 2*minValue - array[idx];
            idx--;
        }
    }
    
    int top() {
        return array[idx]<minValue?minValue:array[idx];
    }
    
    int getMin() {
        return minValue;
    }
};
```