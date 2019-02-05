
#%%
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

sort_times = pd.read_csv("measurements.csv", sep=";")
sort_times.head(3)

array_size = np.array(sort_times["Array size"])
bubble_time = np.array(sort_times["Bubble sorting time"])
selection_time = np.array(sort_times["Selection sorting time"])
insertion_time = np.array(sort_times["Insertion sorting time"])
quicksort_time = sort_times["Quick sorting time"]

plt.plot(array_size, bubble_time, label="Bubble sort")
plt.plot(array_size, insertion_time, label="Insertion sort")
plt.plot(array_size, selection_time, label="Selection sort")
plt.plot(array_size, quicksort_time, label="Quicksort")

plt.legend(loc="upper left")
plt.title("Sort time depending on array length", fontsize=14)
plt.xlabel("Number of elements in array")
plt.ylabel("Sorting time, ms")
plt.show()

#%%
plt.plot(array_size[0:50], bubble_time[0:50], label="Bubble sort")
plt.plot(array_size[0:50], insertion_time[0:50], label="Insertion sort")
plt.plot(array_size[0:50], selection_time[0:50], label="Selection sort")
plt.plot(array_size[0:50], quicksort_time[0:50], label="Quicksort")

plt.legend(loc="upper left")
plt.title("Sort time depending on array length", fontsize=14)
plt.xlabel("Number of elements in array")
plt.ylabel("Sorting time, ms")
plt.show()

#%%
plt.plot(array_size[0:15], bubble_time[0:15], label="Bubble sort")
plt.plot(array_size[0:15], insertion_time[0:15], label="Insertion sort")
plt.plot(array_size[0:15], selection_time[0:15], label="Selection sort")
plt.plot(array_size[0:15], quicksort_time[0:15], label="Quicksort")

plt.legend(loc="upper left")
plt.title("Sort time depending on array length", fontsize=14)
plt.xlabel("Number of elements in array")
plt.ylabel("Sorting time, ms")
plt.show()

