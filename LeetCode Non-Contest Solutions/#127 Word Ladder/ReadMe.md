# Review 
* An excellent question to refresh the basics of **BFS** and **STL** containers.
* **Time Taken** : 15 minutes (including brain storming and coding)
* **Penalty** : None
* **What's New?**
  * Found a clean way for searching in an unordered_map/set. 
  * Adopted a new way to populate STL Containers with the help of existing containers.
  * A Novel approach to change a single charcter of a string using range based for loops.
  
# Approach
* Store all the dictionary words in a hashmap called `dictionary` to facilitate quick searching.
* Make another hashmap `visited` which contains all the string which are visited.
* The queue would store the string and its level. (i,e a pair).
* Whenever you pop a string during bfs, iterate over each of the characters and try to replace them with all the alphabets (while keeping the remaining letters same. If the new string is present in the dictionary and is not visited, visit it.
  
  # To Do
  * Perform BFS with marker to avoid pushing a pair into the queue.
  * Apply an alternate technique of modifying the dictionary instead of a `visited` hashmap.
