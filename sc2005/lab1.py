#
# NTU CS
# SC2005 Lab 1
# Convert Lab 1 output to Submission CSV
# Usage: output.py output.txt
#   output.txt: Debug output from nachos -d

import sys
import re
import csv


if __name__ == "__main__":
    with open(sys.argv[1], "r") as f:
        # discard first section
        sections = f.read().split("==")[1:]

    with open("output.csv", "w") as f:
        out = csv.DictWriter(
            f,
            [
                "Tick",
                "ready list",
                "current thread",
                "printf message",
                "Context switch",
            ],
        )

        # thread state
        ready, current = [], "main"
        current = "main"

        # parse tick sections into csv row
        for i in range(len(sections) // 2):
            tick = int(sections[i * 2].split()[-1])
            content = sections[i * 2 + 1]

            # content switch between threads
            switch_to = None
            if match := re.search(
                r"Switching from thread \w+ #0 to thread (\w+) #0", content
            ):
                switch_to = match[1]
            # printf content
            printed = None
            if match := re.search(r"\*\*\* (.*)", content):
                printed = match[1]

            out.writerow(
                {
                    "Tick": tick,
                    "ready list": "empty" if len(ready) == 0 else " ".join(ready),
                    "current thread": current,
                    "printf message": "n/a" if printed is None else printed,
                    "Context switch": "n/a" if switch_to is None else switch_to,
                }
            )
            # threads placed on ready list
            if match := re.search(r"Putting thread (\w+) #0 on ready list.", content):
                ready.append(match[1])
            # apply context switch on next tick
            if switch_to is not None:
                current = switch_to
                ready.remove(current)
