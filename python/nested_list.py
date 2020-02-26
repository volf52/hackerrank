import sys
from datetime import datetime
from typing import List

lowest = sys.float_info.max
second_lowest = sys.float_info.max
lowest_names: List[str] = []
second_lowest_names = []
for _ in range(int(input())):
    name = input()
    score = float(input())
    if score < lowest:
        lowest = score
        second_lowest = lowest
        second_lowest_names = lowest_names[:]
        lowest_names = [name]
    elif score == lowest:
        lowest_names.append(name)
    elif score < second_lowest:
        second_lowest = score
        second_lowest_names = [name]
    elif score == second_lowest:
        second_lowest_names.append(name)
print("\n".join(sorted(second_lowest_names)))
