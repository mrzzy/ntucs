---
title: SC1007 Tutorial 1
---
            
# SC1007 Tutorial 1
## Q1
a. Yes
- `definition of 'struct person' is not complete until the closing }`.
- To define a recursive type (eg. `ListNode`) use a pointer instead
b. `studentPtr->Info.age`
c. `(*studentPtrPtr)->Info.age`

## Additional Q1
First `Q3F2()` invocation will create a circular linked list between `Aptr` & `Bptr`.
Second `Q3F2()` invocation will create a circular linked list containing only `Bptr` & `Aptr`.