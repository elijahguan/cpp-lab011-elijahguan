# Map Analysis Laboratory

## Core goal
Students must implement a dictionary-like `Map` structure that stores key-value pairs and supports lookup, insertion, deletion, and updates.

## Required operations
Students must implement the following behavior:

- insert a new key-value pair;
- reject duplicate keys;
- find whether a key exists;
- update an existing value;
- remove an existing key;
- retrieve a value by key;
- list keys and values;
- maintain sorted order if appropriate for the design.

## Analysis expectations
Students should discuss:

- average-case time complexity of insertion, lookup, and deletion; All of these operations use findIndex, which scans linearly, giving an O(n) average case. Inserting a new key will also sort the whole vector, which takes O(n log n) time. Deletion also takes O(n) to find and then shift the later entries.
- best-case and worst-case behavior; The best case is when the key is the first entry, but the worst case is when the element doesn't exist, which gives us O(n) time. Inserting a new key becomes O(n log n) which is slower than the linear time complexity of insertion.
- why duplicate-key handling matters; If the key already exists, insert will return false. This allows each key to be unique so it allows for a many-to-one relationship. 
- the difference between a search by key and scanning all entries; Searching by key is comparing keys and the latter is scanning entries linearly until it finds a match, giving O(n) in the average and worst cases.
- trade-offs between sorted vectors and hash-based maps; Using vectors will require sorting after every new insertion but gives linear time for searching. Hash-based map gives average O(1) lookup, insertion, and removal, but doesn't keep keys sorted.
- memory overhead and performance of `keys()` and `values()`. Both visit all entries and build a new vector, so it will be O(n) time and O(n) space. The keys are returned in sorted order and the values are returned in the corresponding order.

## Big-O focus
Students should explain the Big-O of:

- `insert`: O(n log n) for a new key since the vector is sorted after insertion. If the key is already present, it will still require a linear traversal to make sure the element is unique. 
- `contains`: If the key is first, best case is O(1). Average and worst case are O(n) since search may need to scan all entries.
- `update`: If the key is first, best case is O(1). Average and worst case are O(n) since search may need to scan all entries. Assigning the new value is constant O(1) time.
- `erase`: O(n) in the average case and worst case. First scans to find the key, and then shift elements when needed.
- `at`: If the key is first, best case is O(1). Average and worst case is O(n) for search. Further operations such as returning or assignment take O(1).
- `keys`: O(n) time and space to build the vector.
- `values`: O(n) time and space to build the vector.

The expected design is a clear, well-explained mapping abstraction that makes trade-offs explicit.
